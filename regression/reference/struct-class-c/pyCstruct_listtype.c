// pyCstruct_listtype.c
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pystructmodule.h"
#include <stdlib.h>
// splicer begin class.Cstruct_list.impl.include
// splicer end class.Cstruct_list.impl.include

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

// Keep track of the PyObject and pointer to the data it contains.
typedef struct {
    PyObject *obj;
    void *data;   // points into obj.
} SHROUD_converter_value;

// Convert obj into an array of type char *
// Return -1 on error.
static int SHROUD_from_PyObject_char(PyObject *obj, const char *name,
    char * **pin, Py_ssize_t *psize)
{
    PyObject *seq = PySequence_Fast(obj, "holder");
    if (seq == NULL) {
        PyErr_Format(PyExc_TypeError, "argument '%s' must be iterable",
            name);
        return -1;
    }
    Py_ssize_t size = PySequence_Fast_GET_SIZE(seq);
    char * *in = (char * *) malloc(size * sizeof(char *));
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PySequence_Fast_GET_ITEM(seq, i);
        in[i] = PyString_AsString(item);
        if (PyErr_Occurred()) {
            free(in);
            Py_DECREF(seq);
            PyErr_Format(PyExc_ValueError,
                "argument '%s', index %d must be string", name,
                (int) i);
            return -1;
        }
    }
    Py_DECREF(seq);
    *pin = in;
    *psize = size;
    return 0;
}

// Helper - convert PyObject to char * pointer.
static int SHROUD_get_from_object_charptr(PyObject *obj,
    SHROUD_converter_value *value)
{
    char * *in;
    Py_ssize_t size;
    if (SHROUD_from_PyObject_char(obj, "in", &in,  &size) == -1) {
        return 0;
    }
    value->obj = NULL;
    value->data = (char * *) in;
    return 1;
}

// Convert obj into an array of type double
// Return -1 on error.
static int SHROUD_from_PyObject_double(PyObject *obj, const char *name,
    double **pin, Py_ssize_t *psize)
{
    PyObject *seq = PySequence_Fast(obj, "holder");
    if (seq == NULL) {
        PyErr_Format(PyExc_TypeError, "argument '%s' must be iterable",
            name);
        return -1;
    }
    Py_ssize_t size = PySequence_Fast_GET_SIZE(seq);
    double *in = (double *) malloc(size * sizeof(double));
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PySequence_Fast_GET_ITEM(seq, i);
        in[i] = PyFloat_AsDouble(item);
        if (PyErr_Occurred()) {
            free(in);
            Py_DECREF(seq);
            PyErr_Format(PyExc_ValueError,
                "argument '%s', index %d must be double", name,
                (int) i);
            return -1;
        }
    }
    Py_DECREF(seq);
    *pin = in;
    *psize = size;
    return 0;
}

// Helper - convert PyObject to double pointer.
static int SHROUD_get_from_object_double_list(PyObject *obj,
    SHROUD_converter_value *value)
{
    double *in;
    Py_ssize_t size;
    if (SHROUD_from_PyObject_double(obj, "in", &in,  &size) == -1) {
        return 0;
    }
    value->obj = NULL;
    value->data = (double *) in;
    return 1;
}

// Convert obj into an array of type int
// Return -1 on error.
static int SHROUD_from_PyObject_int(PyObject *obj, const char *name,
    int **pin, Py_ssize_t *psize)
{
    PyObject *seq = PySequence_Fast(obj, "holder");
    if (seq == NULL) {
        PyErr_Format(PyExc_TypeError, "argument '%s' must be iterable",
            name);
        return -1;
    }
    Py_ssize_t size = PySequence_Fast_GET_SIZE(seq);
    int *in = (int *) malloc(size * sizeof(int));
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PySequence_Fast_GET_ITEM(seq, i);
        in[i] = PyInt_AsLong(item);
        if (PyErr_Occurred()) {
            free(in);
            Py_DECREF(seq);
            PyErr_Format(PyExc_ValueError,
                "argument '%s', index %d must be int", name, (int) i);
            return -1;
        }
    }
    Py_DECREF(seq);
    *pin = in;
    *psize = size;
    return 0;
}

