// wrapcdesc.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapcdesc.h"

// cxx_header
#include "cdesc.hpp"
// typemap
#include <string>
// shroud
#include "typescdesc.h"
#include <cstdlib>

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

// ----------------------------------------
// Function:  void Rank2In
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int * arg +cdesc+context(Darg)+intent(in)+rank(2)
// Attrs:     +intent(in)
// Exact:     c_native_*_in_cdesc
void CDE_rank2_in(CDE_SHROUD_array *Darg)
{
    // splicer begin function.rank2_in
    int * arg = static_cast<int *>(const_cast<void *>(Darg->addr.base));
    Rank2In(arg);
    // splicer end function.rank2_in
}

/**
 * Create several Fortran generic functions which call a single
 * C wrapper that checkes the type of the Fortran argument
 * and calls the correct templated function.
 * Adding the string argument forces a bufferified function
 * to be create.
 * XXX The non-bufferified version should not be created since
 * users will not manually create a context struct.
 */
// ----------------------------------------
// Function:  void GetScalar1
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  std::string & name +intent(in)
// Attrs:     +intent(in)
// Exact:     c_string_&_in
// ----------------------------------------
// Argument:  void * value +cdesc+context(Dvalue)+intent(out)+rank(0)+value
// Attrs:     +intent(out)
// Requested: c_void_*_out_cdesc
// Match:     c_void_*_cdesc
void CDE_get_scalar1(char * name, CDE_SHROUD_array *Dvalue)
{
    // splicer begin function.get_scalar1
    // This function should not exist
    // splicer end function.get_scalar1
}

/**
 * Create several Fortran generic functions which call a single
 * C wrapper that checkes the type of the Fortran argument
 * and calls the correct templated function.
 * Adding the string argument forces a bufferified function
 * to be create.
 * XXX The non-bufferified version should not be created since
 * users will not manually create a context struct.
 */
// ----------------------------------------
// Function:  void GetScalar1
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  std::string & name +intent(in)+len_trim(Lname)
// Attrs:     +intent(in)
// Exact:     c_string_&_in_buf
// ----------------------------------------
// Argument:  void * value +cdesc+context(Dvalue)+intent(out)+rank(0)+value
// Attrs:     +intent(out)
// Requested: c_void_*_out_cdesc
// Match:     c_void_*_cdesc
void CDE_get_scalar1_bufferify(char * name, int Lname,
    CDE_SHROUD_array *Dvalue)
{
    // splicer begin function.get_scalar1_bufferify
    switch(Dvalue->type) {
    case SH_TYPE_INT: {
      *static_cast<int *>(const_cast<void *>(Dvalue->addr.base)) = getData<int>();
      break;
    }
    case SH_TYPE_LONG: {
      *static_cast<long *>(const_cast<void *>(Dvalue->addr.base)) = getData<long>();
      break;
    }
    case SH_TYPE_FLOAT: {
      *static_cast<float *>(const_cast<void *>(Dvalue->addr.base)) = getData<float>();
      break;
    }
    case SH_TYPE_DOUBLE: {
      *static_cast<double *>(const_cast<void *>(Dvalue->addr.base)) = getData<double>();
      break;
    }
    // default:
    }
    // splicer end function.get_scalar1_bufferify
}

/**
 * Wrapper for function which is templated on the return value.
 */
// ----------------------------------------
// Function:  int getData
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
int CDE_get_data_int(void)
{
    // splicer begin function.get_data_int
    int SHC_rv = getData<int>();
    return SHC_rv;
    // splicer end function.get_data_int
}

/**
 * Wrapper for function which is templated on the return value.
 */
// ----------------------------------------
// Function:  double getData
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
double CDE_get_data_double(void)
{
    // splicer begin function.get_data_double
    double SHC_rv = getData<double>();
    return SHC_rv;
    // splicer end function.get_data_double
}

// Release library allocated memory.
void CDE_SHROUD_memory_destructor(CDE_SHROUD_capsule_data *cap)
{
    cap->addr = nullptr;
    cap->idtor = 0;  // avoid deleting again
}

}  // extern "C"
