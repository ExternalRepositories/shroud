// wrapwrapped_inner2.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapwrapped_inner2.h"

// splicer begin namespace.inner2.CXX_definitions
// splicer end namespace.inner2.CXX_definitions

extern "C" {

// splicer begin namespace.inner2.C_definitions
// splicer end namespace.inner2.C_definitions

// ----------------------------------------
// Function:  void worker
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
void WWW_inner2_worker(void)
{
    // splicer begin namespace.inner2.function.worker
    outer::inner2::worker();
    // splicer end namespace.inner2.function.worker
}

}  // extern "C"