// Helper - convert PyObject to int pointer.
static int SHROUD_get_from_object_int_list(PyObject *obj,
    SHROUD_converter_value *value)
{
    int *in;
    Py_ssize_t size;
    if (SHROUD_from_PyObject_int(obj, "in", &in,  &size) == -1) {
        return 0;
    }
    value->obj = NULL;
    value->data = (int *) in;
    return 1;
}

static PyObject *SHROUD_to_PyList_char(char * *in, size_t size)
{
    PyObject *out = PyList_New(size);
    for (size_t i = 0; i < size; ++i) {
        PyList_SET_ITEM(out, i, PyString_FromString(in[i]));
    }
    return out;
}

static PyObject *SHROUD_to_PyList_double(double *in, size_t size)
{
    PyObject *out = PyList_New(size);
    for (size_t i = 0; i < size; ++i) {
        PyList_SET_ITEM(out, i, PyFloat_FromDouble(in[i]));
    }
    return out;
}

static PyObject *SHROUD_to_PyList_int(int *in, size_t size)
{
    PyObject *out = PyList_New(size);
    for (size_t i = 0; i < size; ++i) {
        PyList_SET_ITEM(out, i, PyInt_FromLong(in[i]));
    }
    return out;
}
// splicer begin class.Cstruct_list.impl.C_definition
// splicer end class.Cstruct_list.impl.C_definition
// splicer begin class.Cstruct_list.impl.additional_methods
// splicer end class.Cstruct_list.impl.additional_methods
static void
PY_Cstruct_list_tp_del (PY_Cstruct_list *self)
{
// splicer begin class.Cstruct_list.type.del
    PY_SHROUD_release_memory(self->idtor, self->obj);
    self->obj = NULL;
    // Python objects for members.
    Py_XDECREF(self->ivalue_obj);
    Py_XDECREF(self->dvalue_obj);
    Py_XDECREF(self->svalue_obj);
// splicer end class.Cstruct_list.type.del
}

static int
PY_Cstruct_list_tp_init(
  PY_Cstruct_list *self,
  PyObject *args,
  PyObject *kwds)
{
// Cstruct_list(int nitems +intent(in)+optional(0), int * ivalue +dimension(nitems)+intent(in)+optional(0), double * dvalue +dimension(nitems)+intent(in)+optional(0), char * * svalue +dimension(nitems)+intent(in)+optional(0)) +name(Cstruct_list_ctor)
// splicer begin class.Cstruct_list.method.cstruct_list_ctor
    int nitems;
    SHROUD_converter_value SHPy_ivalue;
    SHROUD_converter_value SHPy_dvalue;
    SHROUD_converter_value SHPy_svalue;
    char *SHT_kwlist[] = {
        "nitems",
        "ivalue",
        "dvalue",
        "svalue",
        NULL };

    nitems = 0;
    SHPy_ivalue.obj = NULL;
    SHPy_ivalue.data = NULL;
    SHPy_dvalue.obj = NULL;
    SHPy_dvalue.data = NULL;
    SHPy_svalue.obj = NULL;
    SHPy_svalue.data = NULL;
    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "|iO&O&O&:Cstruct_list_ctor", SHT_kwlist, &nitems,
        SHROUD_get_from_object_int_list, &SHPy_ivalue,
        SHROUD_get_from_object_double_list, &SHPy_dvalue,
        SHROUD_get_from_object_charptr, &SHPy_svalue))
        return -1;

    self->obj = malloc(sizeof(Cstruct_list));
    if (self->obj == NULL) {
        PyErr_NoMemory();
        return -1;
    }
    self->idtor = 3;
    // initialize fields
    Cstruct_list *SH_obj = self->obj;
    SH_obj->nitems = nitems;
    SH_obj->ivalue = (int *) SHPy_ivalue.data;
    SH_obj->dvalue = (double *) SHPy_dvalue.data;
    SH_obj->svalue = (char * *) SHPy_svalue.data;
    self->ivalue_obj = SHPy_ivalue.obj;  // steal reference
    self->dvalue_obj = SHPy_dvalue.obj;  // steal reference
    self->svalue_obj = SHPy_svalue.obj;  // steal reference
    return 0;
