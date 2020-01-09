// wrappointers.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrappointers.h
 * \brief Shroud generated wrapper for pointers library
 */
// For C users and C++ implementation

#ifndef WRAPPOINTERS_H
#define WRAPPOINTERS_H

#include "typespointers.h"

// splicer begin CXX_declarations
// splicer end CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin C_declarations
// splicer end C_declarations

void POI_intargs(const int argin, int * arginout, int * argout);

void POI_cos_doubles(double * in, double * out, int sizein);

void POI_truncate_to_int(double * in, int * out, int sizein);

void POI_get_values(int * nvalues, int * values);

void POI_get_values2(int * arg1, int * arg2);

void POI_sum(int len, int * values, int * result);

void POI_fill_int_array(int * out);

void POI_increment_int_array(int * array, int sizein);

#ifdef __cplusplus
}
#endif

#endif  // WRAPPOINTERS_H
