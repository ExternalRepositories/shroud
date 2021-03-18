// wrapvectors.h
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapvectors.h
 * \brief Shroud generated wrapper for vectors library
 */
// For C users and C++ implementation

#ifndef WRAPVECTORS_H
#define WRAPVECTORS_H

// shroud
#include "typesvectors.h"

// splicer begin CXX_declarations
// splicer end CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin C_declarations
// splicer end C_declarations

int VEC_vector_sum_bufferify(int *arg, size_t arg_temp0);

void VEC_vector_iota_out_bufferify(VEC_SHROUD_array *arg_temp0);

long VEC_vector_iota_out_with_num_bufferify(
    VEC_SHROUD_array *arg_temp0);

void VEC_vector_iota_out_with_num2_bufferify(
    VEC_SHROUD_array *arg_temp0);

void VEC_vector_iota_out_alloc_bufferify(VEC_SHROUD_array *arg_temp0);

void VEC_vector_iota_inout_alloc_bufferify(int *arg, size_t arg_temp0,
    VEC_SHROUD_array *arg_temp1);

void VEC_vector_increment_bufferify(int *arg, size_t arg_temp0,
    VEC_SHROUD_array *arg_temp1);

void VEC_vector_iota_out_d_bufferify(VEC_SHROUD_array *arg_temp0);

int VEC_vector_string_count_bufferify(const char *arg, size_t arg_temp0,
    int arg_temp1);

void VEC_return_vector_alloc_bufferify(VEC_SHROUD_array *SHC_rv_temp0,
    int n);

#ifdef __cplusplus
}
#endif

#endif  // WRAPVECTORS_H
