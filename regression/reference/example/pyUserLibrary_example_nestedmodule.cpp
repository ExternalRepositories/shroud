// pyUserLibrary_example_nestedmodule.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pyUserLibrarymodule.hpp"

// splicer begin namespace.example::nested.include
// splicer end namespace.example::nested.include

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

// splicer begin namespace.example::nested.C_definition
// splicer end namespace.example::nested.C_definition
// splicer begin namespace.example::nested.additional_functions
// splicer end namespace.example::nested.additional_functions

static char PP_local_function1__doc__[] =
"documentation"
;

static PyObject *
PP_local_function1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void local_function1()
// splicer begin namespace.example::nested.function.local_function1
    example::nested::local_function1();
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.local_function1
}

static char PP_isNameValid__doc__[] =
"documentation"
;

static PyObject *
PP_isNameValid(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// bool isNameValid(const std::string & name +intent(in))
// splicer begin namespace.example::nested.function.is_name_valid
    const char * name;
    const char *SHT_kwlist[] = {
        "name",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:isNameValid",
        const_cast<char **>(SHT_kwlist), &name))
        return NULL;

    // post_parse
    const std::string SH_name(name);

    bool SHCXX_rv = example::nested::isNameValid(SH_name);

    // post_call
    SHTPy_rv = PyBool_FromLong(SHCXX_rv);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end namespace.example::nested.function.is_name_valid
}

static char PP_isInitialized__doc__[] =
"documentation"
;

static PyObject *
PP_isInitialized(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// bool isInitialized()
// splicer begin namespace.example::nested.function.is_initialized
    PyObject * SHTPy_rv = NULL;

    bool SHCXX_rv = example::nested::isInitialized();

    // post_call
    SHTPy_rv = PyBool_FromLong(SHCXX_rv);
    if (SHTPy_rv == NULL) goto fail;

    return (PyObject *) SHTPy_rv;

fail:
    Py_XDECREF(SHTPy_rv);
    return NULL;
// splicer end namespace.example::nested.function.is_initialized
}

static PyObject *
PP_test_names(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void test_names(const std::string & name +intent(in))
// splicer begin namespace.example::nested.function.test_names
    const char * name;
    const char *SHT_kwlist[] = {
        "name",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:test_names",
        const_cast<char **>(SHT_kwlist), &name))
        return NULL;

    // post_parse
    const std::string SH_name(name);

    example::nested::test_names(SH_name);
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.test_names
}

static PyObject *
PP_test_names_flag(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void test_names(const std::string & name +intent(in), int flag +intent(in)+value)
// splicer begin namespace.example::nested.function.test_names_flag
    const char * name;
    int flag;
    const char *SHT_kwlist[] = {
        "name",
        "flag",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "si:test_names",
        const_cast<char **>(SHT_kwlist), &name, &flag))
        return NULL;

    // post_parse
    const std::string SH_name(name);

    example::nested::test_names(SH_name, flag);
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.test_names_flag
}

static char PP_testoptional_2__doc__[] =
"documentation"
;

static PyObject *
PP_testoptional_2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void testoptional(int i=1 +intent(in)+value, long j=2 +intent(in)+value)
// splicer begin namespace.example::nested.function.testoptional
    Py_ssize_t SH_nargs = 0;
    int i;
    long j;
    const char *SHT_kwlist[] = {
        "i",
        "j",
        NULL };

    if (args != NULL) SH_nargs += PyTuple_Size(args);
    if (kwds != NULL) SH_nargs += PyDict_Size(args);
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|il:testoptional",
        const_cast<char **>(SHT_kwlist), &i, &j))
        return NULL;
    switch (SH_nargs) {
    case 0:
        example::nested::testoptional();
        break;
    case 1:
        example::nested::testoptional(i);
        break;
    case 2:
        example::nested::testoptional(i, j);
        break;
    default:
        PyErr_SetString(PyExc_ValueError, "Wrong number of arguments");
        return NULL;
    }
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.testoptional
}

