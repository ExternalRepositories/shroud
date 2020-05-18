// pypointersmodule.c
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pypointersmodule.h"
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
#define PyInt_FromSize_t PyLong_FromSize_t
#define PyString_FromString PyUnicode_FromString
#define PyString_FromStringAndSize PyUnicode_FromStringAndSize
#endif

// helper create_from_PyObject_char
// Convert obj into an array of type char *
// Return -1 on error.
static int SHROUD_create_from_PyObject_char(PyObject *obj,
    const char *name, char * **pin, Py_ssize_t *psize)
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
            PyErr_Format(PyExc_TypeError,
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

// helper create_from_PyObject_double
// Convert obj into an array of type double
// Return -1 on error.
static int SHROUD_create_from_PyObject_double(PyObject *obj,
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

// helper create_from_PyObject_int
// Convert obj into an array of type int
// Return -1 on error.
static int SHROUD_create_from_PyObject_int(PyObject *obj,
    const char *name, int **pin, Py_ssize_t *psize)
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

// helper to_PyList_double
// Convert double pointer to PyList of PyObjects.
static PyObject *SHROUD_to_PyList_double(const double *in, size_t size)
{
    PyObject *out = PyList_New(size);
    for (size_t i = 0; i < size; ++i) {
        PyList_SET_ITEM(out, i, PyFloat_FromDouble(in[i]));
    }
    return out;
}

// helper to_PyList_int
// Convert int pointer to PyList of PyObjects.
static PyObject *SHROUD_to_PyList_int(const int *in, size_t size)
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

// ----------------------------------------
// Function:  void intargs
// Exact:     py_default
// ----------------------------------------
// Argument:  const int argin +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  int * arginout +intent(inout)
// Requested: py_native_*_inout
// Match:     py_default
// ----------------------------------------
// Argument:  int * argout +intent(out)
// Requested: py_native_*_out
// Match:     py_default
static char PY_intargs__doc__[] =
"documentation"
;

static PyObject *
PY_intargs(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
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

// ----------------------------------------
// Function:  void cos_doubles
// Exact:     py_default
// ----------------------------------------
// Argument:  double * in +intent(in)+rank(1)
// Exact:     py_native_*_in_pointer_list
// ----------------------------------------
// Argument:  double * out +deref(allocatable)+dimension(size(in))+intent(out)
// Exact:     py_native_*_out_allocatable_list
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
// splicer begin function.cos_doubles
    PyObject *SHTPy_in = NULL;
    double * in = NULL;
    double * out = NULL;
    PyObject *SHPy_out = NULL;
    char *SHT_kwlist[] = {
        "in",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:cos_doubles",
        SHT_kwlist, &SHTPy_in))
        return NULL;

    // post_parse
    Py_ssize_t SHSize_in;
    if (SHROUD_create_from_PyObject_double(SHTPy_in, "in", &in, 
        &SHSize_in) == -1)
        goto fail;

    // pre_call
    out = malloc(sizeof(double) * (SHSize_in));
    if (out == NULL) {
        PyErr_NoMemory();
        goto fail;
    }
    int sizein = SHSize_in;

    cos_doubles(in, out, sizein);

    // post_call
    SHPy_out = SHROUD_to_PyList_double(out, SHSize_in);
    if (SHPy_out == NULL) goto fail;

    // cleanup
    free(in);
    free(out);
    out = NULL;

    return (PyObject *) SHPy_out;

fail:
    if (in != NULL) free(in);
    Py_XDECREF(SHPy_out);
    if (out != NULL) free(out);
    return NULL;
// splicer end function.cos_doubles
}

// ----------------------------------------
// Function:  void truncate_to_int
// Exact:     py_default
// ----------------------------------------
// Argument:  double * in +intent(in)+rank(1)
// Exact:     py_native_*_in_pointer_list
// ----------------------------------------
// Argument:  int * out +deref(allocatable)+dimension(size(in))+intent(out)
// Exact:     py_native_*_out_allocatable_list
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
// splicer begin function.truncate_to_int
    PyObject *SHTPy_in = NULL;
    double * in = NULL;
    int * out = NULL;
    PyObject *SHPy_out = NULL;
    char *SHT_kwlist[] = {
        "in",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:truncate_to_int",
        SHT_kwlist, &SHTPy_in))
        return NULL;

    // post_parse
    Py_ssize_t SHSize_in;
    if (SHROUD_create_from_PyObject_double(SHTPy_in, "in", &in, 
        &SHSize_in) == -1)
        goto fail;

    // pre_call
    out = malloc(sizeof(int) * (SHSize_in));
    if (out == NULL) {
        PyErr_NoMemory();
        goto fail;
    }
    int sizein = SHSize_in;

    truncate_to_int(in, out, sizein);

    // post_call
    SHPy_out = SHROUD_to_PyList_int(out, SHSize_in);
    if (SHPy_out == NULL) goto fail;

    // cleanup
    free(in);
    free(out);
    out = NULL;

    return (PyObject *) SHPy_out;

