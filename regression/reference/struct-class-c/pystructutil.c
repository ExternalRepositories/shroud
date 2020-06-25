// pystructutil.c
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pystructmodule.h"
#define NO_IMPORT_ARRAY
#define PY_ARRAY_UNIQUE_SYMBOL SHROUD_STRUCT_ARRAY_API
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"
#include <stdlib.h>
#include <string.h>

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

// helper get_from_object_char
// Converter from PyObject to char *.
// The returned status will be 1 for a successful conversion
// and 0 if the conversion has failed.
// value.obj is unused.
// value.dataobj - object which holds the data.
// If same as obj argument, its refcount is incremented.
// value.data is owned by value.dataobj and must be copied to be preserved.
// Caller must use Py_XDECREF(value.dataobj).
int STR_SHROUD_get_from_object_char(PyObject *obj,
    STR_SHROUD_converter_value *value)
{
    size_t size = 0;
    char *out;
    if (PyUnicode_Check(obj)) {
#if PY_MAJOR_VERSION >= 3
        PyObject *strobj = PyUnicode_AsUTF8String(obj);
        out = PyBytes_AS_STRING(strobj);
        size = PyBytes_GET_SIZE(strobj);
        value->dataobj = strobj;  // steal reference
#else
        PyObject *strobj = PyUnicode_AsUTF8String(obj);
        out = PyString_AsString(strobj);
        size = PyString_Size(obj);
        value->dataobj = strobj;  // steal reference
#endif
#if PY_MAJOR_VERSION >= 3
    } else if (PyByteArray_Check(obj)) {
        out = PyBytes_AS_STRING(obj);
        size = PyBytes_GET_SIZE(obj);
        value->dataobj = obj;
        Py_INCREF(obj);
#else
    } else if (PyString_Check(obj)) {
        out = PyString_AsString(obj);
        size = PyString_Size(obj);
        value->dataobj = obj;
        Py_INCREF(obj);
#endif
    } else if (obj == Py_None) {
        out = NULL;
        size = 0;
        value->dataobj = NULL;
    } else {
        PyErr_Format(PyExc_TypeError,
            "argument should be string or None, not %.200s",
            Py_TYPE(obj)->tp_name);
        return 0;
    }
    value->obj = NULL;
    value->data = out;
    value->size = size;
    return 1;
}


// helper fill_from_PyObject_char
// Fill existing char array from PyObject.
// Return 0 on success, -1 on error.
int STR_SHROUD_fill_from_PyObject_char(PyObject *obj, const char *name,
    char *in, Py_ssize_t insize)
{
    STR_SHROUD_converter_value value;
    int i = STR_SHROUD_get_from_object_char(obj, &value);
    if (i == 0) {
        Py_DECREF(obj);
        return -1;
    }
    if (value.data == NULL) {
        in[0] = '\0';
    } else {
        strncpy(in, (char *) value.data, insize);
        Py_DECREF(value.dataobj);
    }
    return 0;
}

// helper fill_from_PyObject_int_numpy
// Fill int array from Python object using NumPy.
// If obj is a scalar, broadcast to array.
// Return 0 on success, -1 on error.
int STR_SHROUD_fill_from_PyObject_int_numpy(PyObject *obj,
    const char *name, int *in, Py_ssize_t insize)
{
    int value = PyInt_AsLong(obj);
    if (!PyErr_Occurred()) {
        // Broadcast scalar.
        for (Py_ssize_t i = 0; i < insize; ++i) {
            in[i] = value;
        }
        return 0;
    }
    PyErr_Clear();

    PyObject *array = PyArray_FROM_OTF(obj, NPY_INT,
        NPY_ARRAY_IN_ARRAY);
    if (array == NULL) {
        PyErr_Format(PyExc_TypeError,
            "argument '%s' must be a 1-D array of int", name);
        return -1;
    }
    PyArrayObject *pyarray = (PyArrayObject *) array;

    int *data = (int *) PyArray_DATA(pyarray);
    npy_intp size = PyArray_SIZE(pyarray);
    if (size > insize) {
        size = insize;
    }
    for (Py_ssize_t i = 0; i < size; ++i) {
        in[i] = data[i];
    }
    Py_DECREF(pyarray);
    return 0;
}


