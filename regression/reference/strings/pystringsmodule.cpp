// pystringsmodule.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pystringsmodule.hpp"
// shroud
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

// helper py_capsule_dtor
// Release memory in PyCapsule.
// Used with native arrays.
static void FREE_py_capsule_dtor(PyObject *obj)
{
    void *in = PyCapsule_GetPointer(obj, nullptr);
    if (in != nullptr) {
        std::free(in);
    }
}

// helper get_from_object_int_list
// Convert list of PyObject to array of int.
// Return 0 on error, 1 on success.
// Set Python exception on error.
static int SHROUD_get_from_object_int_list(PyObject *obj,
    STR_SHROUD_converter_value *value)
{
    PyObject *seq = PySequence_Fast(obj, "holder");
    if (seq == NULL) {
        PyErr_Format(PyExc_TypeError, "argument '%s' must be iterable",
            value->name);
        return 0;
    }
    Py_ssize_t size = PySequence_Fast_GET_SIZE(seq);
    int *in = static_cast<int *>(std::malloc(size * sizeof(int)));
    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PySequence_Fast_GET_ITEM(seq, i);
        int cvalue = PyInt_AsLong(item);
        if (PyErr_Occurred()) {
            std::free(in);
            Py_DECREF(seq);
            PyErr_Format(PyExc_TypeError,
                "argument '%s', index %d must be int", value->name,
                (int) i);
            return 0;
        }
        in[i] = cvalue;
    }
    Py_DECREF(seq);

    value->obj = nullptr;  // Do not save list object.
    value->dataobj = PyCapsule_New(in, nullptr, FREE_py_capsule_dtor);
    value->data = static_cast<int *>(in);
    value->size = size;
    return 1;
}

// splicer begin C_definition
// splicer end C_definition
PyObject *PY_error_obj;
// splicer begin additional_functions
// splicer end additional_functions

// ----------------------------------------
// Function:  void passChar
// Exact:     py_default
// ----------------------------------------
// Argument:  char status +intent(in)+value
// Exact:     py_char_scalar_in
static char PY_passChar__doc__[] =
"documentation"
;

/**
 * \brief pass a single char argument as a scalar.
 *
 */
static PyObject *
PY_passChar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.pass_char
    char *status;
    const char *SHT_kwlist[] = {
        "status",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:passChar",
        const_cast<char **>(SHT_kwlist), &status))
        return nullptr;

    passChar(status[0]);
    Py_RETURN_NONE;
// splicer end function.pass_char
}

// ----------------------------------------
// Function:  char returnChar
// Exact:     py_char_scalar_result
static char PY_returnChar__doc__[] =
"documentation"
;

/**
 * \brief return a char argument (non-pointer)
 *
 */
static PyObject *
PY_returnChar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_char
    PyObject * SHTPy_rv = nullptr;

    char SHCXX_rv = returnChar();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(&SHCXX_rv, 1);

    return (PyObject *) SHTPy_rv;
// splicer end function.return_char
}

// ----------------------------------------
// Function:  void passCharPtr
// Exact:     py_default
// ----------------------------------------
// Argument:  char * dest +charlen(40)+intent(out)
// Exact:     py_char_*_out_charlen
// ----------------------------------------
// Argument:  const char * src +intent(in)
// Exact:     py_char_*_in
static char PY_passCharPtr__doc__[] =
"documentation"
;

/**
 * \brief strcpy like behavior
 *
 * dest is marked intent(OUT) to override the intent(INOUT) default
 * This avoid a copy-in on dest.
 * In Python, src must not be over 40 characters, defined by charlen.
 */
static PyObject *
PY_passCharPtr(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.pass_char_ptr
    char dest[40];  // intent(out)
    char * src;
    const char *SHT_kwlist[] = {
        "src",
        nullptr };
    PyObject * SHPy_dest = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:passCharPtr",
        const_cast<char **>(SHT_kwlist), &src))
        return nullptr;

    passCharPtr(dest, src);

    // post_call
    SHPy_dest = PyString_FromString(dest);

    return (PyObject *) SHPy_dest;
// splicer end function.pass_char_ptr
}

// ----------------------------------------
// Function:  void passCharPtrInOut
// Exact:     py_default
// ----------------------------------------
// Argument:  char * s +intent(inout)
// Exact:     py_char_*_inout
static char PY_passCharPtrInOut__doc__[] =
"documentation"
;

