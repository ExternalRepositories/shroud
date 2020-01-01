// wrapns_outer.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapns_outer.h
 * \brief Shroud generated wrapper for outer namespace
 */
// For C users and C++ implementation

#ifndef WRAPNS_OUTER_H
#define WRAPNS_OUTER_H

#include "typesns.h"

// splicer begin namespace.outer.CXX_declarations
// splicer end namespace.outer.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif


struct s_NS_cstruct1 {
    int ifield;
    double dfield;
};
typedef struct s_NS_cstruct1 NS_cstruct1;

// splicer begin namespace.outer.C_declarations
// splicer end namespace.outer.C_declarations

void NS_outer_one();

#ifdef __cplusplus
}
#endif

#endif  // WRAPNS_OUTER_H
