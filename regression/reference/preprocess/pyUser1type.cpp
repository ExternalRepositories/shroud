// pyUser1type.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pypreprocessmodule.hpp"
#include "preprocess.hpp"
// splicer begin class.User1.impl.include
// splicer end class.User1.impl.include

#ifdef __cplusplus
#define SHROUD_UNUSED(param)
#else
#define SHROUD_UNUSED(param) param
#endif

#if PY_MAJOR_VERSION >= 3
#define PyInt_AsLong PyLong_AsLong
#define PyInt_FromLong PyLong_FromLong
#define PyString_FromString PyUnicode_FromString
#define PyString_FromStringAndSize PyUnicode_FromStringAndSize
#endif
// splicer begin class.User1.impl.C_definition
// splicer end class.User1.impl.C_definition
// splicer begin class.User1.impl.additional_methods
// splicer end class.User1.impl.additional_methods
static void
PY_User1_tp_del (PY_User1 *self)
{
// splicer begin class.User1.type.del
    PY_SHROUD_release_memory(self->idtor, self->obj);
    self->obj = NULL;
// splicer end class.User1.type.del
}

static char PY_method1__doc__[] =
"documentation"
;

static PyObject *
PY_method1(
  PY_User1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void method1()
// splicer begin class.User1.method.method1
    self->obj->method1();
    Py_RETURN_NONE;
// splicer end class.User1.method.method1
}

#if defined(USE_TWO)
static char PY_method2__doc__[] =
"documentation"
;

static PyObject *
PY_method2(
  PY_User1 *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void method2()
// splicer begin class.User1.method.method2
    self->obj->method2();
    Py_RETURN_NONE;
// splicer end class.User1.method.method2
}
#endif // if defined(USE_TWO)

#if defined(USE_THREE)
static char PY_method3def_1__doc__[] =
"documentation"
;

static PyObject *
PY_method3def_1(
  PY_User1 *self,
  PyObject *args,
  PyObject *kwds)
{
// void method3def(int i=0 +intent(in)+value)
// splicer begin class.User1.method.method3def
    Py_ssize_t SH_nargs = 0;
    int i;
    const char *SHT_kwlist[] = {
        "i",
        NULL };

    if (args != NULL) SH_nargs += PyTuple_Size(args);
    if (kwds != NULL) SH_nargs += PyDict_Size(args);
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|i:method3def",
        const_cast<char **>(SHT_kwlist), &i))
        return NULL;
    switch (SH_nargs) {
    case 0:
        self->obj->method3def();
        break;
    case 1:
        self->obj->method3def(i);
        break;
    default:
        PyErr_SetString(PyExc_ValueError, "Wrong number of arguments");
        return NULL;
    }
    Py_RETURN_NONE;
// splicer end class.User1.method.method3def
}
#endif // if defined(USE_THREE)
// splicer begin class.User1.impl.after_methods
// splicer end class.User1.impl.after_methods
static PyMethodDef PY_User1_methods[] = {
    {"method1", (PyCFunction)PY_method1, METH_NOARGS,
        PY_method1__doc__},
#if defined(USE_TWO)
    {"method2", (PyCFunction)PY_method2, METH_NOARGS,
        PY_method2__doc__},
#endif // if defined(USE_TWO)
#if defined(USE_THREE)
    {"method3def", (PyCFunction)PY_method3def_1,
        METH_VARARGS|METH_KEYWORDS, PY_method3def_1__doc__},
#endif // if defined(USE_THREE)
    // splicer begin class.User1.PyMethodDef
    // splicer end class.User1.PyMethodDef
    {NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

static char User1__doc__[] =
"virtual class"
;

/* static */
PyTypeObject PY_User1_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "preprocess.User1",                       /* tp_name */
    sizeof(PY_User1),         /* tp_basicsize */
    0,                              /* tp_itemsize */
    /* Methods to implement standard operations */
    (destructor)0,                 /* tp_dealloc */
    (printfunc)0,                   /* tp_print */
    (getattrfunc)0,                 /* tp_getattr */
    (setattrfunc)0,                 /* tp_setattr */
#if PY_MAJOR_VERSION >= 3
    0,                               /* tp_reserved */
#else
    (cmpfunc)0,                     /* tp_compare */
#endif
    (reprfunc)0,                    /* tp_repr */
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
    User1__doc__,         /* tp_doc */
    /* Assigned meaning in release 2.0 */
    /* call function for all accessible objects */
    (traverseproc)0,                /* tp_traverse */
    /* delete references to contained objects */
    (inquiry)0,                     /* tp_clear */
    /* Assigned meaning in release 2.1 */
    /* rich comparisons */
    (richcmpfunc)0,                 /* tp_richcompare */
    /* weak reference enabler */
    0,                              /* tp_weaklistoffset */
    /* Added in release 2.2 */
    /* Iterators */
    (getiterfunc)0,                 /* tp_iter */
    (iternextfunc)0,                /* tp_iternext */
    /* Attribute descriptor and subclassing stuff */
    PY_User1_methods,                             /* tp_methods */
    0,                              /* tp_members */
    0,                             /* tp_getset */
    0,                              /* tp_base */
    0,                              /* tp_dict */
    (descrgetfunc)0,                /* tp_descr_get */
    (descrsetfunc)0,                /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc)0,                   /* tp_init */
    (allocfunc)0,                  /* tp_alloc */
    (newfunc)0,                    /* tp_new */
    (freefunc)0,                   /* tp_free */
    (inquiry)0,                     /* tp_is_gc */
    0,                              /* tp_bases */
    0,                              /* tp_mro */
    0,                              /* tp_cache */
    0,                              /* tp_subclasses */
    0,                              /* tp_weaklist */
    (destructor)PY_User1_tp_del,                 /* tp_del */
    0,                              /* tp_version_tag */
#if PY_MAJOR_VERSION >= 3
    (destructor)0,                  /* tp_finalize */
#endif
};
