// typestypes.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// For C users and C++ implementation

#ifndef TYPESTYPES_H
#define TYPESTYPES_H


#ifdef __cplusplus
extern "C" {
#endif

struct s_TYP_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_TYP_SHROUD_capsule_data TYP_SHROUD_capsule_data;

void TYP_SHROUD_memory_destructor(TYP_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESTYPES_H
