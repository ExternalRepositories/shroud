! wrapfscope_ns1Enum.f
! This is generated code, do not edit
! #######################################################################
! Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC.
!
! Produced at the Lawrence Livermore National Laboratory
!
! LLNL-CODE-738041.
!
! All rights reserved.
!
! This file is part of Shroud.
!
! For details about use and distribution, please read LICENSE.
!
! #######################################################################
!>
!! \file wrapfscope_ns1Enum.f
!! \brief Shroud generated wrapper for ns1Enum namespace
!<
! splicer begin namespace.ns1Enum.file_top
! splicer end namespace.ns1Enum.file_top
module scope_ns1enum_mod
    use iso_c_binding, only : C_INT
    ! splicer begin namespace.ns1Enum.module_use
    ! splicer end namespace.ns1Enum.module_use
    implicit none

    ! splicer begin namespace.ns1Enum.module_top
    ! splicer end namespace.ns1Enum.module_top

    !  enum ns1Enum::Color
    integer(C_INT), parameter :: red = 20
    integer(C_INT), parameter :: blue = 21
    integer(C_INT), parameter :: white = 22

    interface

        ! splicer begin namespace.ns1Enum.additional_interfaces
        ! splicer end namespace.ns1Enum.additional_interfaces
    end interface

contains

    ! splicer begin namespace.ns1Enum.additional_functions
    ! splicer end namespace.ns1Enum.additional_functions

end module scope_ns1enum_mod
