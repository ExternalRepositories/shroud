// pyUserLibraryutil.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pyUserLibrarymodule.hpp"

const char *PY_ExClass1_capsule_name = "ExClass1";
const char *PY_ExClass2_capsule_name = "ExClass2";


PyObject *PP_ExClass1_to_Object(example::nested::ExClass1 *addr)
{
    // splicer begin namespace.example::nested.class.ExClass1.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_ExClass1_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PP_ExClass1_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.example::nested.class.ExClass1.utility.to_object
}

int PP_ExClass1_from_Object(PyObject *obj, void **addr)
{
    // splicer begin namespace.example::nested.class.ExClass1.utility.from_object
    if (obj->ob_type != &PP_ExClass1_Type) {
        // raise exception
        return 0;
    }
    PP_ExClass1 * self = (PP_ExClass1 *) obj;
    *addr = self->obj;
    return 1;
    // splicer end namespace.example::nested.class.ExClass1.utility.from_object
}

PyObject *PP_ExClass2_to_Object(example::nested::ExClass2 *addr)
{
    // splicer begin namespace.example::nested.class.ExClass2.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_ExClass2_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PP_ExClass2_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.example::nested.class.ExClass2.utility.to_object
}

int PP_ExClass2_from_Object(PyObject *obj, void **addr)
{
    // splicer begin namespace.example::nested.class.ExClass2.utility.from_object
    if (obj->ob_type != &PP_ExClass2_Type) {
        // raise exception
        return 0;
    }
    PP_ExClass2 * self = (PP_ExClass2 *) obj;
    *addr = self->obj;
    return 1;
    // splicer end namespace.example::nested.class.ExClass2.utility.from_object
}

// ----------------------------------------
typedef struct {
    const char *name;
    void (*dtor)(void *ptr);
} PP_SHROUD_dtor_context;

// 0 - --none--
static void PP_SHROUD_capsule_destructor_0(void *ptr)
{
    // Do not release
}

// 1 - cxx example::nested::ExClass1 *
static void PP_SHROUD_capsule_destructor_1(void *ptr)
{
    example::nested::ExClass1 * cxx_ptr =
        static_cast<example::nested::ExClass1 *>(ptr);
    delete cxx_ptr;
}

// 2 - cxx example::nested::ExClass2 *
static void PP_SHROUD_capsule_destructor_2(void *ptr)
{
    example::nested::ExClass2 * cxx_ptr =
        static_cast<example::nested::ExClass2 *>(ptr);
    delete cxx_ptr;
}

// Code used to release arrays for NumPy objects
// via a Capsule base object with a destructor.
// Context strings
static PP_SHROUD_dtor_context PP_SHROUD_capsule_context[] = {
    {"--none--", PP_SHROUD_capsule_destructor_0},
    {"cxx example::nested::ExClass1 *", PP_SHROUD_capsule_destructor_1},
    {"cxx example::nested::ExClass2 *", PP_SHROUD_capsule_destructor_2},
    {NULL, NULL}
};

// Release memory based on icontext.
void PP_SHROUD_release_memory(int icontext, void *ptr)
{
    PP_SHROUD_capsule_context[icontext].dtor(ptr);
}

//Fetch garbage collection context.
void *PP_SHROUD_fetch_context(int icontext)
{
    return PP_SHROUD_capsule_context + icontext;
}

// destructor function for PyCapsule
void PP_SHROUD_capsule_destructor(PyObject *cap)
{
    void *ptr = PyCapsule_GetPointer(cap, "PP_array_dtor");
    PP_SHROUD_dtor_context * context = static_cast<PP_SHROUD_dtor_context *>
        (PyCapsule_GetContext(cap));
    context->dtor(ptr);
}
