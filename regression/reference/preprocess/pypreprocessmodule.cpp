// pypreprocessmodule.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pypreprocessmodule.hpp"
#include "preprocess.hpp"

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
static PyMethodDef PY_methods[] = {
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

/*
 * initpreprocess - Initialization function for the module
 * *must* be called initpreprocess
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
static int preprocess_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int preprocess_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "preprocess", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    NULL, /* m_reload */
    preprocess_traverse, /* m_traverse */
    preprocess_clear, /* m_clear */
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
PyInit_preprocess(void)
#else
initpreprocess(void)
#endif
{
    PyObject *m = NULL;
    const char * error_name = "preprocess.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("preprocess", PY_methods,
        PY__doc__,
        (PyObject*)NULL,PYTHON_API_VERSION);
#endif
    if (m == NULL)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    // User1
    PY_User1_Type.tp_new   = PyType_GenericNew;
    PY_User1_Type.tp_alloc = PyType_GenericAlloc;
    if (PyType_Ready(&PY_User1_Type) < 0)
        return RETVAL;
    Py_INCREF(&PY_User1_Type);
    PyModule_AddObject(m, "User1", (PyObject *)&PY_User1_Type);

#ifdef USE_USER2
    // User2
    PY_User2_Type.tp_new   = PyType_GenericNew;
    PY_User2_Type.tp_alloc = PyType_GenericAlloc;
    if (PyType_Ready(&PY_User2_Type) < 0)
        return RETVAL;
    Py_INCREF(&PY_User2_Type);
    PyModule_AddObject(m, "User2", (PyObject *)&PY_User2_Type);
#endif // ifdef USE_USER2

    PY_error_obj = PyErr_NewException((char *) error_name, NULL, NULL);
    if (PY_error_obj == NULL)
        return RETVAL;
    st->error = PY_error_obj;
    PyModule_AddObject(m, "Error", st->error);

    // splicer begin C_init_body
    // splicer end C_init_body

    /* Check for errors */
    if (PyErr_Occurred())
        Py_FatalError("can't initialize module preprocess");
    return RETVAL;
}

