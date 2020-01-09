// pytestnamesutil.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pytestnamesmodule.hpp"
const char *PY_Names_capsule_name = "Names";
const char *PY_Vvv1_capsule_name = "Vvv1";
const char *PY_vector_double_capsule_name = "vector_double";
const char *PY_vector_instantiation5_capsule_name = "vector_instantiation5";
const char *PY_vector_instantiation3_capsule_name = "vector_instantiation3";
const char *PY_Names2_capsule_name = "Names2";
const char *PY_twoTs_0_capsule_name = "twoTs_0";
const char *PY_twoTs_instantiation4_capsule_name = "twoTs_instantiation4";


PyObject *PP_Names_to_Object(ns0::Names *addr)
{
    // splicer begin namespace.ns0.class.Names.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_Names_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_Names_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.ns0.class.Names.utility.to_object
}

int PP_Names_from_Object(PyObject *obj, void **addr)
{
    // splicer begin namespace.ns0.class.Names.utility.from_object
    if (obj->ob_type != &PY_Names_Type) {
        // raise exception
        return 0;
    }
    PY_Names * self = (PY_Names *) obj;
    *addr = self->myobj;
    return 1;
    // splicer end namespace.ns0.class.Names.utility.from_object
}

PyObject *PP_Vvv1_to_Object(std::Vvv1 *addr)
{
    // splicer begin namespace.std.class.vector.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_Vvv1_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_Vvv1_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.std.class.vector.utility.to_object
}

int PP_Vvv1_from_Object(PyObject *obj, void **addr)
{
    // splicer begin namespace.std.class.vector.utility.from_object
    if (obj->ob_type != &PY_Vvv1_Type) {
        // raise exception
        return 0;
    }
    PY_Vvv1 * self = (PY_Vvv1 *) obj;
    *addr = self->myobj;
    return 1;
    // splicer end namespace.std.class.vector.utility.from_object
}

PyObject *PP_vector_double_to_Object(std::vector_double *addr)
{
    // splicer begin namespace.std.class.vector.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_vector_double_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_vector_double_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.std.class.vector.utility.to_object
}

int PP_vector_double_from_Object(PyObject *obj, void **addr)
{
    // splicer begin namespace.std.class.vector.utility.from_object
    if (obj->ob_type != &PY_vector_double_Type) {
        // raise exception
        return 0;
    }
    PY_vector_double * self = (PY_vector_double *) obj;
    *addr = self->myobj;
    return 1;
    // splicer end namespace.std.class.vector.utility.from_object
}

PyObject *PP_vector_instantiation5_to_Object(std::vector_instantiation5 *addr)
{
    // splicer begin namespace.std.class.vector.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_vector_instantiation5_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_vector_instantiation5_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.std.class.vector.utility.to_object
}

int PP_vector_instantiation5_from_Object(PyObject *obj, void **addr)
{
    // splicer begin namespace.std.class.vector.utility.from_object
    if (obj->ob_type != &PY_vector_instantiation5_Type) {
        // raise exception
        return 0;
    }
    PY_vector_instantiation5 * self = (PY_vector_instantiation5 *) obj;
    *addr = self->myobj;
    return 1;
    // splicer end namespace.std.class.vector.utility.from_object
}

PyObject *PP_vector_instantiation3_to_Object(std::vector_instantiation3 *addr)
{
    // splicer begin namespace.std.class.vector.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_vector_instantiation3_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_vector_instantiation3_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end namespace.std.class.vector.utility.to_object
}

int PP_vector_instantiation3_from_Object(PyObject *obj, void **addr)
{
    // splicer begin namespace.std.class.vector.utility.from_object
    if (obj->ob_type != &PY_vector_instantiation3_Type) {
        // raise exception
        return 0;
    }
    PY_vector_instantiation3 * self = (PY_vector_instantiation3 *) obj;
    *addr = self->myobj;
    return 1;
    // splicer end namespace.std.class.vector.utility.from_object
}

PyObject *PP_Names2_to_Object(Names2 *addr)
{
    // splicer begin class.Names2.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_Names2_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_Names2_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end class.Names2.utility.to_object
}

int PP_Names2_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.Names2.utility.from_object
    if (obj->ob_type != &PY_Names2_Type) {
        // raise exception
        return 0;
    }
    PY_Names2 * self = (PY_Names2 *) obj;
    *addr = self->myobj;
    return 1;
    // splicer end class.Names2.utility.from_object
}

PyObject *PP_twoTs_0_to_Object(twoTs_0 *addr)
{
    // splicer begin class.twoTs.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_twoTs_0_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_twoTs_0_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end class.twoTs.utility.to_object
}

int PP_twoTs_0_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.twoTs.utility.from_object
    if (obj->ob_type != &PY_twoTs_0_Type) {
        // raise exception
        return 0;
    }
    PY_twoTs_0 * self = (PY_twoTs_0 *) obj;
    *addr = self->myobj;
    return 1;
    // splicer end class.twoTs.utility.from_object
}

PyObject *PP_twoTs_instantiation4_to_Object(twoTs_instantiation4 *addr)
{
    // splicer begin class.twoTs.utility.to_object
    PyObject *voidobj;
    PyObject *args;
    PyObject *rv;

    voidobj = PyCapsule_New(addr, PY_twoTs_instantiation4_capsule_name, NULL);
    args = PyTuple_New(1);
    PyTuple_SET_ITEM(args, 0, voidobj);
    rv = PyObject_Call((PyObject *) &PY_twoTs_instantiation4_Type, args, NULL);
    Py_DECREF(args);
    return rv;
    // splicer end class.twoTs.utility.to_object
}

int PP_twoTs_instantiation4_from_Object(PyObject *obj, void **addr)
{
    // splicer begin class.twoTs.utility.from_object
    if (obj->ob_type != &PY_twoTs_instantiation4_Type) {
        // raise exception
        return 0;
    }
    PY_twoTs_instantiation4 * self = (PY_twoTs_instantiation4 *) obj;
    *addr = self->myobj;
    return 1;
    // splicer end class.twoTs.utility.from_object
}

// ----------------------------------------
typedef struct {
    const char *name;
    void (*dtor)(void *ptr);
} PY_SHROUD_dtor_context;

// 0 - --none--
static void PY_SHROUD_capsule_destructor_0(void *ptr)
{
    // Do not release
}

// Code used to release arrays for NumPy objects
// via a Capsule base object with a destructor.
// Context strings
static PY_SHROUD_dtor_context PY_SHROUD_capsule_context[] = {
    {"--none--", PY_SHROUD_capsule_destructor_0},
    {NULL, NULL}
};

// Release memory based on icontext.
void PY_SHROUD_release_memory(int icontext, void *ptr)
{
    PY_SHROUD_capsule_context[icontext].dtor(ptr);
}

//Fetch garbage collection context.
void *PY_SHROUD_fetch_context(int icontext)
{
    return PY_SHROUD_capsule_context + icontext;
}

// destructor function for PyCapsule
void PY_SHROUD_capsule_destructor(PyObject *cap)
{
    void *ptr = PyCapsule_GetPointer(cap, "PY_array_dtor");
    PY_SHROUD_dtor_context * context = static_cast<PY_SHROUD_dtor_context *>
        (PyCapsule_GetContext(cap));
    context->dtor(ptr);
}