// splicer end class.Cstruct_list.method.cstruct_list_ctor
}
// splicer begin class.Cstruct_list.impl.after_methods
// splicer end class.Cstruct_list.impl.after_methods

static PyObject *PY_Cstruct_list_nitems_getter(PY_Cstruct_list *self,
    void *SHROUD_UNUSED(closure))
{
    PyObject * rv = PyInt_FromLong(self->obj->nitems);
    return rv;
}

static int PY_Cstruct_list_nitems_setter(PY_Cstruct_list *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    int rv = PyInt_AsLong(value);
    if (PyErr_Occurred()) {
        return -1;
    }
    self->obj->nitems = rv;
    return 0;
}

static PyObject *PY_Cstruct_list_ivalue_getter(PY_Cstruct_list *self,
    void *SHROUD_UNUSED(closure))
{
    if (self->obj->ivalue == NULL) {
        Py_RETURN_NONE;
    }
    if (self->ivalue_obj != NULL) {
        Py_INCREF(self->ivalue_obj);
        return self->ivalue_obj;
    }
    PyObject *rv = SHROUD_to_PyList_int(self->obj->ivalue, self->obj->nitems);
    return rv;
}

static int PY_Cstruct_list_ivalue_setter(PY_Cstruct_list *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    SHROUD_converter_value cvalue;
    Py_XDECREF(self->ivalue_obj);
    if (SHROUD_get_from_object_int_list(value, &cvalue) == 0) {
        self->obj->ivalue = NULL;
        self->ivalue_obj = NULL;
        // XXXX set error
        return -1;
    }
    self->obj->ivalue = (int *) cvalue.data;
    self->ivalue_obj = cvalue.obj;  // steal reference
    return 0;
}

static PyObject *PY_Cstruct_list_dvalue_getter(PY_Cstruct_list *self,
    void *SHROUD_UNUSED(closure))
{
    if (self->obj->dvalue == NULL) {
        Py_RETURN_NONE;
    }
    if (self->dvalue_obj != NULL) {
        Py_INCREF(self->dvalue_obj);
        return self->dvalue_obj;
    }
    PyObject *rv = SHROUD_to_PyList_double(self->obj->dvalue, self->obj->nitems);
    return rv;
}

static int PY_Cstruct_list_dvalue_setter(PY_Cstruct_list *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    SHROUD_converter_value cvalue;
    Py_XDECREF(self->dvalue_obj);
    if (SHROUD_get_from_object_double_list(value, &cvalue) == 0) {
        self->obj->dvalue = NULL;
        self->dvalue_obj = NULL;
        // XXXX set error
        return -1;
    }
    self->obj->dvalue = (double *) cvalue.data;
    self->dvalue_obj = cvalue.obj;  // steal reference
    return 0;
}

static PyObject *PY_Cstruct_list_svalue_getter(PY_Cstruct_list *self,
    void *SHROUD_UNUSED(closure))
{
    if (self->obj->svalue == NULL) {
        Py_RETURN_NONE;
    }
    if (self->svalue_obj != NULL) {
        Py_INCREF(self->svalue_obj);
        return self->svalue_obj;
    }
    PyObject *rv = SHROUD_to_PyList_char(self->obj->svalue, self->obj->nitems);
    return rv;
}

static int PY_Cstruct_list_svalue_setter(PY_Cstruct_list *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    SHROUD_converter_value cvalue;
    Py_XDECREF(self->svalue_obj);
    if (SHROUD_get_from_object_charptr(value, &cvalue) == 0) {
        self->obj->svalue = NULL;
        self->svalue_obj = NULL;
        // XXXX set error
        return -1;
    }
    self->obj->svalue = (char * *) cvalue.data;
    self->svalue_obj = cvalue.obj;  // steal reference
    return 0;
}

