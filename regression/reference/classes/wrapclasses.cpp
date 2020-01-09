// wrapclasses.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapclasses.h"
#include <cstdlib>
#include <cstring>
#include <string>
#include "classes.hpp"
#include "typesclasses.h"

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

// Class1::DIRECTION directionFunc(Class1::DIRECTION arg +intent(in)+value)
int CLA_direction_func(int arg)
{
    // splicer begin function.direction_func
    classes::Class1::DIRECTION SHCXX_arg =
        static_cast<classes::Class1::DIRECTION>(arg);
    classes::Class1::DIRECTION SHCXX_rv = classes::directionFunc(
        SHCXX_arg);
    int SHC_rv = static_cast<int>(SHCXX_rv);
    return SHC_rv;
    // splicer end function.direction_func
}

// void passClassByValue(Class1 arg +intent(in)+value)
/**
 * \brief Pass arguments to a function.
 *
 */
void CLA_pass_class_by_value(CLA_Class1 arg)
{
    // splicer begin function.pass_class_by_value
    classes::Class1 * SHCXX_arg = static_cast<classes::Class1 *>
        (arg.addr);
    classes::passClassByValue(*SHCXX_arg);
    return;
    // splicer end function.pass_class_by_value
}

// int useclass(const Class1 * arg +intent(in))
int CLA_useclass(CLA_Class1 * arg)
{
    // splicer begin function.useclass
    const classes::Class1 * SHCXX_arg =
        static_cast<const classes::Class1 *>(arg->addr);
    int SHC_rv = classes::useclass(SHCXX_arg);
    return SHC_rv;
    // splicer end function.useclass
}

// const Class1 * getclass2()
CLA_Class1 * CLA_getclass2(CLA_Class1 * SHC_rv)
{
    // splicer begin function.getclass2
    const classes::Class1 * SHCXX_rv = classes::getclass2();
    SHC_rv->addr = static_cast<void *>(const_cast<classes::Class1 *>
        (SHCXX_rv));
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end function.getclass2
}

// Class1 * getclass3()
CLA_Class1 * CLA_getclass3(CLA_Class1 * SHC_rv)
{
    // splicer begin function.getclass3
    classes::Class1 * SHCXX_rv = classes::getclass3();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end function.getclass3
}

// const Class1 & getConstClassReference()
CLA_Class1 * CLA_get_const_class_reference(CLA_Class1 * SHC_rv)
{
    // splicer begin function.get_const_class_reference
    const classes::Class1 & SHCXX_rv = classes::getConstClassReference(
        );
    SHC_rv->addr = static_cast<void *>(const_cast<classes::Class1 *>
        (&SHCXX_rv));
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end function.get_const_class_reference
}

// Class1 & getClassReference()
CLA_Class1 * CLA_get_class_reference(CLA_Class1 * SHC_rv)
{
    // splicer begin function.get_class_reference
    classes::Class1 & SHCXX_rv = classes::getClassReference();
    SHC_rv->addr = static_cast<void *>(&SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end function.get_class_reference
}

// Class1 getClassCopy(int flag +intent(in)+value)
/**
 * \brief Return Class1 instance by value, uses copy constructor
 *
 */
CLA_Class1 * CLA_get_class_copy(int flag, CLA_Class1 * SHC_rv)
{
    // splicer begin function.get_class_copy
    classes::Class1 * SHCXX_rv = new classes::Class1;
    *SHCXX_rv = classes::getClassCopy(flag);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 1;
    return SHC_rv;
    // splicer end function.get_class_copy
}

// void set_global_flag(int arg +intent(in)+value)
void CLA_set_global_flag(int arg)
{
    // splicer begin function.set_global_flag
    classes::set_global_flag(arg);
    return;
    // splicer end function.set_global_flag
}

// int get_global_flag()
int CLA_get_global_flag()
{
    // splicer begin function.get_global_flag
    int SHC_rv = classes::get_global_flag();
    return SHC_rv;
    // splicer end function.get_global_flag
}

// const std::string & LastFunctionCalled() +deref(result_as_arg)+len(30)
const char * CLA_last_function_called()
{
    // splicer begin function.last_function_called
    const std::string & SHCXX_rv = classes::LastFunctionCalled();
    const char * SHC_rv = SHCXX_rv.c_str();
    return SHC_rv;
    // splicer end function.last_function_called
}

// void LastFunctionCalled(std::string & SHF_rv +intent(out)+len(NSHF_rv)) +len(30)
void CLA_last_function_called_bufferify(char * SHF_rv, int NSHF_rv)
{
    // splicer begin function.last_function_called_bufferify
    const std::string & SHCXX_rv = classes::LastFunctionCalled();
    if (SHCXX_rv.empty()) {
        ShroudStrCopy(SHF_rv, NSHF_rv, NULL, 0);
    } else {
        ShroudStrCopy(SHF_rv, NSHF_rv, SHCXX_rv.data(),
            SHCXX_rv.size());
    }
    return;
    // splicer end function.last_function_called_bufferify
}

// start release allocated memory
// Release library allocated memory.
void CLA_SHROUD_memory_destructor(CLA_SHROUD_capsule_data *cap)
{
    void *ptr = cap->addr;
    switch (cap->idtor) {
    case 0:   // --none--
    {
        // Nothing to delete
        break;
    }
    case 1:   // classes::Class1
    {
        classes::Class1 *cxx_ptr = 
            reinterpret_cast<classes::Class1 *>(ptr);
        delete cxx_ptr;
        break;
    }
    default:
    {
        // Unexpected case in destructor
        break;
    }
    }
    cap->addr = NULL;
    cap->idtor = 0;  // avoid deleting again
}
// end release allocated memory

}  // extern "C"