/**
 * \brief toupper
 *
 * Change a string in-place.
 * For Python, return a new string since strings are immutable.
 */
static PyObject *
PY_passCharPtrInOut(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.pass_char_ptr_in_out
    char * s;
    const char *SHT_kwlist[] = {
        "s",
        nullptr };
    PyObject * SHPy_s = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:passCharPtrInOut",
        const_cast<char **>(SHT_kwlist), &s))
        return nullptr;

    passCharPtrInOut(s);

    // post_call
    SHPy_s = PyString_FromString(s);

    return (PyObject *) SHPy_s;
// splicer end function.pass_char_ptr_in_out
}

// ----------------------------------------
// Function:  const char * getCharPtr1 +deref(allocatable)
// Exact:     py_char_*_result
static char PY_getCharPtr1__doc__[] =
"documentation"
;

/**
 * \brief return a 'const char *' as character(*)
 *
 */
static PyObject *
PY_getCharPtr1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_char_ptr1
    PyObject * SHTPy_rv = nullptr;

    const char * SHCXX_rv = getCharPtr1();

    // post_call
    SHTPy_rv = PyString_FromString(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.get_char_ptr1
}

// ----------------------------------------
// Function:  const char * getCharPtr2 +deref(result-as-arg)+len(30)
// Exact:     py_char_*_result
static char PY_getCharPtr2__doc__[] =
"documentation"
;

/**
 * \brief return 'const char *' with fixed size (len=30)
 *
 */
static PyObject *
PY_getCharPtr2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_char_ptr2
    PyObject * SHTPy_rv = nullptr;

    const char * SHCXX_rv = getCharPtr2();

    // post_call
    SHTPy_rv = PyString_FromString(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.get_char_ptr2
}

// ----------------------------------------
// Function:  const char * getCharPtr3 +deref(result-as-arg)
// Exact:     py_char_*_result
static char PY_getCharPtr3__doc__[] =
"documentation"
;

/**
 * \brief return a 'const char *' as argument
 *
 */
