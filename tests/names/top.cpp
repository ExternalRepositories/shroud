// top.cpp
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
// top.cpp
#include "top.h"
#include <string>

// splicer begin CXX_definitions
// Add some text from splicer
// And another line
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

// void function1()
// function_index=2
void YYY_TES_function1()
{
// splicer begin function.function1
    function1();
    return;
// splicer end function.function1
}

// void function2()
// function_index=3
void c_name_special()
{
// splicer begin function.function2
    function2();
    return;
// splicer end function.function2
}

// void function3a(int i +intent(in)+value)
// function_index=4
void YYY_TES_function3a_0(int i)
{
// splicer begin function.function3a_0
    function3a(i);
    return;
// splicer end function.function3a_0
}

// void function3a(long i +intent(in)+value)
// function_index=5
void YYY_TES_function3a_1(long i)
{
// splicer begin function.function3a_1
    function3a(i);
    return;
// splicer end function.function3a_1
}

// int function4(const std::string & rv +intent(in))
// function_index=6
int YYY_TES_function4(const char * rv)
{
// splicer begin function.function4
    const std::string SH_rv(rv);
    int SHT_rv = function4(SH_rv);
    return SHT_rv;
// splicer end function.function4
}

// int function4(const std::string & rv +intent(in)+len_trim(Lrv))
// function_index=7
int YYY_TES_function4_bufferify(const char * rv, int Lrv)
{
// splicer begin function.function4_bufferify
    const std::string SH_rv(rv, Lrv);
    int SHT_rv = function4(SH_rv);
    return SHT_rv;
// splicer end function.function4_bufferify
}

}  // extern "C"
