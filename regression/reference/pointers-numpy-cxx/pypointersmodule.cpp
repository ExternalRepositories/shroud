// pypointersmodule.cpp
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pypointersmodule.hpp"
#define PY_ARRAY_UNIQUE_SYMBOL SHROUD_POINTERS_ARRAY_API
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"
#include <cstdlib>

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
    char * *in = static_cast<char * *>
        (std::malloc(size * sizeof(char *)));
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PySequence_Fast_GET_ITEM(seq, i);
        in[i] = PyString_AsString(item);
        if (PyErr_Occurred()) {
            std::free(in);
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

// splicer begin C_definition
// splicer end C_definition
PyObject *PY_error_obj;
// splicer begin additional_functions
// splicer end additional_functions

// void intargs(const int argin +intent(in)+value, int * arginout +intent(inout), int * argout +intent(out))
// ----------------------------------------
// Argument:  argin
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  arginout
// Requested: py_native_*_inout
// Match:     py_default
// ----------------------------------------
// Argument:  argout
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
    const char *SHT_kwlist[] = {
        "argin",
        "arginout",
        nullptr };
    PyObject *SHTPy_rv = nullptr;  // return value object

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "ii:intargs",
        const_cast<char **>(SHT_kwlist), &argin, &arginout))
        return nullptr;

    // pre_call
    int argout;  // intent(out)

    intargs(argin, &arginout, &argout);

    // post_call
    SHTPy_rv = Py_BuildValue("ii", arginout, argout);

    return SHTPy_rv;
// splicer end function.intargs
}

// void cos_doubles(double * in +dimension(:)+intent(in), double * out +allocatable(mold=in)+intent(out), int sizein +implied(size(in))+intent(in)+value)
// ----------------------------------------
// Argument:  in
// Exact:     py_native_in_dimension_numpy
// ----------------------------------------
// Argument:  out
// Exact:     py_native_out_allocatable_numpy_mold
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
    PyObject * SHTPy_in;
    PyArrayObject * SHPy_in = nullptr;
    PyArrayObject * SHPy_out = nullptr;
    const char *SHT_kwlist[] = {
        "in",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:cos_doubles",
        const_cast<char **>(SHT_kwlist), &SHTPy_in))
        return nullptr;

    // post_parse
    SHPy_in = reinterpret_cast<PyArrayObject *>(PyArray_FROM_OTF(
        SHTPy_in, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY));
    if (SHPy_in == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "in must be a 1-D array of double");
        goto fail;
    }
    {
        // pre_call
        double * in = static_cast<double *>(PyArray_DATA(SHPy_in));
        SHPy_out = reinterpret_cast<PyArrayObject *>
            (PyArray_NewLikeArray(SHPy_in, NPY_CORDER, NULL, 0));
        if (SHPy_out == nullptr)
            goto fail;
        double * out = static_cast<double *>(PyArray_DATA(SHPy_out));
        int sizein = PyArray_SIZE(SHPy_in);

        cos_doubles(in, out, sizein);

        // cleanup
        Py_DECREF(SHPy_in);

        return (PyObject *) SHPy_out;
    }

fail:
    Py_XDECREF(SHPy_in);
    Py_XDECREF(SHPy_out);
    return nullptr;
// splicer end function.cos_doubles
}

// void truncate_to_int(double * in +dimension(:)+intent(in), int * out +allocatable(mold=in)+intent(out), int sizein +implied(size(in))+intent(in)+value)
// ----------------------------------------
// Argument:  in
// Exact:     py_native_in_dimension_numpy
// ----------------------------------------
// Argument:  out
// Exact:     py_native_out_allocatable_numpy_mold
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
    PyObject * SHTPy_in;
    PyArrayObject * SHPy_in = nullptr;
    PyArrayObject * SHPy_out = nullptr;
    const char *SHT_kwlist[] = {
        "in",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:truncate_to_int",
        const_cast<char **>(SHT_kwlist), &SHTPy_in))
        return nullptr;

    // post_parse
    SHPy_in = reinterpret_cast<PyArrayObject *>(PyArray_FROM_OTF(
        SHTPy_in, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY));
    if (SHPy_in == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "in must be a 1-D array of double");
        goto fail;
    }
    {
        // pre_call
        double * in = static_cast<double *>(PyArray_DATA(SHPy_in));
        PyArray_Descr * SHDPy_out = PyArray_DescrFromType(NPY_INT);
        SHPy_out = reinterpret_cast<PyArrayObject *>
            (PyArray_NewLikeArray(SHPy_in, NPY_CORDER, SHDPy_out, 0));
        if (SHPy_out == nullptr)
            goto fail;
        int * out = static_cast<int *>(PyArray_DATA(SHPy_out));
        int sizein = PyArray_SIZE(SHPy_in);

        truncate_to_int(in, out, sizein);

        // cleanup
        Py_DECREF(SHPy_in);

        return (PyObject *) SHPy_out;
    }

