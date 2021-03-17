// wrapUserLibrary_example_nested.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapUserLibrary_example_nested.h"

// typemap
#include <string>

// splicer begin namespace.example::nested.CXX_definitions
// splicer end namespace.example::nested.CXX_definitions

extern "C" {

// splicer begin namespace.example::nested.C_definitions
// splicer end namespace.example::nested.C_definitions

// ----------------------------------------
// Function:  void local_function1
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
void AA_example_nested_local_function1(void)
{
    // splicer begin namespace.example::nested.function.local_function1
    example::nested::local_function1();
    // splicer end namespace.example::nested.function.local_function1
}

// ----------------------------------------
// Function:  bool isNameValid
// Attrs:     +intent(function)
// Requested: c_function_bool_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  const std::string & name
// Attrs:     +intent(in)
// Exact:     c_in_string_&
bool AA_example_nested_is_name_valid(const char * name)
{
    // splicer begin namespace.example::nested.function.is_name_valid
    return name != NULL;
    // splicer end namespace.example::nested.function.is_name_valid
}

// ----------------------------------------
// Function:  bool isNameValid
// Attrs:     +intent(function)
// Requested: c_function_bool_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  const std::string & name +len_trim(Lname)
// Attrs:     +api(buf)+intent(in)
// Exact:     c_in_string_&_buf
bool AA_example_nested_is_name_valid_bufferify(const char * name,
    int Lname)
{
    // splicer begin namespace.example::nested.function.is_name_valid_bufferify
    return name != NULL;
    // splicer end namespace.example::nested.function.is_name_valid_bufferify
}

// ----------------------------------------
// Function:  bool isInitialized
// Attrs:     +intent(function)
// Requested: c_function_bool_scalar
// Match:     c_default
bool AA_example_nested_is_initialized(void)
{
    // splicer begin namespace.example::nested.function.is_initialized
    bool SHC_rv = example::nested::isInitialized();
    return SHC_rv;
    // splicer end namespace.example::nested.function.is_initialized
}

// ----------------------------------------
// Function:  void test_names
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  const std::string & name
// Attrs:     +intent(in)
// Exact:     c_in_string_&
void AA_example_nested_test_names(const char * name)
{
    // splicer begin namespace.example::nested.function.test_names
    const std::string SHCXX_name(name);
    example::nested::test_names(SHCXX_name);
    // splicer end namespace.example::nested.function.test_names
}

// ----------------------------------------
// Function:  void test_names
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  const std::string & name +len_trim(Lname)
// Attrs:     +api(buf)+intent(in)
// Exact:     c_in_string_&_buf
void AA_example_nested_test_names_bufferify(const char * name,
    int Lname)
{
    // splicer begin namespace.example::nested.function.test_names_bufferify
    const std::string SHCXX_name(name, Lname);
    example::nested::test_names(SHCXX_name);
    // splicer end namespace.example::nested.function.test_names_bufferify
}

// ----------------------------------------
// Function:  void test_names
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  const std::string & name
// Attrs:     +intent(in)
// Exact:     c_in_string_&
// ----------------------------------------
// Argument:  int flag +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void AA_example_nested_test_names_flag(const char * name, int flag)
{
    // splicer begin namespace.example::nested.function.test_names_flag
    const std::string SHCXX_name(name);
    example::nested::test_names(SHCXX_name, flag);
    // splicer end namespace.example::nested.function.test_names_flag
}

// ----------------------------------------
// Function:  void test_names
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  const std::string & name +len_trim(Lname)
// Attrs:     +api(buf)+intent(in)
// Exact:     c_in_string_&_buf
// ----------------------------------------
// Argument:  int flag +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void AA_example_nested_test_names_flag_bufferify(const char * name,
    int Lname, int flag)
{
    // splicer begin namespace.example::nested.function.test_names_flag_bufferify
    const std::string SHCXX_name(name, Lname);
    example::nested::test_names(SHCXX_name, flag);
    // splicer end namespace.example::nested.function.test_names_flag_bufferify
}

