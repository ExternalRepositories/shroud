// wrapcxxlibrary_structns.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapcxxlibrary_structns.h"

// cxx_header
#include "cxxlibrary.hpp"

// splicer begin namespace.structns.CXX_definitions
// splicer end namespace.structns.CXX_definitions

extern "C" {

// splicer begin namespace.structns.C_definitions
// splicer end namespace.structns.C_definitions

/**
 * Argument is modified by library, defaults to intent(inout).
 */
// ----------------------------------------
// Function:  int passStructByReference
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_function
// ----------------------------------------
// Argument:  Cstruct1 & arg
// Attrs:     +intent(inout)
// Requested: c_inout_struct_&
// Match:     c_inout_struct
int CXX_structns_pass_struct_by_reference(CXX_cstruct1 * arg)
{
    // splicer begin namespace.structns.function.pass_struct_by_reference
    structns::Cstruct1 * SHCXX_arg = static_cast<structns::Cstruct1 *>
        (static_cast<void *>(arg));
    int SHC_rv = structns::passStructByReference(*SHCXX_arg);
    return SHC_rv;
    // splicer end namespace.structns.function.pass_struct_by_reference
}

/**
 * const defaults to intent(in)
 */
// ----------------------------------------
// Function:  int passStructByReferenceIn
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_function
// ----------------------------------------
// Argument:  const Cstruct1 & arg
// Attrs:     +intent(in)
// Requested: c_in_struct_&
// Match:     c_in_struct
int CXX_structns_pass_struct_by_reference_in(const CXX_cstruct1 * arg)
{
    // splicer begin namespace.structns.function.pass_struct_by_reference_in
    const structns::Cstruct1 * SHCXX_arg = 
        static_cast<const structns::Cstruct1 *>
        (static_cast<const void *>(arg));
    int SHC_rv = structns::passStructByReferenceIn(*SHCXX_arg);
    return SHC_rv;
    // splicer end namespace.structns.function.pass_struct_by_reference_in
}

// ----------------------------------------
// Function:  void passStructByReferenceInout
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  Cstruct1 & arg +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_struct_&
// Match:     c_inout_struct
void CXX_structns_pass_struct_by_reference_inout(CXX_cstruct1 * arg)
{
    // splicer begin namespace.structns.function.pass_struct_by_reference_inout
    structns::Cstruct1 * SHCXX_arg = static_cast<structns::Cstruct1 *>
        (static_cast<void *>(arg));
    structns::passStructByReferenceInout(*SHCXX_arg);
    // splicer end namespace.structns.function.pass_struct_by_reference_inout
}

// ----------------------------------------
// Function:  void passStructByReferenceOut
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  Cstruct1 & arg +intent(out)
// Attrs:     +intent(out)
// Requested: c_out_struct_&
// Match:     c_out_struct
void CXX_structns_pass_struct_by_reference_out(CXX_cstruct1 * arg)
{
    // splicer begin namespace.structns.function.pass_struct_by_reference_out
    structns::Cstruct1 * SHCXX_arg = static_cast<structns::Cstruct1 *>
        (static_cast<void *>(arg));
    structns::passStructByReferenceOut(*SHCXX_arg);
    // splicer end namespace.structns.function.pass_struct_by_reference_out
}

}  // extern "C"