static PyObject *
PY_getCharPtr3(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_char_ptr3
    PyObject * SHTPy_rv = nullptr;

    const char * SHCXX_rv = getCharPtr3();

    // post_call
    SHTPy_rv = PyString_FromString(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.get_char_ptr3
}

// ----------------------------------------
// Function:  const string getConstStringResult +deref(allocatable)
// Exact:     py_string_scalar_result
static char PY_getConstStringResult__doc__[] =
"documentation"
;

/**
 * \brief return an ALLOCATABLE CHARACTER from std::string
 *
 */
static PyObject *
PY_getConstStringResult(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_result
    PyObject * SHTPy_rv = nullptr;

    const std::string SHCXX_rv = getConstStringResult();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_result
}

// ----------------------------------------
// Function:  const string getConstStringLen +deref(result-as-arg)+len(30)
// Exact:     py_string_scalar_result
static char PY_getConstStringLen__doc__[] =
"documentation"
;

/**
 * \brief return a 'const string' as argument
 *
 */
static PyObject *
PY_getConstStringLen(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_len
    PyObject * SHTPy_rv = nullptr;

    const std::string SHCXX_rv = getConstStringLen();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_len
}

// ----------------------------------------
// Function:  const string getConstStringAsArg +deref(result-as-arg)
// Exact:     py_string_scalar_result
static char PY_getConstStringAsArg__doc__[] =
"documentation"
;

/**
 * \brief return a 'const string' as argument
 *
 */
static PyObject *
PY_getConstStringAsArg(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_as_arg
    PyObject * SHTPy_rv = nullptr;

    const std::string SHCXX_rv = getConstStringAsArg();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_as_arg
}

// ----------------------------------------
// Function:  const std::string getConstStringAlloc +deref(allocatable)
// Exact:     py_string_scalar_result
static char PY_getConstStringAlloc__doc__[] =
"documentation"
;

static PyObject *
PY_getConstStringAlloc(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_alloc
    PyObject * SHTPy_rv = nullptr;

    const std::string SHCXX_rv = getConstStringAlloc();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_alloc
}

// ----------------------------------------
// Function:  const string & getConstStringRefPure +deref(allocatable)
// Exact:     py_string_&_result
static char PY_getConstStringRefPure__doc__[] =
"documentation"
;

/**
 * \brief return a 'const string&' as ALLOCATABLE character
 *
 */
static PyObject *
PY_getConstStringRefPure(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_ref_pure
    PyObject * SHTPy_rv = nullptr;

    const std::string & SHCXX_rv = getConstStringRefPure();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_ref_pure
}

// ----------------------------------------
// Function:  const string & getConstStringRefLen +deref(result-as-arg)+len(30)
// Exact:     py_string_&_result
static char PY_getConstStringRefLen__doc__[] =
"documentation"
;

/**
 * \brief return 'const string&' with fixed size (len=30)
 *
 * Since +len(30) is provided, the result of the function
 * will be copied directly into memory provided by Fortran.
 * The function will not be ALLOCATABLE.
 */
static PyObject *
PY_getConstStringRefLen(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_ref_len
    PyObject * SHTPy_rv = nullptr;

    const std::string & SHCXX_rv = getConstStringRefLen();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_ref_len
}

// ----------------------------------------
// Function:  const string & getConstStringRefAsArg +deref(result-as-arg)
// Exact:     py_string_&_result
static char PY_getConstStringRefAsArg__doc__[] =
"documentation"
;

/**
 * \brief return a 'const string&' as argument
 *
 * Pass an additional argument which wil be used as the return value.
 * The length of the output variable is declared by the caller.
 */
static PyObject *
PY_getConstStringRefAsArg(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_ref_as_arg
    PyObject * SHTPy_rv = nullptr;

    const std::string & SHCXX_rv = getConstStringRefAsArg();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_ref_as_arg
}

// ----------------------------------------
// Function:  const string & getConstStringRefLenEmpty +deref(result-as-arg)+len(30)
// Exact:     py_string_&_result
static char PY_getConstStringRefLenEmpty__doc__[] =
"documentation"
;

/**
 * \brief Test returning empty string reference
 *
 */
static PyObject *
PY_getConstStringRefLenEmpty(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_ref_len_empty
    PyObject * SHTPy_rv = nullptr;

    const std::string & SHCXX_rv = getConstStringRefLenEmpty();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_ref_len_empty
}

// ----------------------------------------
// Function:  const std::string & getConstStringRefAlloc +deref(allocatable)
// Exact:     py_string_&_result
static char PY_getConstStringRefAlloc__doc__[] =
"documentation"
;

static PyObject *
PY_getConstStringRefAlloc(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_ref_alloc
    PyObject * SHTPy_rv = nullptr;

    const std::string & SHCXX_rv = getConstStringRefAlloc();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv.data(),
        SHCXX_rv.size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_ref_alloc
}

// ----------------------------------------
// Function:  const string * getConstStringPtrLen +deref(result-as-arg)+len(30)
// Exact:     py_string_*_result
static char PY_getConstStringPtrLen__doc__[] =
"documentation"
;

/**
 * \brief return a 'const string *' as character(30)
 *
 * It is the caller's responsibility to release the string
 * created by the C++ library.
 * This is accomplished with C_finalize_buf which is possible
 * because +len(30) so the contents are copied before returning.
 */
static PyObject *
PY_getConstStringPtrLen(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_ptr_len
    PyObject * SHTPy_rv = nullptr;

    const std::string * SHCXX_rv = getConstStringPtrLen();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv->data(),
        SHCXX_rv->size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_ptr_len
}

// ----------------------------------------
// Function:  const std::string * getConstStringPtrAlloc +deref(allocatable)+owner(library)
// Exact:     py_string_*_result
static char PY_getConstStringPtrAlloc__doc__[] =
"documentation"
;

static PyObject *
PY_getConstStringPtrAlloc(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_ptr_alloc
    PyObject * SHTPy_rv = nullptr;

    const std::string * SHCXX_rv = getConstStringPtrAlloc();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv->data(),
        SHCXX_rv->size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_ptr_alloc
}

// ----------------------------------------
// Function:  const std::string * getConstStringPtrOwnsAlloc +deref(allocatable)+owner(caller)
// Exact:     py_string_*_result
static char PY_getConstStringPtrOwnsAlloc__doc__[] =
"documentation"
;

/**
 * It is the caller's responsibility to release the string
 * created by the C++ library.
 * This is accomplished +owner(caller) which sets idtor.
 * The contents are copied by Fortran so they must outlast
 * the return from the C wrapper.
 */
static PyObject *
PY_getConstStringPtrOwnsAlloc(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_ptr_owns_alloc
    PyObject * SHTPy_rv = nullptr;

    const std::string * SHCXX_rv = getConstStringPtrOwnsAlloc();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv->data(),
        SHCXX_rv->size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_ptr_owns_alloc
}

// ----------------------------------------
// Function:  const std::string * getConstStringPtrOwnsAllocPattern +deref(allocatable)+free_pattern(C_string_free)+owner(caller)
// Exact:     py_string_*_result
static char PY_getConstStringPtrOwnsAllocPattern__doc__[] =
"documentation"
;

/**
 * Similar to getConstStringPtrOwnsAlloc, but uses pattern to release memory.
 */
static PyObject *
PY_getConstStringPtrOwnsAllocPattern(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.get_const_string_ptr_owns_alloc_pattern
    PyObject * SHTPy_rv = nullptr;

    const std::string * SHCXX_rv = getConstStringPtrOwnsAllocPattern();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(SHCXX_rv->data(),
        SHCXX_rv->size());

    return (PyObject *) SHTPy_rv;
// splicer end function.get_const_string_ptr_owns_alloc_pattern
}

// ----------------------------------------
// Function:  void acceptStringConstReference
// Exact:     py_default
// ----------------------------------------
// Argument:  const std::string & arg1 +intent(in)
// Exact:     py_string_&_in
static char PY_acceptStringConstReference__doc__[] =
"documentation"
;

/**
 * \brief Accept a const string reference
 *
 * Save contents of arg1.
 * arg1 is assumed to be intent(IN) since it is const
 * Will copy in.
 */
static PyObject *
PY_acceptStringConstReference(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_string_const_reference
    char * arg1;
    const char *SHT_kwlist[] = {
        "arg1",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "s:acceptStringConstReference",
        const_cast<char **>(SHT_kwlist), &arg1))
        return nullptr;

    // post_declare
    const std::string SH_arg1(arg1);

    acceptStringConstReference(SH_arg1);
    Py_RETURN_NONE;
// splicer end function.accept_string_const_reference
}