// ----------------------------------------
// Function:  void testoptional
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
void AA_example_nested_testoptional_0(void)
{
    // splicer begin namespace.example::nested.function.testoptional_0
    example::nested::testoptional();
    // splicer end namespace.example::nested.function.testoptional_0
}

// ----------------------------------------
// Function:  void testoptional
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  int i=1 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void AA_example_nested_testoptional_1(int i)
{
    // splicer begin namespace.example::nested.function.testoptional_1
    example::nested::testoptional(i);
    // splicer end namespace.example::nested.function.testoptional_1
}

// ----------------------------------------
// Function:  void testoptional
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  int i=1 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  long j=2 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void AA_example_nested_testoptional_2(int i, long j)
{
    // splicer begin namespace.example::nested.function.testoptional_2
    example::nested::testoptional(i, j);
    // splicer end namespace.example::nested.function.testoptional_2
}

// ----------------------------------------
// Function:  size_t test_size_t
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_default
size_t AA_example_nested_test_size_t(void)
{
    // splicer begin namespace.example::nested.function.test_size_t
    size_t SHC_rv = example::nested::test_size_t();
    return SHC_rv;
    // splicer end namespace.example::nested.function.test_size_t
}

#ifdef HAVE_MPI
// ----------------------------------------
// Function:  void testmpi
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  MPI_Comm comm +value
// Attrs:     +intent(in)
// Requested: c_in_unknown_scalar
// Match:     c_default
void AA_example_nested_testmpi_mpi(MPI_Fint comm)
{
    // splicer begin namespace.example::nested.function.testmpi_mpi
    MPI_Comm SHCXX_comm = MPI_Comm_f2c(comm);
    example::nested::testmpi(SHCXX_comm);
    // splicer end namespace.example::nested.function.testmpi_mpi
}
#endif  // ifdef HAVE_MPI

#ifndef HAVE_MPI
// ----------------------------------------
// Function:  void testmpi
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
void AA_example_nested_testmpi_serial(void)
{
    // splicer begin namespace.example::nested.function.testmpi_serial
    example::nested::testmpi();
    // splicer end namespace.example::nested.function.testmpi_serial
}
#endif  // ifndef HAVE_MPI

/**
 * \brief subroutine
 *
 */
// ----------------------------------------
// Function:  void FuncPtr1
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  void ( * get)(void) +value
// Attrs:     +intent(in)
// Requested: c_in_void_scalar
// Match:     c_default
void AA_example_nested_func_ptr1(void ( * get)(void))
{
    // splicer begin namespace.example::nested.function.func_ptr1
    example::nested::FuncPtr1(get);
    // splicer end namespace.example::nested.function.func_ptr1
}

/**
 * \brief return a pointer
 *
 */
// ----------------------------------------
// Function:  void FuncPtr2
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  double * ( * get)(void)
// Attrs:     +intent(in)
// Requested: c_in_native_*
// Match:     c_default
void AA_example_nested_func_ptr2(double * ( * get)(void))
{
    // splicer begin namespace.example::nested.function.func_ptr2
    example::nested::FuncPtr2(get);
    // splicer end namespace.example::nested.function.func_ptr2
}

/**
 * \brief abstract argument
 *
 */
// ----------------------------------------
// Function:  void FuncPtr3
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  double ( * get)(int i +value, int +value) +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void AA_example_nested_func_ptr3(double ( * get)(int i, int))
{
    // splicer begin namespace.example::nested.function.func_ptr3
    example::nested::FuncPtr3(get);
    // splicer end namespace.example::nested.function.func_ptr3
}

/**
 * \brief abstract argument
 *
 */
// ----------------------------------------
// Function:  void FuncPtr4
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  double ( * get)(double +value, int +value) +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void AA_example_nested_func_ptr4(double ( * get)(double, int))
{
    // splicer begin namespace.example::nested.function.func_ptr4
    example::nested::FuncPtr4(get);
    // splicer end namespace.example::nested.function.func_ptr4
}

