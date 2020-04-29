// wrappointers.cpp
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrappointers.h"
#include <cstdlib>
#include <cstring>
#include "pointers.h"
#include "typespointers.h"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {


// helper ShroudLenTrim
// Returns the length of character string src with length nsrc,
// ignoring any trailing blanks.
static int ShroudLenTrim(const char *src, int nsrc) {
    int i;

    for (i = nsrc - 1; i >= 0; i--) {
        if (src[i] != ' ') {
            break;
        }
    }

    return i + 1;
}


// helper ShroudStrArrayAlloc
// Copy src into new memory and null terminate.
// char **src +size(nsrc) +len(len)
// CHARACTER(len) src(nsrc)
static char **ShroudStrArrayAlloc(const char *src, int nsrc, int len)
{
   char **rv = static_cast<char **>(std::malloc(sizeof(char *) * nsrc));
   const char *src0 = src;
   for(int i=0; i < nsrc; ++i) {
      int ntrim = ShroudLenTrim(src0, len);
      char *tgt = static_cast<char *>(std::malloc(ntrim+1));
      std::memcpy(tgt, src0, ntrim);
      tgt[ntrim] = '\0';
      rv[i] = tgt;
      src0 += len;
   }
   return rv;
}

// helper ShroudStrArrayFree
// Release memory allocated by ShroudStrArrayAlloc
static void ShroudStrArrayFree(char **src, int nsrc)
{
   for(int i=0; i < nsrc; ++i) {
       std::free(src[i]);
   }
   std::free(src);
}
// splicer begin C_definitions
// splicer end C_definitions

// void intargs(const int argin +intent(in)+value, int * arginout +intent(inout), int * argout +intent(out))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  argin
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  arginout
// Requested: c_native_*_inout
// Match:     c_default
// ----------------------------------------
// Argument:  argout
// Requested: c_native_*_out
// Match:     c_default
void POI_intargs(const int argin, int * arginout, int * argout)
{
    // splicer begin function.intargs
    intargs(argin, arginout, argout);
    // splicer end function.intargs
}

// void cos_doubles(double * in +dimension(:)+intent(in), double * out +allocatable(mold=in)+intent(out), int sizein +implied(size(in))+intent(in)+value)
/**
 * \brief compute cos of IN and save in OUT
 *
 * allocate OUT same type as IN implied size of array
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  in
// Requested: c_native_*_in
// Match:     c_default
// ----------------------------------------
// Argument:  out
// Requested: c_native_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  sizein
// Requested: c_native_scalar_in
// Match:     c_default
void POI_cos_doubles(double * in, double * out, int sizein)
{
    // splicer begin function.cos_doubles
    cos_doubles(in, out, sizein);
    // splicer end function.cos_doubles
}

// void truncate_to_int(double * in +dimension(:)+intent(in), int * out +allocatable(mold=in)+intent(out), int sizein +implied(size(in))+intent(in)+value)
/**
 * \brief truncate IN argument and save in OUT
 *
 * allocate OUT different type as IN
 * implied size of array
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  in
// Requested: c_native_*_in
// Match:     c_default
// ----------------------------------------
// Argument:  out
// Requested: c_native_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  sizein
// Requested: c_native_scalar_in
// Match:     c_default
void POI_truncate_to_int(double * in, int * out, int sizein)
{
    // splicer begin function.truncate_to_int
    truncate_to_int(in, out, sizein);
    // splicer end function.truncate_to_int
}

// void get_values(int * nvalues +intent(out), int * values +dimension(3)+intent(out))
/**
 * \brief fill values into array
 *
 * The function knows how long the array must be.
 * Fortran will treat the dimension as assumed-length.
 * The Python wrapper will create a NumPy array or list so it must
 * have an explicit dimension (not assumed-length).
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  nvalues
// Requested: c_native_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  values
// Requested: c_native_*_out
// Match:     c_default
void POI_get_values(int * nvalues, int * values)
{
    // splicer begin function.get_values
    get_values(nvalues, values);
    // splicer end function.get_values
}

// void get_values2(int * arg1 +dimension(3)+intent(out), int * arg2 +dimension(3)+intent(out))
/**
 * \brief fill values into two arrays
 *
 * Test two intent(out) arguments.
 * Make sure error handling works with C++.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  arg1
// Requested: c_native_*_out
// Match:     c_default
// ----------------------------------------
// Argument:  arg2
// Requested: c_native_*_out
// Match:     c_default
void POI_get_values2(int * arg1, int * arg2)
{
    // splicer begin function.get_values2
    get_values2(arg1, arg2);
    // splicer end function.get_values2
}

// void iota_allocatable(int nvar +intent(in)+value, int * values +allocatable(nvar)+intent(out))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  nvar
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  values
// Requested: c_native_*_out
// Match:     c_default
void POI_iota_allocatable(int nvar, int * values)
{
    // splicer begin function.iota_allocatable
    iota_allocatable(nvar, values);
    // splicer end function.iota_allocatable
}

// void iota_dimension(int nvar +intent(in)+value, int * values +dimension(nvar)+intent(out))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  nvar
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  values
// Requested: c_native_*_out
// Match:     c_default
void POI_iota_dimension(int nvar, int * values)
{
    // splicer begin function.iota_dimension
    iota_dimension(nvar, values);
    // splicer end function.iota_dimension
}

// void Sum(int len +implied(size(values))+intent(in)+value, int * values +dimension(:)+intent(in), int * result +intent(out))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  len
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  values
// Requested: c_native_*_in
// Match:     c_default
// ----------------------------------------
// Argument:  result
// Requested: c_native_*_out
// Match:     c_default
// start POI_sum
void POI_sum(int len, int * values, int * result)
{
    // splicer begin function.sum
    Sum(len, values, result);
    // splicer end function.sum
}
// end POI_sum

// void fillIntArray(int * out +dimension(3)+intent(out))
/**
 * Return three values into memory the user provides.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  out
// Requested: c_native_*_out
// Match:     c_default
void POI_fill_int_array(int * out)
{
    // splicer begin function.fill_int_array
    fillIntArray(out);
    // splicer end function.fill_int_array
}

// void incrementIntArray(int * array +dimension(:)+intent(inout), int sizein +implied(size(array))+intent(in)+value)
/**
 * Increment array in place using intent(INOUT).
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  array
// Requested: c_native_*_inout
// Match:     c_default
// ----------------------------------------
// Argument:  sizein
// Requested: c_native_scalar_in
// Match:     c_default
void POI_increment_int_array(int * array, int sizein)
{
    // splicer begin function.increment_int_array
    incrementIntArray(array, sizein);
    // splicer end function.increment_int_array
}

// void acceptCharArrayIn(char * * names +dimension(:)+intent(in))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  names
// Requested: c_char_**_in
// Match:     c_default
void POI_accept_char_array_in(char * * names)
{
    // splicer begin function.accept_char_array_in
    acceptCharArrayIn(names);
    // splicer end function.accept_char_array_in
}

// void acceptCharArrayIn(char * * names +dimension(:)+intent(in)+len(Nnames)+size(Snames))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  names
// Exact:     c_char_**_in_buf
void POI_accept_char_array_in_bufferify(char *names, long Snames,
    int Nnames)
{
    // splicer begin function.accept_char_array_in_bufferify
    char **SHCXX_names = ShroudStrArrayAlloc(names, Snames, Nnames);
    acceptCharArrayIn(SHCXX_names);
    ShroudStrArrayFree(SHCXX_names, Snames);
    // splicer end function.accept_char_array_in_bufferify
}

// void setGlobalInt(int value +intent(in)+value)
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  value
// Requested: c_native_scalar_in
// Match:     c_default
void POI_set_global_int(int value)
{
    // splicer begin function.set_global_int
    setGlobalInt(value);
    // splicer end function.set_global_int
}

// int sumFixedArray()
/**
 * Used to test values global_array.
 */
