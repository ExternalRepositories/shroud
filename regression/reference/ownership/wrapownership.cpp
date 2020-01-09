// wrapownership.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapownership.h"
#include <cstdlib>
#include <cstring>
#include "ownership.hpp"
#include "typesownership.h"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {


// helper function
// Copy std::vector into array c_var(c_var_size).
// Then release std::vector.
// Called from Fortran.
void OWN_ShroudCopyArray(OWN_SHROUD_array *data, void *c_var, 
    size_t c_var_size)
{
    const void *cxx_var = data->addr.base;
    int n = c_var_size < data->size ? c_var_size : data->size;
    n *= data->elem_len;
    std::memcpy(c_var, cxx_var, n);
    OWN_SHROUD_memory_destructor(&data->cxx); // delete data->cxx.addr
}
// splicer begin C_definitions
// splicer end C_definitions

// int * ReturnIntPtrRaw() +deref(raw)
int * OWN_return_int_ptr_raw()
{
    // splicer begin function.return_int_ptr_raw
    int * SHC_rv = ReturnIntPtrRaw();
    return SHC_rv;
    // splicer end function.return_int_ptr_raw
}

// int * ReturnIntPtrScalar() +deref(scalar)
int OWN_return_int_ptr_scalar()
{
    // splicer begin function.return_int_ptr_scalar
    int * SHC_rv = ReturnIntPtrScalar();
    return *SHC_rv;
    // splicer end function.return_int_ptr_scalar
}

// int * ReturnIntPtrPointer() +deref(pointer)
int * OWN_return_int_ptr_pointer()
{
    // splicer begin function.return_int_ptr_pointer
    int * SHC_rv = ReturnIntPtrPointer();
    return SHC_rv;
    // splicer end function.return_int_ptr_pointer
}

// int * ReturnIntPtrDimRaw(int * len +intent(out)) +deref(raw)
int * OWN_return_int_ptr_dim_raw(int * len)
{
    // splicer begin function.return_int_ptr_dim_raw
    int * SHC_rv = ReturnIntPtrDimRaw(len);
    return SHC_rv;
    // splicer end function.return_int_ptr_dim_raw
}

// int * ReturnIntPtrDimPointer(int * len +hidden+intent(out)) +deref(pointer)+dimension(len)
int * OWN_return_int_ptr_dim_pointer(int * len)
{
    // splicer begin function.return_int_ptr_dim_pointer
    int * SHC_rv = ReturnIntPtrDimPointer(len);
    return SHC_rv;
    // splicer end function.return_int_ptr_dim_pointer
}

// int * ReturnIntPtrDimAlloc(int * len +hidden+intent(out)) +deref(allocatable)+dimension(len)
int * OWN_return_int_ptr_dim_alloc(int * len)
{
    // splicer begin function.return_int_ptr_dim_alloc
    int * SHC_rv = ReturnIntPtrDimAlloc(len);
    return SHC_rv;
    // splicer end function.return_int_ptr_dim_alloc
}

// int * ReturnIntPtrDimAlloc(int * len +hidden+intent(out)) +context(DSHC_rv)+deref(allocatable)+dimension(len)
int * OWN_return_int_ptr_dim_alloc_bufferify(OWN_SHROUD_array *DSHC_rv,
    int * len)
{
    // splicer begin function.return_int_ptr_dim_alloc_bufferify
    int * SHC_rv = ReturnIntPtrDimAlloc(len);
    DSHC_rv->cxx.addr  = SHC_rv;
    DSHC_rv->cxx.idtor = 0;
    DSHC_rv->addr.base = SHC_rv;
    DSHC_rv->type = SH_TYPE_INT;
    DSHC_rv->elem_len = sizeof(int);
    DSHC_rv->size = *len;
    return SHC_rv;
    // splicer end function.return_int_ptr_dim_alloc_bufferify
}

// int * ReturnIntPtrDimDefault(int * len +hidden+intent(out)) +dimension(len)
int * OWN_return_int_ptr_dim_default(int * len)
{
    // splicer begin function.return_int_ptr_dim_default
    int * SHC_rv = ReturnIntPtrDimDefault(len);
    return SHC_rv;
    // splicer end function.return_int_ptr_dim_default
}

// int * ReturnIntPtrDimRawNew(int * len +hidden+intent(out)) +dimension(len)+owner(caller)
int * OWN_return_int_ptr_dim_raw_new(int * len)
{
    // splicer begin function.return_int_ptr_dim_raw_new
    int * SHC_rv = ReturnIntPtrDimRawNew(len);
    return SHC_rv;
    // splicer end function.return_int_ptr_dim_raw_new
}

// int * ReturnIntPtrDimPointerNew(int * len +hidden+intent(out)) +deref(pointer)+dimension(len)+owner(caller)
int * OWN_return_int_ptr_dim_pointer_new(int * len)
{
    // splicer begin function.return_int_ptr_dim_pointer_new
    int * SHC_rv = ReturnIntPtrDimPointerNew(len);
    return SHC_rv;
    // splicer end function.return_int_ptr_dim_pointer_new
}

// int * ReturnIntPtrDimAllocNew(int * len +hidden+intent(out)) +deref(allocatable)+dimension(len)+owner(caller)
int * OWN_return_int_ptr_dim_alloc_new(int * len)
{
    // splicer begin function.return_int_ptr_dim_alloc_new
    int * SHC_rv = ReturnIntPtrDimAllocNew(len);
    return SHC_rv;
    // splicer end function.return_int_ptr_dim_alloc_new
}

// int * ReturnIntPtrDimDefaultNew(int * len +hidden+intent(out)) +dimension(len)+owner(caller)
int * OWN_return_int_ptr_dim_default_new(int * len)
{
    // splicer begin function.return_int_ptr_dim_default_new
    int * SHC_rv = ReturnIntPtrDimDefaultNew(len);
    return SHC_rv;
    // splicer end function.return_int_ptr_dim_default_new
}

// void createClassStatic(int flag +intent(in)+value)
void OWN_create_class_static(int flag)
{
    // splicer begin function.create_class_static
    createClassStatic(flag);
    return;
    // splicer end function.create_class_static
}

// Class1 * getClassStatic() +owner(library)
OWN_Class1 * OWN_get_class_static(OWN_Class1 * SHC_rv)
{
    // splicer begin function.get_class_static
    Class1 * SHCXX_rv = getClassStatic();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end function.get_class_static
}

// Class1 * getClassNew(int flag +intent(in)+value) +owner(caller)
/**
 * \brief Return pointer to new Class1 instance.
 *
 */
OWN_Class1 * OWN_get_class_new(int flag, OWN_Class1 * SHC_rv)
{
    // splicer begin function.get_class_new
    Class1 * SHCXX_rv = getClassNew(flag);
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 1;
    return SHC_rv;
    // splicer end function.get_class_new
}

// Release library allocated memory.
void OWN_SHROUD_memory_destructor(OWN_SHROUD_capsule_data *cap)
{
    void *ptr = cap->addr;
    switch (cap->idtor) {
    case 0:   // --none--
    {
        // Nothing to delete
        break;
    }
    case 1:   // Class1
    {
        Class1 *cxx_ptr = reinterpret_cast<Class1 *>(ptr);
        delete cxx_ptr;
        break;
    }
    case 2:   // int
    {
        int *cxx_ptr = reinterpret_cast<int *>(ptr);
        free(cxx_ptr);
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

}  // extern "C"