fail:
    Py_XDECREF(SHPy_in);
    Py_XDECREF(SHPy_out);
    return nullptr;
// splicer end function.truncate_to_int
}

// void get_values(int * nvalues +intent(out), int * values +dimension(3)+intent(out))
// ----------------------------------------
// Argument:  nvalues
// Requested: py_native_*_out
// Match:     py_default
// ----------------------------------------
// Argument:  values
// Exact:     py_native_out_dimension_numpy
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
    npy_intp SHD_values[1];
    PyArrayObject * SHPy_values = nullptr;
    PyObject *SHTPy_rv = nullptr;  // return value object

    // post_parse
    SHD_values[0] = 3;
    SHPy_values = reinterpret_cast<PyArrayObject *>
        (PyArray_SimpleNew(1, SHD_values, NPY_INT));
    if (SHPy_values == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "values must be a 1-D array of int");
        goto fail;
    }
    {
        // pre_call
        int nvalues;  // intent(out)
        int * values = static_cast<int *>(PyArray_DATA(SHPy_values));

        get_values(&nvalues, values);

        // post_call
        SHTPy_rv = Py_BuildValue("iO", nvalues, SHPy_values);

        return SHTPy_rv;
    }

fail:
    Py_XDECREF(SHPy_values);
    return nullptr;
// splicer end function.get_values
}

// void get_values2(int * arg1 +dimension(3)+intent(out), int * arg2 +dimension(3)+intent(out))
// ----------------------------------------
// Argument:  arg1
// Exact:     py_native_out_dimension_numpy
// ----------------------------------------
// Argument:  arg2
// Exact:     py_native_out_dimension_numpy
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
    npy_intp SHD_arg1[1];
    PyArrayObject * SHPy_arg1 = nullptr;
    npy_intp SHD_arg2[1];
    PyArrayObject * SHPy_arg2 = nullptr;
    PyObject *SHTPy_rv = nullptr;  // return value object

    // post_parse
    SHD_arg1[0] = 3;
    SHPy_arg1 = reinterpret_cast<PyArrayObject *>
        (PyArray_SimpleNew(1, SHD_arg1, NPY_INT));
    if (SHPy_arg1 == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "arg1 must be a 1-D array of int");
        goto fail;
    }
    SHD_arg2[0] = 3;
    SHPy_arg2 = reinterpret_cast<PyArrayObject *>
        (PyArray_SimpleNew(1, SHD_arg2, NPY_INT));
    if (SHPy_arg2 == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "arg2 must be a 1-D array of int");
        goto fail;
    }
    {
        // pre_call
        int * arg1 = static_cast<int *>(PyArray_DATA(SHPy_arg1));
        int * arg2 = static_cast<int *>(PyArray_DATA(SHPy_arg2));

        get_values2(arg1, arg2);

        // post_call
        SHTPy_rv = Py_BuildValue("OO", SHPy_arg1, SHPy_arg2);

        return SHTPy_rv;
    }

fail:
    Py_XDECREF(SHPy_arg1);
    Py_XDECREF(SHPy_arg2);
    return nullptr;
// splicer end function.get_values2
}

// void iota_allocatable(int nvar +intent(in)+value, int * values +allocatable(nvar)+intent(out))
// ----------------------------------------
// Argument:  nvar
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  values
// Exact:     py_native_out_allocatable_numpy
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
    npy_intp SHD_values[1];
    PyArrayObject * SHPy_values = nullptr;
    const char *SHT_kwlist[] = {
        "nvar",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:iota_allocatable",
        const_cast<char **>(SHT_kwlist), &nvar))
        return nullptr;

    // post_parse
    SHD_values[0] = nvar;
    SHPy_values = reinterpret_cast<PyArrayObject *>
        (PyArray_SimpleNew(1, SHD_values, NPY_INT));
    if (SHPy_values == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "values must be a 1-D array of int");
        goto fail;
    }
    {
        // pre_call
        int * values = static_cast<int *>(PyArray_DATA(SHPy_values));

        iota_allocatable(nvar, values);
        return (PyObject *) SHPy_values;
    }

fail:
    Py_XDECREF(SHPy_values);
    return nullptr;
// splicer end function.iota_allocatable
}

