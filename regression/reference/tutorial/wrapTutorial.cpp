// wrapTutorial.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapTutorial.h"

// cxx_header
#include "tutorial.hpp"
// typemap
#include <string>
// shroud
#include "typesTutorial.h"
#include <cstdlib>
#include <cstddef>
#include <cstring>

// splicer begin CXX_definitions
// splicer end CXX_definitions

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

// start helper ShroudStrToArray
// helper ShroudStrToArray
// Save str metadata into array to allow Fortran to access values.
// CHARACTER(len=elem_size) src
static void ShroudStrToArray(TUT_SHROUD_array *array, const std::string * src, int idtor)
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
// end helper ShroudStrToArray
// splicer begin C_definitions
// splicer end C_definitions

// ----------------------------------------
// Function:  void NoReturnNoArguments
// Requested: c
// Match:     c_default
// start TUT_no_return_no_arguments
void TUT_no_return_no_arguments(void)
{
    // splicer begin function.no_return_no_arguments
    tutorial::NoReturnNoArguments();
    // splicer end function.no_return_no_arguments
}
// end TUT_no_return_no_arguments

// ----------------------------------------
// Function:  double PassByValue
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  double arg1 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int arg2 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
double TUT_pass_by_value(double arg1, int arg2)
{
    // splicer begin function.pass_by_value
    double SHC_rv = tutorial::PassByValue(arg1, arg2);
    return SHC_rv;
    // splicer end function.pass_by_value
}

/**
 * Note that since a reference is returned, no intermediate string
 * is allocated.  It is assumed +owner(library).
 */
// ----------------------------------------
// Function:  const std::string ConcatenateStrings
// Attrs:     +deref(allocatable)+intent(result)
// Exact:     c_string_scalar_result_buf_allocatable
// ----------------------------------------
// Argument:  const std::string & arg1 +len_trim(Larg1)
// Attrs:     +intent(in)
// Exact:     c_string_&_in_buf
// ----------------------------------------
// Argument:  const std::string & arg2 +len_trim(Larg2)
// Attrs:     +intent(in)
// Exact:     c_string_&_in_buf
void TUT_concatenate_strings_bufferify(TUT_SHROUD_array *SHC_rv_temp0,
    const char * arg1, int Larg1, const char * arg2, int Larg2)
{
    // splicer begin function.concatenate_strings_bufferify
    const std::string SHCXX_arg1(arg1, Larg1);
    const std::string SHCXX_arg2(arg2, Larg2);
    std::string * SHCXX_rv = new std::string;
    *SHCXX_rv = tutorial::ConcatenateStrings(SHCXX_arg1, SHCXX_arg2);
    ShroudStrToArray(SHC_rv_temp0, SHCXX_rv, 1);
    // splicer end function.concatenate_strings_bufferify
}

// ----------------------------------------
// Function:  double UseDefaultArguments
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// start TUT_use_default_arguments
double TUT_use_default_arguments(void)
{
    // splicer begin function.use_default_arguments
    double SHC_rv = tutorial::UseDefaultArguments();
    return SHC_rv;
    // splicer end function.use_default_arguments
}
// end TUT_use_default_arguments

// ----------------------------------------
// Function:  double UseDefaultArguments
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  double arg1=3.1415 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// start TUT_use_default_arguments_arg1
double TUT_use_default_arguments_arg1(double arg1)
{
    // splicer begin function.use_default_arguments_arg1
    double SHC_rv = tutorial::UseDefaultArguments(arg1);
    return SHC_rv;
    // splicer end function.use_default_arguments_arg1
}
// end TUT_use_default_arguments_arg1

// ----------------------------------------
// Function:  double UseDefaultArguments
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  double arg1=3.1415 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  bool arg2=true +value
// Attrs:     +intent(in)
// Requested: c_bool_scalar_in
// Match:     c_default
// start TUT_use_default_arguments_arg1_arg2
double TUT_use_default_arguments_arg1_arg2(double arg1, bool arg2)
{
    // splicer begin function.use_default_arguments_arg1_arg2
    double SHC_rv = tutorial::UseDefaultArguments(arg1, arg2);
    return SHC_rv;
    // splicer end function.use_default_arguments_arg1_arg2
}
// end TUT_use_default_arguments_arg1_arg2

// ----------------------------------------
// Function:  void OverloadedFunction
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const std::string & name
// Attrs:     +intent(in)
// Exact:     c_string_&_in
void TUT_overloaded_function_from_name(const char * name)
{
    // splicer begin function.overloaded_function_from_name
    const std::string SHCXX_name(name);
    tutorial::OverloadedFunction(SHCXX_name);
    // splicer end function.overloaded_function_from_name
}

