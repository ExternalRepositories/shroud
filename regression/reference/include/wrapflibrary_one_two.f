! wrapflibrary_one_two.f
! This is generated code, do not edit
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapflibrary_one_two.f
!! \brief Shroud generated wrapper for two namespace
!<
module library_one_two_mod
    implicit none


    interface

        subroutine function1() &
                bind(C, name="LIB_one_two_function1")
            implicit none
        end subroutine function1

    end interface

contains


end module library_one_two_mod
