// wrapgeneric.c
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapgeneric.h"

// cxx_header
#include "generic.h"
#include "helper.h"

// splicer begin C_definitions
// splicer end C_definitions

/**
 * \brief scalar or array argument using assumed rank
 *
 */
// ----------------------------------------
// Function:  int SumValues
// Attrs:     +intent(result)
// Requested: c_native_scalar_result_cfi
// Match:     c_default
// ----------------------------------------
// Argument:  const int * values +dimension(..)
// Attrs:     +assumed-rank+intent(in)
// Exact:     c_native_*_in_cfi
// ----------------------------------------
// Argument:  int nvalues +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int GEN_sum_values_CFI(CFI_cdesc_t *values, int nvalues)
{
    // splicer begin function.sum_values_CFI
    int *SHCXX_values = (int *) values->base_addr;
    int SHC_rv = SumValues(SHCXX_values, nvalues);
    return SHC_rv;
    // splicer end function.sum_values_CFI
}

/**
 * Broadcast if nfrom == 1
 * Copy if nfrom == nto
 */
// ----------------------------------------
// Function:  void AssignValues
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const int * from
// Attrs:     +intent(in)
// Requested: c_native_*_in
// Match:     c_default
// ----------------------------------------
// Argument:  int nfrom +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int * to
// Attrs:     +intent(inout)
// Requested: c_native_*_inout
// Match:     c_default
// ----------------------------------------
// Argument:  int nto +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void GEN_assign_values_scalar(const int * from, int nfrom, int * to,
    int nto)
{
    // splicer begin function.assign_values_scalar
    AssignValues(from, nfrom, to, nto);
    // splicer end function.assign_values_scalar
}

/**
 * Broadcast if nfrom == 1
 * Copy if nfrom == nto
 */
// ----------------------------------------
// Function:  void AssignValues
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const int * from
// Attrs:     +intent(in)
// Requested: c_native_*_in
// Match:     c_default
// ----------------------------------------
// Argument:  int nfrom +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int * to +rank(1)
// Attrs:     +intent(inout)
// Requested: c_native_*_inout
// Match:     c_default
// ----------------------------------------
// Argument:  int nto +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void GEN_assign_values_broadcast(const int * from, int nfrom, int * to,
    int nto)
{
    // splicer begin function.assign_values_broadcast
    AssignValues(from, nfrom, to, nto);
    // splicer end function.assign_values_broadcast
}

/**
 * Broadcast if nfrom == 1
 * Copy if nfrom == nto
 */
// ----------------------------------------
// Function:  void AssignValues
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const int * from +rank(1)
// Attrs:     +intent(in)
// Requested: c_native_*_in
// Match:     c_default
// ----------------------------------------
// Argument:  int nfrom +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int * to +rank(1)
// Attrs:     +intent(inout)
// Requested: c_native_*_inout
// Match:     c_default
// ----------------------------------------
// Argument:  int nto +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void GEN_assign_values_copy(const int * from, int nfrom, int * to,
    int nto)
{
    // splicer begin function.assign_values_copy
    AssignValues(from, nfrom, to, nto);
    // splicer end function.assign_values_copy
}

#if 1
// ----------------------------------------
// Function:  void SavePointer
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  float * addr +deref(raw)+intent(in)+rank(1)
// Attrs:     +deref(raw)+intent(in)
// Requested: c_native_*_in_raw
// Match:     c_default
// ----------------------------------------
// Argument:  int type +implied(T_FLOAT)+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  size_t size +implied(size(addr))+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void GEN_save_pointer_float1d(float * addr, int type, size_t size)
{
    // splicer begin function.save_pointer_float1d
    SavePointer(addr, type, size);
    // splicer end function.save_pointer_float1d
}
#endif  // if 1

#if 1
// ----------------------------------------
// Function:  void SavePointer
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  float * addr +deref(raw)+intent(in)+rank(2)
// Attrs:     +deref(raw)+intent(in)
// Requested: c_native_*_in_raw
// Match:     c_default
// ----------------------------------------
// Argument:  int type +implied(T_FLOAT)+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  size_t size +implied(size(addr))+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void GEN_save_pointer_float2d(float * addr, int type, size_t size)
{
    // splicer begin function.save_pointer_float2d
    SavePointer(addr, type, size);
    // splicer end function.save_pointer_float2d
}
#endif  // if 1