fail:
    if (in != NULL) free(in);
    Py_XDECREF(SHPy_out);
    if (out != NULL) free(out);
    return NULL;
// splicer end function.truncate_to_int
}

// ----------------------------------------
// Function:  void get_values
// Exact:     py_default
// ----------------------------------------
// Argument:  int * nvalues +intent(out)
// Requested: py_native_*_out
// Match:     py_default
// ----------------------------------------
// Argument:  int * values +dimension(3)+intent(out)
// Exact:     py_native_*_out_pointer_list
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
// splicer begin function.get_values
    int * values = NULL;
    PyObject *SHPy_values = NULL;
    PyObject *SHTPy_rv = NULL;  // return value object

    // pre_call
    int nvalues;  // intent(out)
    values = malloc(sizeof(int) * (3));
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

// ----------------------------------------
// Function:  void get_values2
// Exact:     py_default
// ----------------------------------------
// Argument:  int * arg1 +dimension(3)+intent(out)
// Exact:     py_native_*_out_pointer_list
// ----------------------------------------
// Argument:  int * arg2 +dimension(3)+intent(out)
// Exact:     py_native_*_out_pointer_list
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
// splicer begin function.get_values2
    int * arg1 = NULL;
    PyObject *SHPy_arg1 = NULL;
    int * arg2 = NULL;
    PyObject *SHPy_arg2 = NULL;
    PyObject *SHTPy_rv = NULL;  // return value object

    // pre_call
    arg1 = malloc(sizeof(int) * (3));
    if (arg1 == NULL) {
        PyErr_NoMemory();
        goto fail;
    }
    arg2 = malloc(sizeof(int) * (3));
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

// ----------------------------------------
// Function:  void iota_allocatable
// Exact:     py_default
// ----------------------------------------
// Argument:  int nvar +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  int * values +deref(allocatable)+dimension(nvar)+intent(out)
// Exact:     py_native_*_out_allocatable_list
static char PY_iota_allocatable__doc__[] =
"documentation"
;

static PyObject *
PY_iota_allocatable(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.iota_allocatable
    int nvar;
    int * values = NULL;
    PyObject *SHPy_values = NULL;
    char *SHT_kwlist[] = {
        "nvar",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:iota_allocatable",
        SHT_kwlist, &nvar))
        return NULL;

    // pre_call
    values = malloc(sizeof(int) * (nvar));
    if (values == NULL) {
        PyErr_NoMemory();
        goto fail;
    }

    iota_allocatable(nvar, values);

    // post_call
    SHPy_values = SHROUD_to_PyList_int(values, nvar);
    if (SHPy_values == NULL) goto fail;

    // cleanup
    free(values);
    values = NULL;

    return (PyObject *) SHPy_values;

fail:
    Py_XDECREF(SHPy_values);
    if (values != NULL) free(values);
    return NULL;
// splicer end function.iota_allocatable
}

// ----------------------------------------
// Function:  void iota_dimension
// Exact:     py_default
// ----------------------------------------
// Argument:  int nvar +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  int * values +dimension(nvar)+intent(out)
// Exact:     py_native_*_out_pointer_list
static char PY_iota_dimension__doc__[] =
"documentation"
;

static PyObject *
PY_iota_dimension(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.iota_dimension
    int nvar;
    int * values = NULL;
    PyObject *SHPy_values = NULL;
    char *SHT_kwlist[] = {
        "nvar",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:iota_dimension",
        SHT_kwlist, &nvar))
        return NULL;

    // pre_call
    values = malloc(sizeof(int) * (nvar));
    if (values == NULL) {
        PyErr_NoMemory();
        goto fail;
    }

    iota_dimension(nvar, values);

    // post_call
    SHPy_values = SHROUD_to_PyList_int(values, nvar);
    if (SHPy_values == NULL) goto fail;

    // cleanup
    free(values);
    values = NULL;

    return (PyObject *) SHPy_values;