// ----------------------------------------
// Function:  void FuncPtr5
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  void ( * get)(int verylongname1 +value, int verylongname2 +value, int verylongname3 +value, int verylongname4 +value, int verylongname5 +value, int verylongname6 +value, int verylongname7 +value, int verylongname8 +value, int verylongname9 +value, int verylongname10 +value) +value
// Attrs:     +intent(in)
// Requested: c_in_void_scalar
// Match:     c_default
void AA_example_nested_func_ptr5(void ( * get)(int verylongname1,
    int verylongname2, int verylongname3, int verylongname4,
    int verylongname5, int verylongname6, int verylongname7,
    int verylongname8, int verylongname9, int verylongname10))
{
    // splicer begin namespace.example::nested.function.func_ptr5
    example::nested::FuncPtr5(get);
    // splicer end namespace.example::nested.function.func_ptr5
}

// ----------------------------------------
// Function:  void verylongfunctionname1
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  int * verylongname1 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  int * verylongname2 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  int * verylongname3 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  int * verylongname4 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  int * verylongname5 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  int * verylongname6 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  int * verylongname7 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  int * verylongname8 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  int * verylongname9 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  int * verylongname10 +intent(inout)
// Attrs:     +intent(inout)
// Requested: c_inout_native_*
// Match:     c_default
void AA_example_nested_verylongfunctionname1(int * verylongname1,
    int * verylongname2, int * verylongname3, int * verylongname4,
    int * verylongname5, int * verylongname6, int * verylongname7,
    int * verylongname8, int * verylongname9, int * verylongname10)
{
    // splicer begin namespace.example::nested.function.verylongfunctionname1
    example::nested::verylongfunctionname1(verylongname1, verylongname2,
        verylongname3, verylongname4, verylongname5, verylongname6,
        verylongname7, verylongname8, verylongname9, verylongname10);
    // splicer end namespace.example::nested.function.verylongfunctionname1
}

// ----------------------------------------
// Function:  int verylongfunctionname2
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname1 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname2 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname3 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname4 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname5 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname6 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname7 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname8 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname9 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int verylongname10 +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
int AA_example_nested_verylongfunctionname2(int verylongname1,
    int verylongname2, int verylongname3, int verylongname4,
    int verylongname5, int verylongname6, int verylongname7,
    int verylongname8, int verylongname9, int verylongname10)
{
    // splicer begin namespace.example::nested.function.verylongfunctionname2
    int SHC_rv = example::nested::verylongfunctionname2(verylongname1,
        verylongname2, verylongname3, verylongname4, verylongname5,
        verylongname6, verylongname7, verylongname8, verylongname9,
        verylongname10);
    return SHC_rv;
    // splicer end namespace.example::nested.function.verylongfunctionname2
}

/**
 * \brief Test multidimensional arrays with allocatable
 *
 */
// ----------------------------------------
// Function:  void cos_doubles
// Attrs:     +intent(subroutine)
// Exact:     c_subroutine
// ----------------------------------------
// Argument:  double * in +intent(in)+rank(2)
// Attrs:     +intent(in)
// Requested: c_in_native_*
// Match:     c_default
// ----------------------------------------
// Argument:  double * out +deref(allocatable)+dimension(shape(in))+intent(out)
// Attrs:     +deref(allocatable)+intent(out)
// Requested: c_out_native_*_allocatable
// Match:     c_default
// ----------------------------------------
// Argument:  int sizein +implied(size(in))+value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void AA_example_nested_cos_doubles(double * in, double * out,
    int sizein)
{
    // splicer begin namespace.example::nested.function.cos_doubles
    example::nested::cos_doubles(in, out, sizein);
    // splicer end namespace.example::nested.function.cos_doubles
}

}  // extern "C"
