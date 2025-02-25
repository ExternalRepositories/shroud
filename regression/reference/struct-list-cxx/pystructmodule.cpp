// pystructmodule.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pystructmodule.hpp"
#define PY_ARRAY_UNIQUE_SYMBOL SHROUD_STRUCT_ARRAY_API
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"

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

// splicer begin C_definition
// splicer end C_definition
PyObject *PY_error_obj;
PyArray_Descr *PY_Cstruct1_array_descr;
PyArray_Descr *PY_Cstruct_ptr_array_descr;
PyArray_Descr *PY_Cstruct_list_array_descr;
PyArray_Descr *PY_Cstruct_numpy_array_descr;
PyArray_Descr *PY_Arrays1_array_descr;
// splicer begin additional_functions
// splicer end additional_functions

// ----------------------------------------
// Function:  int passStructByValue
// Attrs:     +intent(function)
// Requested: py_function_native_scalar
// Match:     py_default
// ----------------------------------------
// Argument:  Cstruct1 arg +value
// Attrs:     +intent(in)
// Exact:     py_in_struct_scalar_list
static char PY_passStructByValue__doc__[] =
"documentation"
;

static PyObject *
PY_passStructByValue(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.pass_struct_by_value
    PY_Cstruct1 * SHPy_arg;
    const char *SHT_kwlist[] = {
        "arg",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!:passStructByValue",
        const_cast<char **>(SHT_kwlist), &PY_Cstruct1_Type, &SHPy_arg))
        return nullptr;

    int SHCXX_rv = passStructByValue(arg);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.pass_struct_by_value
}

// ----------------------------------------
// Function:  int passStruct1
// Attrs:     +intent(function)
// Requested: py_function_native_scalar
// Match:     py_default
// ----------------------------------------
// Argument:  const Cstruct1 * arg
// Attrs:     +intent(in)
// Exact:     py_in_struct_*_list
static char PY_passStruct1__doc__[] =
"documentation"
;

static PyObject *
PY_passStruct1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.pass_struct1
    PY_Cstruct1 * SHPy_arg;
    const char *SHT_kwlist[] = {
        "arg",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!:passStruct1",
        const_cast<char **>(SHT_kwlist), &PY_Cstruct1_Type, &SHPy_arg))
        return nullptr;

    int SHCXX_rv = passStruct1(&arg);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.pass_struct1
}

// ----------------------------------------
// Function:  int passStruct2
// Attrs:     +intent(function)
// Requested: py_function_native_scalar
// Match:     py_default
// ----------------------------------------
// Argument:  const Cstruct1 * s1
// Attrs:     +intent(in)
// Exact:     py_in_struct_*_list
// ----------------------------------------
// Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)
// Attrs:     +intent(out)
// Exact:     py_out_char_*_charlen
static char PY_passStruct2__doc__[] =
"documentation"
;

/**
 * Pass name argument which will build a bufferify function.
 */
static PyObject *
PY_passStruct2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.pass_struct2
    PY_Cstruct1 * SHPy_s1;
    char outbuf[LENOUTBUF];  // intent(out)
    const char *SHT_kwlist[] = {
        "s1",
        nullptr };
    PyObject *SHTPy_rv = nullptr;  // return value object

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!:passStruct2",
        const_cast<char **>(SHT_kwlist), &PY_Cstruct1_Type, &SHPy_s1))
        return nullptr;

    int SHCXX_rv = passStruct2(&s1, outbuf);

    // post_call
    SHTPy_rv = Py_BuildValue("is", SHCXX_rv, outbuf);

    return SHTPy_rv;
// splicer end function.pass_struct2
}

// ----------------------------------------
// Function:  int acceptStructInPtr
// Attrs:     +intent(function)
// Requested: py_function_native_scalar
// Match:     py_default
// ----------------------------------------
// Argument:  Cstruct1 * arg +intent(in)
// Attrs:     +intent(in)
// Exact:     py_in_struct_*_list
static char PY_acceptStructInPtr__doc__[] =
"documentation"
;