// ----------------------------------------
// Function:  void acceptStringReferenceOut
// Exact:     py_default
// ----------------------------------------
// Argument:  std::string & arg1 +intent(out)
// Exact:     py_string_&_out
static char PY_acceptStringReferenceOut__doc__[] =
"documentation"
;

/**
 * \brief Accept a string reference
 *
 * Set out to a constant string.
 * arg1 is intent(OUT)
 * Must copy out.
 */
static PyObject *
PY_acceptStringReferenceOut(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.accept_string_reference_out
    PyObject * SHPy_arg1 = nullptr;

    // post_declare
    std::string SH_arg1;

    acceptStringReferenceOut(SH_arg1);

    // post_call
    SHPy_arg1 = PyString_FromStringAndSize(SH_arg1.data(),
        SH_arg1.size());

    return (PyObject *) SHPy_arg1;
// splicer end function.accept_string_reference_out
}

// ----------------------------------------
// Function:  void acceptStringReference
// Exact:     py_default
// ----------------------------------------
// Argument:  std::string & arg1 +intent(inout)
// Exact:     py_string_&_inout
static char PY_acceptStringReference__doc__[] =
"documentation"
;

/**
 * \brief Accept a string reference
 *
 * Append "dog" to the end of arg1.
 * arg1 is assumed to be intent(INOUT)
 * Must copy in and copy out.
 */
static PyObject *
PY_acceptStringReference(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_string_reference
    char * arg1;
    const char *SHT_kwlist[] = {
        "arg1",
        nullptr };
    PyObject * SHPy_arg1 = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "s:acceptStringReference", const_cast<char **>(SHT_kwlist), 
        &arg1))
        return nullptr;

    // post_declare
    std::string SH_arg1(arg1);

    acceptStringReference(SH_arg1);

    // post_call
    SHPy_arg1 = PyString_FromStringAndSize(SH_arg1.data(),
        SH_arg1.size());

    return (PyObject *) SHPy_arg1;
// splicer end function.accept_string_reference
}

