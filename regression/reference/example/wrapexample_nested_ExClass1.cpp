// wrapexample_nested_ExClass1.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapexample_nested_ExClass1.h"

// cxx_header
#include "ExClass1.hpp"
// typemap
#include <string>
// shroud
#include <cstddef>
#include <cstring>

// splicer begin namespace.example::nested.class.ExClass1.CXX_definitions
//   namespace.example::nested.class.ExClass1.CXX_definitions
// splicer end namespace.example::nested.class.ExClass1.CXX_definitions

extern "C" {


// helper ShroudStrCopy
// Copy src into dest, blank fill to ndest characters
// Truncate if dest is too short.
// dest will not be NULL terminated.
static void ShroudStrCopy(char *dest, int ndest, const char *src, int nsrc)
{
   if (src == NULL) {
     std::memset(dest,' ',ndest); // convert NULL pointer to blank filled string
   } else {
     if (nsrc < 0) nsrc = std::strlen(src);
     int nm = nsrc < ndest ? nsrc : ndest;
     std::memcpy(dest,src,nm);
     if(ndest > nm) std::memset(dest+nm,' ',ndest-nm); // blank fill
   }
}

// helper ShroudStrToArray
// Save str metadata into array to allow Fortran to access values.
// CHARACTER(len=elem_size) src
static void ShroudStrToArray(AA_SHROUD_array *array, const std::string * src, int idtor)
{
    array->cxx.addr = const_cast<std::string *>(src);
    array->cxx.idtor = idtor;
    if (src->empty()) {
        array->addr.ccharp = NULL;
        array->elem_len = 0;
    } else {
        array->addr.ccharp = src->data();
        array->elem_len = src->length();
    }
    array->size = 1;
    array->rank = 0;  // scalar
}
// splicer begin namespace.example::nested.class.ExClass1.C_definitions
// splicer end namespace.example::nested.class.ExClass1.C_definitions

// ----------------------------------------
// Function:  ExClass1
// Attrs:     +intent(ctor)
// Requested: c_ctor_shadow_scalar
// Match:     c_ctor
AA_example_nested_ExClass1 * AA_example_nested_ExClass1_ctor_0(
    AA_example_nested_ExClass1 * SHadow_rv)
{
    // splicer begin namespace.example::nested.class.ExClass1.method.ctor_0
    example::nested::ExClass1 *SHCXX_rv =
        new example::nested::ExClass1();
    SHadow_rv->addr = static_cast<void *>(SHCXX_rv);
    SHadow_rv->idtor = 1;
    return SHadow_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.ctor_0
}

/**
 * \brief constructor
 *
 * longer description
 * usually multiple lines
 *
 * \return return new instance
 */
// ----------------------------------------
// Function:  ExClass1
// Attrs:     +intent(ctor)
// Requested: c_ctor_shadow_scalar
// Match:     c_ctor
// ----------------------------------------
// Argument:  const string * name
// Attrs:     +intent(in)
// Exact:     c_in_string_*
AA_example_nested_ExClass1 * AA_example_nested_ExClass1_ctor_1(
    const char * name, AA_example_nested_ExClass1 * SHadow_rv)
{
    // splicer begin namespace.example::nested.class.ExClass1.method.ctor_1
    const std::string SHCXX_name(name);
    example::nested::ExClass1 *SHCXX_rv =
        new example::nested::ExClass1(&SHCXX_name);
    SHadow_rv->addr = static_cast<void *>(SHCXX_rv);
    SHadow_rv->idtor = 1;
    return SHadow_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.ctor_1
}

/**
 * \brief constructor
 *
 * longer description
 * usually multiple lines
 *
 * \return return new instance
 */
// ----------------------------------------
// Function:  ExClass1
// Attrs:     +intent(ctor)
// Requested: c_ctor_shadow_scalar
// Match:     c_ctor
// ----------------------------------------
// Argument:  const string * name +len_trim(Lname)
// Attrs:     +api(buf)+intent(in)
// Exact:     c_in_string_*_buf
AA_example_nested_ExClass1 * AA_example_nested_ExClass1_ctor_1_bufferify(
    const char * name, int Lname,
    AA_example_nested_ExClass1 * SHadow_rv)
{
    // splicer begin namespace.example::nested.class.ExClass1.method.ctor_1_bufferify
    const std::string SHCXX_name(name, Lname);
    example::nested::ExClass1 *SHCXX_rv =
        new example::nested::ExClass1(&SHCXX_name);
    SHadow_rv->addr = static_cast<void *>(SHCXX_rv);
    SHadow_rv->idtor = 1;
    return SHadow_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.ctor_1_bufferify
}

/**
 * \brief destructor
 *
 * longer description joined with previous line
 */
// ----------------------------------------
// Function:  ~ExClass1
// Attrs:     +intent(dtor)
// Exact:     c_dtor
void AA_example_nested_ExClass1_dtor(AA_example_nested_ExClass1 * self)
{
    example::nested::ExClass1 *SH_this =
        static_cast<example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.dtor
    delete SH_this;
    self->addr = nullptr;
    // splicer end namespace.example::nested.class.ExClass1.method.dtor
}

// ----------------------------------------
// Function:  int incrementCount
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int incr +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
int AA_example_nested_ExClass1_increment_count(
    AA_example_nested_ExClass1 * self, int incr)
{
    example::nested::ExClass1 *SH_this =
        static_cast<example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.increment_count
    int SHC_rv = SH_this->incrementCount(incr);
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.increment_count
}

// ----------------------------------------
// Function:  const string & getNameErrorCheck
// Attrs:     +deref(allocatable)+intent(function)
// Requested: c_function_string_&_allocatable
// Match:     c_function_string_&
const char * AA_example_nested_ExClass1_get_name_error_check(
    const AA_example_nested_ExClass1 * self)
{
    const example::nested::ExClass1 *SH_this =
        static_cast<const example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_name_error_check
    const std::string & SHCXX_rv = SH_this->getNameErrorCheck();
    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.get_name_error_check
}

// ----------------------------------------
// Function:  const string & getNameErrorCheck
// Attrs:     +api(buf)+deref(allocatable)+intent(function)
// Exact:     c_function_string_&_buf_allocatable
void AA_example_nested_ExClass1_get_name_error_check_bufferify(
    const AA_example_nested_ExClass1 * self,
    AA_SHROUD_array *SHC_rv_temp0)
{
    const example::nested::ExClass1 *SH_this =
        static_cast<const example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_name_error_check_bufferify
    const std::string & SHCXX_rv = SH_this->getNameErrorCheck();
    ShroudStrToArray(SHC_rv_temp0, &SHCXX_rv, 0);
    // splicer end namespace.example::nested.class.ExClass1.method.get_name_error_check_bufferify
}

// ----------------------------------------
// Function:  const string & getNameArg
// Attrs:     +intent(function)
// Exact:     c_function_string_&
const char * AA_example_nested_ExClass1_get_name_arg(
    const AA_example_nested_ExClass1 * self)
{
    const example::nested::ExClass1 *SH_this =
        static_cast<const example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_name_arg
    const std::string & SHCXX_rv = SH_this->getNameArg();
    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.get_name_arg
}

// ----------------------------------------
// Function:  void getNameArg
// Attrs:     +api(buf)+intent(subroutine)
// Requested: c_subroutine_void_scalar_buf
// Match:     c_subroutine
// ----------------------------------------
// Argument:  string & name
// Attrs:     +api(buf)+deref(result)+intent(out)+is_result
// Requested: c_function_string_&_buf_result
// Match:     c_function_string_&_buf
void AA_example_nested_ExClass1_get_name_arg_bufferify(
    const AA_example_nested_ExClass1 * self, char *name, int name_temp0)
{
    const example::nested::ExClass1 *SH_this =
        static_cast<const example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_name_arg_bufferify
    const std::string & SHCXX_rv = SH_this->getNameArg();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(name, name_temp0, nullptr, 0);
    } else {
        ShroudStrCopy(name, name_temp0, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    // splicer end namespace.example::nested.class.ExClass1.method.get_name_arg_bufferify
}

// ----------------------------------------
// Function:  int getValue
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int value +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
int AA_example_nested_ExClass1_get_value_from_int(
    AA_example_nested_ExClass1 * self, int value)
{
    example::nested::ExClass1 *SH_this =
        static_cast<example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_value_from_int
    int SHC_rv = SH_this->getValue(value);
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.get_value_from_int
}

// ----------------------------------------
// Function:  long getValue
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  long value +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
long AA_example_nested_ExClass1_get_value_1(
    AA_example_nested_ExClass1 * self, long value)
{
    example::nested::ExClass1 *SH_this =
        static_cast<example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_value_1
    long SHC_rv = SH_this->getValue(value);
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.get_value_1
}

// ----------------------------------------
// Function:  bool hasAddr
// Attrs:     +intent(function)
// Requested: c_function_bool_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  bool in +value
// Attrs:     +intent(in)
// Requested: c_in_bool_scalar
// Match:     c_default
bool AA_example_nested_ExClass1_has_addr(
    AA_example_nested_ExClass1 * self, bool in)
{
    example::nested::ExClass1 *SH_this =
        static_cast<example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.has_addr
    bool SHC_rv = SH_this->hasAddr(in);
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.has_addr
}

// ----------------------------------------
// Function:  void SplicerSpecial
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
void AA_example_nested_ExClass1_splicer_special(
    AA_example_nested_ExClass1 * self)
{
    example::nested::ExClass1 *SH_this =
        static_cast<example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.splicer_special
    //   splicer for SplicerSpecial
    // splicer end namespace.example::nested.class.ExClass1.method.splicer_special
}

}  // extern "C"