static void FREE_get_from_object_charptr(PyObject *obj)
{
    void *addr = PyCapsule_GetPointer(obj, NULL);
    // XXX - Loop over array and delete each element.
    free(addr);
}

// helper get_from_object_charptr
// Convert obj into an array of char * (i.e. char **).
int STR_SHROUD_get_from_object_charptr(PyObject *obj,
    STR_SHROUD_converter_value *value)
{
    PyObject *seq = PySequence_Fast(obj, "holder");
    if (seq == NULL) {
        PyErr_Format(PyExc_TypeError, "argument '%s' must be iterable",
            value->name);
        return -1;
    }
    Py_ssize_t size = PySequence_Fast_GET_SIZE(seq);
    char **in = (char **) calloc(size, sizeof(char *));
    PyObject *dataobj = PyCapsule_New(in, NULL, FREE_get_from_object_charptr);
    // int PyCapsule_SetContext(datavalue, void * context);
    STR_SHROUD_converter_value itemvalue = {NULL, NULL, NULL, NULL, 0};
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PySequence_Fast_GET_ITEM(seq, i);
        int ierr = STR_SHROUD_get_from_object_char(item, &itemvalue);
        if (ierr == 0) {
            Py_XDECREF(itemvalue.dataobj);
            Py_DECREF(dataobj);
            Py_DECREF(seq);
            PyErr_Format(PyExc_TypeError,
                "argument '%s', index %d must be string", value->name,
                (int) i);
            return 0;
        }
        if (itemvalue.data != NULL) {
            in[i] = strdup((char *) itemvalue.data);
        }
        Py_XDECREF(itemvalue.dataobj);
    }
    Py_DECREF(seq);

    value->obj = NULL;
    value->dataobj = dataobj;
    value->data = in;
    value->size = size;
    return 1;
}

// helper create_from_PyObject_double
// Convert obj into an array of type double
// Return -1 on error.
int STR_SHROUD_create_from_PyObject_double(PyObject *obj,
    const char *name, double **pin, Py_ssize_t *psize)
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
            PyErr_Format(PyExc_TypeError,
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

// helper get_from_object_double_list
// Convert PyObject to double pointer.
int STR_SHROUD_get_from_object_double_list(PyObject *obj,
    STR_SHROUD_converter_value *value)
{
    double *in;
    Py_ssize_t size;
    if (STR_SHROUD_create_from_PyObject_double(obj, "in", &in, 
        &size) == -1) {
        return 0;
    }
    value->obj = NULL;
    value->dataobj = NULL;
    value->data = (double *) in;
    value->size = size;
    return 1;
}

// helper get_from_object_double_numpy
// Convert PyObject to double pointer.
int STR_SHROUD_get_from_object_double_numpy(PyObject *obj,
    STR_SHROUD_converter_value *value)
{
    PyObject *array = PyArray_FROM_OTF(obj, NPY_DOUBLE,
        NPY_ARRAY_IN_ARRAY);
    if (array == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "must be a 1-D array of double");
        return 0;
    }
    value->obj = array;
    value->dataobj = NULL;
    value->data = PyArray_DATA((PyArrayObject *) array);
    value->size = PyArray_SIZE((PyArrayObject *) array);
    return 1;
}

// helper create_from_PyObject_int
// Convert obj into an array of type int
// Return -1 on error.
int STR_SHROUD_create_from_PyObject_int(PyObject *obj, const char *name,
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
            PyErr_Format(PyExc_TypeError,
                "argument '%s', index %d must be int", name, (int) i);
            return -1;
        }
    }
    Py_DECREF(seq);
    *pin = in;
    *psize = size;
    return 0;
}

