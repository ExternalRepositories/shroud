// wraplibrary_outer2.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wraplibrary_outer2.h"
// cxx_header
#include "outer2.hpp"


extern "C" {


// ----------------------------------------
// Function:  void outer_func
// Requested: c
// Match:     c_default
void LIB_outer2_outer_func(void)
{
    outer2::outer_func();
}

}  // extern "C"
