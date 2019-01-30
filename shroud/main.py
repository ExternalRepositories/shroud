#!/bin/env python3
# Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC.
#
# Produced at the Lawrence Livermore National Laboratory
#
# LLNL-CODE-738041.
#
# All rights reserved.
#
# This file is part of Shroud.
#
# For details about use and distribution, please read LICENSE.
#
########################################################################
"""
generate language bindings
"""

from __future__ import print_function
from __future__ import absolute_import

import argparse
import json
import os
import sys
import yaml
from yaml.composer import Composer
from yaml.constructor import Constructor

from . import ast
from . import generate
from . import splicer
from . import todict
from . import typemap
from . import util
from . import whelpers
from . import wrapc
from . import wrapf
from . import wrapp
from . import wrapl


class Config(object):
    """A class to stash configuration values.
    """

    def __init__(self):
        self.c_fortran_dir = ""
        self.python_dir = ""
        self.lua_dir = ""
        self.yaml_dir = ""
        self.yaml_types = ""
        self.log = ""
        self.cfiles = []  # list of C/C++ files created
        self.ffiles = []  # list of Fortran files created
        self.pyfiles = []  # list of Python module files created


class TypeOut(util.WrapperMixin):
    """A class to write out Class type information.
    It may be 'imported' by another file to share classes across YAML files.
    It subclasses util.WrapperMixin in order to access
    write routines.
    """

    def __init__(self, newlibrary, config):
        self.newlibrary = newlibrary
        self.config = config
        self.log = config.log
        self.comment = "#"
        self.cont = ""
        self.linelen = 1000

    def write_types(self):
        """Write out types into a file.
        This file can be read by Shroud to share types.
        """
        newlibrary = self.newlibrary
        newlibrary.eval_template("YAML_type_filename")
        fname = newlibrary.fmtdict.YAML_type_filename
        output = []

        # split up into namespaces
        top = {}
        for cls in newlibrary.classes:
            fullname = cls.typemap.name
            parts = fullname.split("::")
            ns = top
            for part in parts[:-1]:
                ns = ns.setdefault(part, {})
            ns[parts[-1]] = cls.typemap

        output = []

        def splitup(ns, output):
            for name in sorted(ns.keys()):
                nxt = ns[name]
                if isinstance(nxt, dict):
                    output.append("@- namespace: " + name)
                    output.append(1)
                    output.append("declarations: " + name)
                    splitup(nxt, output)
                    output.append(-1)
                elif isinstance(nxt, typemap.Typemap):
                    output.append("@- type: " + name)
                    output.append(1)
                    output.append("fields:")
                    output.append(1)
                    nxt.__export_yaml__(0, output)
                    output.append(-2)
                else:
                    raise RuntimeError("Unexpected clss in splitup")

        splitup(top, output)

        if output:
            output = [
                "# Types generated by Shroud for library {}".format(
                    self.newlibrary.library
                ),
                "declarations:",
                1,
            ] + output

            self.write_output_file(
                fname, self.config.yaml_dir, output, spaces="  "
            )


def dump_jsonfile(logdir, basename, newlibrary):
    """Write a JSON file for debugging.
    """
    def_types = typemap.get_global_types()

    jsonpath = os.path.join(logdir, basename + ".json")
    fp = open(jsonpath, "w")

    out = dict(
        # This notice should sort to the top.
        __NOTICE__="This file is generated by Shroud "
        "and is useful for debugging.",
        library=todict.to_dict(newlibrary),
        types=todict.to_dict(def_types),
        # yaml=all,
    )

    json.dump(out, fp, sort_keys=True, indent=4, separators=(',', ': '))
    fp.close()


