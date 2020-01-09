// wrapexample_nested_ExClass2.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapexample_nested_ExClass2.h"
#include <cstddef>
#include <cstring>
#include <string>
#include "ExClass1.hpp"
#include "ExClass2.hpp"

// splicer begin namespace.example::nested.class.ExClass2.CXX_definitions
//   namespace.example::nested.class.ExClass2.CXX_definitions
// splicer end namespace.example::nested.class.ExClass2.CXX_definitions

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

// splicer begin namespace.example::nested.class.ExClass2.C_definitions
// splicer end namespace.example::nested.class.ExClass2.C_definitions

// ExClass2(const string * name +intent(in)+len_trim(trim_name))
/**
 * \brief constructor
 *
 */
AA_example_nested_ExClass2 * AA_example_nested_ExClass2_ctor(
    const char * name, AA_example_nested_ExClass2 * SHC_rv)
{
    // splicer begin namespace.example::nested.class.ExClass2.method.ctor
    const std::string SHCXX_name(name);
    example::nested::ExClass2 *SHCXX_rv =
        new example::nested::ExClass2(&SHCXX_name);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.ctor
}

// ExClass2(const string * name +intent(in)+len_trim(trim_name))
/**
 * \brief constructor
 *
 */
AA_example_nested_ExClass2 * AA_example_nested_ExClass2_ctor_bufferify(
    const char * name, int trim_name,
    AA_example_nested_ExClass2 * SHC_rv)
{
    // splicer begin namespace.example::nested.class.ExClass2.method.ctor_bufferify
    const std::string SHCXX_name(name, trim_name);
    example::nested::ExClass2 *SHCXX_rv =
        new example::nested::ExClass2(&SHCXX_name);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.ctor_bufferify
}

// ~ExClass2()
/**
 * \brief destructor
 *
 */
void AA_example_nested_ExClass2_dtor(AA_example_nested_ExClass2 * self)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.dtor
    delete SH_this;
    self->addr = NULL;
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.dtor
}

// const string & getName() const +deref(result_as_arg)+len(aa_exclass2_get_name_length({F_this}%{F_derived_member}))
const char * AA_example_nested_ExClass2_get_name(
    const AA_example_nested_ExClass2 * self)
{
    const example::nested::ExClass2 *SH_this =
        static_cast<const example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_name
    const std::string & SHCXX_rv = SH_this->getName();
    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.get_name
}

// void getName(string & SHF_rv +intent(out)+len(NSHF_rv)) const +len(aa_exclass2_get_name_length({F_this}%{F_derived_member}))
void AA_example_nested_ExClass2_get_name_bufferify(
    const AA_example_nested_ExClass2 * self, char * SHF_rv, int NSHF_rv)
{
    const example::nested::ExClass2 *SH_this =
        static_cast<const example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_name_bufferify
    const std::string & SHCXX_rv = SH_this->getName();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(SHF_rv, NSHF_rv, NULL, 0);
    } else {
        ShroudStrCopy(SHF_rv, NSHF_rv, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.get_name_bufferify
}

// const string & getName2() +deref(allocatable)
const char * AA_example_nested_ExClass2_get_name2(
    AA_example_nested_ExClass2 * self)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_name2
    const std::string & SHCXX_rv = SH_this->getName2();
    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.get_name2
}

// void getName2(const string & SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out))
void AA_example_nested_ExClass2_get_name2_bufferify(
    AA_example_nested_ExClass2 * self, AA_SHROUD_array *DSHF_rv)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_name2_bufferify
    const std::string & SHCXX_rv = SH_this->getName2();
    ShroudStrToArray(DSHF_rv, &SHCXX_rv, 0);
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.get_name2_bufferify
}

// string & getName3() const +deref(allocatable)
char * AA_example_nested_ExClass2_get_name3(
    const AA_example_nested_ExClass2 * self)
{
    const example::nested::ExClass2 *SH_this =
        static_cast<const example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_name3
    std::string & SHCXX_rv = SH_this->getName3();
    char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.get_name3
}

// void getName3(string & SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out)) const
void AA_example_nested_ExClass2_get_name3_bufferify(
    const AA_example_nested_ExClass2 * self, AA_SHROUD_array *DSHF_rv)
{
    const example::nested::ExClass2 *SH_this =
        static_cast<const example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_name3_bufferify
    std::string & SHCXX_rv = SH_this->getName3();
    ShroudStrToArray(DSHF_rv, &SHCXX_rv, 0);
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.get_name3_bufferify
}