// void iota_dimension(int nvar +intent(in)+value, int * values +dimension(nvar)+intent(out))
// ----------------------------------------
// Argument:  nvar
// Requested: py_native_scalar_in
// Match:     py_default
// ----------------------------------------
// Argument:  values
// Exact:     py_native_out_dimension_numpy
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
    npy_intp SHD_values[1];
    PyArrayObject * SHPy_values = nullptr;
    const char *SHT_kwlist[] = {
        "nvar",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:iota_dimension",
        const_cast<char **>(SHT_kwlist), &nvar))
        return nullptr;

    // post_parse
    SHD_values[0] = nvar;
    SHPy_values = reinterpret_cast<PyArrayObject *>
        (PyArray_SimpleNew(1, SHD_values, NPY_INT));
    if (SHPy_values == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "values must be a 1-D array of int");
        goto fail;
    }
    {
        // pre_call
        int * values = static_cast<int *>(PyArray_DATA(SHPy_values));

        iota_dimension(nvar, values);
        return (PyObject *) SHPy_values;
    }

fail:
    Py_XDECREF(SHPy_values);
    return nullptr;
// splicer end function.iota_dimension
}

// void Sum(int len +implied(size(values))+intent(in)+value, int * values +dimension(:)+intent(in), int * result +intent(out))
// ----------------------------------------
// Argument:  values
// Exact:     py_native_in_dimension_numpy
// ----------------------------------------
// Argument:  result
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
    PyObject * SHTPy_values;
    PyArrayObject * SHPy_values = nullptr;
    const char *SHT_kwlist[] = {
        "values",
        nullptr };
    PyObject * SHPy_result = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:Sum",
        const_cast<char **>(SHT_kwlist), &SHTPy_values))
        return nullptr;

    // post_parse
    SHPy_values = reinterpret_cast<PyArrayObject *>(PyArray_FROM_OTF(
        SHTPy_values, NPY_INT, NPY_ARRAY_IN_ARRAY));
    if (SHPy_values == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "values must be a 1-D array of int");
        goto fail;
    }
    {
        // pre_call
        int * values = static_cast<int *>(PyArray_DATA(SHPy_values));
        int result;  // intent(out)
        int len = PyArray_SIZE(SHPy_values);

        Sum(len, values, &result);

        // post_call
        SHPy_result = PyInt_FromLong(result);

        // cleanup
        Py_DECREF(SHPy_values);

        return (PyObject *) SHPy_result;
    }

fail:
    Py_XDECREF(SHPy_values);
    return nullptr;
// splicer end function.sum
}

// void fillIntArray(int * out +dimension(3)+intent(out))
// ----------------------------------------
// Argument:  out
// Exact:     py_native_out_dimension_numpy
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
    npy_intp SHD_out[1];
    PyArrayObject * SHPy_out = nullptr;

    // post_parse
    SHD_out[0] = 3;
    SHPy_out = reinterpret_cast<PyArrayObject *>
        (PyArray_SimpleNew(1, SHD_out, NPY_INT));
    if (SHPy_out == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "out must be a 1-D array of int");
        goto fail;
    }
    {
        // pre_call
        int * out = static_cast<int *>(PyArray_DATA(SHPy_out));

        fillIntArray(out);
        return (PyObject *) SHPy_out;
    }

fail:
    Py_XDECREF(SHPy_out);
    return nullptr;
// splicer end function.fill_int_array
}

// void incrementIntArray(int * array +dimension(:)+intent(inout), int sizein +implied(size(array))+intent(in)+value)
// ----------------------------------------
// Argument:  array
// Exact:     py_native_inout_dimension_numpy
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
    PyObject * SHTPy_array;
    PyArrayObject * SHPy_array = nullptr;
    const char *SHT_kwlist[] = {
        "array",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:incrementIntArray",
        const_cast<char **>(SHT_kwlist), &SHTPy_array))
        return nullptr;

    // post_parse
    SHPy_array = reinterpret_cast<PyArrayObject *>(PyArray_FROM_OTF(
        SHTPy_array, NPY_INT, NPY_ARRAY_INOUT_ARRAY));
    if (SHPy_array == nullptr) {
        PyErr_SetString(PyExc_ValueError,
            "array must be a 1-D array of int");
        goto fail;
    }
    {
        // pre_call
        int * array = static_cast<int *>(PyArray_DATA(SHPy_array));
        int sizein = PyArray_SIZE(SHPy_array);

        incrementIntArray(array, sizein);
        return (PyObject *) SHPy_array;
    }

fail:
    Py_XDECREF(SHPy_array);
    return nullptr;
// splicer end function.increment_int_array
}

