// wrapvectors.cpp
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapvectors.h"
#include <cstdlib>
#include "typesvectors.h"
#include "vectors.hpp"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {


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

// splicer begin C_definitions
// splicer end C_definitions

// ----------------------------------------
// Function:  int vector_sum
// Requested: c_native_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  const std::vector<int> & arg +intent(in)+rank(1)+size(Sarg)
// Requested: c_vector_&_in_buf_native
// Match:     c_vector_in_buf
// start VEC_vector_sum_bufferify
int VEC_vector_sum_bufferify(const int * arg, long Sarg)
{
    // splicer begin function.vector_sum_bufferify
    const std::vector<int> SHCXX_arg(arg, arg + Sarg);
    int SHC_rv = vector_sum(SHCXX_arg);
    return SHC_rv;
    // splicer end function.vector_sum_bufferify
}
// end VEC_vector_sum_bufferify

/**
 * \brief Copy vector into Fortran input array
 *
 */
// ----------------------------------------
// Function:  void vector_iota_out
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  std::vector<int> & arg +context(Darg)+intent(out)+rank(1)
// Requested: c_vector_&_out_buf_native
// Match:     c_vector_out_buf
// start VEC_vector_iota_out_bufferify
void VEC_vector_iota_out_bufferify(VEC_SHROUD_array *Darg)
{
    // splicer begin function.vector_iota_out_bufferify
    std::vector<int> *SHCXX_arg = new std::vector<int>;
    vector_iota_out(*SHCXX_arg);
    Darg->cxx.addr  = SHCXX_arg;
    Darg->cxx.idtor = 1;
    Darg->addr.base = SHCXX_arg->empty() ? nullptr : &SHCXX_arg->front();
    Darg->type = SH_TYPE_INT;
    Darg->elem_len = sizeof(int);
    Darg->size = SHCXX_arg->size();
    Darg->rank = 1;
    Darg->shape[0] = Darg->size;
    // splicer end function.vector_iota_out_bufferify
}
// end VEC_vector_iota_out_bufferify

/**
 * \brief Copy vector into Fortran input array
 *
 * Convert subroutine in to a function and
 * return the number of items copied into argument
 * by setting fstatements for both C and Fortran.
 */
// ----------------------------------------
// Function:  void vector_iota_out_with_num
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  std::vector<int> & arg +context(Darg)+intent(out)+rank(1)
// Requested: c_vector_&_out_buf_native
// Match:     c_vector_out_buf
// start VEC_vector_iota_out_with_num_bufferify
long VEC_vector_iota_out_with_num_bufferify(VEC_SHROUD_array *Darg)
{
    // splicer begin function.vector_iota_out_with_num_bufferify
    std::vector<int> *SHCXX_arg = new std::vector<int>;
    vector_iota_out_with_num(*SHCXX_arg);
    Darg->cxx.addr  = SHCXX_arg;
    Darg->cxx.idtor = 1;
    Darg->addr.base = SHCXX_arg->empty() ? nullptr : &SHCXX_arg->front();
    Darg->type = SH_TYPE_INT;
    Darg->elem_len = sizeof(int);
    Darg->size = SHCXX_arg->size();
    Darg->rank = 1;
    Darg->shape[0] = Darg->size;
    return Darg->size;
    // splicer end function.vector_iota_out_with_num_bufferify
}
// end VEC_vector_iota_out_with_num_bufferify

/**
 * \brief Copy vector into Fortran input array
 *
 * Convert subroutine in to a function.
 * Return the number of items copied into argument
 * by setting fstatements for the Fortran wrapper only.
 */
// ----------------------------------------
// Function:  void vector_iota_out_with_num2
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  std::vector<int> & arg +context(Darg)+intent(out)+rank(1)
// Requested: c_vector_&_out_buf_native
// Match:     c_vector_out_buf
// start VEC_vector_iota_out_with_num2_bufferify
void VEC_vector_iota_out_with_num2_bufferify(VEC_SHROUD_array *Darg)
{
    // splicer begin function.vector_iota_out_with_num2_bufferify
    std::vector<int> *SHCXX_arg = new std::vector<int>;
    vector_iota_out_with_num2(*SHCXX_arg);
    Darg->cxx.addr  = SHCXX_arg;
    Darg->cxx.idtor = 1;
    Darg->addr.base = SHCXX_arg->empty() ? nullptr : &SHCXX_arg->front();
    Darg->type = SH_TYPE_INT;
    Darg->elem_len = sizeof(int);
    Darg->size = SHCXX_arg->size();
    Darg->rank = 1;
    Darg->shape[0] = Darg->size;
    // splicer end function.vector_iota_out_with_num2_bufferify
}
// end VEC_vector_iota_out_with_num2_bufferify

