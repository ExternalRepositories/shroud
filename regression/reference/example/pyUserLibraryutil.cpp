// pyUserLibraryutil.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// shroud
#include "pyUserLibrarymodule.hpp"

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

const char *PY_ExClass1_capsule_name = "ExClass1";
const char *PY_ExClass2_capsule_name = "ExClass2";


// Wrap pointer to struct/class.
PyObject *PP_ExClass1_to_Object_idtor(example::nested::ExClass1 *addr,
    int idtor)
{
    // splicer begin namespace.example::nested.class.ExClass1.utility.to_object
    PP_ExClass1 *obj = PyObject_New(PP_ExClass1, &PP_ExClass1_Type);
    if (obj == nullptr)
        return nullptr;
    obj->obj = addr;
    obj->idtor = idtor;
    return reinterpret_cast<PyObject *>(obj);
    // splicer end namespace.example::nested.class.ExClass1.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_ExClass1_to_Object(example::nested::ExClass1 *addr)
{
    // splicer begin namespace.example::nested.class.ExClass1.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_ExClass1_capsule_name, nullptr);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PP_ExClass1_Type, args, nullptr);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.example::nested.class.ExClass1.utility.to_object
}

// converter which may be used with PyArg_Parse.
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

// Wrap pointer to struct/class.
PyObject *PP_ExClass2_to_Object_idtor(example::nested::ExClass2 *addr,
    int idtor)
{
    // splicer begin namespace.example::nested.class.ExClass2.utility.to_object
    PP_ExClass2 *obj = PyObject_New(PP_ExClass2, &PP_ExClass2_Type);
    if (obj == nullptr)
        return nullptr;
    obj->obj = addr;
    obj->idtor = idtor;
    return reinterpret_cast<PyObject *>(obj);
    // splicer end namespace.example::nested.class.ExClass2.utility.to_object
}

// converter which may be used with PyBuild.
PyObject *PP_ExClass2_to_Object(example::nested::ExClass2 *addr)
{
    // splicer begin namespace.example::nested.class.ExClass2.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_ExClass2_capsule_name, nullptr);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PP_ExClass2_Type, args, nullptr);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.example::nested.class.ExClass2.utility.to_object
}

// converter which may be used with PyArg_Parse.
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
    {nullptr, nullptr},
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
