// wrapstructAsClass_int.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapstructAsClass_int.h"

// cxx_header
#include "templates.hpp"

// splicer begin class.structAsClass.CXX_definitions
// splicer end class.structAsClass.CXX_definitions

extern "C" {

// splicer begin class.structAsClass.C_definitions
// splicer end class.structAsClass.C_definitions

// ----------------------------------------
// Function:  structAsClass
// Attrs:     +intent(ctor)
// Requested: c_ctor_shadow_scalar
// Match:     c_ctor
void TEM_structAsClass_int_ctor(TEM_structAsClass_int * SHC_rv)
{
    // splicer begin class.structAsClass.method.ctor
    structAsClass<int> *SHCXX_rv = new structAsClass<int>();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 3;
    // splicer end class.structAsClass.method.ctor
}

// ----------------------------------------
// Function:  void set_npts
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  int n +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void TEM_structAsClass_int_set_npts(TEM_structAsClass_int * self, int n)
{
    structAsClass<int> *SH_this = static_cast<structAsClass<int> *>
        (self->addr);
    // splicer begin class.structAsClass.method.set_npts
    SH_this->set_npts(n);
    // splicer end class.structAsClass.method.set_npts
}

// ----------------------------------------
// Function:  int get_npts
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_function
int TEM_structAsClass_int_get_npts(TEM_structAsClass_int * self)
{
    structAsClass<int> *SH_this = static_cast<structAsClass<int> *>
        (self->addr);
    // splicer begin class.structAsClass.method.get_npts
    int SHC_rv = SH_this->get_npts();
    return SHC_rv;
    // splicer end class.structAsClass.method.get_npts
}

// ----------------------------------------
// Function:  void set_value
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  int v +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void TEM_structAsClass_int_set_value(TEM_structAsClass_int * self,
    int v)
{
    structAsClass<int> *SH_this = static_cast<structAsClass<int> *>
        (self->addr);
    // splicer begin class.structAsClass.method.set_value
    SH_this->set_value(v);
    // splicer end class.structAsClass.method.set_value
}

// ----------------------------------------
// Function:  int get_value
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_function
int TEM_structAsClass_int_get_value(TEM_structAsClass_int * self)
{
    structAsClass<int> *SH_this = static_cast<structAsClass<int> *>
        (self->addr);
    // splicer begin class.structAsClass.method.get_value
    int SHC_rv = SH_this->get_value();
    return SHC_rv;
    // splicer end class.structAsClass.method.get_value
}

}  // extern "C"
