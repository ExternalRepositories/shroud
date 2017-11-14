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
//
// tutorial.hpp - wrapped routines
//

#include "tutorial.hpp"

namespace tutorial
{

static std::string last_function_called;

// These variables exist to avoid warning errors
static std::string global_str;
static int global_int;
static double global_double;
static const Class1 *global_class1;



void Function1()
{
    last_function_called = "Function1";
    return;
}

double Function2(double arg1, int arg2)
{
    last_function_called = "Function2";
    return arg1 + arg2;
}

bool Function3(bool arg)
{
    last_function_called = "Function3";
    return ! arg;
}

void Function3b(const bool arg1, bool *arg2, bool *arg3)
{
    last_function_called = "Function3b";
    *arg2 = ! arg1;
    *arg3 = ! *arg3;
    return;
}

const std::string Function4a(const std::string& arg1, const std::string& arg2)
{
    last_function_called = "Function4a";
    return arg1 + arg2;
}
const std::string& Function4b(const std::string& arg1, const std::string& arg2)
{
    last_function_called = "Function4b";
    return global_str = arg1 + arg2;
    return global_str;
}

double Function5(double arg1, bool arg2)
{
    last_function_called = "Function5";
    if (arg2) {
	return arg1 + 10.0;
    } else {
	return arg1;
    }
}

void Function6(const std::string& name)
{
    last_function_called = "Function6(string)";
    global_str = name;
    return;
}
void Function6(int indx)
{
    last_function_called = "Function6(int)";
    global_int = indx;
    return;
}

template<>
void Function7<int>(int arg)
{
    last_function_called = "Function7<int>";
    global_int = arg;
}

template<>
void Function7<double>(double arg)
{
    last_function_called = "Function7<double>";
    global_double = arg;
}

template<>
int Function8<int>()
{
    last_function_called = "Function8<int>";
    return global_int;
}

template<>
double Function8<double>()
{
    last_function_called = "Function8<double>";
    return global_double;
}

void Function9(double arg)
{
    last_function_called = "Function9";
    global_double = arg;
    return;
}

void Function10()
{
    last_function_called = "Function10_0";
}

void Function10(const std::string &name, double arg2)
{
    last_function_called = "Function10_1";
    global_str = name;
    global_double = arg2;
}

void Sum(int len, int *values, int *result)
{
    last_function_called = "Sum";

    int sum = 0;
    for (int i=0; i < len; i++) {
	sum += values[i];
    }
    *result = sum;
    return;
}

int overload1(int num, int offset, int stride)
{
    last_function_called = "overload1_0";
    return num + offset * stride;
    
}

int overload1(double type, int num, int offset, int stride)
{
    last_function_called = "overload1_1";
    global_double = type;
    return num + offset * stride;
}

TypeID typefunc(TypeID arg)
{
    last_function_called = "typefunc";
    return static_cast<int>(arg);
}

EnumTypeID enumfunc(EnumTypeID arg)
{
    last_function_called = "enumfunc";
    switch (arg) {
    default:
	return ENUM2;
    }
}

void useclass(const Class1 *arg)
{
    last_function_called = "useclass";
    global_class1 = arg;
}

void getclass(const Class1 **arg)
{
    last_function_called = "getclass";
    *arg = global_class1;
}

//----------------------------------------------------------------------

void Class1::Method1()
{
    last_function_called = "Class1::Method1";
    return;
}

//----------------------------------------------------------------------
// vector reference as argument, intent(in)

int vector_sum(const std::vector<int> &arg)
{
  int sum = 0;
  for(std::vector<int>::const_iterator it = arg.begin(); it != arg.end(); ++it) {
    sum += *it;
  }
  return sum;
}

//----------------------------------------------------------------------
// vector reference as argument, intent(out)

void vector_iota(std::vector<int> &arg)
{
  for(unsigned int i=0; i < arg.size(); i++) {
    arg[i] = i + 1;
  }
  return;
}

//----------------------------------------------------------------------

const std::string& LastFunctionCalled()
{
    return last_function_called;
}

} /* end namespace tutorial */
