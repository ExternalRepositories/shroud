// pytestnamesmodule.hpp
// This is generated code, do not edit
// #######################################################################
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
#ifndef PYTESTNAMESMODULE_HPP
#define PYTESTNAMESMODULE_HPP
#include <Python.h>
// splicer begin header.include
// splicer end header.include

// forward declare classes
class Names;
class Names2;
namespace std {
    class vector;
}
namespace std {
    class vector;
}
namespace std {
    class vector;
}
namespace std {
    class vector;
}
class twoTs;
class twoTs;

extern PyTypeObject PY_Names_Type;
extern PyTypeObject PY_Names2_Type;
extern PyTypeObject PY_Vvv1_Type;
extern PyTypeObject PY_vector_double_Type;
extern PyTypeObject PY_vector_instantiation5_Type;
extern PyTypeObject PY_vector_instantiation3_Type;
extern PyTypeObject PY_twoTs_0_Type;
extern PyTypeObject PY_twoTs_instantiation4_Type;

// splicer begin header.C_declaration
// splicer end header.C_declaration

// helper functions
extern const char *PY_Names_capsule_name;
extern const char *PY_Names2_capsule_name;
extern const char *PY_Vvv1_capsule_name;
extern const char *PY_vector_double_capsule_name;
extern const char *PY_vector_instantiation5_capsule_name;
extern const char *PY_vector_instantiation3_capsule_name;
extern const char *PY_twoTs_0_capsule_name;
extern const char *PY_twoTs_instantiation4_capsule_name;
PyObject *PP_Names_to_Object(Names *addr);
int PP_Names_from_Object(PyObject *obj, void **addr);
PyObject *PP_Names2_to_Object(Names2 *addr);
int PP_Names2_from_Object(PyObject *obj, void **addr);
PyObject *PP_Vvv1_to_Object(std::Vvv1 *addr);
int PP_Vvv1_from_Object(PyObject *obj, void **addr);
PyObject *PP_vector_double_to_Object(std::vector_double *addr);
int PP_vector_double_from_Object(PyObject *obj, void **addr);
PyObject *PP_vector_instantiation5_to_Object(std::vector_instantiation5 *addr);
int PP_vector_instantiation5_from_Object(PyObject *obj, void **addr);
PyObject *PP_vector_instantiation3_to_Object(std::vector_instantiation3 *addr);
int PP_vector_instantiation3_from_Object(PyObject *obj, void **addr);
PyObject *PP_twoTs_0_to_Object(twoTs_0 *addr);
int PP_twoTs_0_from_Object(PyObject *obj, void **addr);
PyObject *PP_twoTs_instantiation4_to_Object(twoTs_instantiation4 *addr);
int PP_twoTs_instantiation4_from_Object(PyObject *obj, void **addr);

// splicer begin class.Names.C_declaration
// splicer end class.Names.C_declaration

typedef struct {
PyObject_HEAD
    Names * obj;
    // splicer begin class.Names.C_object
    // splicer end class.Names.C_object
} PY_Names;
// splicer begin class.Names2.C_declaration
// splicer end class.Names2.C_declaration

typedef struct {
PyObject_HEAD
    Names2 * obj;
    // splicer begin class.Names2.C_object
    // splicer end class.Names2.C_object
} PY_Names2;
// splicer begin class.vector.C_declaration
// splicer end class.vector.C_declaration

typedef struct {
PyObject_HEAD
    std::Vvv1 * obj;
    // splicer begin class.vector.C_object
    // splicer end class.vector.C_object
} PY_Vvv1;
// splicer begin class.vector.C_declaration
// splicer end class.vector.C_declaration

typedef struct {
PyObject_HEAD
    std::vector_double * obj;
    // splicer begin class.vector.C_object
    // splicer end class.vector.C_object
} PY_vector_double;
// splicer begin class.vector.C_declaration
// splicer end class.vector.C_declaration

typedef struct {
PyObject_HEAD
    std::vector_instantiation5 * obj;
    // splicer begin class.vector.C_object
    // splicer end class.vector.C_object
} PY_vector_instantiation5;
// splicer begin class.vector.C_declaration
// splicer end class.vector.C_declaration

typedef struct {
PyObject_HEAD
    std::vector_instantiation3 * obj;
    // splicer begin class.vector.C_object
    // splicer end class.vector.C_object
} PY_vector_instantiation3;
// splicer begin class.twoTs.C_declaration
// splicer end class.twoTs.C_declaration

typedef struct {
PyObject_HEAD
    twoTs_0 * obj;
    // splicer begin class.twoTs.C_object
    // splicer end class.twoTs.C_object
} PY_twoTs_0;
// splicer begin class.twoTs.C_declaration
// splicer end class.twoTs.C_declaration

typedef struct {
PyObject_HEAD
    twoTs_instantiation4 * obj;
    // splicer begin class.twoTs.C_object
    // splicer end class.twoTs.C_object
} PY_twoTs_instantiation4;

extern PyObject *PY_error_obj;

#if PY_MAJOR_VERSION >= 3
extern "C" PyMODINIT_FUNC PyInit_testnames(void);
#else
extern "C" PyMODINIT_FUNC inittestnames(void);
#endif

#endif  /* PYTESTNAMESMODULE_HPP */