fail:
    Py_XDECREF(SHPy_values);
    if (values != NULL) free(values);
    return NULL;
// splicer end function.iota_dimension
}

// ----------------------------------------
// Function:  void Sum
// Exact:     py_default
// ----------------------------------------
// Argument:  int * values +intent(in)+rank(1)
// Exact:     py_native_*_in_pointer_list
// ----------------------------------------
// Argument:  int * result +intent(out)
// Requested: py_native_*_out
// Match:     py_default
static char PY_Sum__doc__[] =
"documentation"
;

static PyObject *
PY_Sum(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
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
    if (SHROUD_create_from_PyObject_int(SHTPy_values, "values",
        &values,  &SHSize_values) == -1)
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

// ----------------------------------------
// Function:  void fillIntArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * out +dimension(3)+intent(out)
// Exact:     py_native_*_out_pointer_list
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
// splicer begin function.fill_int_array
    int * out = NULL;
    PyObject *SHPy_out = NULL;

    // pre_call
    out = malloc(sizeof(int) * (3));
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

// ----------------------------------------
// Function:  void incrementIntArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * array +intent(inout)+rank(1)
// Exact:     py_native_*_inout_pointer_list
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
    if (SHROUD_create_from_PyObject_int(SHTPy_array, "array", &array, 
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

// ----------------------------------------
// Function:  void acceptCharArrayIn
// Exact:     py_default
// ----------------------------------------
// Argument:  char * * names +intent(in)+rank(1)
// Exact:     py_char_**_in
static char PY_acceptCharArrayIn__doc__[] =
"documentation"
;

static PyObject *
PY_acceptCharArrayIn(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_char_array_in
    char ** names = NULL;
    PyObject * SHTPy_names;
    char *SHT_kwlist[] = {
        "names",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:acceptCharArrayIn",
        SHT_kwlist, &SHTPy_names))
        return NULL;

    // pre_call
    Py_ssize_t SHSize_names;
    if (SHROUD_create_from_PyObject_char(SHTPy_names, "names", &names, 
        &SHSize_names) == -1)
        goto fail;

    acceptCharArrayIn(names);

    // post_call
    free(names);
    names = NULL;

    Py_RETURN_NONE;

fail:
    if (names != NULL) {
        free(names);
    }
    return NULL;
// splicer end function.accept_char_array_in
}

// ----------------------------------------
// Function:  void setGlobalInt
// Exact:     py_default
// ----------------------------------------
// Argument:  int value +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
static char PY_setGlobalInt__doc__[] =
"documentation"
;

static PyObject *
PY_setGlobalInt(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.set_global_int
    int value;
    char *SHT_kwlist[] = {
        "value",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:setGlobalInt",
        SHT_kwlist, &value))
        return NULL;

    setGlobalInt(value);
    Py_RETURN_NONE;
// splicer end function.set_global_int
}

// ----------------------------------------
// Function:  int sumFixedArray
// Requested: py_native_scalar_result
// Match:     py_default
static char PY_sumFixedArray__doc__[] =
"documentation"
;

/**
 * Used to test values global_array.
 */
static PyObject *
PY_sumFixedArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.sum_fixed_array
    PyObject * SHTPy_rv = NULL;

    int SHCXX_rv = sumFixedArray();

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.sum_fixed_array
}

// ----------------------------------------
// Function:  void getPtrToFixedArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * count +deref(pointer)+dimension(10)+intent(out)
// Exact:     py_native_**_out_pointer_list
static char PY_getPtrToFixedArray__doc__[] =
"documentation"
;

/**
 * Return a Fortran pointer to an array which is always the same length.
 */
static PyObject *
PY_getPtrToFixedArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_fixed_array
    int *count;
    PyObject *SHPy_count = NULL;

    getPtrToFixedArray(&count);

    // post_call
    SHPy_count = SHROUD_to_PyList_int(count, 10);
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_fixed_array
}

// ----------------------------------------
// Function:  void getPtrToDynamicArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * count +deref(pointer)+dimension(ncount)+intent(out)
// Exact:     py_native_**_out_pointer_list
// ----------------------------------------
// Argument:  int * ncount +hidden+intent(out)
// Requested: py_native_*_out
// Match:     py_default
static char PY_getPtrToDynamicArray__doc__[] =
"documentation"
;