// ----------------------------------------
// Result
// Requested: c_native_scalar_result
// Match:     c_default
int POI_sum_fixed_array()
{
    // splicer begin function.sum_fixed_array
    int SHC_rv = sumFixedArray();
    return SHC_rv;
    // splicer end function.sum_fixed_array
}

// void getPtrToScalar(int * * nitems +intent(out))
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  nitems
// Requested: c_native_**_out
// Match:     c_default
void POI_get_ptr_to_scalar(int * * nitems)
{
    // splicer begin function.get_ptr_to_scalar
    getPtrToScalar(nitems);
    // splicer end function.get_ptr_to_scalar
}

// void getPtrToFixedArray(int * * count +dimension(10)+intent(out))
/**
 * Return a Fortran pointer to an array which is always the same length.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  count
// Requested: c_native_**_out
// Match:     c_default
void POI_get_ptr_to_fixed_array(int * * count)
{
    // splicer begin function.get_ptr_to_fixed_array
    getPtrToFixedArray(count);
    // splicer end function.get_ptr_to_fixed_array
}

// void getRawPtrToScalar(int * * nitems +deref(raw)+intent(out))
/**
 * Called directly via an interface.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  nitems
// Requested: c_native_**_out
// Match:     c_default
void POI_get_raw_ptr_to_scalar(int * * nitems)
{
    // splicer begin function.get_raw_ptr_to_scalar
    getRawPtrToScalar(nitems);
    // splicer end function.get_raw_ptr_to_scalar
}

// void getRawPtrToFixedArray(int * * count +deref(raw)+intent(out))
/**
 * Return a type(C_PTR) to an array which is always the same length.
 * Called directly via an interface.
 * # Uses +deref(raw) instead of +dimension(10) like getPtrToFixedArray.
 */
// ----------------------------------------
// Result
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  count
// Requested: c_native_**_out
// Match:     c_default
void POI_get_raw_ptr_to_fixed_array(int * * count)
{
    // splicer begin function.get_raw_ptr_to_fixed_array
    getRawPtrToFixedArray(count);
    // splicer end function.get_raw_ptr_to_fixed_array
}

// void * returnAddress1(int flag +intent(in)+value)
// ----------------------------------------
// Result
// Requested: c_unknown_*_result
// Match:     c_default
// ----------------------------------------
// Argument:  flag
// Requested: c_native_scalar_in
// Match:     c_default
void * POI_return_address1(int flag)
{
    // splicer begin function.return_address1
    void * SHC_rv = returnAddress1(flag);
    return SHC_rv;
    // splicer end function.return_address1
}

// void * returnAddress2(int flag +intent(in)+value)
// ----------------------------------------
// Result
// Requested: c_unknown_*_result
// Match:     c_default
// ----------------------------------------
// Argument:  flag
// Requested: c_native_scalar_in
// Match:     c_default
void * POI_return_address2(int flag)
{
    // splicer begin function.return_address2
    void * SHC_rv = returnAddress2(flag);
    return SHC_rv;
    // splicer end function.return_address2
}

// start release allocated memory
// Release library allocated memory.
void POI_SHROUD_memory_destructor(POI_SHROUD_capsule_data *cap)
{
    cap->addr = nullptr;
    cap->idtor = 0;  // avoid deleting again
}
// end release allocated memory

}  // extern "C"
