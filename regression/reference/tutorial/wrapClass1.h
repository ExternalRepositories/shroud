// wrapClass1.h
// This is generated code, do not edit
// #######################################################################
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC.
//
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-738041.
//
// All rights reserved.
//
// This file is part of Shroud.
//
// For details about use and distribution, please read LICENSE.
//
// #######################################################################
/**
 * \file wrapClass1.h
 * \brief Shroud generated wrapper for Class1 class
 */
// For C users and C++ implementation

#ifndef WRAPCLASS1_H
#define WRAPCLASS1_H

#include "typesTutorial.h"

// splicer begin class.Class1.CXX_declarations
// splicer end class.Class1.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

//  DIRECTION
enum TUT_class1_DIRECTION {
    UP = 2,
    DOWN,
    LEFT = 100,
    RIGHT
};

// splicer begin class.Class1.C_declarations
// splicer end class.Class1.C_declarations

TUT_class1 * TUT_class1_new_default(TUT_class1 * SHC_rv);

TUT_class1 * TUT_class1_new_flag(int flag, TUT_class1 * SHC_rv);

void TUT_class1_delete(TUT_class1 * self);

int TUT_class1_method1(TUT_class1 * self);

bool TUT_class1_equivalent(const TUT_class1 * self,
    const TUT_class1 * obj2);

void TUT_class1_return_this(TUT_class1 * self);

TUT_class1 * TUT_class1_return_this_buffer(TUT_class1 * self,
    char * name, bool flag, TUT_class1 * SHC_rv);

TUT_class1 * TUT_class1_return_this_buffer_bufferify(TUT_class1 * self,
    char * name, int Lname, bool flag, TUT_class1 * SHC_rv);

TUT_class1 * TUT_class1_getclass3(const TUT_class1 * self,
    TUT_class1 * SHC_rv);

int TUT_class1_direction_func(TUT_class1 * self, int arg);

int TUT_class1_get_m_flag(TUT_class1 * self);

int TUT_class1_get_test(TUT_class1 * self);

void TUT_class1_set_test(TUT_class1 * self, int val);

#ifdef __cplusplus
}
#endif

#endif  // WRAPCLASS1_H