/**
 * Return a Fortran pointer to an array which is the length of
 * the argument ncount.
 */
static PyObject *
PY_getPtrToDynamicArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_dynamic_array
    int *count;
    PyObject *SHPy_count = NULL;

    // pre_call
    int ncount;  // intent(out)

    getPtrToDynamicArray(&count, &ncount);

    // post_call
    SHPy_count = SHROUD_to_PyList_int(count, ncount);
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_dynamic_array
}

// ----------------------------------------
// Function:  void getPtrToFuncArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * count +deref(pointer)+dimension(getLen())+intent(out)
// Exact:     py_native_**_out_pointer_list
static char PY_getPtrToFuncArray__doc__[] =
"documentation"
;

/**
 * Return a Fortran pointer to an array which is the length
 * is computed by C++ function getLen.
 * getLen will be called from C/C++ to compute the shape.
 */
static PyObject *
PY_getPtrToFuncArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_func_array
    int *count;
    PyObject *SHPy_count = NULL;

    getPtrToFuncArray(&count);

    // post_call
    SHPy_count = SHROUD_to_PyList_int(count, getLen());
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_func_array
}

// ----------------------------------------
// Function:  void getPtrToFixedConstArray
// Exact:     py_default
// ----------------------------------------
// Argument:  const int * * count +deref(pointer)+dimension(10)+intent(out)
// Exact:     py_native_**_out_pointer_list
static char PY_getPtrToFixedConstArray__doc__[] =
"documentation"
;

static PyObject *
PY_getPtrToFixedConstArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_fixed_const_array
    const int *count;
    PyObject *SHPy_count = NULL;

    getPtrToFixedConstArray(&count);

    // post_call
    SHPy_count = SHROUD_to_PyList_int(count, 10);
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_fixed_const_array
}

// ----------------------------------------
// Function:  void getPtrToDynamicConstArray
// Exact:     py_default
// ----------------------------------------
// Argument:  const int * * count +deref(pointer)+dimension(ncount)+intent(out)
// Exact:     py_native_**_out_pointer_list
// ----------------------------------------
// Argument:  int * ncount +hidden+intent(out)
// Requested: py_native_*_out
// Match:     py_default
static char PY_getPtrToDynamicConstArray__doc__[] =
"documentation"
;

static PyObject *
PY_getPtrToDynamicConstArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_ptr_to_dynamic_const_array
    const int *count;
    PyObject *SHPy_count = NULL;

    // pre_call
    int ncount;  // intent(out)

    getPtrToDynamicConstArray(&count, &ncount);

    // post_call
    SHPy_count = SHROUD_to_PyList_int(count, ncount);
    if (SHPy_count == NULL) goto fail;

    return (PyObject *) SHPy_count;

fail:
    Py_XDECREF(SHPy_count);
    return NULL;
// splicer end function.get_ptr_to_dynamic_const_array
}

// ----------------------------------------
// Function:  void getRawPtrToScalar
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * nitems +deref(raw)+intent(out)
// Exact:     py_native_**_out_raw
static char PY_getRawPtrToScalar__doc__[] =
"documentation"
;

/**
 * Called directly via an interface in Fortran.
 */
static PyObject *
PY_getRawPtrToScalar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_raw_ptr_to_scalar
    int *nitems;
    PyObject *SHPy_nitems = NULL;

    getRawPtrToScalar(&nitems);

    // post_call
    SHPy_nitems = PyCapsule_New(nitems, NULL, NULL);

    return (PyObject *) SHPy_nitems;
// splicer end function.get_raw_ptr_to_scalar
}

// ----------------------------------------
// Function:  void getRawPtrToFixedArray
// Exact:     py_default
// ----------------------------------------
// Argument:  int * * count +deref(raw)+intent(out)
// Exact:     py_native_**_out_raw
static char PY_getRawPtrToFixedArray__doc__[] =
"documentation"
;

/**
 * Return a type(C_PTR) to an array which is always the same length.
 * Called directly via an interface in Fortran.
 * # Uses +deref(raw) instead of +dimension(10) like getPtrToFixedArray.
 */
