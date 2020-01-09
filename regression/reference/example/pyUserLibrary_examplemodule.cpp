// pyUserLibrary_examplemodule.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pyUserLibrarymodule.hpp"

// splicer begin namespace.example.include
// splicer end namespace.example.include

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

// splicer begin namespace.example.C_definition
// splicer end namespace.example.C_definition
// splicer begin namespace.example.additional_functions
// splicer end namespace.example.additional_functions
static PyMethodDef PP_methods[] = {
{NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "userlibrary.example", /* m_name */
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

PyObject *PP_init_userlibrary_example(void)
{
    PyObject *m;
#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else
    m = Py_InitModule3((char *) "userlibrary.example", PP_methods, NULL);
#endif
    if (m == NULL)
        return NULL;


    {
        PyObject *submodule = PP_init_userlibrary_example_nested();
        if (submodule == NULL)
            INITERROR;
        Py_INCREF(submodule);
        PyModule_AddObject(m, (char *) "nested", submodule);
    }

    return m;
}

