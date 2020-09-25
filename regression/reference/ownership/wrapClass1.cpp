// wrapClass1.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapClass1.h"
// cxx_header
#include "ownership.hpp"
// shroud
#include <cstddef>

// splicer begin class.Class1.CXX_definitions
// splicer end class.Class1.CXX_definitions

extern "C" {

// splicer begin class.Class1.C_definitions
// splicer end class.Class1.C_definitions

// ----------------------------------------
// Function:  ~Class1
// Exact:     c_shadow_dtor
void OWN_Class1_dtor(OWN_Class1 * self)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.dtor
    delete SH_this;
    self->addr = nullptr;
    // splicer end class.Class1.method.dtor
}

// ----------------------------------------
// Function:  int getFlag
// Requested: c_native_scalar_result
// Match:     c_default
int OWN_Class1_get_flag(OWN_Class1 * self)
{
    Class1 *SH_this = static_cast<Class1 *>(self->addr);
    // splicer begin class.Class1.method.get_flag
    return SH_this->m_flag;
    // splicer end class.Class1.method.get_flag
}

}  // extern "C"
