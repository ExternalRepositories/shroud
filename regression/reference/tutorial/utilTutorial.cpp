// utilTutorial.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// shroud
#include "typesTutorial.h"

#include <cstddef>
#include <cstring>


#ifdef __cplusplus
extern "C" {
#endif

// start helper copy_string
// helper copy_string
// Copy the char* or std::string in context into c_var.
// Called by Fortran to deal with allocatable character.
void TUT_ShroudCopyStringAndFree(TUT_SHROUD_array *data, char *c_var, size_t c_var_len) {
    const char *cxx_var = data->addr.ccharp;
    size_t n = c_var_len;
    if (data->elem_len < n) n = data->elem_len;
    std::strncpy(c_var, cxx_var, n);
    TUT_SHROUD_memory_destructor(&data->cxx); // delete data->cxx.addr
}
// end helper copy_string


#ifdef __cplusplus
}
#endif