static char PP_test_size_t__doc__[] =
"documentation"
;

static PyObject *
PP_test_size_t(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// size_t test_size_t()
// splicer begin namespace.example::nested.function.test_size_t
    PyObject * SHTPy_rv = NULL;

    size_t SHCXX_rv = example::nested::test_size_t();

    // post_call
    SHTPy_rv = PyInt_FromSize_t(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end namespace.example::nested.function.test_size_t
}

#ifdef HAVE_MPI
static PyObject *
PP_testmpi_mpi(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void testmpi(MPI_Comm comm +intent(in)+value)
// splicer begin namespace.example::nested.function.testmpi_mpi
    MPI_Fint comm;
    const char *SHT_kwlist[] = {
        "comm",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:testmpi",
        const_cast<char **>(SHT_kwlist), &comm))
        return NULL;

    // post_parse
    MPI_Comm SH_comm = MPI_Comm_f2c(comm);

    example::nested::testmpi(SH_comm);
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.testmpi_mpi
}
#endif // ifdef HAVE_MPI

#ifndef HAVE_MPI
static PyObject *
PP_testmpi_serial(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void testmpi()
// splicer begin namespace.example::nested.function.testmpi_serial
    example::nested::testmpi();
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.testmpi_serial
}
#endif // ifndef HAVE_MPI

static char PP_FuncPtr1__doc__[] =
"documentation"
;

/**
 * \brief subroutine
 *
 */
static PyObject *
PP_FuncPtr1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void FuncPtr1(void ( * get)() +intent(in)+value)
// splicer begin namespace.example::nested.function.func_ptr1
    void ( * get)();
    const char *SHT_kwlist[] = {
        "get",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:FuncPtr1",
        const_cast<char **>(SHT_kwlist), &get))
        return NULL;

    example::nested::FuncPtr1(get);
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.func_ptr1
}

static char PP_FuncPtr2__doc__[] =
"documentation"
;

/**
 * \brief return a pointer
 *
 */
static PyObject *
PP_FuncPtr2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void FuncPtr2(double * ( * get)() +intent(in))
// splicer begin namespace.example::nested.function.func_ptr2
    double * ( * get)();
    const char *SHT_kwlist[] = {
        "get",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "d:FuncPtr2",
        const_cast<char **>(SHT_kwlist), &get))
        return NULL;

    example::nested::FuncPtr2(get);
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.func_ptr2
}

static char PP_FuncPtr3__doc__[] =
"documentation"
;

/**
 * \brief abstract argument
 *
 */
static PyObject *
PP_FuncPtr3(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void FuncPtr3(double ( * get)(int i +value, int +value) +intent(in)+value)
// splicer begin namespace.example::nested.function.func_ptr3
    double ( * get)(int i, int);
    const char *SHT_kwlist[] = {
        "get",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "d:FuncPtr3",
        const_cast<char **>(SHT_kwlist), &get))
        return NULL;

    example::nested::FuncPtr3(get);
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.func_ptr3
}

static char PP_FuncPtr5__doc__[] =
"documentation"
;

static PyObject *
PP_FuncPtr5(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void FuncPtr5(void ( * get)(int verylongname1 +value, int verylongname2 +value, int verylongname3 +value, int verylongname4 +value, int verylongname5 +value, int verylongname6 +value, int verylongname7 +value, int verylongname8 +value, int verylongname9 +value, int verylongname10 +value) +intent(in)+value)
// splicer begin namespace.example::nested.function.func_ptr5
    void ( * get)(int verylongname1, int verylongname2,
        int verylongname3, int verylongname4, int verylongname5,
        int verylongname6, int verylongname7, int verylongname8,
        int verylongname9, int verylongname10);
    const char *SHT_kwlist[] = {
        "get",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:FuncPtr5",
        const_cast<char **>(SHT_kwlist), &get))
        return NULL;

    example::nested::FuncPtr5(get);
    Py_RETURN_NONE;
