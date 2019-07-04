// typesClibrary.h
// This is generated code, do not edit
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// For C users and C implementation

#ifndef TYPESCLIBRARY_H
#define TYPESCLIBRARY_H

struct s_CLI_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_CLI_SHROUD_capsule_data CLI_SHROUD_capsule_data;

void CLI_SHROUD_memory_destructor(CLI_SHROUD_capsule_data *cap);

#endif  // TYPESCLIBRARY_H
