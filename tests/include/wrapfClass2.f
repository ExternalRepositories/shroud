! wrapfClass2.f
! This is generated code, do not edit
! #######################################################################
! Copyright (c) 2017-2018, Lawrence Livermore National Security, LLC.
! Produced at the Lawrence Livermore National Laboratory
!
! LLNL-CODE-738041.
! All rights reserved.
!
! This file is part of Shroud.  For details, see
! https://github.com/LLNL/shroud. Please also read shroud/LICENSE.
!
! Redistribution and use in source and binary forms, with or without
! modification, are permitted provided that the following conditions are
! met:
!
! * Redistributions of source code must retain the above copyright
!   notice, this list of conditions and the disclaimer below.
!
! * Redistributions in binary form must reproduce the above copyright
!   notice, this list of conditions and the disclaimer (as noted below)
!   in the documentation and/or other materials provided with the
!   distribution.
!
! * Neither the name of the LLNS/LLNL nor the names of its contributors
!   may be used to endorse or promote products derived from this
!   software without specific prior written permission.
!
! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
! LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
! A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE
! LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR
! CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
! EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
! PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
! PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
! LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
! NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
! SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
!
! #######################################################################
!>
!! \file wrapfClass2.f
!! \brief Shroud generated wrapper for Class2 class
!<
module class2_mod
    use iso_c_binding, only : C_INT, C_NULL_PTR, C_PTR
    implicit none


    type, bind(C) :: SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_capsule_data


    type class2
        type(SHROUD_capsule_data), private :: cxxmem
    contains
        procedure :: method1 => class2_method1
        procedure :: method2 => class2_method2
        procedure :: get_instance => class2_get_instance
        procedure :: set_instance => class2_set_instance
        procedure :: associated => class2_associated
        final :: class2_final
    end type class2

    interface operator (.eq.)
        module procedure class2_eq
    end interface

    interface operator (.ne.)
        module procedure class2_ne
    end interface

    interface

        subroutine c_class2_method1(self, comm) &
                bind(C, name="DEF_class2_method1")
            use iso_c_binding, only : C_INT
            import :: SHROUD_capsule_data
            implicit none
            type(SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: comm
        end subroutine c_class2_method1

        subroutine c_class2_method2(self, c2) &
                bind(C, name="DEF_class2_method2")
            use class1_mod, only : class1
            import :: SHROUD_capsule_data
            implicit none
            type(SHROUD_capsule_data), intent(IN) :: self
            type(SHROUD_capsule_data), intent(IN) :: c2
        end subroutine c_class2_method2

    end interface

contains

    subroutine class2_method1(obj, comm)
        class(class2) :: obj
        integer, value, intent(IN) :: comm
        call c_class2_method1(obj%cxxmem, comm)
    end subroutine class2_method1

    subroutine class2_method2(obj, c2)
        use class1_mod, only : class1
        class(class2) :: obj
        type(class1), intent(IN) :: c2
        call c_class2_method2(obj%cxxmem, c2%cxxmem)
    end subroutine class2_method2

    function class2_get_instance(obj) result (cxxmem)
        use iso_c_binding, only: C_PTR
        class(class2), intent(IN) :: obj
        type(C_PTR) :: cxxmem
        cxxmem = obj%cxxmem%addr
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

    subroutine class2_final(obj)
        type(class2), intent(INOUT) :: obj
        interface
            subroutine array_destructor(mem) &
                bind(C, name="DEF_SHROUD_array_destructor_function")
                import SHROUD_capsule_data
                implicit none
                type(SHROUD_capsule_data), intent(INOUT) :: mem
            end subroutine array_destructor
        end interface
        call array_destructor(obj%cxxmem)
    end subroutine class2_final


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

end module class2_mod
