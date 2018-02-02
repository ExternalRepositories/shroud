// pyExClass1type.cpp
// This is generated code, do not edit
// Copyright (c) 2017, Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-738041.
// All rights reserved.
//
// This file is part of Shroud.  For details, see
// https://github.com/LLNL/shroud. Please also read shroud/LICENSE.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the disclaimer below.
//
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the disclaimer (as noted below)
//   in the documentation and/or other materials provided with the
//   distribution.
//
// * Neither the name of the LLNS/LLNL nor the names of its contributors
//   may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE
// LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// #######################################################################
#include "pyUserLibrarymodule.hpp"
// splicer begin class.ExClass1.impl.include
// splicer end class.ExClass1.impl.include

namespace example {
namespace nested {
// splicer begin class.ExClass1.impl.C_definition
// splicer end class.ExClass1.impl.C_definition
// splicer begin class.ExClass1.impl.additional_methods
// splicer end class.ExClass1.impl.additional_methods
static PyObject *
PP_ExClass1_tp_repr (PP_ExClass1 *self)
{
// splicer begin class.ExClass1.type.repr
    repr code
// splicer end class.ExClass1.type.repr
}
static int
PP_ExClass1_tp_init (PP_ExClass1 *self, PyObject *args, PyObject *kwds)
{
// splicer begin class.ExClass1.type.init
    init code
// splicer end class.ExClass1.type.init
}
static PyObject *
PP_ExClass1_tp_richcompare (PP_ExClass1 *self, PyObject *other, int opid)
{
// splicer begin class.ExClass1.type.richcompare
Py_INCREF(Py_NotImplemented);
return Py_NotImplemented;
// splicer end class.ExClass1.type.richcompare
}

static char PP_exclass1_dtor__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_dtor(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// ~ExClass1()
// splicer begin class.ExClass1.method.dtor
    delete self->obj;
    self->obj = NULL;
    Py_RETURN_NONE;
// splicer end class.ExClass1.method.dtor
}

static char PP_exclass1_increment_count__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_increment_count(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// int incrementCount(int incr +intent(in)+value)
// splicer begin class.ExClass1.method.increment_count
    int incr;
    const char *SH_kwcpp = "incr";
    char *SH_kw_list[] = {
        (char *) SH_kwcpp+0,
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:incrementCount",
        SH_kw_list,
        &incr))
    {
        return NULL;
    }
    int rv = self->obj->incrementCount(incr);
    PyObject * SH_Py_rv = PyInt_FromLong(rv);
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.increment_count
}

static char PP_exclass1_get_name__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_get_name(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// const string & getName +len(aa_exclass1_get_name_length({F_this}%{F_derived_member}))() const
// splicer begin class.ExClass1.method.get_name
    const std::string & rv = self->obj->getName();
    if (! isNameValid(rv)) {
        PyErr_SetString(PyExc_KeyError, "XXX need value of name");
        return NULL;
    }

    PyObject * SH_Py_rv = PyString_FromString(rv.c_str());
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.get_name
}

static char PP_exclass1_get_name_length__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_get_name_length(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// int GetNameLength() const
// splicer begin class.ExClass1.method.get_name_length
    int rv = self->obj->GetNameLength();
    PyObject * SH_Py_rv = PyInt_FromLong(rv);
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.get_name_length
}

static char PP_exclass1_get_name_error_check__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_get_name_error_check(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// const string & getNameErrorCheck() const
// splicer begin class.ExClass1.method.get_name_error_check
    const std::string & rv = self->obj->getNameErrorCheck();
    PyObject * SH_Py_rv = PyString_FromString(rv.c_str());
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.get_name_error_check
}

static char PP_exclass1_get_name_arg__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_get_name_arg(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// const string & getNameArg() const
// splicer begin class.ExClass1.method.get_name_arg
    const std::string & rv = self->obj->getNameArg();
    PyObject * SH_Py_rv = PyString_FromString(rv.c_str());
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.get_name_arg
}

static char PP_exclass1_get_root__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_get_root(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// ExClass2 * getRoot()
// splicer begin class.ExClass1.method.get_root
    ExClass2 * rv = self->obj->getRoot();
    PP_ExClass2 * SH_Py_rv = PyObject_New(PP_ExClass2, &PP_ExClass2_Type);
    SH_Py_rv->obj = rv;
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.get_root
}

static PyObject *
PP_exclass1_get_value_from_int(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// int getValue(int value +intent(in)+value)
// splicer begin class.ExClass1.method.get_value_from_int
    int value;
    const char *SH_kwcpp = "value";
    char *SH_kw_list[] = {
        (char *) SH_kwcpp+0,
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:getValue",
        SH_kw_list,
        &value))
    {
        return NULL;
    }
    int rv = self->obj->getValue(value);
    PyObject * SH_Py_rv = PyInt_FromLong(rv);
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.get_value_from_int
}

