// pystructmodule.h
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#ifndef PYSTRUCTMODULE_H
#define PYSTRUCTMODULE_H
#include <Python.h>
#include "struct.h"
// splicer begin header.include
// splicer end header.include

// utility functions
extern void PY_SHROUD_release_memory(int icontext, void *ptr);
extern void *PY_SHROUD_fetch_context(int icontext);
extern void PY_SHROUD_capsule_destructor(PyObject *cap);

// ------------------------------
extern PyTypeObject PY_Cstruct_as_class_Type;
// splicer begin class.Cstruct_as_class.C_declaration
// splicer end class.Cstruct_as_class.C_declaration

typedef struct {
PyObject_HEAD
    Cstruct_as_class * obj;
    int idtor;
    // splicer begin class.Cstruct_as_class.C_object
    // splicer end class.Cstruct_as_class.C_object
} PY_Cstruct_as_class;

extern const char *PY_Cstruct_as_class_capsule_name;
PyObject *PP_Cstruct_as_class_to_Object(Cstruct_as_class *addr);
int PP_Cstruct_as_class_from_Object(PyObject *obj, void **addr);
// ------------------------------

// splicer begin header.C_declaration
// splicer end header.C_declaration

extern PyObject *PY_error_obj;

#if PY_MAJOR_VERSION >= 3
PyMODINIT_FUNC PyInit_cstruct(void);
#else
PyMODINIT_FUNC initcstruct(void);
#endif

#endif  /* PYSTRUCTMODULE_H */
