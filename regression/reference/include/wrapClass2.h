// wrapClass2.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapClass2.h
 * \brief Shroud generated wrapper for Class2 class
 */
// For C users and C++ implementation

#ifndef WRAPCLASS2_H
#define WRAPCLASS2_H

#include "mpi.h"
#include "typeslibrary.h"


#ifdef __cplusplus
extern "C" {
#endif


void LIB_Class2_method1(LIB_Class2 * self, MPI_Fint comm);

void LIB_Class2_method2(LIB_Class2 * self, LIB_three_Class1 * c2);

#ifdef __cplusplus
}
#endif

#endif  // WRAPCLASS2_H
