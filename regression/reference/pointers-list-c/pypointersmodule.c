// pypointersmodule.c
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pypointersmodule.h"
#include "pointers.hpp"
#include <stdlib.h>

// splicer begin include
// splicer end include

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
    double *in = malloc(size * sizeof(double));
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
    int *in = malloc(size * sizeof(int));
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

// splicer begin C_definition
// splicer end C_definition
PyObject *PY_error_obj;
// splicer begin additional_functions
// splicer end additional_functions

static char PY_intargs__doc__[] =
"documentation"
;

static PyObject *
PY_intargs(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void intargs(const int argin +intent(in)+value, int * arginout +intent(inout), int * argout +intent(out))
// splicer begin function.intargs
    int argin;
    int arginout;
    char *SHT_kwlist[] = {
        "argin",
        "arginout",
        NULL };
    PyObject *SHTPy_rv = NULL;  // return value object

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "ii:intargs",
        SHT_kwlist, &argin, &arginout))
        return NULL;

    // pre_call
    int argout;  // intent(out)

    intargs(argin, &arginout, &argout);

    // post_call
    SHTPy_rv = Py_BuildValue("ii", arginout, argout);

    return SHTPy_rv;
// splicer end function.intargs
}

static char PY_cos_doubles__doc__[] =
"documentation"
;

/**
 * \brief compute cos of IN and save in OUT
 *
 * allocate OUT same type as IN implied size of array
 */
static PyObject *
PY_cos_doubles(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void cos_doubles(double * in +dimension(:)+intent(in), double * out +allocatable(mold=in)+intent(out), int sizein +implied(size(in))+intent(in)+value)
// splicer begin function.cos_doubles
    PyObject *SHTPy_in = NULL;
    double * in = NULL;
    double * out = NULL;
    char *SHT_kwlist[] = {
        "in",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:cos_doubles",
        SHT_kwlist, &SHTPy_in))
        return NULL;

    // post_parse
    Py_ssize_t SHSize_in;
    if (SHROUD_from_PyObject_double(SHTPy_in, "in", &in, 
        &SHSize_in) == -1)
        goto fail;

    // pre_call
    out = malloc(sizeof(double) * SHSize_in);
    if (out == NULL) {
        PyErr_NoMemory();
        goto fail;
    }
    int sizein = SHSize_in;

    cos_doubles(in, out, sizein);

    // post_call
    PyObject *SHPy_out = SHROUD_to_PyList_double(out, SHSize_in);
    if (SHPy_out == NULL) goto fail;

    // cleanup
    free(in);
    free(out);

    return (PyObject *) SHPy_out;

fail:
    if (in != NULL) free(in);
    if (out != NULL) free(out);
    return NULL;
// splicer end function.cos_doubles
}

static char PY_truncate_to_int__doc__[] =
"documentation"
;

/**
 * \brief truncate IN argument and save in OUT
 *
 * allocate OUT different type as IN
 * implied size of array
 */
static PyObject *
PY_truncate_to_int(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void truncate_to_int(double * in +dimension(:)+intent(in), int * out +allocatable(mold=in)+intent(out), int sizein +implied(size(in))+intent(in)+value)
// splicer begin function.truncate_to_int
    PyObject *SHTPy_in = NULL;
    double * in = NULL;
    int * out = NULL;
    char *SHT_kwlist[] = {
        "in",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:truncate_to_int",
        SHT_kwlist, &SHTPy_in))
        return NULL;

    // post_parse
    Py_ssize_t SHSize_in;
    if (SHROUD_from_PyObject_double(SHTPy_in, "in", &in, 
        &SHSize_in) == -1)
        goto fail;

    // pre_call
    out = malloc(sizeof(int) * SHSize_in);
    if (out == NULL) {
        PyErr_NoMemory();
        goto fail;
    }
    int sizein = SHSize_in;

    truncate_to_int(in, out, sizein);

    // post_call
    PyObject *SHPy_out = SHROUD_to_PyList_int(out, SHSize_in);
    if (SHPy_out == NULL) goto fail;

    // cleanup
    free(in);
    free(out);

    return (PyObject *) SHPy_out;

fail:
    if (in != NULL) free(in);
    if (out != NULL) free(out);
    return NULL;
// splicer end function.truncate_to_int
}

static char PY_get_values__doc__[] =
"documentation"
;