// splicer end namespace.example::nested.function.func_ptr5
}

static char PP_verylongfunctionname1__doc__[] =
"documentation"
;

static PyObject *
PP_verylongfunctionname1(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void verylongfunctionname1(int * verylongname1 +intent(inout), int * verylongname2 +intent(inout), int * verylongname3 +intent(inout), int * verylongname4 +intent(inout), int * verylongname5 +intent(inout), int * verylongname6 +intent(inout), int * verylongname7 +intent(inout), int * verylongname8 +intent(inout), int * verylongname9 +intent(inout), int * verylongname10 +intent(inout))
// splicer begin namespace.example::nested.function.verylongfunctionname1
    int verylongname1;
    int verylongname2;
    int verylongname3;
    int verylongname4;
    int verylongname5;
    int verylongname6;
    int verylongname7;
    int verylongname8;
    int verylongname9;
    int verylongname10;
    const char *SHT_kwlist[] = {
        "verylongname1",
        "verylongname2",
        "verylongname3",
        "verylongname4",
        "verylongname5",
        "verylongname6",
        "verylongname7",
        "verylongname8",
        "verylongname9",
        "verylongname10",
        NULL };
    PyObject *SHTPy_rv = NULL;  // return value object

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "iiiiiiiiii:verylongfunctionname1",
        const_cast<char **>(SHT_kwlist), &verylongname1, &verylongname2,
        &verylongname3, &verylongname4, &verylongname5, &verylongname6,
        &verylongname7, &verylongname8, &verylongname9,
        &verylongname10))
        return NULL;

    example::nested::verylongfunctionname1(&verylongname1,
        &verylongname2, &verylongname3, &verylongname4, &verylongname5,
        &verylongname6, &verylongname7, &verylongname8, &verylongname9,
        &verylongname10);

    // post_call
    SHTPy_rv = Py_BuildValue("iiiiiiiiii", verylongname1, verylongname2,
        verylongname3, verylongname4, verylongname5, verylongname6,
        verylongname7, verylongname8, verylongname9, verylongname10);

    return SHTPy_rv;
// splicer end namespace.example::nested.function.verylongfunctionname1
}

static char PP_verylongfunctionname2__doc__[] =
"documentation"
;

static PyObject *
PP_verylongfunctionname2(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// int verylongfunctionname2(int verylongname1 +intent(in)+value, int verylongname2 +intent(in)+value, int verylongname3 +intent(in)+value, int verylongname4 +intent(in)+value, int verylongname5 +intent(in)+value, int verylongname6 +intent(in)+value, int verylongname7 +intent(in)+value, int verylongname8 +intent(in)+value, int verylongname9 +intent(in)+value, int verylongname10 +intent(in)+value)
// splicer begin namespace.example::nested.function.verylongfunctionname2
    int verylongname1;
    int verylongname2;
    int verylongname3;
    int verylongname4;
    int verylongname5;
    int verylongname6;
    int verylongname7;
    int verylongname8;
    int verylongname9;
    int verylongname10;
    const char *SHT_kwlist[] = {
        "verylongname1",
        "verylongname2",
        "verylongname3",
        "verylongname4",
        "verylongname5",
        "verylongname6",
        "verylongname7",
        "verylongname8",
        "verylongname9",
        "verylongname10",
        NULL };
    PyObject * SHTPy_rv = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "iiiiiiiiii:verylongfunctionname2",
        const_cast<char **>(SHT_kwlist), &verylongname1, &verylongname2,
        &verylongname3, &verylongname4, &verylongname5, &verylongname6,
        &verylongname7, &verylongname8, &verylongname9,
        &verylongname10))
        return NULL;

    int SHCXX_rv = example::nested::verylongfunctionname2(verylongname1,
        verylongname2, verylongname3, verylongname4, verylongname5,
        verylongname6, verylongname7, verylongname8, verylongname9,
        verylongname10);

    // post_call
    SHTPy_rv = PyInt_FromLong(SHCXX_rv);

    return (PyObject *) SHTPy_rv;