static PyGetSetDef PY_Cstruct_list_getset[] = {
    {(char *)"nitems", (getter)PY_Cstruct_list_nitems_getter,
        (setter)PY_Cstruct_list_nitems_setter, NULL, NULL},
    {(char *)"ivalue", (getter)PY_Cstruct_list_ivalue_getter,
        (setter)PY_Cstruct_list_ivalue_setter, NULL, NULL},
    {(char *)"dvalue", (getter)PY_Cstruct_list_dvalue_getter,
        (setter)PY_Cstruct_list_dvalue_setter, NULL, NULL},
    {(char *)"svalue", (getter)PY_Cstruct_list_svalue_getter,
        (setter)PY_Cstruct_list_svalue_setter, NULL, NULL},
    // splicer begin class.Cstruct_list.PyGetSetDef
    // splicer end class.Cstruct_list.PyGetSetDef
    {NULL}            /* sentinel */
};
static PyMethodDef PY_Cstruct_list_methods[] = {
    // splicer begin class.Cstruct_list.PyMethodDef
    // splicer end class.Cstruct_list.PyMethodDef
    {NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

static char Cstruct_list__doc__[] =
"virtual class"
;

/* static */
PyTypeObject PY_Cstruct_list_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "cstruct.Cstruct_list",                       /* tp_name */
    sizeof(PY_Cstruct_list),         /* tp_basicsize */
    0,                              /* tp_itemsize */
    /* Methods to implement standard operations */
    (destructor)NULL,                 /* tp_dealloc */
    (printfunc)NULL,                   /* tp_print */
    (getattrfunc)NULL,                 /* tp_getattr */
    (setattrfunc)NULL,                 /* tp_setattr */
#if PY_MAJOR_VERSION >= 3
    NULL,                               /* tp_reserved */
#else
    (cmpfunc)NULL,                     /* tp_compare */
#endif
    (reprfunc)NULL,                    /* tp_repr */
    /* Method suites for standard classes */
    NULL,                              /* tp_as_number */
    NULL,                              /* tp_as_sequence */
    NULL,                              /* tp_as_mapping */
    /* More standard operations (here for binary compatibility) */
    (hashfunc)NULL,                    /* tp_hash */
    (ternaryfunc)NULL,                 /* tp_call */
    (reprfunc)NULL,                    /* tp_str */
    (getattrofunc)NULL,                /* tp_getattro */
    (setattrofunc)NULL,                /* tp_setattro */
    /* Functions to access object as input/output buffer */
    NULL,                              /* tp_as_buffer */
    /* Flags to define presence of optional/expanded features */
    Py_TPFLAGS_DEFAULT,             /* tp_flags */
    Cstruct_list__doc__,         /* tp_doc */
    /* Assigned meaning in release 2.0 */
    /* call function for all accessible objects */
    (traverseproc)NULL,                /* tp_traverse */
    /* delete references to contained objects */
    (inquiry)NULL,                     /* tp_clear */
    /* Assigned meaning in release 2.1 */
    /* rich comparisons */
    (richcmpfunc)NULL,                 /* tp_richcompare */
    /* weak reference enabler */
    0,                              /* tp_weaklistoffset */
    /* Added in release 2.2 */
    /* Iterators */
    (getiterfunc)NULL,                 /* tp_iter */
    (iternextfunc)NULL,                /* tp_iternext */
    /* Attribute descriptor and subclassing stuff */
    PY_Cstruct_list_methods,                             /* tp_methods */
    NULL,                              /* tp_members */
    PY_Cstruct_list_getset,                             /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,                /* tp_descr_get */
    (descrsetfunc)NULL,                /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc)PY_Cstruct_list_tp_init,                   /* tp_init */
    (allocfunc)NULL,                  /* tp_alloc */
    (newfunc)NULL,                    /* tp_new */
    (freefunc)NULL,                   /* tp_free */
    (inquiry)NULL,                     /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor)PY_Cstruct_list_tp_del,                 /* tp_del */
    0,                              /* tp_version_tag */
#if PY_MAJOR_VERSION >= 3
    (destructor)NULL,                  /* tp_finalize */
#endif
};