static PyObject *
PP_exclass1_get_value_1(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// long getValue(long value +intent(in)+value)
// splicer begin class.ExClass1.method.get_value_1
    long value;
    const char *SH_kwcpp = "value";
    char *SH_kw_list[] = {
        (char *) SH_kwcpp+0,
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "l:getValue",
        SH_kw_list,
        &value))
    {
        return NULL;
    }
    long rv = self->obj->getValue(value);
    PyObject * SH_Py_rv = PyInt_FromLong(rv);
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.get_value_1
}

static char PP_exclass1_get_addr__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_get_addr(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void * getAddr()
// splicer begin class.ExClass1.method.get_addr
    void * rv = self->obj->getAddr();
    PyObject * SH_Py_rv = PyCapsule_New(rv, NULL, NULL);
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.get_addr
}

static char PP_exclass1_has_addr__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_has_addr(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// bool hasAddr(bool in +intent(in)+value)
// splicer begin class.ExClass1.method.has_addr
    PyObject * SH_Py_in;
    const char *SH_kwcpp = "in";
    char *SH_kw_list[] = {
        (char *) SH_kwcpp+0,
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!:hasAddr",
        SH_kw_list,
        &PyBool_Type, &SH_Py_in))
    {
        return NULL;
    }
    bool in = PyObject_IsTrue(SH_Py_in);
    bool rv = self->obj->hasAddr(in);
    PyObject * SH_Py_rv = PyBool_FromLong(rv);
    return (PyObject *) SH_Py_rv;
// splicer end class.ExClass1.method.has_addr
}

static char PP_exclass1_splicer_special__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_splicer_special(
  PP_ExClass1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void SplicerSpecial()
// splicer begin class.ExClass1.method.splicer_special
    self->obj->SplicerSpecial();
    Py_RETURN_NONE;
// splicer end class.ExClass1.method.splicer_special
}

static char PP_exclass1_get_value__doc__[] =
"documentation"
;