static PyObject *
PY_getRawPtrToFixedArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_raw_ptr_to_fixed_array
    int *count;
    PyObject *SHPy_count = NULL;

    getRawPtrToFixedArray(&count);

    // post_call
    SHPy_count = PyCapsule_New(count, NULL, NULL);

    return (PyObject *) SHPy_count;
// splicer end function.get_raw_ptr_to_fixed_array
}

// ----------------------------------------
// Function:  void * returnAddress1
// Requested: py_unknown_result
// Match:     py_default
// ----------------------------------------
// Argument:  int flag +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
static char PY_returnAddress1__doc__[] =
"documentation"
;

static PyObject *
PY_returnAddress1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.return_address1
    int flag;
    char *SHT_kwlist[] = {
        "flag",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:returnAddress1",
        SHT_kwlist, &flag))
        return NULL;

    void * SHCXX_rv = returnAddress1(flag);

    // post_call
    SHTPy_rv = PyCapsule_New(SHCXX_rv, NULL, NULL);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_address1
}

// ----------------------------------------
// Function:  void * returnAddress2
// Requested: py_unknown_result
// Match:     py_default
// ----------------------------------------
// Argument:  int flag +intent(in)+value
// Requested: py_native_scalar_in
// Match:     py_default
static char PY_returnAddress2__doc__[] =
"documentation"
;

static PyObject *
PY_returnAddress2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.return_address2
    int flag;
    char *SHT_kwlist[] = {
        "flag",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:returnAddress2",
        SHT_kwlist, &flag))
        return NULL;

    void * SHCXX_rv = returnAddress2(flag);

    // post_call
    SHTPy_rv = PyCapsule_New(SHCXX_rv, NULL, NULL);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_address2
}

// ----------------------------------------
// Function:  void fetchVoidPtr
// Exact:     py_default
// ----------------------------------------
// Argument:  void * * addr +intent(out)
// Exact:     py_unknown_**_out
static char PY_fetchVoidPtr__doc__[] =
"documentation"
;

static PyObject *
PY_fetchVoidPtr(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.fetch_void_ptr
    void *addr;
    PyObject * SHPy_addr = NULL;

    fetchVoidPtr(&addr);

    // post_call
    SHPy_addr = PyCapsule_New(addr, NULL, NULL);

    return (PyObject *) SHPy_addr;
// splicer end function.fetch_void_ptr
}

// ----------------------------------------
// Function:  int * returnIntPtrToScalar +deref(pointer)
// Exact:     py_native_*_result_pointer_list
static char PY_returnIntPtrToScalar__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntPtrToScalar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_ptr_to_scalar
    PyObject *SHTPy_rv = NULL;

    int * SHCXX_rv = returnIntPtrToScalar();

    // post_call
    SHTPy_rv = SHROUD_to_PyList_int(SHCXX_rv, 1);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.return_int_ptr_to_scalar
}

// ----------------------------------------
// Function:  int * returnIntPtrToFixedArray +deref(pointer)+dimension(10)
// Exact:     py_native_*_result_pointer_list
static char PY_returnIntPtrToFixedArray__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntPtrToFixedArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_ptr_to_fixed_array
    PyObject *SHTPy_rv = NULL;

    int * SHCXX_rv = returnIntPtrToFixedArray();

    // post_call
    SHTPy_rv = SHROUD_to_PyList_int(SHCXX_rv, 10);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.return_int_ptr_to_fixed_array
}

// ----------------------------------------
// Function:  const int * returnIntPtrToConstScalar +deref(pointer)
// Exact:     py_native_*_result_pointer_list
static char PY_returnIntPtrToConstScalar__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntPtrToConstScalar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_ptr_to_const_scalar
    PyObject *SHTPy_rv = NULL;

    const int * SHCXX_rv = returnIntPtrToConstScalar();

    // post_call
    SHTPy_rv = SHROUD_to_PyList_int(SHCXX_rv, 1);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.return_int_ptr_to_const_scalar
}

// ----------------------------------------
// Function:  const int * returnIntPtrToFixedConstArray +deref(pointer)+dimension(10)
// Exact:     py_native_*_result_pointer_list
static char PY_returnIntPtrToFixedConstArray__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntPtrToFixedConstArray(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_ptr_to_fixed_const_array
    PyObject *SHTPy_rv = NULL;

    const int * SHCXX_rv = returnIntPtrToFixedConstArray();

    // post_call
    SHTPy_rv = SHROUD_to_PyList_int(SHCXX_rv, 10);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.return_int_ptr_to_fixed_const_array
}

