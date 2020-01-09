# Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
# other Shroud Project Developers.
# See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (BSD-3-Clause)

from __future__ import print_function

from shroud import ast
from shroud import util
from shroud import wrapp

import unittest


class CheckImplied(unittest.TestCase):
    def setUp(self):
        # Create a dictionary of parsed arguments
        self.library = ast.LibraryNode()
        node = self.library.add_function(
            "void func1("
            "int *array  +intent(in)+dimension(:),"
            "int  scalar +intent(in)+implied(size(array))"
            ")"
        )

        node._fmtargs = dict(
            array=dict(fmtpy=util.Scope(None, py_var="SHPy_array")),
            scalar=dict(fmtpy=util.Scope(None, py_var="SHPy_scalar")),
        )
        self.func1 = node

    def test_implied1(self):
        self.assertEqual(
            "PyArray_SIZE(SHPy_array)",
            wrapp.py_implied("size(array)", self.func1),
        )
        self.assertEqual(
            "PyArray_SIZE(SHPy_array)+2",
            wrapp.py_implied("size(array) + 2", self.func1),
        )

    def test_expr1(self):
        self.assertEqual("size+n", wrapp.py_implied("size+n", self.func1))


if __name__ == "__main__":
    unittest.main()
