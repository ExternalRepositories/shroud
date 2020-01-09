! wrapflibrary.f
! This is generated code, do not edit
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
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


    type, bind(C) :: SHROUD_class2_capsule
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_class2_capsule

    type class2
        type(SHROUD_class2_capsule) :: cxxmem
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

        subroutine c_class2_method1(self, comm) &
                bind(C, name="LIB_Class2_method1")
            use iso_c_binding, only : C_INT
            import :: SHROUD_class2_capsule
            implicit none
            type(SHROUD_class2_capsule), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: comm
        end subroutine c_class2_method1

        subroutine c_class2_method2(self, c2) &
                bind(C, name="LIB_Class2_method2")
            import :: SHROUD_class1_capsule, SHROUD_class2_capsule
            implicit none
            type(SHROUD_class2_capsule), intent(IN) :: self
            type(SHROUD_class1_capsule), intent(IN) :: c2
        end subroutine c_class2_method2


    end interface

contains

    subroutine class2_method1(obj, comm)
        class(class2) :: obj
        integer, value, intent(IN) :: comm
        call c_class2_method1(obj%cxxmem, comm)
    end subroutine class2_method1

    subroutine class2_method2(obj, c2)
        use library_three_mod, only : class1
        class(class2) :: obj
        type(class1), intent(IN) :: c2
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
