// pyCstruct_as_classtype.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pystructmodule.hpp"

// splicer begin class.Cstruct_as_class.impl.include
// splicer end class.Cstruct_as_class.impl.include

#ifdef __cplusplus
#define SHROUD_UNUSED(param)
#else
#define SHROUD_UNUSED(param) param
#endif

#if PY_MAJOR_VERSION >= 3
#define PyInt_AsLong PyLong_AsLong
#define PyInt_FromLong PyLong_FromLong
#define PyInt_FromSize_t PyLong_FromSize_t
#define PyString_FromString PyUnicode_FromString
#define PyString_FromStringAndSize PyUnicode_FromStringAndSize
#endif
// splicer begin class.Cstruct_as_class.impl.C_definition
// splicer end class.Cstruct_as_class.impl.C_definition
// splicer begin class.Cstruct_as_class.impl.additional_methods
// splicer end class.Cstruct_as_class.impl.additional_methods
static void
PY_Cstruct_as_class_tp_del (PY_Cstruct_as_class *self)
{
// splicer begin class.Cstruct_as_class.type.del
    PY_SHROUD_release_memory(self->idtor, self->obj);
    self->obj = nullptr;
// splicer end class.Cstruct_as_class.type.del
}

// ----------------------------------------
// Function:  Cstruct_as_class +name(Cstruct_as_class_ctor)
// Attrs:     +intent(ctor)
// Exact:     py_default
// ----------------------------------------
// Argument:  int x1
// Attrs:     +intent(in)
// Requested: py_ctor_native_scalar_numpy
// Match:     py_ctor_native
// ----------------------------------------
// Argument:  int y1
// Attrs:     +intent(in)
// Requested: py_ctor_native_scalar_numpy
// Match:     py_ctor_native
static int
PY_Cstruct_as_class_tp_init(
  PY_Cstruct_as_class *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin class.Cstruct_as_class.method.cstruct_as_class_ctor
    int x1 = 0;
    int y1 = 0;
    const char *SHT_kwlist[] = {
        "x1",
        "y1",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "|ii:Cstruct_as_class_ctor", const_cast<char **>(SHT_kwlist), 
        &x1, &y1))
        return -1;

    self->obj = new Cstruct_as_class;
    if (self->obj == nullptr) {
        PyErr_NoMemory();
        return -1;
    }
    self->idtor = 1;

    // post_call - initialize fields
    Cstruct_as_class *SH_obj = self->obj;
    SH_obj->x1 = x1;
    SH_obj->y1 = y1;

    return 0;
// splicer end class.Cstruct_as_class.method.cstruct_as_class_ctor
}
// splicer begin class.Cstruct_as_class.impl.after_methods
// splicer end class.Cstruct_as_class.impl.after_methods

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static PyObject *PY_Cstruct_as_class_x1_getter(PY_Cstruct_as_class *self,
    void *SHROUD_UNUSED(closure))
{
    PyObject * rv = PyInt_FromLong(self->obj->x1);
    return rv;
}

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static int PY_Cstruct_as_class_x1_setter(PY_Cstruct_as_class *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    int rv = PyInt_AsLong(value);
    if (PyErr_Occurred()) {
        return -1;
    }
    self->obj->x1 = rv;
    return 0;
}

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static PyObject *PY_Cstruct_as_class_y1_getter(PY_Cstruct_as_class *self,
    void *SHROUD_UNUSED(closure))
{
    PyObject * rv = PyInt_FromLong(self->obj->y1);
    return rv;
}

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static int PY_Cstruct_as_class_y1_setter(PY_Cstruct_as_class *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    int rv = PyInt_AsLong(value);
    if (PyErr_Occurred()) {
        return -1;
    }
    self->obj->y1 = rv;
    return 0;
}

