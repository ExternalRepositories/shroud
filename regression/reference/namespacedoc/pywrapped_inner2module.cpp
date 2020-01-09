// pywrapped_inner2module.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pywrappedmodule.hpp"

// splicer begin namespace.inner2.include
// splicer end namespace.inner2.include

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

// splicer begin namespace.inner2.C_definition
// splicer end namespace.inner2.C_definition
// splicer begin namespace.inner2.additional_functions
// splicer end namespace.inner2.additional_functions

static char PY_worker__doc__[] =
"documentation"
;

static PyObject *
PY_worker(
  PyObject *SHROUD_UNUSED(self),
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void worker()
// splicer begin namespace.inner2.function.worker
    outer::inner2::worker();
    Py_RETURN_NONE;
// splicer end namespace.inner2.function.worker
}
static PyMethodDef PY_methods[] = {
{"worker", (PyCFunction)PY_worker, METH_NOARGS, PY_worker__doc__},
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "wrapped.inner2", /* m_name */
    PY__doc__, /* m_doc */
    sizeof(struct module_state), /* m_size */
    PY_methods, /* m_methods */
    NULL, /* m_reload */
//    wrapped_traverse, /* m_traverse */
//    wrapped_clear, /* m_clear */
    NULL, /* m_traverse */
    NULL, /* m_clear */
    NULL  /* m_free */
};
#endif
#define RETVAL NULL

PyObject *PY_init_wrapped_inner2(void)
{
    PyObject *m;
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule3((char *) "wrapped.inner2", PY_methods, NULL);
#endif
    if (m == NULL)
        return NULL;


    return m;
}

