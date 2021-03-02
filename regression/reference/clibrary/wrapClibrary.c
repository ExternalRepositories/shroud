// wrapClibrary.c
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapClibrary.h"

// cxx_header
#include "clibrary.h"
// shroud
#include "typesClibrary.h"
#include <stdlib.h>
#include <string.h>


// helper ShroudLenTrim
// Returns the length of character string src with length nsrc,
// ignoring any trailing blanks.
static int ShroudLenTrim(const char *src, int nsrc) {
    int i;

    for (i = nsrc - 1; i >= 0; i--) {
        if (src[i] != ' ') {
            break;
        }
    }

    return i + 1;
}


// helper ShroudStrAlloc
// Copy src into new memory and null terminate.
// if ntrim is -1, call ShroudLenTrim.
static char *ShroudStrAlloc(const char *src, int nsrc, int ntrim)
{
   char *rv = malloc(nsrc + 1);
   if (ntrim == -1) {
      ntrim = ShroudLenTrim(src, nsrc);
   }
   if (ntrim > 0) {
     memcpy(rv, src, ntrim);
   }
   rv[ntrim] = '\0';
   return rv;
}

// helper ShroudStrBlankFill
// blank fill dest starting at trailing NULL.
static void ShroudStrBlankFill(char *dest, int ndest)
{
   int nm = strlen(dest);
   if(ndest > nm) memset(dest+nm,' ',ndest-nm);
}

// helper ShroudStrCopy
// Copy src into dest, blank fill to ndest characters
// Truncate if dest is too short.
// dest will not be NULL terminated.
static void ShroudStrCopy(char *dest, int ndest, const char *src, int nsrc)
{
   if (src == NULL) {
     memset(dest,' ',ndest); // convert NULL pointer to blank filled string
   } else {
     if (nsrc < 0) nsrc = strlen(src);
     int nm = nsrc < ndest ? nsrc : ndest;
     memcpy(dest,src,nm);
     if(ndest > nm) memset(dest+nm,' ',ndest-nm); // blank fill
   }
}

// helper ShroudStrFree
// Release memory allocated by ShroudStrAlloc
static void ShroudStrFree(char *src)
{
   free(src);
}
// splicer begin C_definitions
// splicer end C_definitions

/**
 * PassByValueMacro is a #define macro. Force a C wrapper
 * to allow Fortran to have an actual function to call.
 */
// ----------------------------------------
// Function:  double PassByValueMacro
// Requested: c_native_scalar_result
// Match:     c_default
//    metaattrs:  +intent(result)
// ----------------------------------------
// Argument:  int arg2 +intent(in)+value
// Requested: c_native_scalar_in
// Match:     c_default
//    metaattrs:  +intent(in)
double CLI_pass_by_value_macro(int arg2)
{
    // splicer begin function.pass_by_value_macro
    double SHC_rv = PassByValueMacro(arg2);
    return SHC_rv;
    // splicer end function.pass_by_value_macro
}

// ----------------------------------------
// Function:  void Function4a +len(30)
// Requested: c_void_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  const char * arg1 +intent(in)
// Requested: c_char_*_in
// Match:     c_default
//    metaattrs:  +intent(in)
// ----------------------------------------
// Argument:  const char * arg2 +intent(in)
// Requested: c_char_*_in
// Match:     c_default
//    metaattrs:  +intent(in)
// ----------------------------------------
// Argument:  char * SHF_rv +intent(out)+len(NSHF_rv)
// Exact:     c_char_*_result_buf
//    metaattrs:  +intent(out)
void CLI_function4a_bufferify(const char * arg1, const char * arg2,
    char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.function4a_bufferify
    char * SHC_rv = Function4a(arg1, arg2);
    ShroudStrCopy(SHF_rv, NSHF_rv, SHC_rv, -1);
    // splicer end function.function4a_bufferify
}

/**
 * \brief toupper
 *
 * Change a string in-place.
 * For Python, return a new string since strings are immutable.
 */
// ----------------------------------------
// Function:  void passCharPtrInOut
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  char * s +intent(inout)+len(Ns)+len_trim(Ls)
// Exact:     c_char_*_inout_buf
//    metaattrs:  +intent(inout)
void CLI_pass_char_ptr_in_out_bufferify(char * s, int Ls, int Ns)
{
    // splicer begin function.pass_char_ptr_in_out_bufferify
    char * SHCXX_s = ShroudStrAlloc(s, Ns, Ls);
    passCharPtrInOut(SHCXX_s);
    ShroudStrCopy(s, Ns, SHCXX_s, -1);
    ShroudStrFree(SHCXX_s);
    // splicer end function.pass_char_ptr_in_out_bufferify
}

/**
 * \brief Test charlen attribute
 *
 * Each argument is assumed to be at least MAXNAME long.
 * This define is provided by the user.
 * The function will copy into the user provided buffer.
 */
// ----------------------------------------
// Function:  void returnOneName
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  char * name1 +charlen(MAXNAME)+intent(out)+len(Nname1)
// Exact:     c_char_*_out_buf
//    metaattrs:  +intent(out)
// start CLI_return_one_name_bufferify
void CLI_return_one_name_bufferify(char * name1, int Nname1)
{
    // splicer begin function.return_one_name_bufferify
    returnOneName(name1);
    ShroudStrBlankFill(name1, Nname1);
    // splicer end function.return_one_name_bufferify
}
// end CLI_return_one_name_bufferify

/**
 * \brief Test charlen attribute
 *
 * Each argument is assumed to be at least MAXNAME long.
 * This define is provided by the user.
 * The function will copy into the user provided buffer.
 */
