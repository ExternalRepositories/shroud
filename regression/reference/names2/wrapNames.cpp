// wrapNames.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapNames.h"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

// ----------------------------------------
// Function:  void AFunction
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
void NAM_afunction(void)
{
    // splicer begin function.afunction
    ignore1::ignore2::AFunction();
    // splicer end function.afunction
}

}  // extern "C"
