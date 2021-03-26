// wrapstruct.c
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapstruct.h"

// cxx_header
#include "struct.h"
// shroud
#include <string.h>


// helper ShroudStrBlankFill
// blank fill dest starting at trailing NULL.
static void ShroudStrBlankFill(char *dest, int ndest)
{
   int nm = strlen(dest);
   if(ndest > nm) memset(dest+nm,' ',ndest-nm);
}
// splicer begin C_definitions
// splicer end C_definitions

/**
 * Pass name argument which will build a bufferify function.
 */
// ----------------------------------------
// Function:  int passStruct2
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_function
// ----------------------------------------
// Argument:  const Cstruct1 * s1
// Attrs:     +intent(in)
// Requested: c_in_struct_*
// Match:     c_in_struct
// ----------------------------------------
// Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)
// Attrs:     +api(buf)+intent(out)
// Exact:     c_out_char_*_buf
int STR_pass_struct2_bufferify(const Cstruct1 * s1, char *outbuf,
    int SHT_outbuf_len)
{
    // splicer begin function.pass_struct2_bufferify
    int SHC_rv = passStruct2(s1, outbuf);
    ShroudStrBlankFill(outbuf, SHT_outbuf_len);
    return SHC_rv;
    // splicer end function.pass_struct2_bufferify
}

/**
 * \brief Return a pointer to a struct
 *
 * Generates a bufferify C wrapper function.
 */
// ----------------------------------------
// Function:  Cstruct1 * returnStructPtr2
// Attrs:     +api(buf)+deref(pointer)+intent(function)
// Requested: c_function_struct_*_buf_pointer
// Match:     c_function_struct_*
// ----------------------------------------
// Argument:  int i +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  double d +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  char * outbuf +charlen(LENOUTBUF)+intent(out)
// Attrs:     +api(buf)+intent(out)
// Exact:     c_out_char_*_buf
Cstruct1 * STR_return_struct_ptr2_bufferify(int i, double d,
    char *outbuf, int SHT_outbuf_len)
{
    // splicer begin function.return_struct_ptr2_bufferify
    Cstruct1 * SHC_rv = returnStructPtr2(i, d, outbuf);
    ShroudStrBlankFill(outbuf, SHT_outbuf_len);
    return SHC_rv;
    // splicer end function.return_struct_ptr2_bufferify
}

// ----------------------------------------
// Function:  Cstruct_as_class * Create_Cstruct_as_class
// Attrs:     +intent(function)
// Requested: c_function_shadow_*
// Match:     c_function_shadow
// start STR_create__cstruct_as_class
void STR_create__cstruct_as_class(STR_Cstruct_as_class * SHC_rv)
{
    // splicer begin function.create__cstruct_as_class
    Cstruct_as_class * SHCXX_rv = Create_Cstruct_as_class();
    SHC_rv->addr = SHCXX_rv;
    SHC_rv->idtor = 0;
    // splicer end function.create__cstruct_as_class
}
// end STR_create__cstruct_as_class

// ----------------------------------------
// Function:  Cstruct_as_class * Create_Cstruct_as_class_args
// Attrs:     +intent(function)
// Requested: c_function_shadow_*
// Match:     c_function_shadow
// ----------------------------------------
// Argument:  int x +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int y +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void STR_create__cstruct_as_class_args(STR_Cstruct_as_class * SHC_rv,
    int x, int y)
{
    // splicer begin function.create__cstruct_as_class_args
    Cstruct_as_class * SHCXX_rv = Create_Cstruct_as_class_args(x, y);
    SHC_rv->addr = SHCXX_rv;
    SHC_rv->idtor = 0;
    // splicer end function.create__cstruct_as_class_args
}

// ----------------------------------------
// Function:  int Cstruct_as_class_sum
// Attrs:     +intent(function)
// Requested: c_function_native_scalar
// Match:     c_function
// ----------------------------------------
// Argument:  const Cstruct_as_class * point +pass
// Attrs:     +intent(in)
// Requested: c_in_shadow_*
// Match:     c_in_shadow
int STR_cstruct_as_class_sum(STR_Cstruct_as_class * point)
{
    // splicer begin function.cstruct_as_class_sum
    const Cstruct_as_class * SHCXX_point =
        (const Cstruct_as_class *) point->addr;
    int SHC_rv = Cstruct_as_class_sum(SHCXX_point);
    return SHC_rv;
    // splicer end function.cstruct_as_class_sum
}

// ----------------------------------------
// Function:  Cstruct_as_subclass * Create_Cstruct_as_subclass_args
// Attrs:     +intent(function)
// Requested: c_function_shadow_*
// Match:     c_function_shadow
// ----------------------------------------
// Argument:  int x +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int y +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
// ----------------------------------------
// Argument:  int z +value
// Attrs:     +intent(in)
// Requested: c_in_native_scalar
// Match:     c_default
void STR_create__cstruct_as_subclass_args(
    STR_Cstruct_as_subclass * SHC_rv, int x, int y, int z)
{
    // splicer begin function.create__cstruct_as_subclass_args
    Cstruct_as_subclass * SHCXX_rv = Create_Cstruct_as_subclass_args(x,
        y, z);
    SHC_rv->addr = SHCXX_rv;
    SHC_rv->idtor = 0;
    // splicer end function.create__cstruct_as_subclass_args
}
