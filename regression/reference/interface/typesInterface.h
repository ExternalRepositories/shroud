// typesInterface.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// For C users and C implementation

#ifndef TYPESINTERFACE_H
#define TYPESINTERFACE_H

struct s_INT_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_INT_SHROUD_capsule_data INT_SHROUD_capsule_data;

void INT_SHROUD_memory_destructor(INT_SHROUD_capsule_data *cap);

#endif  // TYPESINTERFACE_H