static PyGetSetDef PY_Cstruct_as_class_getset[] = {
    {(char *)"x1", (getter)PY_Cstruct_as_class_x1_getter,
        (setter)PY_Cstruct_as_class_x1_setter, nullptr, nullptr},
    {(char *)"y1", (getter)PY_Cstruct_as_class_y1_getter,
        (setter)PY_Cstruct_as_class_y1_setter, nullptr, nullptr},
    // splicer begin class.Cstruct_as_class.PyGetSetDef
    // splicer end class.Cstruct_as_class.PyGetSetDef
    {nullptr}            /* sentinel */
};
static PyMethodDef PY_Cstruct_as_class_methods[] = {
    // splicer begin class.Cstruct_as_class.PyMethodDef
    // splicer end class.Cstruct_as_class.PyMethodDef
    {nullptr,   (PyCFunction)nullptr, 0, nullptr}            /* sentinel */
};

static char Cstruct_as_class__doc__[] =
"virtual class"
;

/* static */
PyTypeObject PY_Cstruct_as_class_Type = {
    PyVarObject_HEAD_INIT(nullptr, 0)
    "cstruct.Cstruct_as_class",                       /* tp_name */
    sizeof(PY_Cstruct_as_class),         /* tp_basicsize */
    0,                              /* tp_itemsize */
    /* Methods to implement standard operations */
    (destructor)nullptr,                 /* tp_dealloc */
    (printfunc)nullptr,                   /* tp_print */
    (getattrfunc)nullptr,                 /* tp_getattr */
    (setattrfunc)nullptr,                 /* tp_setattr */
#if PY_MAJOR_VERSION >= 3
    nullptr,                               /* tp_reserved */
#else
    (cmpfunc)nullptr,                     /* tp_compare */
#endif
    (reprfunc)nullptr,                    /* tp_repr */
    /* Method suites for standard classes */
    nullptr,                              /* tp_as_number */
    nullptr,                              /* tp_as_sequence */
    nullptr,                              /* tp_as_mapping */
    /* More standard operations (here for binary compatibility) */
    (hashfunc)nullptr,                    /* tp_hash */
    (ternaryfunc)nullptr,                 /* tp_call */
    (reprfunc)nullptr,                    /* tp_str */
    (getattrofunc)nullptr,                /* tp_getattro */
    (setattrofunc)nullptr,                /* tp_setattro */
    /* Functions to access object as input/output buffer */
    nullptr,                              /* tp_as_buffer */
    /* Flags to define presence of optional/expanded features */
    Py_TPFLAGS_DEFAULT,             /* tp_flags */
    Cstruct_as_class__doc__,         /* tp_doc */
    /* Assigned meaning in release 2.0 */
    /* call function for all accessible objects */
    (traverseproc)nullptr,                /* tp_traverse */
    /* delete references to contained objects */
    (inquiry)nullptr,                     /* tp_clear */
    /* Assigned meaning in release 2.1 */
    /* rich comparisons */
    (richcmpfunc)nullptr,                 /* tp_richcompare */
    /* weak reference enabler */
    0,                              /* tp_weaklistoffset */
    /* Added in release 2.2 */
    /* Iterators */
    (getiterfunc)nullptr,                 /* tp_iter */
    (iternextfunc)nullptr,                /* tp_iternext */
    /* Attribute descriptor and subclassing stuff */
    PY_Cstruct_as_class_methods,                             /* tp_methods */
    nullptr,                              /* tp_members */
    PY_Cstruct_as_class_getset,                             /* tp_getset */
    nullptr,                              /* tp_base */
    nullptr,                              /* tp_dict */
    (descrgetfunc)nullptr,                /* tp_descr_get */
    (descrsetfunc)nullptr,                /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc)PY_Cstruct_as_class_tp_init,                   /* tp_init */
    (allocfunc)nullptr,                  /* tp_alloc */
    (newfunc)nullptr,                    /* tp_new */
    (freefunc)nullptr,                   /* tp_free */
    (inquiry)nullptr,                     /* tp_is_gc */
    nullptr,                              /* tp_bases */
    nullptr,                              /* tp_mro */
    nullptr,                              /* tp_cache */
    nullptr,                              /* tp_subclasses */
    nullptr,                              /* tp_weaklist */
    (destructor)PY_Cstruct_as_class_tp_del,                 /* tp_del */
    0,                              /* tp_version_tag */
#if PY_MAJOR_VERSION >= 3
    (destructor)nullptr,                  /* tp_finalize */
#endif
};