// ----------------------------------------
// Function:  void OverloadedFunction
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const std::string & name +len_trim(Lname)
// Attrs:     +intent(in)
// Exact:     c_string_&_in_buf
void TUT_overloaded_function_from_name_bufferify(const char * name,
    int Lname)
{
    // splicer begin function.overloaded_function_from_name_bufferify
    const std::string SHCXX_name(name, Lname);
    tutorial::OverloadedFunction(SHCXX_name);
    // splicer end function.overloaded_function_from_name_bufferify
}

// ----------------------------------------
// Function:  void OverloadedFunction
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int indx +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void TUT_overloaded_function_from_index(int indx)
{
    // splicer begin function.overloaded_function_from_index
    tutorial::OverloadedFunction(indx);
    // splicer end function.overloaded_function_from_index
}

// ----------------------------------------
// Function:  void TemplateArgument
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int arg +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void TUT_template_argument_int(int arg)
{
    // splicer begin function.template_argument_int
    tutorial::TemplateArgument<int>(arg);
    // splicer end function.template_argument_int
}

// ----------------------------------------
// Function:  void TemplateArgument
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  double arg +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void TUT_template_argument_double(double arg)
{
    // splicer begin function.template_argument_double
    tutorial::TemplateArgument<double>(arg);
    // splicer end function.template_argument_double
}

// ----------------------------------------
// Function:  int TemplateReturn
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
int TUT_template_return_int(void)
{
    // splicer begin function.template_return_int
    int SHC_rv = tutorial::TemplateReturn<int>();
    return SHC_rv;
    // splicer end function.template_return_int
}

// ----------------------------------------
// Function:  double TemplateReturn
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
double TUT_template_return_double(void)
{
    // splicer begin function.template_return_double
    double SHC_rv = tutorial::TemplateReturn<double>();
    return SHC_rv;
    // splicer end function.template_return_double
}

// ----------------------------------------
// Function:  void FortranGenericOverloaded
// Requested: c
// Match:     c_default
void TUT_fortran_generic_overloaded_0(void)
{
    // splicer begin function.fortran_generic_overloaded_0
    tutorial::FortranGenericOverloaded();
    // splicer end function.fortran_generic_overloaded_0
}

// ----------------------------------------
// Function:  void FortranGenericOverloaded
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const std::string & name
// Attrs:     +intent(in)
// Exact:     c_string_&_in
// ----------------------------------------
// Argument:  double arg2 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void TUT_fortran_generic_overloaded_1(const char * name, double arg2)
{
    // splicer begin function.fortran_generic_overloaded_1
    const std::string SHCXX_name(name);
    tutorial::FortranGenericOverloaded(SHCXX_name, arg2);
    // splicer end function.fortran_generic_overloaded_1
}

// ----------------------------------------
// Function:  void FortranGenericOverloaded
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const std::string & name +len_trim(Lname)
// Attrs:     +intent(in)
// Exact:     c_string_&_in_buf
// ----------------------------------------
// Argument:  double arg2 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
void TUT_fortran_generic_overloaded_1_bufferify(const char * name,
    int Lname, double arg2)
{
    // splicer begin function.fortran_generic_overloaded_1_bufferify
    const std::string SHCXX_name(name, Lname);
    tutorial::FortranGenericOverloaded(SHCXX_name, arg2);
    // splicer end function.fortran_generic_overloaded_1_bufferify
}

// ----------------------------------------
// Function:  int UseDefaultOverload
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  int num +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int TUT_use_default_overload_num(int num)
{
    // splicer begin function.use_default_overload_num
    int SHC_rv = tutorial::UseDefaultOverload(num);
    return SHC_rv;
    // splicer end function.use_default_overload_num
}

// ----------------------------------------
// Function:  int UseDefaultOverload
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  int num +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int offset=0 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int TUT_use_default_overload_num_offset(int num, int offset)
{
    // splicer begin function.use_default_overload_num_offset
    int SHC_rv = tutorial::UseDefaultOverload(num, offset);
    return SHC_rv;
    // splicer end function.use_default_overload_num_offset
}

// ----------------------------------------
// Function:  int UseDefaultOverload
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  int num +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int offset=0 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int stride=1 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int TUT_use_default_overload_num_offset_stride(int num, int offset,
    int stride)
{
    // splicer begin function.use_default_overload_num_offset_stride
    int SHC_rv = tutorial::UseDefaultOverload(num, offset, stride);
    return SHC_rv;
    // splicer end function.use_default_overload_num_offset_stride
}

// ----------------------------------------
// Function:  int UseDefaultOverload
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  double type +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int num +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int TUT_use_default_overload_3(double type, int num)
{
    // splicer begin function.use_default_overload_3
    int SHC_rv = tutorial::UseDefaultOverload(type, num);
    return SHC_rv;
    // splicer end function.use_default_overload_3
}

