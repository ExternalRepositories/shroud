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
//
// User2.hpp
//

class User2 {
  public:
#ifdef USE_USER2_A
    void exfunc()
#endif
#ifdef USE_USER2_A
    void exfunc(int flag) {};
#endif
};