// ----------------------------------------
// Function:  void SavePointer2
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  void * addr +value
// Attrs:     +intent(in)
// Requested: c_void_*_in
// Match:     c_default
// ----------------------------------------
// Argument:  int type +implied(type(addr))+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  size_t size +implied(size(addr))+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void GEN_save_pointer2(void * addr, int type, size_t size)
{
    // splicer begin function.save_pointer2
    // Test adding a blank line below.

    type = convert_type(type);
    SavePointer2(addr, type, size);
    // splicer end function.save_pointer2
}

// ----------------------------------------
// Function:  void SavePointer2
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  float * addr +deref(raw)+intent(in)+rank(1)
// Attrs:     +deref(raw)+intent(in)
// Requested: c_native_*_in_raw
// Match:     c_default
// ----------------------------------------
// Argument:  int type +implied(type(addr))+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  size_t size +implied(size(addr))+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void GEN_save_pointer2_float1d(float * addr, int type, size_t size)
{
    // splicer begin function.save_pointer2_float1d
    // Test adding a blank line below.

    type = convert_type(type);
    SavePointer2(addr, type, size);
    // splicer end function.save_pointer2_float1d
}

// ----------------------------------------
// Function:  void SavePointer2
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  float * addr +deref(raw)+intent(in)+rank(2)
// Attrs:     +deref(raw)+intent(in)
// Requested: c_native_*_in_raw
// Match:     c_default
// ----------------------------------------
// Argument:  int type +implied(type(addr))+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  size_t size +implied(size(addr))+value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void GEN_save_pointer2_float2d(float * addr, int type, size_t size)
{
    // splicer begin function.save_pointer2_float2d
    // Test adding a blank line below.

    type = convert_type(type);
    SavePointer2(addr, type, size);
    // splicer end function.save_pointer2_float2d
}

#if 0
// ----------------------------------------
// Function:  void GetPointerAsPointer
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  float * * addr +context(Daddr)+deref(pointer)+intent(out)+rank(1)
// Attrs:     +deref(pointer)+intent(out)
// Requested: c_native_**_out_buf_pointer
// Match:     c_native_**_out_buf
// ----------------------------------------
// Argument:  int * type +hidden+intent(out)
// Attrs:     +intent(out)
// Requested: c_native_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  size_t * size +hidden+intent(out)
// Attrs:     +intent(out)
// Requested: c_native_*_out
// Match:     c_default
void GEN_get_pointer_as_pointer_float1d_bufferify(
    GEN_SHROUD_array *Daddr, int * type, size_t * size)
{
    // splicer begin function.get_pointer_as_pointer_float1d_bufferify
    float *addr;
    GetPointerAsPointer(&addr, type, size);
    Daddr->cxx.addr  = addr;
    Daddr->cxx.idtor = 0;
    Daddr->addr.base = addr;
    Daddr->type = SH_TYPE_FLOAT;
    Daddr->elem_len = sizeof(float);
    Daddr->rank = 0;
    Daddr->size = 1;
    // splicer end function.get_pointer_as_pointer_float1d_bufferify
}
#endif  // if 0

#if 0
// ----------------------------------------
// Function:  void GetPointerAsPointer
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  float * * addr +context(Daddr)+deref(pointer)+intent(out)+rank(2)
// Attrs:     +deref(pointer)+intent(out)
// Requested: c_native_**_out_buf_pointer
// Match:     c_native_**_out_buf
// ----------------------------------------
// Argument:  int * type +hidden+intent(out)
// Attrs:     +intent(out)
// Requested: c_native_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  size_t * size +hidden+intent(out)
// Attrs:     +intent(out)
// Requested: c_native_*_out
// Match:     c_default
void GEN_get_pointer_as_pointer_float2d_bufferify(
    GEN_SHROUD_array *Daddr, int * type, size_t * size)
{
    // splicer begin function.get_pointer_as_pointer_float2d_bufferify
    float *addr;
    GetPointerAsPointer(&addr, type, size);
    Daddr->cxx.addr  = addr;
    Daddr->cxx.idtor = 0;
    Daddr->addr.base = addr;
    Daddr->type = SH_TYPE_FLOAT;
    Daddr->elem_len = sizeof(float);
    Daddr->rank = 0;
    Daddr->size = 1;
    // splicer end function.get_pointer_as_pointer_float2d_bufferify
}
#endif  // if 0
