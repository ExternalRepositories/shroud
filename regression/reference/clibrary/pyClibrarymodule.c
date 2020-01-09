// pyClibrarymodule.c
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pyClibrarymodule.h"
#include "clibrary.h"

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

// splicer begin C_definition
// splicer end C_definition
PyObject *PY_error_obj;
// splicer begin additional_functions
// splicer end additional_functions

static char PY_NoReturnNoArguments__doc__[] =
"documentation"
;

static PyObject *
PY_NoReturnNoArguments(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void NoReturnNoArguments()
// splicer begin function.no_return_no_arguments
    NoReturnNoArguments();
    Py_RETURN_NONE;
// splicer end function.no_return_no_arguments
}

static char PY_PassByValue__doc__[] =
"documentation"
;

static PyObject *
PY_PassByValue(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// double PassByValue(double arg1 +intent(in)+value, int arg2 +intent(in)+value)
// splicer begin function.pass_by_value
    double arg1;
    int arg2;
    char *SHT_kwlist[] = {
        "arg1",
        "arg2",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "di:PassByValue",
        SHT_kwlist, &arg1, &arg2))
        return NULL;

    double SHCXX_rv = PassByValue(arg1, arg2);

    // post_call
    SHTPy_rv = PyFloat_FromDouble(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.pass_by_value
}

static char PY_PassByReference__doc__[] =
"documentation"
;

static PyObject *
PY_PassByReference(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void PassByReference(double * arg1 +intent(in), int * arg2 +intent(out))
// splicer begin function.pass_by_reference
    double arg1;
    char *SHT_kwlist[] = {
        "arg1",
        NULL };
    PyObject * SHPy_arg2 = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "d:PassByReference",
        SHT_kwlist, &arg1))
        return NULL;

    // pre_call
    int arg2;  // intent(out)

    PassByReference(&arg1, &arg2);

    // post_call
    SHPy_arg2 = PyInt_FromLong(arg2);

    return (PyObject *) SHPy_arg2;
// splicer end function.pass_by_reference
}

static char PY_checkBool__doc__[] =
"documentation"
;

/**
 * \brief Check intent with bool
 *
 */
static PyObject *
PY_checkBool(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void checkBool(const bool arg1 +intent(in)+value, bool * arg2 +intent(out), bool * arg3 +intent(inout))
// splicer begin function.check_bool
    PyObject * SHPy_arg1;
    PyObject * SHPy_arg2 = NULL;
    PyObject * SHPy_arg3;
    char *SHT_kwlist[] = {
        "arg1",
        "arg3",
        NULL };
    PyObject *SHTPy_rv = NULL;  // return value object

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!O!:checkBool",
        SHT_kwlist, &PyBool_Type, &SHPy_arg1, &PyBool_Type, &SHPy_arg3))
        return NULL;

    // pre_call
    bool arg1 = PyObject_IsTrue(SHPy_arg1);
    bool arg2;  // intent(out)
    bool arg3 = PyObject_IsTrue(SHPy_arg3);

    checkBool(arg1, &arg2, &arg3);

    // post_call
    SHPy_arg2 = PyBool_FromLong(arg2);
    if (SHPy_arg2 == NULL) goto fail;
    SHPy_arg3 = PyBool_FromLong(arg3);
    if (SHPy_arg3 == NULL) goto fail;
    SHTPy_rv = Py_BuildValue("OO", SHPy_arg2, SHPy_arg3);

    return SHTPy_rv;

fail:
    Py_XDECREF(SHPy_arg2);
    Py_XDECREF(SHPy_arg3);
    return NULL;
// splicer end function.check_bool
}

static char PY_Function4a__doc__[] =
"documentation"
;

static PyObject *
PY_Function4a(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// char * Function4a(const char * arg1 +intent(in), const char * arg2 +intent(in)) +deref(result_as_arg)+len(30)
// splicer begin function.function4a
    const char * arg1;
    const char * arg2;
    char *SHT_kwlist[] = {
        "arg1",
        "arg2",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "ss:Function4a",
        SHT_kwlist, &arg1, &arg2))
        return NULL;

    char * SHCXX_rv = Function4a(arg1, arg2);

    // post_call
    SHTPy_rv = PyString_FromString(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.function4a
}

static char PY_acceptName__doc__[] =
"documentation"
;