def main():
    from . import __version__

    appname = "shroud"

    parser = argparse.ArgumentParser(
        prog=appname,
        description="""Create Fortran or Python wrapper for a C++ library.
""",
    )
    parser.add_argument("--version", action="version", version=__version__)
    parser.add_argument(
        "--outdir",
        default="",
        help="Directory for output files." "Defaults to current directory.",
    )
    parser.add_argument(
        "--outdir-c-fortran",
        default="",
        dest="outdir_c_fortran",
        help="Directory for C/Fortran wrapper output files, "
        "overrides --outdir.",
    )
    parser.add_argument(
        "--outdir-python",
        default="",
        dest="outdir_python",
        help="Directory for Python wrapper output files, "
        "overrides --outdir.",
    )
    parser.add_argument(
        "--outdir-lua",
        default="",
        dest="outdir_lua",
        help="Directory for Lua wrapper output files, " "overrides --outdir.",
    )
    parser.add_argument(
        "--outdir-yaml",
        default="",
        dest="outdir_yaml",
        help="Directory for yaml output files, " "overrides --outdir.",
    )
    parser.add_argument(
        "--logdir",
        default="",
        help="Directory for log files." "Defaults to current directory.",
    )
    parser.add_argument(
        "--cfiles",
        default="",
        help="Output file with list of C and C++ files " "created.",
    )
    parser.add_argument(
        "--ffiles", default="", help="Output file with list of Fortran created"
    )
    parser.add_argument(
        "--path",
        default=[],
        action="append",
        help="Colon delimited paths to search for "
        "splicer files, may be supplied multiple "
        "times to append to path.",
    )
    parser.add_argument(
        "--cmake", default="", help="Create a file with CMake macro"
    )
    parser.add_argument(
        "--yaml-types", default="", help="Write a YAML file with default types"
    )
    parser.add_argument("filename", nargs="*", help="Input file to process.")

    args = parser.parse_args()
    main_with_args(args)
    #    sys.stderr.write("Some useful message")  # example error message
    sys.exit(0)  # set status for errors


def create_wrapper(filename, outdir="", path=None):
    """Translate function arguments into command line options.
    Return config instance. It has list of files created.
    Create a wrapper from a Python program.
    Useful with setup.py.
       config = shroud.create_wrapper('../../ownership.yaml', outdir=outdir)
    """
    args = argparse.Namespace()
    args.cmake = ""
    args.cfiles = ""
    args.ffiles = ""
    args.filename = [filename]
    args.logdir = ""
    args.outdir = outdir
    args.outdir_c_fortran = ""
    args.outdir_lua = ""
    args.outdir_python = ""
    args.outdir_yaml = ""
    if path is None:
        args.path = []
    else:
        args.path = path
    args.yaml_types = ""

    config = main_with_args(args)

    return config


