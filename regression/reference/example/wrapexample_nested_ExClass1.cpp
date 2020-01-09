// wrapexample_nested_ExClass1.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapexample_nested_ExClass1.h"
#include <cstddef>
#include <cstring>
#include <string>
#include "ExClass1.hpp"

// splicer begin namespace.example::nested.class.ExClass1.CXX_definitions
//   namespace.example::nested.class.ExClass1.CXX_definitions
// splicer end namespace.example::nested.class.ExClass1.CXX_definitions

extern "C" {


// helper function
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

// helper function
// Save str metadata into array to allow Fortran to access values.
static void ShroudStrToArray(AA_SHROUD_array *array, const std::string * src, int idtor)
{
    array->cxx.addr = static_cast<void *>(const_cast<std::string *>(src));
    array->cxx.idtor = idtor;
    if (src->empty()) {
        array->addr.ccharp = NULL;
        array->elem_len = 0;
    } else {
        array->addr.ccharp = src->data();
        array->elem_len = src->length();
    }
    array->size = 1;
}

// helper function
// Copy the char* or std::string in context into c_var.
// Called by Fortran to deal with allocatable character.
void AA_ShroudCopyStringAndFree(AA_SHROUD_array *data, char *c_var, size_t c_var_len) {
    const char *cxx_var = data->addr.ccharp;
    size_t n = c_var_len;
    if (data->elem_len < n) n = data->elem_len;
    std::strncpy(c_var, cxx_var, n);
    AA_SHROUD_memory_destructor(&data->cxx); // delete data->cxx.addr
}

// splicer begin namespace.example::nested.class.ExClass1.C_definitions
// splicer end namespace.example::nested.class.ExClass1.C_definitions

// ExClass1()
AA_example_nested_ExClass1 * AA_example_nested_ExClass1_ctor_0(
    AA_example_nested_ExClass1 * SHC_rv)
{
    // splicer begin namespace.example::nested.class.ExClass1.method.ctor_0
    example::nested::ExClass1 *SHCXX_rv =
        new example::nested::ExClass1();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.ctor_0
}

// ExClass1(const string * name +intent(in))
/**
 * \brief constructor
 *
 * longer description
 * usually multiple lines
 *
 * \return return new instance
 */
AA_example_nested_ExClass1 * AA_example_nested_ExClass1_ctor_1(
    const char * name, AA_example_nested_ExClass1 * SHC_rv)
{
    // splicer begin namespace.example::nested.class.ExClass1.method.ctor_1
    const std::string SHCXX_name(name);
    example::nested::ExClass1 *SHCXX_rv =
        new example::nested::ExClass1(&SHCXX_name);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.ctor_1
}

// ExClass1(const string * name +intent(in)+len_trim(Lname))
/**
 * \brief constructor
 *
 * longer description
 * usually multiple lines
 *
 * \return return new instance
 */
AA_example_nested_ExClass1 * AA_example_nested_ExClass1_ctor_1_bufferify(
    const char * name, int Lname, AA_example_nested_ExClass1 * SHC_rv)
{
    // splicer begin namespace.example::nested.class.ExClass1.method.ctor_1_bufferify
    const std::string SHCXX_name(name, Lname);
    example::nested::ExClass1 *SHCXX_rv =
        new example::nested::ExClass1(&SHCXX_name);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.ctor_1_bufferify
}

// ~ExClass1()
/**
 * \brief destructor
 *
 * longer description joined with previous line
 */
void AA_example_nested_ExClass1_dtor(AA_example_nested_ExClass1 * self)
{
    example::nested::ExClass1 *SH_this =
        static_cast<example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.dtor
    delete SH_this;
    self->addr = NULL;
    return;
    // splicer end namespace.example::nested.class.ExClass1.method.dtor
}

// int incrementCount(int incr +intent(in)+value)
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

// const string & getNameErrorCheck() const +deref(allocatable)
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

// void getNameErrorCheck(const string & SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out)) const
void AA_example_nested_ExClass1_get_name_error_check_bufferify(
    const AA_example_nested_ExClass1 * self, AA_SHROUD_array *DSHF_rv)
{
    const example::nested::ExClass1 *SH_this =
        static_cast<const example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_name_error_check_bufferify
    const std::string & SHCXX_rv = SH_this->getNameErrorCheck();
    ShroudStrToArray(DSHF_rv, &SHCXX_rv, 0);
    return;
    // splicer end namespace.example::nested.class.ExClass1.method.get_name_error_check_bufferify
}

// const string & getNameArg() const +deref(result_as_arg)
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

// void getNameArg(string & name +intent(out)+len(Nname)) const
void AA_example_nested_ExClass1_get_name_arg_bufferify(
    const AA_example_nested_ExClass1 * self, char * name, int Nname)
{
    const example::nested::ExClass1 *SH_this =
        static_cast<const example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_name_arg_bufferify
    const std::string & SHCXX_rv = SH_this->getNameArg();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(name, Nname, NULL, 0);
    } else {
        ShroudStrCopy(name, Nname, SHCXX_rv.data(), SHCXX_rv.size());
    }
    return;
    // splicer end namespace.example::nested.class.ExClass1.method.get_name_arg_bufferify
}

// void * getRoot()
void * AA_example_nested_ExClass1_get_root(
    AA_example_nested_ExClass1 * self)
{
    example::nested::ExClass1 *SH_this =
        static_cast<example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_root
    void * SHC_rv = SH_this->getRoot();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.get_root
}

// int getValue(int value +intent(in)+value)
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

// long getValue(long value +intent(in)+value)
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

// void * getAddr()
void * AA_example_nested_ExClass1_get_addr(
    AA_example_nested_ExClass1 * self)
{
    example::nested::ExClass1 *SH_this =
        static_cast<example::nested::ExClass1 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass1.method.get_addr
    void * SHC_rv = SH_this->getAddr();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass1.method.get_addr
}

// bool hasAddr(bool in +intent(in)+value)
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

// void SplicerSpecial()
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
