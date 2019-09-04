// wrapns.h
// This is generated code, do not edit
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapns.h
 * \brief Shroud generated wrapper for ns library
 */
// For C users and C++ implementation

#ifndef WRAPNS_H
#define WRAPNS_H

#include "typesns.h"

// splicer begin CXX_declarations
// splicer end CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin C_declarations
// splicer end C_declarations

const char * NS_last_function_called();

void NS_last_function_called_bufferify(NS_SHROUD_array *DSHF_rv);

void NS_one();

#ifdef __cplusplus
}
#endif

#endif  // WRAPNS_H
