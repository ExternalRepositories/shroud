// utiltemplates.cpp
// This file is generated by Shroud nowrite-version. Do not edit.
// Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//

// typemap
#include <vector>
#include "templates.hpp"
// shroud
#include "typestemplates.h"


#ifdef __cplusplus
extern "C" {
#endif

// Release library allocated memory.
void TEM_SHROUD_memory_destructor(TEM_SHROUD_capsule_data *cap)
{
    void *ptr = cap->addr;
    switch (cap->idtor) {
    case 0:   // --none--
    {
        // Nothing to delete
        break;
    }
    case 1:   // std::vector<int>
    {
        std::vector<int> *cxx_ptr = 
            reinterpret_cast<std::vector<int> *>(ptr);
        delete cxx_ptr;
        break;
    }
    case 2:   // std::vector<double>
    {
        std::vector<double> *cxx_ptr = 
            reinterpret_cast<std::vector<double> *>(ptr);
        delete cxx_ptr;
        break;
    }
    case 3:   // structAsClass<int>
    {
        structAsClass<int> *cxx_ptr =
            reinterpret_cast<structAsClass<int> *>(ptr);
        delete cxx_ptr;
        break;
    }
    case 4:   // structAsClass<double>
    {
        structAsClass<double> *cxx_ptr =
            reinterpret_cast<structAsClass<double> *>(ptr);
        delete cxx_ptr;
        break;
    }
    case 5:   // user<int>
    {
        user<int> *cxx_ptr = reinterpret_cast<user<int> *>(ptr);
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

#ifdef __cplusplus
}
#endif
