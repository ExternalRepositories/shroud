// wraptemplates.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wraptemplates.h"
// cxx_header
#include "templates.hpp"
#include "implworker1.hpp"
#include "implworker2.hpp"
#include <vector>
// shroud
#include "typestemplates.h"
#include <cstdlib>

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

/**
 * \brief Function template with two template parameters.
 *
 */
// ----------------------------------------
// Function:  void FunctionTU
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int arg1 +intent(in)+value
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  long arg2 +intent(in)+value
// Requested: c_native_scalar_in
// Match:     c_default
void TEM_function_tu_0(int arg1, long arg2)
{
    // splicer begin function.function_tu_0
    FunctionTU<int, long>(arg1, arg2);
    // splicer end function.function_tu_0
}

/**
 * \brief Function template with two template parameters.
 *
 */
// ----------------------------------------
// Function:  void FunctionTU
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  float arg1 +intent(in)+value
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  double arg2 +intent(in)+value
// Requested: c_native_scalar_in
// Match:     c_default
void TEM_function_tu_1(float arg1, double arg2)
{
    // splicer begin function.function_tu_1
    FunctionTU<float, double>(arg1, arg2);
    // splicer end function.function_tu_1
}

/**
 * \brief Function which uses a templated T in the implemetation.
 *
 */
// ----------------------------------------
// Function:  int UseImplWorker
// Requested: c_native_scalar_result
// Match:     c_default
int TEM_use_impl_worker_internal_ImplWorker1(void)
{
    // splicer begin function.use_impl_worker_internal_ImplWorker1
    int SHC_rv = UseImplWorker<internal::ImplWorker1>();
    return SHC_rv;
    // splicer end function.use_impl_worker_internal_ImplWorker1
}

/**
 * \brief Function which uses a templated T in the implemetation.
 *
 */
// ----------------------------------------
// Function:  int UseImplWorker
// Requested: c_native_scalar_result
// Match:     c_default
int TEM_use_impl_worker_internal_ImplWorker2(void)
{
    // splicer begin function.use_impl_worker_internal_ImplWorker2
    int SHC_rv = UseImplWorker<internal::ImplWorker2>();
    return SHC_rv;
    // splicer end function.use_impl_worker_internal_ImplWorker2
}

// Release library allocated memory.
void TEM_SHROUD_memory_destructor(TEM_SHROUD_capsule_data *cap)
{
    void *ptr = cap->addr;
    switch (cap->idtor) {
    case 0:   // --none--
    {
        // Nothing to delete
        break;
    }
    case 1:   // std::vector<int>
    {
        std::vector<int> *cxx_ptr = 
            reinterpret_cast<std::vector<int> *>(ptr);
        delete cxx_ptr;
        break;
    }
    case 2:   // std::vector<double>
    {
        std::vector<double> *cxx_ptr = 
            reinterpret_cast<std::vector<double> *>(ptr);
        delete cxx_ptr;
        break;
    }
    default:
    {
        // Unexpected case in destructor
        break;
    }
    }
    cap->addr = nullptr;
    cap->idtor = 0;  // avoid deleting again
}

}  // extern "C"