/**
 * \brief fill values into array
 *
 * The function knows how long the array must be.
 * Fortran will treat the dimension as assumed-length.
 * The Python wrapper will create a NumPy array or list so it must
 * have an explicit dimension (not assumed-length).
 */
static PyObject *
PY_get_values(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void get_values(int * nvalues +intent(out), int * values +dimension(3)+intent(out))
// splicer begin function.get_values
    PyObject *SHPy_values = NULL;
    int * values = NULL;
    PyObject *SHTPy_rv = NULL;  // return value object

    // pre_call
    int nvalues;  // intent(out)
    values = malloc(sizeof(int) * 3);
    if (values == NULL) {
        PyErr_NoMemory();
        goto fail;
    }

    get_values(&nvalues, values);

    // post_call
    SHPy_values = SHROUD_to_PyList_int(values, 3);
    if (SHPy_values == NULL) goto fail;
    SHTPy_rv = Py_BuildValue("iO", nvalues, SHPy_values);

    // cleanup
    free(values);
    values = NULL;

    return SHTPy_rv;

fail:
    Py_XDECREF(SHPy_values);
    if (values != NULL) free(values);
    return NULL;
// splicer end function.get_values
}

static char PY_get_values2__doc__[] =
"documentation"
;

/**
 * \brief fill values into two arrays
 *
 * Test two intent(out) arguments.
 * Make sure error handling works with C++.
 */
static PyObject *
PY_get_values2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void get_values2(int * arg1 +dimension(3)+intent(out), int * arg2 +dimension(3)+intent(out))
// splicer begin function.get_values2
    PyObject *SHPy_arg1 = NULL;
    int * arg1 = NULL;
    PyObject *SHPy_arg2 = NULL;
    int * arg2 = NULL;
    PyObject *SHTPy_rv = NULL;  // return value object

    // pre_call
    arg1 = malloc(sizeof(int) * 3);
    if (arg1 == NULL) {
        PyErr_NoMemory();
        goto fail;
    }
    arg2 = malloc(sizeof(int) * 3);
    if (arg2 == NULL) {
        PyErr_NoMemory();
        goto fail;
    }

    get_values2(arg1, arg2);

    // post_call
    SHPy_arg1 = SHROUD_to_PyList_int(arg1, 3);
    if (SHPy_arg1 == NULL) goto fail;
    SHPy_arg2 = SHROUD_to_PyList_int(arg2, 3);
    if (SHPy_arg2 == NULL) goto fail;
    SHTPy_rv = Py_BuildValue("OO", SHPy_arg1, SHPy_arg2);

    // cleanup
    free(arg1);
    arg1 = NULL;
    free(arg2);
    arg2 = NULL;

    return SHTPy_rv;

fail:
    Py_XDECREF(SHPy_arg1);
    if (arg1 != NULL) free(arg1);
    Py_XDECREF(SHPy_arg2);
    if (arg2 != NULL) free(arg2);
    return NULL;
// splicer end function.get_values2
}

static char PY_Sum__doc__[] =
"documentation"
;

static PyObject *
PY_Sum(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void Sum(int len +implied(size(values))+intent(in)+value, int * values +dimension(:)+intent(in), int * result +intent(out))
// splicer begin function.sum
    PyObject *SHTPy_values = NULL;
    int * values = NULL;
    char *SHT_kwlist[] = {
        "values",
        NULL };
    PyObject * SHPy_result = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:Sum", SHT_kwlist, 
        &SHTPy_values))
        return NULL;

    // post_parse
    Py_ssize_t SHSize_values;
    if (SHROUD_from_PyObject_int(SHTPy_values, "values", &values, 
        &SHSize_values) == -1)
        goto fail;

    // pre_call
    int result;  // intent(out)
    int len = SHSize_values;

    Sum(len, values, &result);

    // post_call
    SHPy_result = PyInt_FromLong(result);

    // cleanup
    free(values);

    return (PyObject *) SHPy_result;

fail:
    if (values != NULL) free(values);
    return NULL;
// splicer end function.sum
}

static char PY_fillIntArray__doc__[] =
"documentation"
;

/**
 * Return three values into memory the user provides.
 */