// helper get_from_object_int_list
// Convert PyObject to int pointer.
int STR_SHROUD_get_from_object_int_list(PyObject *obj,
    STR_SHROUD_converter_value *value)
{
    int *in;
    Py_ssize_t size;
    if (STR_SHROUD_create_from_PyObject_int(obj, "in", &in, 
        &size) == -1) {
        return 0;
    }
    value->obj = NULL;
    value->dataobj = NULL;
    value->data = (int *) in;
    value->size = size;
    return 1;
}

// helper get_from_object_int_numpy
// Convert PyObject to int pointer.
int STR_SHROUD_get_from_object_int_numpy(PyObject *obj,
    STR_SHROUD_converter_value *value)
{
    PyObject *array = PyArray_FROM_OTF(obj, NPY_INT,
        NPY_ARRAY_IN_ARRAY);
    if (array == NULL) {
        PyErr_SetString(PyExc_ValueError, "must be a 1-D array of int");
        return 0;
    }
    value->obj = array;
    value->dataobj = NULL;
    value->data = PyArray_DATA((PyArrayObject *) array);
    value->size = PyArray_SIZE((PyArrayObject *) array);
    return 1;
}

// helper to_PyList_char
// Convert char * pointer to PyList of PyObjects.
PyObject *STR_SHROUD_to_PyList_char(char * *in, size_t size)
{
    PyObject *out = PyList_New(size);
    for (size_t i = 0; i < size; ++i) {
        PyList_SET_ITEM(out, i, PyString_FromString(in[i]));
    }
    return out;
}

// helper to_PyList_double
// Convert double pointer to PyList of PyObjects.
PyObject *STR_SHROUD_to_PyList_double(const double *in, size_t size)
{
    PyObject *out = PyList_New(size);
    for (size_t i = 0; i < size; ++i) {
        PyList_SET_ITEM(out, i, PyFloat_FromDouble(in[i]));
    }
    return out;
}

// helper to_PyList_int
// Convert int pointer to PyList of PyObjects.
PyObject *STR_SHROUD_to_PyList_int(const int *in, size_t size)
{
    PyObject *out = PyList_New(size);
    for (size_t i = 0; i < size; ++i) {
        PyList_SET_ITEM(out, i, PyInt_FromLong(in[i]));
    }
    return out;
}

const char *PY_Cstruct1_capsule_name = "Cstruct1";
const char *PY_Cstruct_ptr_capsule_name = "Cstruct_ptr";
const char *PY_Cstruct_list_capsule_name = "Cstruct_list";
const char *PY_Cstruct_numpy_capsule_name = "Cstruct_numpy";
const char *PY_Arrays1_capsule_name = "Arrays1";


// Wrap pointer to struct/class.
PyObject *PP_Cstruct1_to_Object_idtor(Cstruct1 *addr, int idtor)
{
    // splicer begin class.Cstruct1.utility.to_object
    PY_Cstruct1 *obj = PyObject_New(PY_Cstruct1, &PY_Cstruct1_Type);
    if (obj == NULL)
        return NULL;
    obj->obj = addr;
    obj->idtor = idtor;
    return (PyObject *) obj;
    // splicer end class.Cstruct1.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_Cstruct1_to_Object(Cstruct1 *addr)
{
    // splicer begin class.Cstruct1.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_Cstruct1_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_Cstruct1_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end class.Cstruct1.utility.to_object
}

// converter which may be used with PyArg_Parse.
int PP_Cstruct1_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.Cstruct1.utility.from_object
    if (obj->ob_type != &PY_Cstruct1_Type) {
        // raise exception
        return 0;
    }
    PY_Cstruct1 * self = (PY_Cstruct1 *) obj;
    *addr = self->obj;
    return 1;
    // splicer end class.Cstruct1.utility.from_object
}

