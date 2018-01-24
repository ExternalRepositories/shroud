// wrapTutorial.h
// This is generated code, do not edit
// #######################################################################
// Copyright (c) 2017, Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-738041.
// All rights reserved.
//
// This file is part of Shroud.  For details, see
// https://github.com/LLNL/shroud. Please also read shroud/LICENSE.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the disclaimer below.
//
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the disclaimer (as noted below)
//   in the documentation and/or other materials provided with the
//   distribution.
//
// * Neither the name of the LLNS/LLNL nor the names of its contributors
//   may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE
// LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// #######################################################################
/**
 * \file wrapTutorial.h
 * \brief Shroud generated wrapper for Tutorial library
 */
// For C users and C++ implementation

#ifndef WRAPTUTORIAL_H
#define WRAPTUTORIAL_H

// splicer begin CXX_declarations
// splicer end CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// declaration of wrapped types
struct s_TUT_class1;
typedef struct s_TUT_class1 TUT_class1;

// splicer begin C_declarations
// splicer end C_declarations

void TUT_function1();

double TUT_function2(double arg1, int arg2);

void TUT_sum(int len, int * values, int * result);

long long TUT_type_long_long(long long arg1);

bool TUT_function3(bool arg);

void TUT_function3b(const bool arg1, bool * arg2, bool * arg3);

void TUT_function4a_bufferify(const char * arg1, int Larg1,
    const char * arg2, int Larg2, char * SHF_rv, int NSHF_rv);

const char * TUT_function4b(const char * arg1, const char * arg2);

void TUT_function4b_bufferify(const char * arg1, int Larg1,
    const char * arg2, int Larg2, char * output, int Noutput);

double TUT_function5();

double TUT_function5_arg1(double arg1);

double TUT_function5_arg1_arg2(double arg1, bool arg2);

void TUT_function6_from_name(const char * name);

void TUT_function6_from_name_bufferify(const char * name, int Lname);

void TUT_function6_from_index(int indx);

void TUT_function7_int(int arg);

void TUT_function7_double(double arg);

int TUT_function8_int();

double TUT_function8_double();

void TUT_function9(double arg);

void TUT_function10_0();

void TUT_function10_1(const char * name, double arg2);

void TUT_function10_1_bufferify(const char * name, int Lname,
    double arg2);

int TUT_overload1_num(int num);

int TUT_overload1_num_offset(int num, int offset);

int TUT_overload1_num_offset_stride(int num, int offset, int stride);

int TUT_overload1_3(double type, int num);

int TUT_overload1_4(double type, int num, int offset);

int TUT_overload1_5(double type, int num, int offset, int stride);

int TUT_typefunc(int arg);

int TUT_enumfunc(int arg);

void TUT_useclass(const TUT_class1 * arg1);

int TUT_vector_sum_bufferify(const int * arg, long Sarg);

void TUT_vector_iota_bufferify(int * arg, long Sarg);

void TUT_vector_increment_bufferify(int * arg, long Sarg);

int TUT_vector_string_count_bufferify(const char * arg, long Sarg,
    int Narg);

int TUT_vector_string_fill_bufferify(char * arg, long Sarg, int Narg);

void TUT_vector_string_append_bufferify(char * arg, long Sarg, int Narg);

const char * TUT_last_function_called();

void TUT_last_function_called_bufferify(char * SHF_rv, int NSHF_rv);

#ifdef __cplusplus
}
#endif

#endif  // WRAPTUTORIAL_H