// ----------------------------------------
// Function:  int UseDefaultOverload
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  double type +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int num +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int offset=0 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int TUT_use_default_overload_4(double type, int num, int offset)
{
    // splicer begin function.use_default_overload_4
    int SHC_rv = tutorial::UseDefaultOverload(type, num, offset);
    return SHC_rv;
    // splicer end function.use_default_overload_4
}

// ----------------------------------------
// Function:  int UseDefaultOverload
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  double type +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int num +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int offset=0 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int stride=1 +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int TUT_use_default_overload_5(double type, int num, int offset,
    int stride)
{
    // splicer begin function.use_default_overload_5
    int SHC_rv = tutorial::UseDefaultOverload(type, num, offset,
        stride);
    return SHC_rv;
    // splicer end function.use_default_overload_5
}

// ----------------------------------------
// Function:  TypeID typefunc
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  TypeID arg +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int TUT_typefunc(int arg)
{
    // splicer begin function.typefunc
    tutorial::TypeID SHC_rv = tutorial::typefunc(arg);
    return SHC_rv;
    // splicer end function.typefunc
}

// ----------------------------------------
// Function:  EnumTypeID enumfunc
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  EnumTypeID arg +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int TUT_enumfunc(int arg)
{
    // splicer begin function.enumfunc
    tutorial::EnumTypeID SHCXX_arg =
        static_cast<tutorial::EnumTypeID>(arg);
    tutorial::EnumTypeID SHCXX_rv = tutorial::enumfunc(SHCXX_arg);
    int SHC_rv = static_cast<int>(SHCXX_rv);
    return SHC_rv;
    // splicer end function.enumfunc
}

// ----------------------------------------
// Function:  Color colorfunc
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  Color arg +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
int TUT_colorfunc(int arg)
{
    // splicer begin function.colorfunc
    tutorial::Color SHCXX_arg = static_cast<tutorial::Color>(arg);
    tutorial::Color SHCXX_rv = tutorial::colorfunc(SHCXX_arg);
    int SHC_rv = static_cast<int>(SHCXX_rv);
    return SHC_rv;
    // splicer end function.colorfunc
}

/**
 * \brief Pass in reference to scalar
 *
 */
// ----------------------------------------
// Function:  void getMinMax
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int & min +intent(out)
// Attrs:     +intent(out)
// Requested: c_native_&_out
// Match:     c_default
// ----------------------------------------
// Argument:  int & max +intent(out)
// Attrs:     +intent(out)
// Requested: c_native_&_out
// Match:     c_default
// start TUT_get_min_max
void TUT_get_min_max(int * min, int * max)
{
    // splicer begin function.get_min_max
    tutorial::getMinMax(*min, *max);
    // splicer end function.get_min_max
}
// end TUT_get_min_max

/**
 * \brief Test function pointer
 *
 */
// ----------------------------------------
// Function:  int callback1
// Attrs:     +intent(result)
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  int in +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// ----------------------------------------
// Argument:  int ( * incr)(int +value) +value
// Attrs:     +intent(in)
// Requested: c_native_scalar_in
// Match:     c_default
// start TUT_callback1
int TUT_callback1(int in, int ( * incr)(int))
{
    // splicer begin function.callback1
    int SHC_rv = tutorial::callback1(in, incr);
    return SHC_rv;
    // splicer end function.callback1
}
// end TUT_callback1

// ----------------------------------------
// Function:  const std::string & LastFunctionCalled +len(30)
// Attrs:     +deref(result-as-arg)+intent(result)
// Requested: c_string_&_result_result-as-arg
// Match:     c_string_&_result
const char * TUT_last_function_called(void)
{
    // splicer begin function.last_function_called
    const std::string & SHCXX_rv = tutorial::LastFunctionCalled();
    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end function.last_function_called
}

// ----------------------------------------
// Function:  void LastFunctionCalled +len(30)
// Requested: c_void_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  std::string & SHF_rv +len(NSHF_rv)
// Attrs:     +intent(out)+is_result
// Exact:     c_string_&_result_buf
void TUT_last_function_called_bufferify(char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.last_function_called_bufferify
    const std::string & SHCXX_rv = tutorial::LastFunctionCalled();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(SHF_rv, NSHF_rv, nullptr, 0);
    } else {
        ShroudStrCopy(SHF_rv, NSHF_rv, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    // splicer end function.last_function_called_bufferify
}

// start release allocated memory
// Release library allocated memory.
void TUT_SHROUD_memory_destructor(TUT_SHROUD_capsule_data *cap)
{
    void *ptr = cap->addr;
    switch (cap->idtor) {
    case 0:   // --none--
    {
        // Nothing to delete
        break;
    }
    case 1:   // new_string
    {
        std::string *cxx_ptr = reinterpret_cast<std::string *>(ptr);
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
// end release allocated memory

}  // extern "C"