// ----------------------------------------
// Function:  void acceptStringPointerConst
// Exact:     py_default
// ----------------------------------------
// Argument:  const std::string * arg1 +intent(in)
// Exact:     py_string_*_in
static char PY_acceptStringPointerConst__doc__[] =
"documentation"
;

/**
 * \brief Accept a const string pointer - intent(in)
 *
 */
static PyObject *
PY_acceptStringPointerConst(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_string_pointer_const
    char * arg1;
    const char *SHT_kwlist[] = {
        "arg1",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "s:acceptStringPointerConst", const_cast<char **>(SHT_kwlist), 
        &arg1))
        return nullptr;

    // post_declare
    const std::string SH_arg1(arg1);

    acceptStringPointerConst(&SH_arg1);
    Py_RETURN_NONE;
// splicer end function.accept_string_pointer_const
}

// ----------------------------------------
// Function:  void acceptStringPointer
// Exact:     py_default
// ----------------------------------------
// Argument:  std::string * arg1 +intent(inout)
// Exact:     py_string_*_inout
static char PY_acceptStringPointer__doc__[] =
"documentation"
;

/**
 * \brief Accept a string pointer - intent(inout)
 *
 */
static PyObject *
PY_acceptStringPointer(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_string_pointer
    char * arg1;
    const char *SHT_kwlist[] = {
        "arg1",
        nullptr };
    PyObject * SHPy_arg1 = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "s:acceptStringPointer", const_cast<char **>(SHT_kwlist), 
        &arg1))
        return nullptr;

    // post_declare
    std::string SH_arg1(arg1);

    acceptStringPointer(&SH_arg1);

    // post_call
    SHPy_arg1 = PyString_FromStringAndSize(SH_arg1.data(),
        SH_arg1.size());

    return (PyObject *) SHPy_arg1;
// splicer end function.accept_string_pointer
}

// ----------------------------------------
// Function:  void fetchStringPointer
// Exact:     py_default
// ----------------------------------------
// Argument:  std::string * arg1 +intent(out)
// Exact:     py_string_*_out
static char PY_fetchStringPointer__doc__[] =
"documentation"
;

/**
 * \brief Accept a string pointer - intent(out)
 *
 * Return global_str.
 */
static PyObject *
PY_fetchStringPointer(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.fetch_string_pointer
    PyObject * SHPy_arg1 = nullptr;

    // post_declare
    std::string SH_arg1;

    fetchStringPointer(&SH_arg1);

    // post_call
    SHPy_arg1 = PyString_FromStringAndSize(SH_arg1.data(),
        SH_arg1.size());

    return (PyObject *) SHPy_arg1;
// splicer end function.fetch_string_pointer
}

// ----------------------------------------
// Function:  void acceptStringPointerLen
// Exact:     py_default
// ----------------------------------------
// Argument:  std::string * arg1 +intent(inout)
// Exact:     py_string_*_inout
// ----------------------------------------
// Argument:  int * nlen +intent(out)
// Exact:     py_native_*_out
static char PY_acceptStringPointerLen__doc__[] =
"documentation"
;

/**
 * \brief Accept a string pointer - intent(inout)
 *
 * Test return tuple with two arguments.
 * Must rename argument to nlen to avoid conflict with intrinsic len.
 */
static PyObject *
PY_acceptStringPointerLen(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_string_pointer_len
    char * arg1;
    int nlen;
    const char *SHT_kwlist[] = {
        "arg1",
        nullptr };
    PyObject *SHTPy_rv = nullptr;  // return value object

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "s:acceptStringPointerLen", const_cast<char **>(SHT_kwlist), 
        &arg1))
        return nullptr;

    // post_declare
    std::string SH_arg1(arg1);

    acceptStringPointerLen(&SH_arg1, &nlen);

    // post_call
    SHTPy_rv = Py_BuildValue("s#i", SH_arg1.data(), SH_arg1.size(),
        nlen);

    return SHTPy_rv;
// splicer end function.accept_string_pointer_len
}

// ----------------------------------------
// Function:  void fetchStringPointerLen
// Exact:     py_default
// ----------------------------------------
// Argument:  std::string * arg1 +intent(out)
// Exact:     py_string_*_out
// ----------------------------------------
// Argument:  int * nlen +intent(out)
// Exact:     py_native_*_out
static char PY_fetchStringPointerLen__doc__[] =
"documentation"
;