// void acceptCharArrayIn(char * * names +dimension(:)+intent(in))
// ----------------------------------------
// Argument:  names
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
    char ** names = nullptr;
    PyObject * SHTPy_names;
    const char *SHT_kwlist[] = {
        "names",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:acceptCharArrayIn",
        const_cast<char **>(SHT_kwlist), &SHTPy_names))
        return nullptr;
    {
        // pre_call
        Py_ssize_t SHSize_names;
        if (SHROUD_create_from_PyObject_char(SHTPy_names, "names",
            &names,  &SHSize_names) == -1)
            goto fail;

        acceptCharArrayIn(names);

        // post_call
        std::free(names);
        names = nullptr;

        Py_RETURN_NONE;
    }

fail:
    if (names != nullptr) {
        std::free(names);
    }
    return nullptr;
// splicer end function.accept_char_array_in
}

// void setGlobalInt(int value +intent(in)+value)
// ----------------------------------------
// Argument:  value
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
    const char *SHT_kwlist[] = {
        "value",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:setGlobalInt",
        const_cast<char **>(SHT_kwlist), &value))
        return nullptr;

    setGlobalInt(value);
    Py_RETURN_NONE;
// splicer end function.set_global_int
}

// int sumFixedArray()
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
    PyObject * SHTPy_rv = nullptr;

    int SHCXX_rv = sumFixedArray();

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.sum_fixed_array
}

// void * returnAddress1(int flag +intent(in)+value)
// ----------------------------------------
// Argument:  flag
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
    const char *SHT_kwlist[] = {
        "flag",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:returnAddress1",
        const_cast<char **>(SHT_kwlist), &flag))
        return nullptr;

    void * SHCXX_rv = returnAddress1(flag);

    // post_call
    SHTPy_rv = PyCapsule_New(SHCXX_rv, NULL, NULL);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_address1
}

// void * returnAddress2(int flag +intent(in)+value)
// ----------------------------------------
// Argument:  flag
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
    const char *SHT_kwlist[] = {
        "flag",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i:returnAddress2",
        const_cast<char **>(SHT_kwlist), &flag))
        return nullptr;

    void * SHCXX_rv = returnAddress2(flag);

    // post_call
    SHTPy_rv = PyCapsule_New(SHCXX_rv, NULL, NULL);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_address2
}

// int * returnIntPtrToScalar()
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
    PyObject * SHTPy_rv = nullptr;

    int * SHCXX_rv = returnIntPtrToScalar();

    // post_call
    SHTPy_rv = PyArray_SimpleNewFromData(0, nullptr, NPY_INT, SHCXX_rv);
    if (SHTPy_rv == nullptr) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return nullptr;
// splicer end function.return_int_ptr_to_scalar
}

// int * returnIntPtrToFixedArray() +dimension(10)
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
    npy_intp SHD_rv[1];
    PyObject * SHTPy_rv = nullptr;

    int * SHCXX_rv = returnIntPtrToFixedArray();

    // post_call
    SHD_rv[0] = 10;
    SHTPy_rv = PyArray_SimpleNewFromData(1, SHD_rv, NPY_INT, SHCXX_rv);
    if (SHTPy_rv == nullptr) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return nullptr;
// splicer end function.return_int_ptr_to_fixed_array
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
{"returnAddress1", (PyCFunction)PY_returnAddress1,
    METH_VARARGS|METH_KEYWORDS, PY_returnAddress1__doc__},
{"returnAddress2", (PyCFunction)PY_returnAddress2,
    METH_VARARGS|METH_KEYWORDS, PY_returnAddress2__doc__},
{"returnIntPtrToScalar", (PyCFunction)PY_returnIntPtrToScalar,
    METH_NOARGS, PY_returnIntPtrToScalar__doc__},
{"returnIntPtrToFixedArray", (PyCFunction)PY_returnIntPtrToFixedArray,
    METH_NOARGS, PY_returnIntPtrToFixedArray__doc__},
{nullptr,   (PyCFunction)nullptr, 0, nullptr}            /* sentinel */
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
    nullptr, /* m_reload */
    pointers_traverse, /* m_traverse */
    pointers_clear, /* m_clear */
    NULL  /* m_free */
};

#define RETVAL m
#define INITERROR return nullptr
#else
#define RETVAL
#define INITERROR return
#endif

extern "C" PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
PyInit_pointers(void)
#else
initpointers(void)
#endif
{
    PyObject *m = nullptr;
    const char * error_name = "pointers.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("pointers", PY_methods,
        PY__doc__,
        (PyObject*)nullptr,PYTHON_API_VERSION);
#endif
    if (m == nullptr)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    import_array();

    PY_error_obj = PyErr_NewException((char *) error_name, nullptr, nullptr);
    if (PY_error_obj == nullptr)
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