static PyObject *
PY_acceptStructInPtr(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_struct_in_ptr
    PY_Cstruct1 * SHPy_arg;
    const char *SHT_kwlist[] = {
        "arg",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!:acceptStructInPtr",
        const_cast<char **>(SHT_kwlist), &PY_Cstruct1_Type, &SHPy_arg))
        return nullptr;

    int SHCXX_rv = acceptStructInPtr(&arg);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.accept_struct_in_ptr
}

// ----------------------------------------
// Function:  void acceptStructOutPtr
// Attrs:     +intent(subroutine)
// Exact:     py_default
// ----------------------------------------
// Argument:  Cstruct1 * arg +intent(out)
// Attrs:     +intent(out)
// Exact:     py_out_struct_*_list
// ----------------------------------------
// Argument:  int i +value
// Attrs:     +intent(in)
// Requested: py_in_native_scalar
// Match:     py_default
// ----------------------------------------
// Argument:  double d +value
// Attrs:     +intent(in)
// Requested: py_in_native_scalar
// Match:     py_default
static char PY_acceptStructOutPtr__doc__[] =
"documentation"
;

/**
 * Pass name argument which will build a bufferify function.
 */
static PyObject *
PY_acceptStructOutPtr(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_struct_out_ptr
    int i;
    double d;
    const char *SHT_kwlist[] = {
        "i",
        "d",
        nullptr };
    PY_Cstruct1 * SHPy_arg = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "id:acceptStructOutPtr", const_cast<char **>(SHT_kwlist), &i,
        &d))
        return nullptr;

    // post_declare
    Cstruct1 arg;

    acceptStructOutPtr(&arg, i, d);

    // post_call
    SHPy_arg = Py_BuildValue("O", arg);

    return (PyObject *) SHPy_arg;
// splicer end function.accept_struct_out_ptr
}

// ----------------------------------------
// Function:  void acceptStructInOutPtr
// Attrs:     +intent(subroutine)
// Exact:     py_default
// ----------------------------------------
// Argument:  Cstruct1 * arg +intent(inout)
// Attrs:     +intent(inout)
// Exact:     py_inout_struct_*_list
static char PY_acceptStructInOutPtr__doc__[] =
"documentation"
;

static PyObject *
PY_acceptStructInOutPtr(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_struct_in_out_ptr
    PY_Cstruct1 * SHPy_arg;
    const char *SHT_kwlist[] = {
        "arg",
        nullptr };
    PY_Cstruct1 * SHPy_arg = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "O!:acceptStructInOutPtr", const_cast<char **>(SHT_kwlist), 
        &PY_Cstruct1_Type, &SHPy_arg))
        return nullptr;

    acceptStructInOutPtr(&arg);

    // post_call
    SHPy_arg = Py_BuildValue("O", arg);

    return (PyObject *) SHPy_arg;
// splicer end function.accept_struct_in_out_ptr
}

// ----------------------------------------
// Function:  Cstruct1 returnStructByValue
// Attrs:     +intent(function)
// Requested: py_function_struct_list
// Match:     py_default
// ----------------------------------------
// Argument:  int i +value
// Attrs:     +intent(in)
// Requested: py_in_native_scalar
// Match:     py_default
// ----------------------------------------
// Argument:  double d +value
// Attrs:     +intent(in)
// Requested: py_in_native_scalar
// Match:     py_default
static char PY_returnStructByValue__doc__[] =
"documentation"
;

static PyObject *
PY_returnStructByValue(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.return_struct_by_value
    int i;
    double d;
    const char *SHT_kwlist[] = {
        "i",
        "d",
        nullptr };
    PY_Cstruct1 * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "id:returnStructByValue", const_cast<char **>(SHT_kwlist), &i,
        &d))
        return nullptr;

    Cstruct1 SHCXX_rv = returnStructByValue(i, d);

    // post_call
    SHTPy_rv = Py_BuildValue("O", SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_struct_by_value
}

// ----------------------------------------
// Function:  Cstruct1 * returnStructPtr1
// Attrs:     +deref(pointer)+intent(function)
// Requested: py_function_struct_list
// Match:     py_default
// ----------------------------------------
// Argument:  int i +value
// Attrs:     +intent(in)
// Requested: py_in_native_scalar
// Match:     py_default
// ----------------------------------------
// Argument:  double d +value
// Attrs:     +intent(in)
// Requested: py_in_native_scalar
// Match:     py_default
static char PY_returnStructPtr1__doc__[] =
"documentation"
;

