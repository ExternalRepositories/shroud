// wrapNames.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapNames.h"
#include <cstdlib>
#include "typesNames.h"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

// void AFunction()
void NAM_afunction()
{
    // splicer begin function.afunction
    ignore1::ignore2::AFunction();
    return;
    // splicer end function.afunction
}

// Release library allocated memory.
void NAM_SHROUD_memory_destructor(NAM_SHROUD_capsule_data *cap)
{
    cap->addr = NULL;
    cap->idtor = 0;  // avoid deleting again
}

}  // extern "C"
