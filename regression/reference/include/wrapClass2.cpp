// wrapClass2.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapClass2.h"
#include "class_header.hpp"
#include "global_header.hpp"


extern "C" {


void LIB_Class2_method1(LIB_Class2 * self, MPI_Fint comm)
{
    Class2 *SH_this = static_cast<Class2 *>(self->addr);
    MPI_Comm SHCXX_comm = MPI_Comm_f2c(comm);
    SH_this->method1(SHCXX_comm);
    return;
}

void LIB_Class2_method2(LIB_Class2 * self, LIB_three_Class1 * c2)
{
    Class2 *SH_this = static_cast<Class2 *>(self->addr);
    three::Class1 * SHCXX_c2 = static_cast<three::Class1 *>(c2->addr);
    SH_this->method2(SHCXX_c2);
    return;
}

}  // extern "C"
