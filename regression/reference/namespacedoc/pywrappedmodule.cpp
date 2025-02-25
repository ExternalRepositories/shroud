// pywrappedmodule.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pywrappedmodule.hpp"

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
PyObject *PY_init_wrapped_inner1(void);
PyObject *PY_init_wrapped_inner2(void);
PyObject *PY_init_wrapped_inner4(void);
// splicer begin additional_functions
// splicer end additional_functions

// ----------------------------------------
// Function:  void worker3
// Attrs:     +intent(subroutine)
// Exact:     py_default
static char PY_worker3__doc__[] =
"documentation"
;

static PyObject *
PY_worker3(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.worker3
    outer::inner3::worker3();
    Py_RETURN_NONE;
// splicer end function.worker3
}

// ----------------------------------------
// Function:  void worker
// Attrs:     +intent(subroutine)
// Exact:     py_default
static char PY_worker__doc__[] =
"documentation"
;

static PyObject *
PY_worker(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// splicer begin function.worker
    outer::worker();
    Py_RETURN_NONE;
// splicer end function.worker
}
static PyMethodDef PY_methods[] = {
{"worker3", (PyCFunction)PY_worker3, METH_NOARGS, PY_worker3__doc__},
{"worker", (PyCFunction)PY_worker, METH_NOARGS, PY_worker__doc__},
{nullptr,   (PyCFunction)nullptr, 0, nullptr}            /* sentinel */
};

/*
 * initwrapped - Initialization function for the module
 * *must* be called initwrapped
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
static int wrapped_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int wrapped_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "wrapped", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    nullptr, /* m_reload */
    wrapped_traverse, /* m_traverse */
    wrapped_clear, /* m_clear */
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
PyInit_wrapped(void)
#else
initwrapped(void)
#endif
{
    PyObject *m = nullptr;
    const char * error_name = "wrapped.Error";

    // splicer begin C_init_locals
    // splicer end C_init_locals


    /* Create the module and add the functions */
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule4("wrapped", PY_methods,
        PY__doc__,
        (PyObject*)nullptr,PYTHON_API_VERSION);
#endif
    if (m == nullptr)
        return RETVAL;
    struct module_state *st = GETSTATE(m);

    {
        PyObject *submodule = PY_init_wrapped_inner1();
        if (submodule == nullptr)
            INITERROR;
        Py_INCREF(submodule);
        PyModule_AddObject(m, (char *) "inner1", submodule);
    }

    {
        PyObject *submodule = PY_init_wrapped_inner2();
        if (submodule == nullptr)
            INITERROR;
        Py_INCREF(submodule);
        PyModule_AddObject(m, (char *) "inner2", submodule);
    }

    {
        PyObject *submodule = PY_init_wrapped_inner4();
        if (submodule == nullptr)
            INITERROR;
        Py_INCREF(submodule);
        PyModule_AddObject(m, (char *) "inner4", submodule);
    }

    PY_error_obj = PyErr_NewException((char *) error_name, nullptr, nullptr);
    if (PY_error_obj == nullptr)
        return RETVAL;
    st->error = PY_error_obj;
    PyModule_AddObject(m, "Error", st->error);

    // splicer begin C_init_body
    // splicer end C_init_body

    /* Check for errors */
    if (PyErr_Occurred())
        Py_FatalError("can't initialize module wrapped");
    return RETVAL;
}

