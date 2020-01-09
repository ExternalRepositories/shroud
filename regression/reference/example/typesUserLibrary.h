// typesUserLibrary.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// For C users and C++ implementation

#ifndef TYPESUSERLIBRARY_H
#define TYPESUSERLIBRARY_H

#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif

struct s_AA_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_AA_SHROUD_capsule_data AA_SHROUD_capsule_data;

struct s_AA_SHROUD_array {
    AA_SHROUD_capsule_data cxx;      /* address of C++ memory */
    union {
        const void * base;
        const char * ccharp;
    } addr;
    int type;        /* type of element */
    size_t elem_len; /* bytes-per-item or character len in c++ */
    size_t size;     /* size of data in c++ */
};
typedef struct s_AA_SHROUD_array AA_SHROUD_array;

struct s_AA_example_nested_ExClass1 {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_AA_example_nested_ExClass1 AA_example_nested_ExClass1;

struct s_AA_example_nested_ExClass2 {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_AA_example_nested_ExClass2 AA_example_nested_ExClass2;

void AA_SHROUD_memory_destructor(AA_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESUSERLIBRARY_H