// Wrap pointer to struct/class.
PyObject *PP_Cstruct_ptr_to_Object_idtor(Cstruct_ptr *addr, int idtor)
{
    // splicer begin class.Cstruct_ptr.utility.to_object
    PY_Cstruct_ptr *obj =
        PyObject_New(PY_Cstruct_ptr, &PY_Cstruct_ptr_Type);
    if (obj == NULL)
        return NULL;
    obj->obj = addr;
    obj->idtor = idtor;
    // Python objects for members.
    obj->cfield_obj = NULL;
    obj->const_dvalue_obj = NULL;
    // Python objects for members.
    obj->cfield_dataobj = NULL;
    obj->const_dvalue_dataobj = NULL;
    return (PyObject *) obj;
    // splicer end class.Cstruct_ptr.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_Cstruct_ptr_to_Object(Cstruct_ptr *addr)
{
    // splicer begin class.Cstruct_ptr.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_Cstruct_ptr_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_Cstruct_ptr_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end class.Cstruct_ptr.utility.to_object
}

// converter which may be used with PyArg_Parse.
int PP_Cstruct_ptr_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.Cstruct_ptr.utility.from_object
    if (obj->ob_type != &PY_Cstruct_ptr_Type) {
        // raise exception
        return 0;
    }
    PY_Cstruct_ptr * self = (PY_Cstruct_ptr *) obj;
    *addr = self->obj;
    return 1;
    // splicer end class.Cstruct_ptr.utility.from_object
}

// Wrap pointer to struct/class.
PyObject *PP_Cstruct_list_to_Object_idtor(Cstruct_list *addr, int idtor)
{
    // splicer begin class.Cstruct_list.utility.to_object
    PY_Cstruct_list *obj =
        PyObject_New(PY_Cstruct_list, &PY_Cstruct_list_Type);
    if (obj == NULL)
        return NULL;
    obj->obj = addr;
    obj->idtor = idtor;
    // Python objects for members.
    obj->ivalue_obj = NULL;
    obj->dvalue_obj = NULL;
    obj->svalue_obj = NULL;
    // Python objects for members.
    obj->ivalue_dataobj = NULL;
    obj->dvalue_dataobj = NULL;
    obj->svalue_dataobj = NULL;
    return (PyObject *) obj;
    // splicer end class.Cstruct_list.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_Cstruct_list_to_Object(Cstruct_list *addr)
{
    // splicer begin class.Cstruct_list.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_Cstruct_list_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_Cstruct_list_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end class.Cstruct_list.utility.to_object
}

// converter which may be used with PyArg_Parse.
int PP_Cstruct_list_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.Cstruct_list.utility.from_object
    if (obj->ob_type != &PY_Cstruct_list_Type) {
        // raise exception
        return 0;
    }
    PY_Cstruct_list * self = (PY_Cstruct_list *) obj;
    *addr = self->obj;
    return 1;
    // splicer end class.Cstruct_list.utility.from_object
}

// Wrap pointer to struct/class.
PyObject *PP_Cstruct_numpy_to_Object_idtor(Cstruct_numpy *addr,
    int idtor)
{
    // splicer begin class.Cstruct_numpy.utility.to_object
    PY_Cstruct_numpy *obj =
        PyObject_New(PY_Cstruct_numpy, &PY_Cstruct_numpy_Type);
    if (obj == NULL)
        return NULL;
    obj->obj = addr;
    obj->idtor = idtor;
    // Python objects for members.
    obj->ivalue_obj = NULL;
    obj->dvalue_obj = NULL;
    // Python objects for members.
    obj->ivalue_dataobj = NULL;
    obj->dvalue_dataobj = NULL;
    return (PyObject *) obj;
    // splicer end class.Cstruct_numpy.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_Cstruct_numpy_to_Object(Cstruct_numpy *addr)
{
    // splicer begin class.Cstruct_numpy.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_Cstruct_numpy_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_Cstruct_numpy_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end class.Cstruct_numpy.utility.to_object
}

// converter which may be used with PyArg_Parse.
int PP_Cstruct_numpy_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.Cstruct_numpy.utility.from_object
    if (obj->ob_type != &PY_Cstruct_numpy_Type) {
        // raise exception
        return 0;
    }
    PY_Cstruct_numpy * self = (PY_Cstruct_numpy *) obj;
    *addr = self->obj;
    return 1;
    // splicer end class.Cstruct_numpy.utility.from_object
}