// ----------------------------------------
// Function:  void returnTwoNames
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  char * name1 +charlen(MAXNAME)+intent(out)+len(Nname1)
// Exact:     c_char_*_out_buf
//    metaattrs:  +intent(out)
// ----------------------------------------
// Argument:  char * name2 +charlen(MAXNAME)+intent(out)+len(Nname2)
// Exact:     c_char_*_out_buf
//    metaattrs:  +intent(out)
void CLI_return_two_names_bufferify(char * name1, int Nname1,
    char * name2, int Nname2)
{
    // splicer begin function.return_two_names_bufferify
    returnTwoNames(name1, name2);
    ShroudStrBlankFill(name1, Nname1);
    ShroudStrBlankFill(name2, Nname2);
    // splicer end function.return_two_names_bufferify
}

/**
 * \brief Fill text, at most ltext characters.
 *
 */
// ----------------------------------------
// Function:  void ImpliedTextLen
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  char * text +charlen(MAXNAME)+intent(out)+len(Ntext)
// Exact:     c_char_*_out_buf
//    metaattrs:  +intent(out)
// ----------------------------------------
// Argument:  int ltext +implied(len(text))+intent(in)+value
// Requested: c_native_scalar_in_buf
// Match:     c_default
//    metaattrs:  +intent(in)
// start CLI_implied_text_len_bufferify
void CLI_implied_text_len_bufferify(char * text, int Ntext, int ltext)
{
    // splicer begin function.implied_text_len_bufferify
    ImpliedTextLen(text, ltext);
    ShroudStrBlankFill(text, Ntext);
    // splicer end function.implied_text_len_bufferify
}
// end CLI_implied_text_len_bufferify

/**
 * \brief Rename Fortran name for interface only function
 *
 * This creates a Fortran bufferify function and an interface.
 */
// ----------------------------------------
// Function:  void bindC2
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  char * outbuf +intent(out)+len(Noutbuf)
// Exact:     c_char_*_out_buf
//    metaattrs:  +intent(out)
void CLI_bind_c2_bufferify(char * outbuf, int Noutbuf)
{
    // splicer begin function.bind_c2_bufferify
    bindC2(outbuf);
    ShroudStrBlankFill(outbuf, Noutbuf);
    // splicer end function.bind_c2_bufferify
}

/**
 * \brief Test assumed-type
 *
 * A bufferify function is created.
 * Should only be call with an C_INT argument, and will
 * return the value passed in.
 */
// ----------------------------------------
// Function:  int passAssumedTypeBuf
// Requested: c_native_scalar_result_buf
// Match:     c_default
//    metaattrs:  +intent(result)
// ----------------------------------------
// Argument:  void * arg +assumedtype+intent(in)
// Requested: c_void_*_in_buf
// Match:     c_default
//    metaattrs:  +intent(in)
// ----------------------------------------
// Argument:  char * outbuf +intent(out)+len(Noutbuf)
// Exact:     c_char_*_out_buf
//    metaattrs:  +intent(out)
int CLI_pass_assumed_type_buf_bufferify(void * arg, char * outbuf,
    int Noutbuf)
{
    // splicer begin function.pass_assumed_type_buf_bufferify
    int SHC_rv = passAssumedTypeBuf(arg, outbuf);
    ShroudStrBlankFill(outbuf, Noutbuf);
    return SHC_rv;
    // splicer end function.pass_assumed_type_buf_bufferify
}

/**
 * \brief Test function pointer
 *
 * Add C_force_wrapper to test generating function pointer prototype.
 */
// ----------------------------------------
// Function:  void callback1a
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  int type +intent(in)+value
// Requested: c_native_scalar_in
// Match:     c_default
//    metaattrs:  +intent(in)
// ----------------------------------------
// Argument:  void ( * incr)(void) +external+intent(in)+value
// Requested: c_void_scalar_in
// Match:     c_default
//    metaattrs:  +intent(in)
// start CLI_callback1a
void CLI_callback1a(int type, void ( * incr)(void))
{
    // splicer begin function.callback1a
    callback1a(type, incr);
    // splicer end function.callback1a
}
// end CLI_callback1a

/**
 * \brief Test function pointer
 *
 * A bufferify function will be created.
 */
// ----------------------------------------
// Function:  void callback3
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  const char * type +intent(in)
// Requested: c_char_*_in
// Match:     c_default
//    metaattrs:  +intent(in)
// ----------------------------------------
// Argument:  void * in +assumedtype+intent(in)
// Requested: c_void_*_in_buf
// Match:     c_default
//    metaattrs:  +intent(in)
// ----------------------------------------
// Argument:  void ( * incr)(int *) +external+intent(in)+value
// Requested: c_void_scalar_in_buf
// Match:     c_default
//    metaattrs:  +intent(in)
// ----------------------------------------
// Argument:  char * outbuf +intent(out)+len(Noutbuf)
// Exact:     c_char_*_out_buf
//    metaattrs:  +intent(out)
void CLI_callback3_bufferify(const char * type, void * in,
    void ( * incr)(int *), char * outbuf, int Noutbuf)
{
    // splicer begin function.callback3_bufferify
    callback3(type, in, incr, outbuf);
    ShroudStrBlankFill(outbuf, Noutbuf);
    // splicer end function.callback3_bufferify
}

// start release allocated memory
// Release library allocated memory.
void CLI_SHROUD_memory_destructor(CLI_SHROUD_capsule_data *cap)
{
    cap->addr = NULL;
    cap->idtor = 0;  // avoid deleting again
}
// end release allocated memory