// splicer end namespace.example::nested.function.verylongfunctionname2
}

static char PP_cos_doubles__doc__[] =
"documentation"
;

/**
 * \brief Test multidimensional arrays with allocatable
 *
 */
static PyObject *
PP_cos_doubles(
  PyObject *SHROUD_UNUSED(self),
  PyObject *args,
  PyObject *kwds)
{
// void cos_doubles(double * in +dimension(:,:)+intent(in), double * out +allocatable(mold=in)+dimension(:,:)+intent(out), int sizein +implied(size(in))+intent(in)+value)
// splicer begin namespace.example::nested.function.cos_doubles
    PyObject * SHTPy_in;
    PyArrayObject * SHPy_in = NULL;
    PyArrayObject * SHPy_out = NULL;
    const char *SHT_kwlist[] = {
        "in",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:cos_doubles",
        const_cast<char **>(SHT_kwlist), &SHTPy_in))
        return NULL;

    // post_parse
    SHPy_in = reinterpret_cast<PyArrayObject *>(PyArray_FROM_OTF(
        SHTPy_in, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY));
    if (SHPy_in == NULL) {
        PyErr_SetString(PyExc_ValueError,
            "in must be a 1-D array of double");
        goto fail;
    }
    {
        // pre_call
        double * in = static_cast<double *>(PyArray_DATA(SHPy_in));
        SHPy_out = reinterpret_cast<PyArrayObject *>
            (PyArray_NewLikeArray(SHPy_in, NPY_CORDER, NULL, 0));
        if (SHPy_out == NULL)
            goto fail;
        double * out = static_cast<double *>(PyArray_DATA(SHPy_out));
        int sizein = PyArray_SIZE(SHPy_in);

        example::nested::cos_doubles(in, out, sizein);

        // cleanup
        Py_DECREF(SHPy_in);

        return (PyObject *) SHPy_out;
    }

fail:
    Py_XDECREF(SHPy_in);
    Py_XDECREF(SHPy_out);
    return NULL;
// splicer end namespace.example::nested.function.cos_doubles
}

static char PP_test_names__doc__[] =
"documentation"
;

