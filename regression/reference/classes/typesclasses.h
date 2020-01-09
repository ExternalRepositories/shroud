// typesclasses.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// For C users and C++ implementation

#ifndef TYPESCLASSES_H
#define TYPESCLASSES_H


#ifdef __cplusplus
extern "C" {
#endif

// start struct CLA_Class1
struct s_CLA_Class1 {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_CLA_Class1 CLA_Class1;
// end struct CLA_Class1

struct s_CLA_Singleton {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_CLA_Singleton CLA_Singleton;

struct s_CLA_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_CLA_SHROUD_capsule_data CLA_SHROUD_capsule_data;

void CLA_SHROUD_memory_destructor(CLA_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESCLASSES_H