/**
 * \brief Accept a string pointer - intent(out)
 *
 * Return global_str.
 * Test return tuple with two arguments.
 * Must rename argument to nlen to avoid conflict with intrinsic len.
 */
static PyObject *
PY_fetchStringPointerLen(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.fetch_string_pointer_len
    int nlen;
    PyObject *SHTPy_rv = nullptr;  // return value object

    // post_declare
    std::string SH_arg1;

    fetchStringPointerLen(&SH_arg1, &nlen);

    // post_call
    SHTPy_rv = Py_BuildValue("s#i", SH_arg1.data(), SH_arg1.size(),
        nlen);

    return SHTPy_rv;
// splicer end function.fetch_string_pointer_len
}

// ----------------------------------------
// Function:  int acceptStringInstance
// Requested: py_native_scalar_result
// Match:     py_default
// ----------------------------------------
// Argument:  std::string arg1 +intent(in)+value
// Exact:     py_string_scalar_in
static char PY_acceptStringInstance__doc__[] =
"documentation"
;

/**
 * \brief Accept a string instance
 *
 */
static PyObject *
PY_acceptStringInstance(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.accept_string_instance
    char * arg1;
    const char *SHT_kwlist[] = {
        "arg1",
        nullptr };
    PyObject * SHTPy_rv = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "s:acceptStringInstance", const_cast<char **>(SHT_kwlist), 
        &arg1))
        return nullptr;

    // post_declare
    std::string SH_arg1(arg1);

    int SHCXX_rv = acceptStringInstance(SH_arg1);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.accept_string_instance
}

// ----------------------------------------
// Function:  void returnStrings
// Exact:     py_default
// ----------------------------------------
// Argument:  std::string & arg1 +intent(out)
// Exact:     py_string_&_out
// ----------------------------------------
// Argument:  std::string & arg2 +intent(out)
// Exact:     py_string_&_out
static char PY_returnStrings__doc__[] =
"documentation"
;

/**
 * \brief Test Python returning multiple std::string arguments.
 *
 */
static PyObject *
PY_returnStrings(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.return_strings
    PyObject *SHTPy_rv = nullptr;  // return value object

    // post_declare
    std::string SH_arg1;
    std::string SH_arg2;

    returnStrings(SH_arg1, SH_arg2);

    // post_call
    SHTPy_rv = Py_BuildValue("s#s#", SH_arg1.data(), SH_arg1.size(),
        SH_arg2.data(), SH_arg2.size());

    return SHTPy_rv;
// splicer end function.return_strings
}

// ----------------------------------------
// Function:  void explicit1
// Exact:     py_default
// ----------------------------------------
// Argument:  char * name +intent(in)+len_trim(AAlen)
// Exact:     py_char_*_in
static char PY_explicit1__doc__[] =
"documentation"
;

static PyObject *
PY_explicit1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.explicit1
    char * name;
    const char *SHT_kwlist[] = {
        "name",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:explicit1",
        const_cast<char **>(SHT_kwlist), &name))
        return nullptr;

    explicit1(name);
    Py_RETURN_NONE;
// splicer end function.explicit1
}

// ----------------------------------------
// Function:  void CpassChar
// Exact:     py_default
// ----------------------------------------
// Argument:  char status +intent(in)+value
// Exact:     py_char_scalar_in
static char PY_CpassChar__doc__[] =
"documentation"
;

/**
 * \brief pass a single char argument as a scalar, extern "C"
 *
 */
static PyObject *
PY_CpassChar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.cpass_char
    char *status;
    const char *SHT_kwlist[] = {
        "status",
        nullptr };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:CpassChar",
        const_cast<char **>(SHT_kwlist), &status))
        return nullptr;

    CpassChar(status[0]);
    Py_RETURN_NONE;
// splicer end function.cpass_char
}

// ----------------------------------------
// Function:  char CreturnChar
// Exact:     py_char_scalar_result
static char PY_CreturnChar__doc__[] =
"documentation"
;

/**
 * \brief return a char argument (non-pointer), extern "C"
 *
 */
