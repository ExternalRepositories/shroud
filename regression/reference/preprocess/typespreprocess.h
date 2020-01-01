// typespreprocess.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// For C users and C++ implementation

#ifndef TYPESPREPROCESS_H
#define TYPESPREPROCESS_H


#ifdef __cplusplus
extern "C" {
#endif

struct s_PRE_User1 {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_PRE_User1 PRE_User1;

#ifdef USE_USER2
struct s_PRE_User2 {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_PRE_User2 PRE_User2;
#endif  // ifdef USE_USER2

struct s_PRE_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_PRE_SHROUD_capsule_data PRE_SHROUD_capsule_data;

void PRE_SHROUD_memory_destructor(PRE_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESPREPROCESS_H
