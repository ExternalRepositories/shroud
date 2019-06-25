// typesstruct.h
// This is generated code, do not edit
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// For C users and C++ implementation

#ifndef TYPESSTRUCT_H
#define TYPESSTRUCT_H


#ifdef __cplusplus
extern "C" {
#endif

struct s_STR_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_STR_SHROUD_capsule_data STR_SHROUD_capsule_data;

void STR_SHROUD_memory_destructor(STR_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESSTRUCT_H