static PyObject *
PP_test_names(
  PyObject *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin namespace.example::nested.function.test_names
    Py_ssize_t SHT_nargs = 0;
    if (args != NULL) SHT_nargs += PyTuple_Size(args);
    if (kwds != NULL) SHT_nargs += PyDict_Size(args);
    PyObject *rvobj;
    if (SHT_nargs == 1) {
        rvobj = PP_test_names(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    if (SHT_nargs == 2) {
        rvobj = PP_test_names_flag(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
    PyErr_SetString(PyExc_TypeError, "wrong arguments multi-dispatch");
    return NULL;
// splicer end namespace.example::nested.function.test_names
}

static char PP_testmpi__doc__[] =
"documentation"
;

static PyObject *
PP_testmpi(
  PyObject *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin namespace.example::nested.function.testmpi
    Py_ssize_t SHT_nargs = 0;
    if (args != NULL) SHT_nargs += PyTuple_Size(args);
    if (kwds != NULL) SHT_nargs += PyDict_Size(args);
    PyObject *rvobj;
#ifdef HAVE_MPI
    if (SHT_nargs == 1) {
        rvobj = PP_testmpi_mpi(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
#endif // ifdef HAVE_MPI
#ifndef HAVE_MPI
    if (SHT_nargs == 0) {
        rvobj = PP_testmpi_serial(self, args, kwds);
        if (!PyErr_Occurred()) {
            return rvobj;
        } else if (! PyErr_ExceptionMatches(PyExc_TypeError)) {
            return rvobj;
        }
        PyErr_Clear();
    }
#endif // ifndef HAVE_MPI
    PyErr_SetString(PyExc_TypeError, "wrong arguments multi-dispatch");
    return NULL;
// splicer end namespace.example::nested.function.testmpi
}
static PyMethodDef PP_methods[] = {
{"local_function1", (PyCFunction)PP_local_function1, METH_NOARGS,
    PP_local_function1__doc__},
{"isNameValid", (PyCFunction)PP_isNameValid, METH_VARARGS|METH_KEYWORDS,
    PP_isNameValid__doc__},
{"isInitialized", (PyCFunction)PP_isInitialized, METH_NOARGS,
    PP_isInitialized__doc__},
{"testoptional", (PyCFunction)PP_testoptional_2,
    METH_VARARGS|METH_KEYWORDS, PP_testoptional_2__doc__},
{"test_size_t", (PyCFunction)PP_test_size_t, METH_NOARGS,
    PP_test_size_t__doc__},
{"FuncPtr1", (PyCFunction)PP_FuncPtr1, METH_VARARGS|METH_KEYWORDS,
    PP_FuncPtr1__doc__},
{"FuncPtr2", (PyCFunction)PP_FuncPtr2, METH_VARARGS|METH_KEYWORDS,
    PP_FuncPtr2__doc__},
{"FuncPtr3", (PyCFunction)PP_FuncPtr3, METH_VARARGS|METH_KEYWORDS,
    PP_FuncPtr3__doc__},
{"FuncPtr5", (PyCFunction)PP_FuncPtr5, METH_VARARGS|METH_KEYWORDS,
    PP_FuncPtr5__doc__},
{"verylongfunctionname1", (PyCFunction)PP_verylongfunctionname1,
    METH_VARARGS|METH_KEYWORDS, PP_verylongfunctionname1__doc__},
{"verylongfunctionname2", (PyCFunction)PP_verylongfunctionname2,
    METH_VARARGS|METH_KEYWORDS, PP_verylongfunctionname2__doc__},
{"cos_doubles", (PyCFunction)PP_cos_doubles, METH_VARARGS|METH_KEYWORDS,
    PP_cos_doubles__doc__},
{"test_names", (PyCFunction)PP_test_names, METH_VARARGS|METH_KEYWORDS,
    PP_test_names__doc__},
{"testmpi", (PyCFunction)PP_testmpi, METH_VARARGS|METH_KEYWORDS,
    PP_testmpi__doc__},
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "userlibrary.example.nested", /* m_name */
    PP__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PP_methods, /* m_methods */
    NULL, /* m_reload */
//    userlibrary_traverse, /* m_traverse */
//    userlibrary_clear, /* m_clear */
    NULL, /* m_traverse */
    NULL, /* m_clear */
    NULL  /* m_free */
};
#endif
#define RETVAL NULL

PyObject *PP_init_userlibrary_example_nested(void)
{
    PyObject *m;
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule3((char *) "userlibrary.example.nested", PP_methods, NULL);
#endif
    if (m == NULL)
        return NULL;


    // ExClass1
    PP_ExClass1_Type.tp_new   = PyType_GenericNew;
    PP_ExClass1_Type.tp_alloc = PyType_GenericAlloc;
    if (PyType_Ready(&PP_ExClass1_Type) < 0)
        return RETVAL;
    Py_INCREF(&PP_ExClass1_Type);
    PyModule_AddObject(m, "ExClass1", (PyObject *)&PP_ExClass1_Type);

    // ExClass2
    PP_ExClass2_Type.tp_new   = PyType_GenericNew;
    PP_ExClass2_Type.tp_alloc = PyType_GenericAlloc;
    if (PyType_Ready(&PP_ExClass2_Type) < 0)
        return RETVAL;
    Py_INCREF(&PP_ExClass2_Type);
    PyModule_AddObject(m, "ExClass2", (PyObject *)&PP_ExClass2_Type);

    return m;
}

