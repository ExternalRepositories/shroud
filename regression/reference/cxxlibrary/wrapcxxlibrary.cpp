// wrapcxxlibrary.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapcxxlibrary.h"

// cxx_header
#include "cxxlibrary.hpp"
// shroud
#include "typescxxlibrary.h"
#include <cstdlib>

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

// ----------------------------------------
// Function:  bool defaultPtrIsNULL
// Requested: c_bool_scalar_result
// Match:     c_default
bool CXX_default_ptr_is_null_0(void)
{
    // splicer begin function.default_ptr_is_null_0
    bool SHC_rv = defaultPtrIsNULL();
    return SHC_rv;
    // splicer end function.default_ptr_is_null_0
}

// ----------------------------------------
// Function:  bool defaultPtrIsNULL
// Requested: c_bool_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  double * data=nullptr +intent(in)+rank(1)
// Requested: c_native_*_in
// Match:     c_default
bool CXX_default_ptr_is_null_1(double * data)
{
    // splicer begin function.default_ptr_is_null_1
    bool SHC_rv = defaultPtrIsNULL(data);
    return SHC_rv;
    // splicer end function.default_ptr_is_null_1
}

// ----------------------------------------
// Function:  void defaultArgsInOut
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int in1 +intent(in)+value
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int * out1 +intent(out)
// Requested: c_native_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  int * out2 +intent(out)
// Requested: c_native_*_out
// Match:     c_default
void CXX_default_args_in_out_0(int in1, int * out1, int * out2)
{
    // splicer begin function.default_args_in_out_0
    defaultArgsInOut(in1, out1, out2);
    // splicer end function.default_args_in_out_0
}

// ----------------------------------------
// Function:  void defaultArgsInOut
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int in1 +intent(in)+value
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int * out1 +intent(out)
// Requested: c_native_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  int * out2 +intent(out)
// Requested: c_native_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  bool flag=false +intent(in)+value
// Requested: c_bool_scalar_in
// Match:     c_default
void CXX_default_args_in_out_1(int in1, int * out1, int * out2,
    bool flag)
{
    // splicer begin function.default_args_in_out_1
    defaultArgsInOut(in1, out1, out2, flag);
    // splicer end function.default_args_in_out_1
}

// Release library allocated memory.
void CXX_SHROUD_memory_destructor(CXX_SHROUD_capsule_data *cap)
{
    cap->addr = nullptr;
    cap->idtor = 0;  // avoid deleting again
}

}  // extern "C"
