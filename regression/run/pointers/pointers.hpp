// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// pointers.hpp - wrapped routines

#ifndef POINTERS_HPP
#define POINTERS_HPP

void intargs(const int argin, int * argout, int * arginout);

void cos_doubles(double * in, double * out, int sizein);

void truncate_to_int(double *in, int *out, int size);

void get_values(int *nvalues, int *values);

void get_values2(int *arg1, int *arg2);

void Sum(int len, int * values, int *result);
void fillIntArray(int *out);
void incrementIntArray(int *array, int size);


#endif // POINTERS_HPP
