// wrapstatement.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapstatement.h"
#include <cstdlib>
#include <cstring>
#include <string>
#include "statement.hpp"
#include "typesstatement.h"

// splicer begin CXX_definitions
// splicer end CXX_definitions

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
// splicer begin C_definitions
// splicer end C_definitions

// int GetNameLength() +pure
/**
 * \brief helper function for Fortran to get length of name.
 *
 */
int STMT_get_name_length()
{
    // splicer begin function.get_name_length
    return getNameErrorPattern().length();
    // splicer end function.get_name_length
}

// const string & getNameErrorPattern() +deref(result_as_arg)+len(get_name_length())
const char * STMT_get_name_error_pattern()
{
    // splicer begin function.get_name_error_pattern
    const std::string & SHCXX_rv = getNameErrorPattern();
    // C_error_pattern
    if (! isNameValid(SHCXX_rv)) {
        return NULL;
    }

    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end function.get_name_error_pattern
}

// void getNameErrorPattern(string & SHF_rv +intent(out)+len(NSHF_rv)) +len(get_name_length())
void STMT_get_name_error_pattern_bufferify(char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.get_name_error_pattern_bufferify
    const std::string & SHCXX_rv = getNameErrorPattern();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(SHF_rv, NSHF_rv, NULL, 0);
    } else {
        ShroudStrCopy(SHF_rv, NSHF_rv, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    return;
    // splicer end function.get_name_error_pattern_bufferify
}

// Release library allocated memory.
void STMT_SHROUD_memory_destructor(STMT_SHROUD_capsule_data *cap)
{
    cap->addr = NULL;
    cap->idtor = 0;  // avoid deleting again
}

}  // extern "C"