static PyObject *
PY_CreturnChar(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.creturn_char
    PyObject * SHTPy_rv = nullptr;

    char SHCXX_rv = CreturnChar();

    // post_call
    SHTPy_rv = PyString_FromStringAndSize(&SHCXX_rv, 1);

    return (PyObject *) SHTPy_rv;
// splicer end function.creturn_char
}

// ----------------------------------------
// Function:  void PostDeclare
// Exact:     py_default
// ----------------------------------------
// Argument:  int * count +intent(in)+rank(1)
// Exact:     py_native_*_in_pointer_list
// ----------------------------------------
// Argument:  std::string & name +intent(inout)
// Exact:     py_string_&_inout
static char PY_PostDeclare__doc__[] =
"documentation"
;

static PyObject *
PY_PostDeclare(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// splicer begin function.post_declare
    int * count = nullptr;
    PyObject *SHTPy_count = nullptr;
    STR_SHROUD_converter_value SHValue_count = {NULL, NULL, NULL, NULL, 0};
    SHValue_count.name = "count";
    Py_ssize_t SHSize_count;
    char * name;
    const char *SHT_kwlist[] = {
        "count",
        "name",
        nullptr };
    PyObject * SHPy_name = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "Os:PostDeclare",
        const_cast<char **>(SHT_kwlist), &SHTPy_count, &name))
        return nullptr;

    // post_declare
    std::string SH_name(name);

    // post_parse
    if (SHROUD_get_from_object_int_list
        (SHTPy_count, &SHValue_count) == 0)
        goto fail;
    count = static_cast<int *>(SHValue_count.data);
    SHSize_count = SHValue_count.size;

    PostDeclare(count, SH_name);

    // post_call
    SHPy_name = PyString_FromStringAndSize(SH_name.data(),
        SH_name.size());

    // cleanup
    Py_XDECREF(SHValue_count.dataobj);

    return (PyObject *) SHPy_name;

fail:
    Py_XDECREF(SHValue_count.dataobj);
    return nullptr;