/**
 * \brief Return a pointer to a struct
 *
 * Does not generate a bufferify C wrapper.
 */
static PyObject *
PY_returnStructPtr1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.return_struct_ptr1
    int i;
    double d;
    const char *SHT_kwlist[] = {
        "i",
        "d",
        nullptr };
    PY_Cstruct1 * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "id:returnStructPtr1",
        const_cast<char **>(SHT_kwlist), &i, &d))
        return nullptr;

    Cstruct1 * SHCXX_rv = returnStructPtr1(i, d);

    // post_call
    SHTPy_rv = Py_BuildValue("O", SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_struct_ptr1
}

// ----------------------------------------
// Function:  Cstruct1 * returnStructPtr2
// Attrs:     +deref(pointer)+intent(function)
// Requested: py_function_struct_list
// Match:     py_default
// ----------------------------------------
// Argument:  int i +value
// Attrs:     +intent(in)
// Requested: py_in_native_scalar
// Match:     py_default
// ----------------------------------------
// Argument:  double d +value
// Attrs:     +intent(in)
// Requested: py_in_native_scalar
// Match:     py_default
// ----------------------------------------
// Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)
// Attrs:     +intent(out)
// Exact:     py_out_char_*_charlen
static char PY_returnStructPtr2__doc__[] =
"documentation"
;

/**
 * \brief Return a pointer to a struct
 *
 * Generates a bufferify C wrapper function.
 */
static PyObject *
PY_returnStructPtr2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.return_struct_ptr2
    int i;
    double d;
    char outbuf[LENOUTBUF];  // intent(out)
    const char *SHT_kwlist[] = {
        "i",
        "d",
        nullptr };
    PyObject *SHPyResult = nullptr;  // return value object

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "id:returnStructPtr2",
        const_cast<char **>(SHT_kwlist), &i, &d))
        return nullptr;

    Cstruct1 * SHCXX_rv = returnStructPtr2(i, d, outbuf);

    // post_call
    SHPyResult = Py_BuildValue("Os", SHCXX_rv, outbuf);

    return SHPyResult;
// splicer end function.return_struct_ptr2
}

// ----------------------------------------
// Function:  Cstruct_list * get_global_struct_list
// Attrs:     +deref(pointer)+intent(function)
// Requested: py_function_struct_list
// Match:     py_default
static char PY_get_global_struct_list__doc__[] =
"documentation"
;

