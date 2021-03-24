// wrapcdesc.h
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapcdesc.h
 * \brief Shroud generated wrapper for cdesc library
 */
// For C users and C++ implementation

#ifndef WRAPCDESC_H
#define WRAPCDESC_H

// shroud
#include "typescdesc.h"

// splicer begin CXX_declarations
// splicer end CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin C_declarations
// splicer end C_declarations

void CDE_rank2_in(CDE_SHROUD_array *arg_temp0);

void CDE_get_scalar1(char * name, CDE_SHROUD_array *value_temp0);

void CDE_get_scalar1_0_bufferify(char *name, int name_temp0,
    CDE_SHROUD_array *value_temp0);

void CDE_get_scalar1_1_bufferify(char *name, int name_temp0,
    CDE_SHROUD_array *value_temp0);

int CDE_get_data_int(void);

double CDE_get_data_double(void);

#ifdef __cplusplus
}
#endif

#endif  // WRAPCDESC_H