// Wrap pointer to struct/class.
PyObject *PP_Arrays1_to_Object_idtor(Arrays1 *addr, int idtor)
{
    // splicer begin class.Arrays1.utility.to_object
    PY_Arrays1 *obj = PyObject_New(PY_Arrays1, &PY_Arrays1_Type);
    if (obj == NULL)
        return NULL;
    obj->obj = addr;
    obj->idtor = idtor;
    // Python objects for members.
    obj->name_obj = NULL;
    obj->count_obj = NULL;
    // Python objects for members.
    obj->name_dataobj = NULL;
    obj->count_dataobj = NULL;
    return (PyObject *) obj;
    // splicer end class.Arrays1.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_Arrays1_to_Object(Arrays1 *addr)
{
    // splicer begin class.Arrays1.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_Arrays1_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_Arrays1_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end class.Arrays1.utility.to_object
}

// converter which may be used with PyArg_Parse.
int PP_Arrays1_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.Arrays1.utility.from_object
    if (obj->ob_type != &PY_Arrays1_Type) {
        // raise exception
        return 0;
    }
    PY_Arrays1 * self = (PY_Arrays1 *) obj;
    *addr = self->obj;
    return 1;
    // splicer end class.Arrays1.utility.from_object
}

// ----------------------------------------
typedef struct {
    const char *name;
    void (*dtor)(void *ptr);
} PY_SHROUD_dtor_context;

// 0 - --none--
static void PY_SHROUD_capsule_destructor_0(void *ptr)
{
    // Do not release
}

// 1 - c Cstruct1 *
static void PY_SHROUD_capsule_destructor_1(void *ptr)
{
    free(ptr);
}

// 2 - c Cstruct_ptr *
static void PY_SHROUD_capsule_destructor_2(void *ptr)
{
    free(ptr);
}

// 3 - c Cstruct_list *
static void PY_SHROUD_capsule_destructor_3(void *ptr)
{
    free(ptr);
}

// 4 - c Cstruct_numpy *
static void PY_SHROUD_capsule_destructor_4(void *ptr)
{
    free(ptr);
}

// 5 - c Arrays1 *
static void PY_SHROUD_capsule_destructor_5(void *ptr)
{
    free(ptr);
}

// 6 - c const Cstruct1 *
static void PY_SHROUD_capsule_destructor_6(void *ptr)
{
    free(ptr);
}

// Code used to release arrays for NumPy objects
// via a Capsule base object with a destructor.
// Context strings
static PY_SHROUD_dtor_context PY_SHROUD_capsule_context[] = {
    {"--none--", PY_SHROUD_capsule_destructor_0},
    {"c Cstruct1 *", PY_SHROUD_capsule_destructor_1},
    {"c Cstruct_ptr *", PY_SHROUD_capsule_destructor_2},
    {"c Cstruct_list *", PY_SHROUD_capsule_destructor_3},
    {"c Cstruct_numpy *", PY_SHROUD_capsule_destructor_4},
    {"c Arrays1 *", PY_SHROUD_capsule_destructor_5},
    {"c const Cstruct1 *", PY_SHROUD_capsule_destructor_6},
    {NULL, NULL},
};

// Release memory based on icontext.
void PY_SHROUD_release_memory(int icontext, void *ptr)
{
    PY_SHROUD_capsule_context[icontext].dtor(ptr);
}

//Fetch garbage collection context.
void *PY_SHROUD_fetch_context(int icontext)
{
    return PY_SHROUD_capsule_context + icontext;
}

// destructor function for PyCapsule
void PY_SHROUD_capsule_destructor(PyObject *cap)
{
    void *ptr = PyCapsule_GetPointer(cap, "PY_array_dtor");
    PY_SHROUD_dtor_context * context = PyCapsule_GetContext(cap);
    context->dtor(ptr);
}