static PyObject *
PY_get_global_struct_list(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_global_struct_list
    PY_Cstruct_list * SHTPy_rv = nullptr;

    Cstruct_list * SHCXX_rv = get_global_struct_list();

    // post_call
    SHTPy_rv = Py_BuildValue("O", SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.get_global_struct_list
}
static PyMethodDef PY_methods[] = {
{"passStructByValue", (PyCFunction)PY_passStructByValue,
    METH_VARARGS|METH_KEYWORDS, PY_passStructByValue__doc__},
{"passStruct1", (PyCFunction)PY_passStruct1, METH_VARARGS|METH_KEYWORDS,
    PY_passStruct1__doc__},
{"passStruct2", (PyCFunction)PY_passStruct2, METH_VARARGS|METH_KEYWORDS,
    PY_passStruct2__doc__},
{"acceptStructInPtr", (PyCFunction)PY_acceptStructInPtr,
    METH_VARARGS|METH_KEYWORDS, PY_acceptStructInPtr__doc__},
{"acceptStructOutPtr", (PyCFunction)PY_acceptStructOutPtr,
    METH_VARARGS|METH_KEYWORDS, PY_acceptStructOutPtr__doc__},
{"acceptStructInOutPtr", (PyCFunction)PY_acceptStructInOutPtr,
    METH_VARARGS|METH_KEYWORDS, PY_acceptStructInOutPtr__doc__},
{"returnStructByValue", (PyCFunction)PY_returnStructByValue,
    METH_VARARGS|METH_KEYWORDS, PY_returnStructByValue__doc__},
{"returnStructPtr1", (PyCFunction)PY_returnStructPtr1,
    METH_VARARGS|METH_KEYWORDS, PY_returnStructPtr1__doc__},
{"returnStructPtr2", (PyCFunction)PY_returnStructPtr2,
    METH_VARARGS|METH_KEYWORDS, PY_returnStructPtr2__doc__},
{"get_global_struct_list", (PyCFunction)PY_get_global_struct_list,
    METH_NOARGS, PY_get_global_struct_list__doc__},
{nullptr,   (PyCFunction)nullptr, 0, nullptr}            /* sentinel */
};

// start PY_Cstruct1_create_array_descr
// Create PyArray_Descr for Cstruct1
static PyArray_Descr *PY_Cstruct1_create_array_descr()
{
    int ierr;
    PyObject *obj = nullptr;
    PyObject * lnames = nullptr;
    PyObject * ldescr = nullptr;
    PyObject * dict = nullptr;
    PyArray_Descr *dtype = nullptr;

    lnames = PyList_New(2);
    if (lnames == nullptr) goto fail;
    ldescr = PyList_New(2);
    if (ldescr == nullptr) goto fail;

    // ifield
    obj = PyString_FromString("ifield");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 0, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INT);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 0, obj);

    // dfield
    obj = PyString_FromString("dfield");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 1, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_DOUBLE);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 1, obj);
    obj = nullptr;

    dict = PyDict_New();
    if (dict == nullptr) goto fail;
    ierr = PyDict_SetItemString(dict, "names", lnames);
    if (ierr == -1) goto fail;
    lnames = nullptr;
    ierr = PyDict_SetItemString(dict, "formats", ldescr);
    if (ierr == -1) goto fail;
    ldescr = nullptr;
    ierr = PyArray_DescrAlignConverter(dict, &dtype);
    if (ierr == 0) goto fail;
    return dtype;
fail:
    Py_XDECREF(obj);
    if (lnames != nullptr) {
        for (int i=0; i < 2; i++) {
            Py_XDECREF(PyList_GET_ITEM(lnames, i));
        }
        Py_DECREF(lnames);
    }
    if (ldescr != nullptr) {
        for (int i=0; i < 2; i++) {
            Py_XDECREF(PyList_GET_ITEM(ldescr, i));
        }
        Py_DECREF(ldescr);
    }
    Py_XDECREF(dict);
    Py_XDECREF(dtype);
    return nullptr;
}
// end PY_Cstruct1_create_array_descr

// Create PyArray_Descr for Cstruct_ptr
static PyArray_Descr *PY_Cstruct_ptr_create_array_descr()
{
    int ierr;
    PyObject *obj = nullptr;
    PyObject * lnames = nullptr;
    PyObject * ldescr = nullptr;
    PyObject * dict = nullptr;
    PyArray_Descr *dtype = nullptr;

    lnames = PyList_New(2);
    if (lnames == nullptr) goto fail;
    ldescr = PyList_New(2);
    if (ldescr == nullptr) goto fail;

    // cfield
    obj = PyString_FromString("cfield");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 0, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INTP);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 0, obj);

    // const_dvalue
    obj = PyString_FromString("const_dvalue");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 1, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INTP);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 1, obj);
    obj = nullptr;

    dict = PyDict_New();
    if (dict == nullptr) goto fail;
    ierr = PyDict_SetItemString(dict, "names", lnames);
    if (ierr == -1) goto fail;
    lnames = nullptr;
    ierr = PyDict_SetItemString(dict, "formats", ldescr);
    if (ierr == -1) goto fail;
    ldescr = nullptr;
    ierr = PyArray_DescrAlignConverter(dict, &dtype);
    if (ierr == 0) goto fail;
    return dtype;
fail:
    Py_XDECREF(obj);
    if (lnames != nullptr) {
        for (int i=0; i < 2; i++) {
            Py_XDECREF(PyList_GET_ITEM(lnames, i));
        }
        Py_DECREF(lnames);
    }
    if (ldescr != nullptr) {
        for (int i=0; i < 2; i++) {
            Py_XDECREF(PyList_GET_ITEM(ldescr, i));
        }
        Py_DECREF(ldescr);
    }
    Py_XDECREF(dict);
    Py_XDECREF(dtype);
    return nullptr;
}