static PyObject *
PY_fillIntArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void fillIntArray(int * out +dimension(3)+intent(out))
// splicer begin function.fill_int_array
    PyObject *SHPy_out = NULL;
    int * out = NULL;

    // pre_call
    out = malloc(sizeof(int) * 3);
    if (out == NULL) {
        PyErr_NoMemory();
        goto fail;
    }

    fillIntArray(out);

    // post_call
    SHPy_out = SHROUD_to_PyList_int(out, 3);
    if (SHPy_out == NULL) goto fail;

    // cleanup
    free(out);
    out = NULL;

    return (PyObject *) SHPy_out;

fail:
    Py_XDECREF(SHPy_out);
    if (out != NULL) free(out);
    return NULL;
// splicer end function.fill_int_array
}

static char PY_incrementIntArray__doc__[] =
"documentation"
;

/**
 * Increment array in place using intent(INOUT).
 */
static PyObject *
PY_incrementIntArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void incrementIntArray(int * array +dimension(:)+intent(inout), int sizein +implied(size(array))+intent(in)+value)
// splicer begin function.increment_int_array
    PyObject *SHTPy_array = NULL;
    int * array = NULL;
    char *SHT_kwlist[] = {
        "array",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:incrementIntArray",
        SHT_kwlist, &SHTPy_array))
        return NULL;

    // post_parse
    Py_ssize_t SHSize_array;
    if (SHROUD_from_PyObject_int(SHTPy_array, "array", &array, 
        &SHSize_array) == -1)
        goto fail;

    // pre_call
    int sizein = SHSize_array;

    incrementIntArray(array, sizein);

    // post_call
    PyObject *SHPy_array = SHROUD_to_PyList_int(array, SHSize_array);
    if (SHPy_array == NULL) goto fail;

    // cleanup
    free(array);

    return (PyObject *) SHPy_array;

fail:
    if (array != NULL) free(array);
    return NULL;
// splicer end function.increment_int_array
}
static PyMethodDef PY_methods[] = {
{"intargs", (PyCFunction)PY_intargs, METH_VARARGS|METH_KEYWORDS,
    PY_intargs__doc__},
{"cos_doubles", (PyCFunction)PY_cos_doubles, METH_VARARGS|METH_KEYWORDS,
    PY_cos_doubles__doc__},
{"truncate_to_int", (PyCFunction)PY_truncate_to_int,
    METH_VARARGS|METH_KEYWORDS, PY_truncate_to_int__doc__},
{"get_values", (PyCFunction)PY_get_values, METH_NOARGS,
    PY_get_values__doc__},
{"get_values2", (PyCFunction)PY_get_values2, METH_NOARGS,
    PY_get_values2__doc__},
{"Sum", (PyCFunction)PY_Sum, METH_VARARGS|METH_KEYWORDS, PY_Sum__doc__},
{"fillIntArray", (PyCFunction)PY_fillIntArray, METH_NOARGS,
    PY_fillIntArray__doc__},
{"incrementIntArray", (PyCFunction)PY_incrementIntArray,
    METH_VARARGS|METH_KEYWORDS, PY_incrementIntArray__doc__},
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

/*
 * initpointers - Initialization function for the module
 * *must* be called initpointers
 */
static char PY__doc__[] =
"library documentation"
;

struct module_state {
    PyObject *error;
};

#if PY_MAJOR_VERSION >= 3
#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))
#else
#define GETSTATE(m) (&_state)
static struct module_state _state;
#endif

#if PY_MAJOR_VERSION >= 3
static int pointers_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int pointers_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "pointers", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    NULL, /* m_reload */
    pointers_traverse, /* m_traverse */
    pointers_clear, /* m_clear */
    NULL  /* m_free */
};

#define RETVAL m
#define INITERROR return NULL
#else
#define RETVAL
#define INITERROR return
#endif

PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
PyInit_pointers(void)
#else
initpointers(void)
#endif
{
    PyObject *m = NULL;
    const char * error_name = "pointers.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("pointers", PY_methods,
        PY__doc__,
        (PyObject*)NULL,PYTHON_API_VERSION);
#endif
    if (m == NULL)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    PY_error_obj = PyErr_NewException((char *) error_name, NULL, NULL);
    if (PY_error_obj == NULL)
        return RETVAL;
    st->error = PY_error_obj;
    PyModule_AddObject(m, "Error", st->error);

    // splicer begin C_init_body
    // splicer end C_init_body

    /* Check for errors */
    if (PyErr_Occurred())
        Py_FatalError("can't initialize module pointers");
    return RETVAL;
}

