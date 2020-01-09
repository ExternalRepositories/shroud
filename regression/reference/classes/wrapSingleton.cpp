// wrapSingleton.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapSingleton.h"
#include "classes.hpp"

// splicer begin class.Singleton.CXX_definitions
// splicer end class.Singleton.CXX_definitions

extern "C" {

// splicer begin class.Singleton.C_definitions
// splicer end class.Singleton.C_definitions

// static Singleton & getReference()
CLA_Singleton * CLA_Singleton_get_reference(CLA_Singleton * SHC_rv)
{
    // splicer begin class.Singleton.method.get_reference
    classes::Singleton & SHCXX_rv = classes::Singleton::getReference();
    SHC_rv->addr = static_cast<void *>(&SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end class.Singleton.method.get_reference
}

}  // extern "C"