def main_with_args(args):
    """Main after args have been parsed.
    Useful for testing.
    """
    if args.cmake:
        # Create C make file
        try:
            fp = open(args.cmake, "w")
            fp.write(whelpers.cmake)
            fp.close()
            raise SystemExit
        except IOError as e:
            print(str(e))
            raise SystemExit(1)

    # check command line options
    if len(args.filename) == 0:
        raise SystemExit("Must give at least one input file")
    if args.outdir and not os.path.isdir(args.outdir):
        raise SystemExit("outdir {} does not exist".format(args.outdir))
    if args.outdir_c_fortran and not os.path.isdir(args.outdir_c_fortran):
        raise SystemExit(
            "outdir-fortran {} does not exist".format(args.outdir_c_fortran)
        )
    if args.outdir_python and not os.path.isdir(args.outdir_python):
        raise SystemExit(
            "outdir-python {} does not exist".format(args.outdir_python)
        )
    if args.outdir_lua and not os.path.isdir(args.outdir_lua):
        raise SystemExit("outdir-lua {} does not exist".format(args.outdir_lua))
    if args.outdir_yaml and not os.path.isdir(args.outdir_yaml):
        raise SystemExit(
            "outdir-yaml {} does not exist".format(args.outdir_yaml)
        )
    if args.logdir and not os.path.isdir(args.logdir):
        raise SystemExit("logdir {} does not exist".format(args.logdir))

    # append all paths together
    if args.path:
        search_path = []
        for pth in args.path:
            search_path.extend(pth.split(":"))
    else:
        search_path = ["."]

    basename = os.path.splitext(os.path.basename(args.filename[0]))[0]
    logpath = os.path.join(args.logdir, basename + ".log")
    log = open(logpath, "w")

    # pass around a configuration object
    config = Config()
    config.c_fortran_dir = args.outdir_c_fortran or args.outdir
    config.python_dir = args.outdir_python or args.outdir
    config.lua_dir = args.outdir_lua or args.outdir
    config.yaml_dir = args.outdir_yaml or args.outdir
    config.yaml_types = args.yaml_types
    config.log = log
    #    config.cfiles = []  # list of C/C++ files created
    #    config.ffiles = []  # list of Fortran files created
    #    config.pyfiles = [] # list of Python module files created

    # accumulated input
    allinput = {}
    splicers = dict(c={}, f={}, py={}, lua={})

    for filename in args.filename:
        ext = os.path.splitext(filename)[1]
        if ext == ".yaml":
            # print("Read %s" % os.path.basename(filename))
            log.write("Read yaml %s\n" % os.path.basename(filename))
            fp = open(filename, "r")
            # d = yaml.load(fp.read())  # no line numbers

            # https://stackoverflow.com/questions/13319067/
            # parsing-yaml-return-with-line-number
            loader = yaml.Loader(fp.read())

            def compose_node(parent, index):
                # the line number where the previous token has ended (plus empty lines)
                line = loader.line
                node = Composer.compose_node(loader, parent, index)
                node.__line__ = line + 1
                return node

            def construct_mapping(node, deep=False):
                mapping = Constructor.construct_mapping(loader, node, deep=deep)
                mapping["__line__"] = node.__line__
                return mapping

            loader.compose_node = compose_node
            loader.construct_mapping = construct_mapping
            d = loader.get_single_data()

            fp.close()
            if d is not None:
                allinput.update(d)
        #            util.update(allinput, d)  # recursive update
        elif ext == ".json":
            raise NotImplementedError("Can not deal with json input for now")
        else:
            # process splicer file on command line, search path is not used
            splicer.get_splicer_based_on_suffix(filename, splicers)

    #    print(allinput)

    def_types = typemap.initialize()

    # Write out native types as YAML if requested
    if config.yaml_types:
        with open(
            os.path.join(config.yaml_dir, config.yaml_types), "w"
        ) as yaml_file:
            yaml.dump(def_types, yaml_file, default_flow_style=False)
        print("Wrote", config.yaml_types)

    newlibrary = ast.create_library_from_dictionary(allinput)

    try:
        generate.generate_functions(newlibrary, config)
    except RuntimeError:
        dump_jsonfile(args.logdir, basename, newlibrary)
        raise

    if "splicer" in allinput:
        # read splicer files defined in input YAML file
        for suffix in sorted(allinput["splicer"].keys()):
            if suffix == "__line__":
                continue
            names = allinput["splicer"][suffix]
            # suffix = 'c', 'f', 'py', 'lua'
            subsplicer = splicers.setdefault(suffix, {})
            for name in names:
                for pth in search_path:
                    fullname = os.path.join(pth, name)
                    #                    log.write("Try splicer %s\n" % fullname)
                    if os.path.isfile(fullname):
                        break
                else:
                    fullname = None
                if not fullname:
                    raise RuntimeError("File not found: %s" % name)
                log.write("Read splicer %s\n" % name)
                splicer.get_splicers(fullname, subsplicer)

    # Add any explicit splicers in the YAML file.
    if "splicer_code" in allinput:
        splicers.update(allinput["splicer_code"])

    # Write out generated types
    TypeOut(newlibrary, config).write_types()

    try:
        options = newlibrary.options
        if options.wrap_c:
            wrapc.Wrapc(newlibrary, config, splicers["c"]).wrap_library()

        if options.wrap_fortran:
            wrapf.Wrapf(newlibrary, config, splicers["f"]).wrap_library()

        if options.wrap_python:
            wrapp.Wrapp(newlibrary, config, splicers["py"]).wrap_library()

        if options.wrap_lua:
            wrapl.Wrapl(newlibrary, config, splicers["lua"]).wrap_library()
    finally:
        # Write a debug dump even if there was an exception.
        dump_jsonfile(args.logdir, basename, newlibrary)

    # Write list of output files.  May be useful for build systems
    if args.cfiles:
        with open(args.cfiles, "w") as fp:
            if config.cfiles:
                fp.write(" ".join(config.cfiles))
            fp.write("\n")
    if args.ffiles:
        with open(args.ffiles, "w") as fp:
            if config.ffiles:
                fp.write(" ".join(config.ffiles))
            fp.write("\n")

    log.close()

    # This helps when running with a pipe, like CMake's execute_process
    # It doesn't fix the error, but it does report a better error message
    # http://www.thecodingforums.com/threads/help-with-a-piping-error.749747/
    sys.stdout.flush()
    return config


if __name__ == "__main__":
    main()