// ----------------------------------------
// Function:  int * returnIntScalar +deref(scalar)
// Requested: py_native_*_result_scalar
// Match:     py_default
static char PY_returnIntScalar__doc__[] =
"documentation"
;

static PyObject *
PY_returnIntScalar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_int_scalar
    PyObject * SHTPy_rv = NULL;

    int * SHCXX_rv = returnIntScalar();

    // post_call
    SHTPy_rv = PyInt_FromLong(*SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_int_scalar
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
{"iota_allocatable", (PyCFunction)PY_iota_allocatable,
    METH_VARARGS|METH_KEYWORDS, PY_iota_allocatable__doc__},
{"iota_dimension", (PyCFunction)PY_iota_dimension,
    METH_VARARGS|METH_KEYWORDS, PY_iota_dimension__doc__},
{"Sum", (PyCFunction)PY_Sum, METH_VARARGS|METH_KEYWORDS, PY_Sum__doc__},
{"fillIntArray", (PyCFunction)PY_fillIntArray, METH_NOARGS,
    PY_fillIntArray__doc__},
{"incrementIntArray", (PyCFunction)PY_incrementIntArray,
    METH_VARARGS|METH_KEYWORDS, PY_incrementIntArray__doc__},
{"acceptCharArrayIn", (PyCFunction)PY_acceptCharArrayIn,
    METH_VARARGS|METH_KEYWORDS, PY_acceptCharArrayIn__doc__},
{"setGlobalInt", (PyCFunction)PY_setGlobalInt,
    METH_VARARGS|METH_KEYWORDS, PY_setGlobalInt__doc__},
{"sumFixedArray", (PyCFunction)PY_sumFixedArray, METH_NOARGS,
    PY_sumFixedArray__doc__},
{"getPtrToFixedArray", (PyCFunction)PY_getPtrToFixedArray, METH_NOARGS,
    PY_getPtrToFixedArray__doc__},
{"getPtrToDynamicArray", (PyCFunction)PY_getPtrToDynamicArray,
    METH_NOARGS, PY_getPtrToDynamicArray__doc__},
{"getPtrToFuncArray", (PyCFunction)PY_getPtrToFuncArray, METH_NOARGS,
    PY_getPtrToFuncArray__doc__},
{"getPtrToFixedConstArray", (PyCFunction)PY_getPtrToFixedConstArray,
    METH_NOARGS, PY_getPtrToFixedConstArray__doc__},
{"getPtrToDynamicConstArray", (PyCFunction)PY_getPtrToDynamicConstArray,
    METH_NOARGS, PY_getPtrToDynamicConstArray__doc__},
{"getRawPtrToScalar", (PyCFunction)PY_getRawPtrToScalar, METH_NOARGS,
    PY_getRawPtrToScalar__doc__},
{"getRawPtrToFixedArray", (PyCFunction)PY_getRawPtrToFixedArray,
    METH_NOARGS, PY_getRawPtrToFixedArray__doc__},
{"returnAddress1", (PyCFunction)PY_returnAddress1,
    METH_VARARGS|METH_KEYWORDS, PY_returnAddress1__doc__},
{"returnAddress2", (PyCFunction)PY_returnAddress2,
    METH_VARARGS|METH_KEYWORDS, PY_returnAddress2__doc__},
{"fetchVoidPtr", (PyCFunction)PY_fetchVoidPtr, METH_NOARGS,
    PY_fetchVoidPtr__doc__},
{"returnIntPtrToScalar", (PyCFunction)PY_returnIntPtrToScalar,
    METH_NOARGS, PY_returnIntPtrToScalar__doc__},
{"returnIntPtrToFixedArray", (PyCFunction)PY_returnIntPtrToFixedArray,
    METH_NOARGS, PY_returnIntPtrToFixedArray__doc__},
{"returnIntPtrToConstScalar", (PyCFunction)PY_returnIntPtrToConstScalar,
    METH_NOARGS, PY_returnIntPtrToConstScalar__doc__},
{"returnIntPtrToFixedConstArray",
    (PyCFunction)PY_returnIntPtrToFixedConstArray, METH_NOARGS,
    PY_returnIntPtrToFixedConstArray__doc__},
{"returnIntScalar", (PyCFunction)PY_returnIntScalar, METH_NOARGS,
    PY_returnIntScalar__doc__},
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