static PyObject *
PY_acceptName(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void acceptName(const char * name +intent(in))
// splicer begin function.accept_name
    const char * name;
    char *SHT_kwlist[] = {
        "name",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:acceptName",
        SHT_kwlist, &name))
        return NULL;

    acceptName(name);
    Py_RETURN_NONE;
// splicer end function.accept_name
}

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
// void passCharPtrInOut(char * s +intent(inout))
// splicer begin function.pass_char_ptr_in_out
    char * s;
    char *SHT_kwlist[] = {
        "s",
        NULL };
    PyObject * SHPy_s = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:passCharPtrInOut",
        SHT_kwlist, &s))
        return NULL;

    passCharPtrInOut(s);

    // post_call
    SHPy_s = PyString_FromString(s);

    return (PyObject *) SHPy_s;
// splicer end function.pass_char_ptr_in_out
}

static char PY_returnOneName__doc__[] =
"documentation"
;

/**
 * \brief Test charlen attribute
 *
 * Each argument is assumed to be at least MAXNAME long.
 * This define is provided by the user.
 * The function will copy into the user provided buffer.
 */
static PyObject *
PY_returnOneName(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void returnOneName(char * name1 +charlen(MAXNAME)+intent(out))
// splicer begin function.return_one_name
    PyObject * SHPy_name1 = NULL;

    // pre_call
    char name1[MAXNAME];  // intent(out)

    returnOneName(name1);

    // post_call
    SHPy_name1 = PyString_FromString(name1);

    return (PyObject *) SHPy_name1;
// splicer end function.return_one_name
}

static char PY_returnTwoNames__doc__[] =
"documentation"
;

/**
 * \brief Test charlen attribute
 *
 * Each argument is assumed to be at least MAXNAME long.
 * This define is provided by the user.
 * The function will copy into the user provided buffer.
 */
static PyObject *
PY_returnTwoNames(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void returnTwoNames(char * name1 +charlen(MAXNAME)+intent(out), char * name2 +charlen(MAXNAME)+intent(out))
// splicer begin function.return_two_names
    PyObject *SHTPy_rv = NULL;  // return value object

    // pre_call
    char name1[MAXNAME];  // intent(out)
    char name2[MAXNAME];  // intent(out)

    returnTwoNames(name1, name2);

    // post_call
    SHTPy_rv = Py_BuildValue("ss", name1, name2);

    return SHTPy_rv;
// splicer end function.return_two_names
}

static char PY_ImpliedTextLen__doc__[] =
"documentation"
;

/**
 * \brief Fill text, at most ltext characters.
 *
 */
static PyObject *
PY_ImpliedTextLen(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void ImpliedTextLen(char * text +charlen(MAXNAME)+intent(out), int ltext +implied(len(text))+intent(in)+value)
// splicer begin function.implied_text_len
    PyObject * SHPy_text = NULL;

    // pre_call
    char text[MAXNAME];  // intent(out)
    int ltext = MAXNAME;

    ImpliedTextLen(text, ltext);

    // post_call
    SHPy_text = PyString_FromString(text);

    return (PyObject *) SHPy_text;
// splicer end function.implied_text_len
}

static char PY_ImpliedLen__doc__[] =
"documentation"
;

/**
 * \brief Return the implied argument - text length
 *
 * Pass the Fortran length of the char argument directy to the C function.
 * No need for the bufferify version which will needlessly copy the string.
 */
static PyObject *
PY_ImpliedLen(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// int ImpliedLen(const char * text +intent(in), int ltext +implied(len(text))+intent(in)+value, bool flag +implied(false)+intent(in)+value)
// splicer begin function.implied_len
    const char * text;
    char *SHT_kwlist[] = {
        "text",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:ImpliedLen",
        SHT_kwlist, &text))
        return NULL;

    // pre_call
    int ltext = strlen(text);
    bool flag = false;

    int SHCXX_rv = ImpliedLen(text, ltext, flag);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.implied_len
}

static char PY_ImpliedLenTrim__doc__[] =
"documentation"
;

/**
 * \brief Return the implied argument - text length
 *
 * Pass the Fortran length of the char argument directy to the C function.
 * No need for the bufferify version which will needlessly copy the string.
 */
