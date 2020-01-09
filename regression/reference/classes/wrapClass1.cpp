// wrapClass1.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapClass1.h"
#include <cstddef>
#include <string>
#include "classes.hpp"

// splicer begin class.Class1.CXX_definitions
// splicer end class.Class1.CXX_definitions

extern "C" {

// splicer begin class.Class1.C_definitions
// splicer end class.Class1.C_definitions

// Class1() +name(new)
// start CLA_Class1_new_default
CLA_Class1 * CLA_Class1_new_default(CLA_Class1 * SHC_rv)
{
    // splicer begin class.Class1.method.new_default
    classes::Class1 *SHCXX_rv = new classes::Class1();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end class.Class1.method.new_default
}
// end CLA_Class1_new_default

// Class1(int flag +intent(in)+value) +name(new)
// start CLA_Class1_new_flag
CLA_Class1 * CLA_Class1_new_flag(int flag, CLA_Class1 * SHC_rv)
{
    // splicer begin class.Class1.method.new_flag
    classes::Class1 *SHCXX_rv = new classes::Class1(flag);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end class.Class1.method.new_flag
}
// end CLA_Class1_new_flag

// ~Class1() +name(delete)
// start CLA_Class1_delete
void CLA_Class1_delete(CLA_Class1 * self)
{
    classes::Class1 *SH_this =
        static_cast<classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.delete
    delete SH_this;
    self->addr = NULL;
    return;
    // splicer end class.Class1.method.delete
}
// end CLA_Class1_delete

// int Method1()
/**
 * \brief returns the value of flag member
 *
 */
// start CLA_Class1_method1
int CLA_Class1_method1(CLA_Class1 * self)
{
    classes::Class1 *SH_this =
        static_cast<classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.method1
    int SHC_rv = SH_this->Method1();
    return SHC_rv;
    // splicer end class.Class1.method.method1
}
// end CLA_Class1_method1

// bool equivalent(const Class1 & obj2 +intent(in)) const
/**
 * \brief Pass in reference to instance
 *
 */
// start CLA_Class1_equivalent
bool CLA_Class1_equivalent(const CLA_Class1 * self, CLA_Class1 * obj2)
{
    const classes::Class1 *SH_this =
        static_cast<const classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.equivalent
    const classes::Class1 * SHCXX_obj2 =
        static_cast<const classes::Class1 *>(obj2->addr);
    bool SHC_rv = SH_this->equivalent(*SHCXX_obj2);
    return SHC_rv;
    // splicer end class.Class1.method.equivalent
}
// end CLA_Class1_equivalent

// Class1 * returnThis()
/**
 * \brief Return pointer to 'this' to allow chaining calls
 *
 */
// start CLA_Class1_return_this
void CLA_Class1_return_this(CLA_Class1 * self)
{
    classes::Class1 *SH_this =
        static_cast<classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.return_this
    SH_this->returnThis();
    return;
    // splicer end class.Class1.method.return_this
}
// end CLA_Class1_return_this

// Class1 * returnThisBuffer(std::string & name +intent(in), bool flag +intent(in)+value)
/**
 * \brief Return pointer to 'this' to allow chaining calls
 *
 */
// start CLA_Class1_return_this_buffer
CLA_Class1 * CLA_Class1_return_this_buffer(CLA_Class1 * self,
    char * name, bool flag, CLA_Class1 * SHC_rv)
{
    classes::Class1 *SH_this =
        static_cast<classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.return_this_buffer
    std::string SHCXX_name(name);
    classes::Class1 * SHCXX_rv = SH_this->returnThisBuffer(SHCXX_name,
        flag);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end class.Class1.method.return_this_buffer
}
// end CLA_Class1_return_this_buffer

// Class1 * returnThisBuffer(std::string & name +intent(in)+len_trim(Lname), bool flag +intent(in)+value)
/**
 * \brief Return pointer to 'this' to allow chaining calls
 *
 */
// start CLA_Class1_return_this_buffer_bufferify
CLA_Class1 * CLA_Class1_return_this_buffer_bufferify(CLA_Class1 * self,
    char * name, int Lname, bool flag, CLA_Class1 * SHC_rv)
{
    classes::Class1 *SH_this =
        static_cast<classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.return_this_buffer_bufferify
    std::string SHCXX_name(name, Lname);
    classes::Class1 * SHCXX_rv = SH_this->returnThisBuffer(SHCXX_name,
        flag);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end class.Class1.method.return_this_buffer_bufferify
}
// end CLA_Class1_return_this_buffer_bufferify

// Class1 * getclass3() const
/**
 * \brief Test const method
 *
 */
// start CLA_Class1_getclass3
CLA_Class1 * CLA_Class1_getclass3(const CLA_Class1 * self,
    CLA_Class1 * SHC_rv)
{
    const classes::Class1 *SH_this =
        static_cast<const classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.getclass3
    classes::Class1 * SHCXX_rv = SH_this->getclass3();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end class.Class1.method.getclass3
}
// end CLA_Class1_getclass3

// DIRECTION directionFunc(DIRECTION arg +intent(in)+value)
// start CLA_Class1_direction_func
int CLA_Class1_direction_func(CLA_Class1 * self, int arg)
{
    classes::Class1 *SH_this =
        static_cast<classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.direction_func
    classes::Class1::DIRECTION SHCXX_arg =
        static_cast<classes::Class1::DIRECTION>(arg);
    classes::Class1::DIRECTION SHCXX_rv = SH_this->directionFunc(
        SHCXX_arg);
    int SHC_rv = static_cast<int>(SHCXX_rv);
    return SHC_rv;
    // splicer end class.Class1.method.direction_func
}
// end CLA_Class1_direction_func

// int getM_flag()
// start CLA_Class1_get_m_flag
int CLA_Class1_get_m_flag(CLA_Class1 * self)
{
    classes::Class1 *SH_this =
        static_cast<classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.get_m_flag
    return SH_this->m_flag;
    // splicer end class.Class1.method.get_m_flag
}
// end CLA_Class1_get_m_flag

// int getTest()
// start CLA_Class1_get_test
int CLA_Class1_get_test(CLA_Class1 * self)
{
    classes::Class1 *SH_this =
        static_cast<classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.get_test
    return SH_this->m_test;
    // splicer end class.Class1.method.get_test
}
// end CLA_Class1_get_test

// void setTest(int val +intent(in)+value)
// start CLA_Class1_set_test
void CLA_Class1_set_test(CLA_Class1 * self, int val)
{
    classes::Class1 *SH_this =
        static_cast<classes::Class1 *>(self->addr);
    // splicer begin class.Class1.method.set_test
    SH_this->m_test = val;
    return;
    // splicer end class.Class1.method.set_test
}
// end CLA_Class1_set_test

}  // extern "C"
