// wrapShape.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapShape.h"

// cxx_header
#include "classes.hpp"

// splicer begin class.Shape.CXX_definitions
// splicer end class.Shape.CXX_definitions

extern "C" {

// splicer begin class.Shape.C_definitions
// splicer end class.Shape.C_definitions

// ----------------------------------------
// Function:  Shape
// Exact:     c_shadow_scalar_ctor
//    metaattrs:  +intent(result)
CLA_Shape * CLA_Shape_ctor(CLA_Shape * SHadow_rv)
{
    // splicer begin class.Shape.method.ctor
    classes::Shape *SHCXX_rv = new classes::Shape();
    SHadow_rv->addr = static_cast<void *>(SHCXX_rv);
    SHadow_rv->idtor = 2;
    return SHadow_rv;
    // splicer end class.Shape.method.ctor
}

// ----------------------------------------
// Function:  int get_ivar
// Requested: c_native_scalar_result
// Match:     c_default
//    metaattrs:  +intent(result)
int CLA_Shape_get_ivar(const CLA_Shape * self)
{
    const classes::Shape *SH_this = static_cast<const classes::Shape *>
        (self->addr);
    // splicer begin class.Shape.method.get_ivar
    int SHC_rv = SH_this->get_ivar();
    return SHC_rv;
    // splicer end class.Shape.method.get_ivar
}

}  // extern "C"