/**
 * \brief Copy vector into Fortran allocatable array
 *
 */
// ----------------------------------------
// Function:  void vector_iota_out_alloc
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  std::vector<int> & arg +context(Darg)+deref(allocatable)+intent(out)+rank(1)
// Requested: c_vector_&_out_buf_native
// Match:     c_vector_out_buf
// start VEC_vector_iota_out_alloc_bufferify
void VEC_vector_iota_out_alloc_bufferify(VEC_SHROUD_array *Darg)
{
    // splicer begin function.vector_iota_out_alloc_bufferify
    std::vector<int> *SHCXX_arg = new std::vector<int>;
    vector_iota_out_alloc(*SHCXX_arg);
    Darg->cxx.addr  = SHCXX_arg;
    Darg->cxx.idtor = 1;
    Darg->addr.base = SHCXX_arg->empty() ? nullptr : &SHCXX_arg->front();
    Darg->type = SH_TYPE_INT;
    Darg->elem_len = sizeof(int);
    Darg->size = SHCXX_arg->size();
    Darg->rank = 1;
    Darg->shape[0] = Darg->size;
    // splicer end function.vector_iota_out_alloc_bufferify
}
// end VEC_vector_iota_out_alloc_bufferify

/**
 * \brief Copy vector into Fortran allocatable array
 *
 */
// ----------------------------------------
// Function:  void vector_iota_inout_alloc
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  std::vector<int> & arg +context(Darg)+deref(allocatable)+intent(inout)+rank(1)+size(Sarg)
// Requested: c_vector_&_inout_buf_native
// Match:     c_vector_inout_buf
// start VEC_vector_iota_inout_alloc_bufferify
void VEC_vector_iota_inout_alloc_bufferify(int * arg, long Sarg,
    VEC_SHROUD_array *Darg)
{
    // splicer begin function.vector_iota_inout_alloc_bufferify
    std::vector<int> *SHCXX_arg = new std::vector<int>(arg, arg + Sarg);
    vector_iota_inout_alloc(*SHCXX_arg);
    Darg->cxx.addr  = SHCXX_arg;
    Darg->cxx.idtor = 1;
    Darg->addr.base = SHCXX_arg->empty() ? nullptr : &SHCXX_arg->front();
    Darg->type = SH_TYPE_INT;
    Darg->elem_len = sizeof(int);
    Darg->size = SHCXX_arg->size();
    Darg->rank = 1;
    Darg->shape[0] = Darg->size;
    // splicer end function.vector_iota_inout_alloc_bufferify
}
// end VEC_vector_iota_inout_alloc_bufferify

// ----------------------------------------
// Function:  void vector_increment
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  std::vector<int> & arg +context(Darg)+intent(inout)+rank(1)+size(Sarg)
// Requested: c_vector_&_inout_buf_native
// Match:     c_vector_inout_buf
void VEC_vector_increment_bufferify(int * arg, long Sarg,
    VEC_SHROUD_array *Darg)
{
    // splicer begin function.vector_increment_bufferify
    std::vector<int> *SHCXX_arg = new std::vector<int>(arg, arg + Sarg);
    vector_increment(*SHCXX_arg);
    Darg->cxx.addr  = SHCXX_arg;
    Darg->cxx.idtor = 1;
    Darg->addr.base = SHCXX_arg->empty() ? nullptr : &SHCXX_arg->front();
    Darg->type = SH_TYPE_INT;
    Darg->elem_len = sizeof(int);
    Darg->size = SHCXX_arg->size();
    Darg->rank = 1;
    Darg->shape[0] = Darg->size;
    // splicer end function.vector_increment_bufferify
}

/**
 * \brief Copy vector into Fortran input array
 *
 */
