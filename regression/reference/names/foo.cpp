// foo.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "foo.h"

// splicer begin namespace.ns0.class.Names.CXX_definitions
// CXX_definitions for ns0 class Names
// splicer end namespace.ns0.class.Names.CXX_definitions

extern "C" {

// splicer begin namespace.ns0.class.Names.C_definitions
// splicer end namespace.ns0.class.Names.C_definitions

// void method1()
void XXX_TES_ns0_Names_method1(TES_ns0_Names * self)
{
    ns0::Names *SH_this = static_cast<ns0::Names *>(self->addr);
    // splicer begin namespace.ns0.class.Names.method.method1
    SH_this->method1();
    return;
    // splicer end namespace.ns0.class.Names.method.method1
}

// void method2()
void XXX_TES_ns0_Names_method2(TES_ns0_Names * self2)
{
    ns0::Names *SH_this2 = static_cast<ns0::Names *>(self2->addr);
    // splicer begin namespace.ns0.class.Names.method.method2
    SH_this->method2();
    return;
    // splicer end namespace.ns0.class.Names.method.method2
}

}  // extern "C"