// splicer end function.post_declare
}
static PyMethodDef PY_methods[] = {
{"passChar", (PyCFunction)PY_passChar, METH_VARARGS|METH_KEYWORDS,
    PY_passChar__doc__},
{"returnChar", (PyCFunction)PY_returnChar, METH_NOARGS,
    PY_returnChar__doc__},
{"passCharPtr", (PyCFunction)PY_passCharPtr, METH_VARARGS|METH_KEYWORDS,
    PY_passCharPtr__doc__},
{"passCharPtrInOut", (PyCFunction)PY_passCharPtrInOut,
    METH_VARARGS|METH_KEYWORDS, PY_passCharPtrInOut__doc__},
{"getCharPtr1", (PyCFunction)PY_getCharPtr1, METH_NOARGS,
    PY_getCharPtr1__doc__},
{"getCharPtr2", (PyCFunction)PY_getCharPtr2, METH_NOARGS,
    PY_getCharPtr2__doc__},
{"getCharPtr3", (PyCFunction)PY_getCharPtr3, METH_NOARGS,
    PY_getCharPtr3__doc__},
{"getConstStringResult", (PyCFunction)PY_getConstStringResult,
    METH_NOARGS, PY_getConstStringResult__doc__},
{"getConstStringLen", (PyCFunction)PY_getConstStringLen, METH_NOARGS,
    PY_getConstStringLen__doc__},
{"getConstStringAsArg", (PyCFunction)PY_getConstStringAsArg,
    METH_NOARGS, PY_getConstStringAsArg__doc__},
{"getConstStringAlloc", (PyCFunction)PY_getConstStringAlloc,
    METH_NOARGS, PY_getConstStringAlloc__doc__},
{"getConstStringRefPure", (PyCFunction)PY_getConstStringRefPure,
    METH_NOARGS, PY_getConstStringRefPure__doc__},
{"getConstStringRefLen", (PyCFunction)PY_getConstStringRefLen,
    METH_NOARGS, PY_getConstStringRefLen__doc__},
{"getConstStringRefAsArg", (PyCFunction)PY_getConstStringRefAsArg,
    METH_NOARGS, PY_getConstStringRefAsArg__doc__},
{"getConstStringRefLenEmpty", (PyCFunction)PY_getConstStringRefLenEmpty,
    METH_NOARGS, PY_getConstStringRefLenEmpty__doc__},
{"getConstStringRefAlloc", (PyCFunction)PY_getConstStringRefAlloc,
    METH_NOARGS, PY_getConstStringRefAlloc__doc__},
{"getConstStringPtrLen", (PyCFunction)PY_getConstStringPtrLen,
    METH_NOARGS, PY_getConstStringPtrLen__doc__},
{"getConstStringPtrAlloc", (PyCFunction)PY_getConstStringPtrAlloc,
    METH_NOARGS, PY_getConstStringPtrAlloc__doc__},
{"getConstStringPtrOwnsAlloc",
    (PyCFunction)PY_getConstStringPtrOwnsAlloc, METH_NOARGS,
    PY_getConstStringPtrOwnsAlloc__doc__},
{"getConstStringPtrOwnsAllocPattern",
    (PyCFunction)PY_getConstStringPtrOwnsAllocPattern, METH_NOARGS,
    PY_getConstStringPtrOwnsAllocPattern__doc__},
{"acceptStringConstReference",
    (PyCFunction)PY_acceptStringConstReference,
    METH_VARARGS|METH_KEYWORDS, PY_acceptStringConstReference__doc__},
{"acceptStringReferenceOut", (PyCFunction)PY_acceptStringReferenceOut,
    METH_NOARGS, PY_acceptStringReferenceOut__doc__},
{"acceptStringReference", (PyCFunction)PY_acceptStringReference,
    METH_VARARGS|METH_KEYWORDS, PY_acceptStringReference__doc__},
{"acceptStringPointerConst", (PyCFunction)PY_acceptStringPointerConst,
    METH_VARARGS|METH_KEYWORDS, PY_acceptStringPointerConst__doc__},
{"acceptStringPointer", (PyCFunction)PY_acceptStringPointer,
    METH_VARARGS|METH_KEYWORDS, PY_acceptStringPointer__doc__},
{"fetchStringPointer", (PyCFunction)PY_fetchStringPointer, METH_NOARGS,
    PY_fetchStringPointer__doc__},
{"acceptStringPointerLen", (PyCFunction)PY_acceptStringPointerLen,
    METH_VARARGS|METH_KEYWORDS, PY_acceptStringPointerLen__doc__},
{"fetchStringPointerLen", (PyCFunction)PY_fetchStringPointerLen,
    METH_NOARGS, PY_fetchStringPointerLen__doc__},
{"acceptStringInstance", (PyCFunction)PY_acceptStringInstance,
    METH_VARARGS|METH_KEYWORDS, PY_acceptStringInstance__doc__},
{"returnStrings", (PyCFunction)PY_returnStrings, METH_NOARGS,
    PY_returnStrings__doc__},
{"explicit1", (PyCFunction)PY_explicit1, METH_VARARGS|METH_KEYWORDS,
    PY_explicit1__doc__},
{"CpassChar", (PyCFunction)PY_CpassChar, METH_VARARGS|METH_KEYWORDS,
    PY_CpassChar__doc__},
{"CreturnChar", (PyCFunction)PY_CreturnChar, METH_NOARGS,
    PY_CreturnChar__doc__},
{"PostDeclare", (PyCFunction)PY_PostDeclare, METH_VARARGS|METH_KEYWORDS,
    PY_PostDeclare__doc__},
{nullptr,   (PyCFunction)nullptr, 0, nullptr}            /* sentinel */
};

/*
 * initstrings - Initialization function for the module
 * *must* be called initstrings
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
static int strings_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int strings_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "strings", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    nullptr, /* m_reload */
    strings_traverse, /* m_traverse */
    strings_clear, /* m_clear */
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
PyInit_strings(void)
#else
initstrings(void)
#endif
{
    PyObject *m = nullptr;
    const char * error_name = "strings.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("strings", PY_methods,
        PY__doc__,
        (PyObject*)nullptr,PYTHON_API_VERSION);
#endif
    if (m == nullptr)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    PY_error_obj = PyErr_NewException((char *) error_name, nullptr, nullptr);
    if (PY_error_obj == nullptr)
        return RETVAL;
    st->error = PY_error_obj;
    PyModule_AddObject(m, "Error", st->error);

    // splicer begin C_init_body
    // splicer end C_init_body

    /* Check for errors */
    if (PyErr_Occurred())
        Py_FatalError("can't initialize module strings");
    return RETVAL;
}

