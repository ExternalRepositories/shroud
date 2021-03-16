! wrapflibrary.f
! This file is generated by Shroud nowrite-version. Do not edit.
! Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapflibrary.f
!! \brief Shroud generated wrapper for library library
!<
module library_mod
    use iso_c_binding, only : C_INT, C_NULL_PTR, C_PTR
    implicit none


    ! helper capsule_data_helper
    type, bind(C) :: LIB_SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type LIB_SHROUD_capsule_data

    type class2
        type(LIB_SHROUD_capsule_data) :: cxxmem
    contains
        procedure :: method1 => class2_method1
        procedure :: method2 => class2_method2
        procedure :: get_instance => class2_get_instance
        procedure :: set_instance => class2_set_instance
        procedure :: associated => class2_associated
    end type class2

    interface operator (.eq.)
        module procedure class2_eq
    end interface

    interface operator (.ne.)
        module procedure class2_ne
    end interface

    interface

        ! ----------------------------------------
        ! Function:  void method1
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  MPI_Comm comm +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_unknown_scalar
        ! Match:     c_default
        subroutine c_class2_method1(self, comm) &
                bind(C, name="LIB_Class2_method1")
            use iso_c_binding, only : C_INT
            import :: LIB_SHROUD_capsule_data
            implicit none
            type(LIB_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: comm
        end subroutine c_class2_method1

        ! ----------------------------------------
        ! Function:  void method2
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  three::Class1 * c2
        ! Attrs:     +intent(inout)
        ! Requested: c_inout_shadow_*
        ! Match:     c_inout_shadow
        subroutine c_class2_method2(self, c2) &
                bind(C, name="LIB_Class2_method2")
            import :: LIB_SHROUD_capsule_data
            implicit none
            type(LIB_SHROUD_capsule_data), intent(IN) :: self
            type(LIB_SHROUD_capsule_data), intent(INOUT) :: c2
        end subroutine c_class2_method2


    end interface

contains

    ! ----------------------------------------
    ! Function:  void method1
    ! Attrs:     +intent(subroutine)
    ! Exact:     f_subroutine
    ! Attrs:     +intent(subroutine)
    ! Exact:     c_subroutine
    ! ----------------------------------------
    ! Argument:  MPI_Comm comm +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_unknown_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_unknown_scalar
    ! Match:     c_default
    subroutine class2_method1(obj, comm)
        class(class2) :: obj
        integer, value, intent(IN) :: comm
        call c_class2_method1(obj%cxxmem, comm)
    end subroutine class2_method1

    ! ----------------------------------------
    ! Function:  void method2
    ! Attrs:     +intent(subroutine)
    ! Exact:     f_subroutine
    ! Attrs:     +intent(subroutine)
    ! Exact:     c_subroutine
    ! ----------------------------------------
    ! Argument:  three::Class1 * c2
    ! Attrs:     +intent(inout)
    ! Requested: f_inout_shadow_*
    ! Match:     f_default
    ! Attrs:     +intent(inout)
    ! Requested: c_inout_shadow_*
    ! Match:     c_inout_shadow
    subroutine class2_method2(obj, c2)
        use library_three_mod, only : class1
        class(class2) :: obj
        type(class1), intent(INOUT) :: c2
        call c_class2_method2(obj%cxxmem, c2%cxxmem)
    end subroutine class2_method2

    ! Return pointer to C++ memory.
    function class2_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(class2), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function class2_get_instance

    subroutine class2_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(class2), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine class2_set_instance

    function class2_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(class2), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function class2_associated



    function class2_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class2), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class2_eq

    function class2_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class2), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class2_ne

end module library_mod