// string & getName4() +deref(allocatable)
char * AA_example_nested_ExClass2_get_name4(
    AA_example_nested_ExClass2 * self)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_name4
    std::string & SHCXX_rv = SH_this->getName4();
    char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.get_name4
}

// void getName4(string & SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out))
void AA_example_nested_ExClass2_get_name4_bufferify(
    AA_example_nested_ExClass2 * self, AA_SHROUD_array *DSHF_rv)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_name4_bufferify
    std::string & SHCXX_rv = SH_this->getName4();
    ShroudStrToArray(DSHF_rv, &SHCXX_rv, 0);
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.get_name4_bufferify
}

// int GetNameLength() const
/**
 * \brief helper function for Fortran
 *
 */
int AA_example_nested_ExClass2_get_name_length(
    const AA_example_nested_ExClass2 * self)
{
    const example::nested::ExClass2 *SH_this =
        static_cast<const example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_name_length
    return SH_this->getName().length();
    // splicer end namespace.example::nested.class.ExClass2.method.get_name_length
}

// ExClass1 * get_class1(const ExClass1 * in +intent(in))
AA_example_nested_ExClass1 * AA_example_nested_ExClass2_get_class1(
    AA_example_nested_ExClass2 * self, AA_example_nested_ExClass1 * in,
    AA_example_nested_ExClass1 * SHC_rv)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_class1
    const example::nested::ExClass1 * SHCXX_in =
        static_cast<const example::nested::ExClass1 *>(in->addr);
    example::nested::ExClass1 * SHCXX_rv = SH_this->get_class1(
        SHCXX_in);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.get_class1
}

// void * declare(TypeID type +intent(in)+value)
void AA_example_nested_ExClass2_declare_0(
    AA_example_nested_ExClass2 * self, int type)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.declare_0
    TypeID SHCXX_type = getTypeID(type);
    SH_this->declare(SHCXX_type);
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.declare_0
}

// void * declare(TypeID type +intent(in)+value, SidreLength len=1 +intent(in)+value)
void AA_example_nested_ExClass2_declare_1(
    AA_example_nested_ExClass2 * self, int type, SIDRE_SidreLength len)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.declare_1
    TypeID SHCXX_type = getTypeID(type);
    SH_this->declare(SHCXX_type, len);
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.declare_1
}

// void destroyall()
void AA_example_nested_ExClass2_destroyall(
    AA_example_nested_ExClass2 * self)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.destroyall
    SH_this->destroyall();
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.destroyall
}

// TypeID getTypeID() const
int AA_example_nested_ExClass2_get_type_id(
    const AA_example_nested_ExClass2 * self)
{
    const example::nested::ExClass2 *SH_this =
        static_cast<const example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_type_id
    TypeID SHCXX_rv = SH_this->getTypeID();
    int SHC_rv = static_cast<int>(SHCXX_rv);
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.get_type_id
}

// void setValue(int value +intent(in)+value)
void AA_example_nested_ExClass2_set_value_int(
    AA_example_nested_ExClass2 * self, int value)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.set_value_int
    SH_this->setValue<int>(value);
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.set_value_int
}

// void setValue(long value +intent(in)+value)
void AA_example_nested_ExClass2_set_value_long(
    AA_example_nested_ExClass2 * self, long value)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.set_value_long
    SH_this->setValue<long>(value);
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.set_value_long
}

// void setValue(float value +intent(in)+value)
void AA_example_nested_ExClass2_set_value_float(
    AA_example_nested_ExClass2 * self, float value)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.set_value_float
    SH_this->setValue<float>(value);
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.set_value_float
}

// void setValue(double value +intent(in)+value)
void AA_example_nested_ExClass2_set_value_double(
    AA_example_nested_ExClass2 * self, double value)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.set_value_double
    SH_this->setValue<double>(value);
    return;
    // splicer end namespace.example::nested.class.ExClass2.method.set_value_double
}

// int getValue()
int AA_example_nested_ExClass2_get_value_int(
    AA_example_nested_ExClass2 * self)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_value_int
    int SHC_rv = SH_this->getValue<int>();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.get_value_int
}

// double getValue()
double AA_example_nested_ExClass2_get_value_double(
    AA_example_nested_ExClass2 * self)
{
    example::nested::ExClass2 *SH_this =
        static_cast<example::nested::ExClass2 *>(self->addr);
    // splicer begin namespace.example::nested.class.ExClass2.method.get_value_double
    double SHC_rv = SH_this->getValue<double>();
    return SHC_rv;
    // splicer end namespace.example::nested.class.ExClass2.method.get_value_double
}

}  // extern "C"