// Create PyArray_Descr for Cstruct_list
static PyArray_Descr *PY_Cstruct_list_create_array_descr()
{
    int ierr;
    PyObject *obj = nullptr;
    PyObject * lnames = nullptr;
    PyObject * ldescr = nullptr;
    PyObject * dict = nullptr;
    PyArray_Descr *dtype = nullptr;

    lnames = PyList_New(4);
    if (lnames == nullptr) goto fail;
    ldescr = PyList_New(4);
    if (ldescr == nullptr) goto fail;

    // nitems
    obj = PyString_FromString("nitems");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 0, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INT);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 0, obj);

    // ivalue
    obj = PyString_FromString("ivalue");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 1, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INTP);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 1, obj);

    // dvalue
    obj = PyString_FromString("dvalue");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 2, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INTP);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 2, obj);

    // svalue
    obj = PyString_FromString("svalue");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 3, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INTP);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 3, obj);
    obj = nullptr;

    dict = PyDict_New();
    if (dict == nullptr) goto fail;
    ierr = PyDict_SetItemString(dict, "names", lnames);
    if (ierr == -1) goto fail;
    lnames = nullptr;
    ierr = PyDict_SetItemString(dict, "formats", ldescr);
    if (ierr == -1) goto fail;
    ldescr = nullptr;
    ierr = PyArray_DescrAlignConverter(dict, &dtype);
    if (ierr == 0) goto fail;
    return dtype;
fail:
    Py_XDECREF(obj);
    if (lnames != nullptr) {
        for (int i=0; i < 4; i++) {
            Py_XDECREF(PyList_GET_ITEM(lnames, i));
        }
        Py_DECREF(lnames);
    }
    if (ldescr != nullptr) {
        for (int i=0; i < 4; i++) {
            Py_XDECREF(PyList_GET_ITEM(ldescr, i));
        }
        Py_DECREF(ldescr);
    }
    Py_XDECREF(dict);
    Py_XDECREF(dtype);
    return nullptr;
}

// Create PyArray_Descr for Cstruct_numpy
static PyArray_Descr *PY_Cstruct_numpy_create_array_descr()
{
    int ierr;
    PyObject *obj = nullptr;
    PyObject * lnames = nullptr;
    PyObject * ldescr = nullptr;
    PyObject * dict = nullptr;
    PyArray_Descr *dtype = nullptr;

    lnames = PyList_New(3);
    if (lnames == nullptr) goto fail;
    ldescr = PyList_New(3);
    if (ldescr == nullptr) goto fail;

    // nitems
    obj = PyString_FromString("nitems");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 0, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INT);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 0, obj);

    // ivalue
    obj = PyString_FromString("ivalue");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 1, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INTP);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 1, obj);

    // dvalue
    obj = PyString_FromString("dvalue");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 2, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INTP);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 2, obj);
    obj = nullptr;

    dict = PyDict_New();
    if (dict == nullptr) goto fail;
    ierr = PyDict_SetItemString(dict, "names", lnames);
    if (ierr == -1) goto fail;
    lnames = nullptr;
    ierr = PyDict_SetItemString(dict, "formats", ldescr);
    if (ierr == -1) goto fail;
    ldescr = nullptr;
    ierr = PyArray_DescrAlignConverter(dict, &dtype);
    if (ierr == 0) goto fail;
    return dtype;
fail:
    Py_XDECREF(obj);
    if (lnames != nullptr) {
        for (int i=0; i < 3; i++) {
            Py_XDECREF(PyList_GET_ITEM(lnames, i));
        }
        Py_DECREF(lnames);
    }
    if (ldescr != nullptr) {
        for (int i=0; i < 3; i++) {
            Py_XDECREF(PyList_GET_ITEM(ldescr, i));
        }
        Py_DECREF(ldescr);
    }
    Py_XDECREF(dict);
    Py_XDECREF(dtype);
    return nullptr;
}