static PyObject *
PY_ImpliedLenTrim(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// int ImpliedLenTrim(const char * text +intent(in), int ltext +implied(len_trim(text))+intent(in)+value, bool flag +implied(true)+intent(in)+value)
// splicer begin function.implied_len_trim
    const char * text;
    char *SHT_kwlist[] = {
        "text",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:ImpliedLenTrim",
        SHT_kwlist, &text))
        return NULL;

    // pre_call
    int ltext = strlen(text);
    bool flag = true;

    int SHCXX_rv = ImpliedLenTrim(text, ltext, flag);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end function.implied_len_trim
}

static char PY_ImpliedBoolTrue__doc__[] =
"documentation"
;

/**
 * \brief Single, implied bool argument
 *
 */
static PyObject *
PY_ImpliedBoolTrue(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// bool ImpliedBoolTrue(bool flag +implied(true)+intent(in)+value)
// splicer begin function.implied_bool_true
    PyObject * SHTPy_rv = NULL;

    // pre_call
    bool flag = true;

    bool SHCXX_rv = ImpliedBoolTrue(flag);

    // post_call
    SHTPy_rv = PyBool_FromLong(SHCXX_rv);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.implied_bool_true
}

static char PY_ImpliedBoolFalse__doc__[] =
"documentation"
;

/**
 * \brief Single, implied bool argument
 *
 */
static PyObject *
PY_ImpliedBoolFalse(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// bool ImpliedBoolFalse(bool flag +implied(false)+intent(in)+value)
// splicer begin function.implied_bool_false
    PyObject * SHTPy_rv = NULL;

    // pre_call
    bool flag = false;

    bool SHCXX_rv = ImpliedBoolFalse(flag);

    // post_call
    SHTPy_rv = PyBool_FromLong(SHCXX_rv);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end function.implied_bool_false
}
static PyMethodDef PY_methods[] = {
{"NoReturnNoArguments", (PyCFunction)PY_NoReturnNoArguments,
    METH_NOARGS, PY_NoReturnNoArguments__doc__},
{"PassByValue", (PyCFunction)PY_PassByValue, METH_VARARGS|METH_KEYWORDS,
    PY_PassByValue__doc__},
{"PassByReference", (PyCFunction)PY_PassByReference,
    METH_VARARGS|METH_KEYWORDS, PY_PassByReference__doc__},
{"checkBool", (PyCFunction)PY_checkBool, METH_VARARGS|METH_KEYWORDS,
    PY_checkBool__doc__},
{"Function4a", (PyCFunction)PY_Function4a, METH_VARARGS|METH_KEYWORDS,
    PY_Function4a__doc__},
{"acceptName", (PyCFunction)PY_acceptName, METH_VARARGS|METH_KEYWORDS,
    PY_acceptName__doc__},
{"passCharPtrInOut", (PyCFunction)PY_passCharPtrInOut,
    METH_VARARGS|METH_KEYWORDS, PY_passCharPtrInOut__doc__},
{"returnOneName", (PyCFunction)PY_returnOneName, METH_NOARGS,
    PY_returnOneName__doc__},
{"returnTwoNames", (PyCFunction)PY_returnTwoNames, METH_NOARGS,
    PY_returnTwoNames__doc__},
{"ImpliedTextLen", (PyCFunction)PY_ImpliedTextLen, METH_NOARGS,
    PY_ImpliedTextLen__doc__},
{"ImpliedLen", (PyCFunction)PY_ImpliedLen, METH_VARARGS|METH_KEYWORDS,
    PY_ImpliedLen__doc__},
{"ImpliedLenTrim", (PyCFunction)PY_ImpliedLenTrim,
    METH_VARARGS|METH_KEYWORDS, PY_ImpliedLenTrim__doc__},
{"ImpliedBoolTrue", (PyCFunction)PY_ImpliedBoolTrue, METH_NOARGS,
    PY_ImpliedBoolTrue__doc__},
{"ImpliedBoolFalse", (PyCFunction)PY_ImpliedBoolFalse, METH_NOARGS,
    PY_ImpliedBoolFalse__doc__},
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

/*
 * initclibrary - Initialization function for the module
 * *must* be called initclibrary
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
static int clibrary_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int clibrary_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "clibrary", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    NULL, /* m_reload */
    clibrary_traverse, /* m_traverse */
    clibrary_clear, /* m_clear */
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
PyInit_clibrary(void)
#else
initclibrary(void)
#endif
{
    PyObject *m = NULL;
    const char * error_name = "clibrary.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("clibrary", PY_methods,
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
        Py_FatalError("can't initialize module clibrary");
    return RETVAL;
}

