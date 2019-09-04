// pyUserLibrarymodule.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC.
//
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-738041.
//
// All rights reserved.
//
// This file is part of Shroud.
//
// For details about use and distribution, please read LICENSE.
//
// #######################################################################
#include "pyUserLibrarymodule.hpp"
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
#define PyString_FromString PyUnicode_FromString
#define PyString_FromStringAndSize PyUnicode_FromStringAndSize
#endif

// splicer begin C_definition
// splicer end C_definition
PyObject *PP_error_obj;
PyObject *PP_init_userlibrary_example_nested(void);
PyObject *PP_init_userlibrary_example(void);
// splicer begin additional_functions
// splicer end additional_functions
static PyMethodDef PP_methods[] = {
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

/*
 * inituserlibrary - Initialization function for the module
 * *must* be called inituserlibrary
 */
static char PP__doc__[] =
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
static int userlibrary_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int userlibrary_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "userlibrary", /* m_name */
    PP__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PP_methods, /* m_methods */
    NULL, /* m_reload */
    userlibrary_traverse, /* m_traverse */
    userlibrary_clear, /* m_clear */
    NULL  /* m_free */
};

#define RETVAL m
#define INITERROR return NULL
#else
#define RETVAL
#define INITERROR return
#endif

extern "C" PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
PyInit_userlibrary(void)
#else
inituserlibrary(void)
#endif
{
    PyObject *m = NULL;
    const char * error_name = "userlibrary.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("userlibrary", PP_methods,
        PP__doc__,
        (PyObject*)NULL,PYTHON_API_VERSION);
#endif
    if (m == NULL)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    import_array();

    {
        PyObject *submodule = PP_init_userlibrary_example();
        if (submodule == NULL)
            INITERROR;
        Py_INCREF(submodule);
        PyModule_AddObject(m, (char *) "example", submodule);
    }

    PP_error_obj = PyErr_NewException((char *) error_name, NULL, NULL);
    if (PP_error_obj == NULL)
        return RETVAL;
    st->error = PP_error_obj;
    PyModule_AddObject(m, "Error", st->error);

    // splicer begin C_init_body
    // splicer end C_init_body

    /* Check for errors */
    if (PyErr_Occurred())
        Py_FatalError("can't initialize module userlibrary");
    return RETVAL;
}