static PyObject *
PP_exclass1_get_value(
  PP_ExClass1 *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin class.ExClass1.method.get_value
    Py_ssize_t SH_nargs = 0;
    if (args != NULL) SH_nargs += PyTuple_Size(args);
    if (kwds != NULL) SH_nargs += PyDict_Size(args);
    PyObject *rvobj;
    if (SH_nargs == 1) {
        rvobj = PP_exclass1_get_value_from_int(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    if (SH_nargs == 1) {
        rvobj = PP_exclass1_get_value_1(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    PyErr_SetString(PyExc_TypeError, "wrong arguments multi-dispatch");
    return NULL;
// splicer end class.ExClass1.method.get_value
}
// splicer begin class.ExClass1.impl.after_methods
// splicer end class.ExClass1.impl.after_methods
static PyMethodDef PP_ExClass1_methods[] = {
{"dtor", (PyCFunction)PP_exclass1_dtor, METH_NOARGS,
    PP_exclass1_dtor__doc__},
{"incrementCount", (PyCFunction)PP_exclass1_increment_count,
    METH_VARARGS|METH_KEYWORDS, PP_exclass1_increment_count__doc__},
{"getName", (PyCFunction)PP_exclass1_get_name, METH_NOARGS,
    PP_exclass1_get_name__doc__},
{"GetNameLength", (PyCFunction)PP_exclass1_get_name_length, METH_NOARGS,
    PP_exclass1_get_name_length__doc__},
{"getNameErrorCheck", (PyCFunction)PP_exclass1_get_name_error_check,
    METH_NOARGS, PP_exclass1_get_name_error_check__doc__},
{"getNameArg", (PyCFunction)PP_exclass1_get_name_arg, METH_NOARGS,
    PP_exclass1_get_name_arg__doc__},
{"getRoot", (PyCFunction)PP_exclass1_get_root, METH_NOARGS,
    PP_exclass1_get_root__doc__},
{"getAddr", (PyCFunction)PP_exclass1_get_addr, METH_NOARGS,
    PP_exclass1_get_addr__doc__},
{"hasAddr", (PyCFunction)PP_exclass1_has_addr,
    METH_VARARGS|METH_KEYWORDS, PP_exclass1_has_addr__doc__},
{"SplicerSpecial", (PyCFunction)PP_exclass1_splicer_special,
    METH_NOARGS, PP_exclass1_splicer_special__doc__},
{"getValue", (PyCFunction)PP_exclass1_get_value,
    METH_VARARGS|METH_KEYWORDS, PP_exclass1_get_value__doc__},
// splicer begin class.ExClass1.PyMethodDef
// splicer end class.ExClass1.PyMethodDef
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

static char ExClass1__doc__[] =
"virtual class"
;

/* static */
PyTypeObject PP_ExClass1_Type = {
        PyVarObject_HEAD_INIT(NULL, 0)
        "userlibrary.ExClass1",                       /* tp_name */
        sizeof(PP_ExClass1),         /* tp_basicsize */
        0,                              /* tp_itemsize */
        /* Methods to implement standard operations */
        (destructor)0,                 /* tp_dealloc */
        (printfunc)0,                   /* tp_print */
        (getattrfunc)0,                 /* tp_getattr */
        (setattrfunc)0,                 /* tp_setattr */
#ifdef IS_PY3K
        0,                               /* tp_reserved */
#else
        (cmpfunc)0,                     /* tp_compare */
#endif
        (reprfunc)PP_ExClass1_tp_repr,                    /* tp_repr */
        /* Method suites for standard classes */
        0,                              /* tp_as_number */
        0,                              /* tp_as_sequence */
        0,                              /* tp_as_mapping */
        /* More standard operations (here for binary compatibility) */
        (hashfunc)0,                    /* tp_hash */
        (ternaryfunc)0,                 /* tp_call */
        (reprfunc)0,                    /* tp_str */
        (getattrofunc)0,                /* tp_getattro */
        (setattrofunc)0,                /* tp_setattro */
        /* Functions to access object as input/output buffer */
        0,                              /* tp_as_buffer */
        /* Flags to define presence of optional/expanded features */
        Py_TPFLAGS_DEFAULT,             /* tp_flags */
        ExClass1__doc__,         /* tp_doc */
        /* Assigned meaning in release 2.0 */
        /* call function for all accessible objects */
        (traverseproc)0,                /* tp_traverse */
        /* delete references to contained objects */
        (inquiry)0,                     /* tp_clear */
        /* Assigned meaning in release 2.1 */
        /* rich comparisons */
        (richcmpfunc)PP_ExClass1_tp_richcompare,                 /* tp_richcompare */
        /* weak reference enabler */
        0,                              /* tp_weaklistoffset */
        /* Added in release 2.2 */
        /* Iterators */
        (getiterfunc)0,                 /* tp_iter */
        (iternextfunc)0,                /* tp_iternext */
        /* Attribute descriptor and subclassing stuff */
        PP_ExClass1_methods,                             /* tp_methods */
        0,                              /* tp_members */
        0,                             /* tp_getset */
        0,                              /* tp_base */
        0,                              /* tp_dict */
        (descrgetfunc)0,                /* tp_descr_get */
        (descrsetfunc)0,                /* tp_descr_set */
        0,                              /* tp_dictoffset */
        (initproc)PP_ExClass1_tp_init,                   /* tp_init */
        (allocfunc)0,                  /* tp_alloc */
        (newfunc)0,                    /* tp_new */
        (freefunc)0,                   /* tp_free */
        (inquiry)0,                     /* tp_is_gc */
        0,                              /* tp_bases */
        0,                              /* tp_mro */
        0,                              /* tp_cache */
        0,                              /* tp_subclasses */
        0,                              /* tp_weaklist */
        (destructor)0,                 /* tp_del */
        0,                              /* tp_version_tag */
#ifdef IS_PY3K
        (destructor)0,                  /* tp_finalize */
#endif
};

}  // namespace nested
}  // namespace example