// ----------------------------------------
// Function:  void vector_iota_out_d
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  std::vector<double> & arg +context(Darg)+intent(out)+rank(1)
// Requested: c_vector_&_out_buf_native
// Match:     c_vector_out_buf
void VEC_vector_iota_out_d_bufferify(VEC_SHROUD_array *Darg)
{
    // splicer begin function.vector_iota_out_d_bufferify
    std::vector<double> *SHCXX_arg = new std::vector<double>;
    vector_iota_out_d(*SHCXX_arg);
    Darg->cxx.addr  = SHCXX_arg;
    Darg->cxx.idtor = 2;
    Darg->addr.base = SHCXX_arg->empty() ? nullptr : &SHCXX_arg->front();
    Darg->type = SH_TYPE_DOUBLE;
    Darg->elem_len = sizeof(double);
    Darg->size = SHCXX_arg->size();
    Darg->rank = 1;
    Darg->shape[0] = Darg->size;
    // splicer end function.vector_iota_out_d_bufferify
}

/**
 * \brief count number of underscore in vector of strings
 *
 */
// ----------------------------------------
// Function:  int vector_string_count
// Requested: c_native_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  const std::vector<std::string> & arg +intent(in)+len(Narg)+rank(1)+size(Sarg)
// Requested: c_vector_&_in_buf_string
// Match:     c_vector_in_buf_string
int VEC_vector_string_count_bufferify(const char * arg, long Sarg,
    int Narg)
{
    // splicer begin function.vector_string_count_bufferify
    std::vector<std::string> SHCXX_arg;
    {
        const char * BBB = arg;
        std::vector<std::string>::size_type
            SHT_i = 0,
            SHT_n = Sarg;
        for(; SHT_i < SHT_n; SHT_i++) {
            SHCXX_arg.push_back(std::string(BBB,ShroudLenTrim(BBB, Narg)));
            BBB += Narg;
        }
    }
    int SHC_rv = vector_string_count(SHCXX_arg);
    return SHC_rv;
    // splicer end function.vector_string_count_bufferify
}

/**
 * Implement iota function.
 * Return a vector as an ALLOCATABLE array.
 * Copy results into the new array.
 */
// ----------------------------------------
// Function:  void ReturnVectorAlloc +rank(1)
// Requested: c_void_scalar_result_buf
// Match:     c_default
// ----------------------------------------
// Argument:  int n +intent(in)+value
// Requested: c_native_scalar_in_buf
// Match:     c_default
// ----------------------------------------
// Argument:  std::vector<int> * SHF_rv +context(DSHF_rv)+deref(allocatable)+intent(out)+rank(1)
// Requested: c_vector_scalar_result_buf_allocatable
// Match:     c_vector_result_buf
void VEC_return_vector_alloc_bufferify(int n, VEC_SHROUD_array *DSHF_rv)
{
    // splicer begin function.return_vector_alloc_bufferify
    std::vector<int> *SHC_rv = new std::vector<int>;
    *SHC_rv = ReturnVectorAlloc(n);
    DSHF_rv->cxx.addr  = SHC_rv;
    DSHF_rv->cxx.idtor = 1;
    DSHF_rv->addr.base = SHC_rv->empty() ? nullptr : &SHC_rv->front();
    DSHF_rv->type = SH_TYPE_INT;
    DSHF_rv->elem_len = sizeof(int);
    DSHF_rv->size = SHC_rv->size();
    DSHF_rv->rank = 1;
    DSHF_rv->shape[0] = DSHF_rv->size;
    // splicer end function.return_vector_alloc_bufferify
}

// start release allocated memory
// Release library allocated memory.
void VEC_SHROUD_memory_destructor(VEC_SHROUD_capsule_data *cap)
{
    void *ptr = cap->addr;
    switch (cap->idtor) {
    case 0:   // --none--
    {
        // Nothing to delete
        break;
    }
    case 1:   // std_vector_int
    {
        std::vector<int> *cxx_ptr = 
            reinterpret_cast<std::vector<int> *>(ptr);
        delete cxx_ptr;
        break;
    }
    case 2:   // std_vector_double
    {
        std::vector<double> *cxx_ptr = 
            reinterpret_cast<std::vector<double> *>(ptr);
        delete cxx_ptr;
        break;
    }
    default:
    {
        // Unexpected case in destructor
        break;
    }
    }
    cap->addr = nullptr;
    cap->idtor = 0;  // avoid deleting again
}
// end release allocated memory

}  // extern "C"