// Create PyArray_Descr for Arrays1
static PyArray_Descr *PY_Arrays1_create_array_descr()
{
    int ierr;
    PyObject *obj = nullptr;
    PyObject * lnames = nullptr;
    PyObject * ldescr = nullptr;
    PyObject * dict = nullptr;
    PyArray_Descr *dtype = nullptr;

    lnames = PyList_New(2);
    if (lnames == nullptr) goto fail;
    ldescr = PyList_New(2);
    if (ldescr == nullptr) goto fail;

    // name
    obj = PyString_FromString("name");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 0, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INTP);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 0, obj);

    // count
    obj = PyString_FromString("count");
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(lnames, 1, obj);
    obj = (PyObject *) PyArray_DescrFromType(NPY_INT);
    if (obj == nullptr) goto fail;
    PyList_SET_ITEM(ldescr, 1, obj);
    obj = nullptr;

    dict = PyDict_New();
    if (dict == nullptr) goto fail;
    ierr = PyDict_SetItemString(dict, "names", lnames);
    if (ierr == -1) goto fail;
    lnames = nullptr;
    ierr = PyDict_SetItemString(dict, "formats", ldescr);
    if (ierr == -1) goto fail;
    ldescr = nullptr;
    ierr = PyArray_DescrAlignConverter(dict, &dtype);
    if (ierr == 0) goto fail;
    return dtype;
fail:
    Py_XDECREF(obj);
    if (lnames != nullptr) {
        for (int i=0; i < 2; i++) {
            Py_XDECREF(PyList_GET_ITEM(lnames, i));
        }
        Py_DECREF(lnames);
    }
    if (ldescr != nullptr) {
        for (int i=0; i < 2; i++) {
            Py_XDECREF(PyList_GET_ITEM(ldescr, i));
        }
        Py_DECREF(ldescr);
    }
    Py_XDECREF(dict);
    Py_XDECREF(dtype);
    return nullptr;
}

/*
 * initstruct - Initialization function for the module
 * *must* be called initstruct
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
static int struct_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int struct_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "struct", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    nullptr, /* m_reload */
    struct_traverse, /* m_traverse */
    struct_clear, /* m_clear */
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
PyInit_cstruct(void)
#else
initcstruct(void)
#endif
{
    PyObject *m = nullptr;
    const char * error_name = "struct.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("cstruct", PY_methods,
        PY__doc__,
        (PyObject*)nullptr,PYTHON_API_VERSION);
#endif
    if (m == nullptr)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    import_array();

    // Define PyArray_Descr for structs
    PY_Cstruct1_array_descr = PY_Cstruct1_create_array_descr();
    PyModule_AddObject(m, "Cstruct1_dtype", 
        (PyObject *) PY_Cstruct1_array_descr);
    PY_Cstruct_ptr_array_descr = PY_Cstruct_ptr_create_array_descr();
    PyModule_AddObject(m, "Cstruct_ptr_dtype", 
        (PyObject *) PY_Cstruct_ptr_array_descr);
    PY_Cstruct_list_array_descr = PY_Cstruct_list_create_array_descr();
    PyModule_AddObject(m, "Cstruct_list_dtype", 
        (PyObject *) PY_Cstruct_list_array_descr);
    PY_Cstruct_numpy_array_descr = PY_Cstruct_numpy_create_array_descr();
    PyModule_AddObject(m, "Cstruct_numpy_dtype", 
        (PyObject *) PY_Cstruct_numpy_array_descr);
    PY_Arrays1_array_descr = PY_Arrays1_create_array_descr();
    PyModule_AddObject(m, "Arrays1_dtype", 
        (PyObject *) PY_Arrays1_array_descr);

    PY_error_obj = PyErr_NewException((char *) error_name, nullptr, nullptr);
    if (PY_error_obj == nullptr)
        return RETVAL;
    st->error = PY_error_obj;
    PyModule_AddObject(m, "Error", st->error);

    // splicer begin C_init_body
    // splicer end C_init_body

    /* Check for errors */
    if (PyErr_Occurred())
        Py_FatalError("can't initialize module cstruct");
    return RETVAL;
}

