! wrapfmemdoc.f
! This file is generated by Shroud nowrite-version. Do not edit.
! Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfmemdoc.f
!! \brief Shroud generated wrapper for memdoc library
!<
! splicer begin file_top
! splicer end file_top
module memdoc_mod
    use iso_c_binding, only : C_INT, C_LONG, C_NULL_PTR, C_PTR, C_SIZE_T
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    ! start helper capsule_data_helper
    ! helper capsule_data_helper
    type, bind(C) :: STR_SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type STR_SHROUD_capsule_data
    ! end helper capsule_data_helper

    ! start array_context
    ! helper array_context
    type, bind(C) :: STR_SHROUD_array
        ! address of C++ memory
        type(STR_SHROUD_capsule_data) :: cxx
        ! address of data in cxx
        type(C_PTR) :: base_addr = C_NULL_PTR
        ! type of element
        integer(C_INT) :: type
        ! bytes-per-item or character len of data in cxx
        integer(C_SIZE_T) :: elem_len = 0_C_SIZE_T
        ! size of data in cxx
        integer(C_SIZE_T) :: size = 0_C_SIZE_T
        ! number of dimensions
        integer(C_INT) :: rank = -1
        integer(C_LONG) :: shape(7) = 0
    end type STR_SHROUD_array
    ! end array_context

    ! ----------------------------------------
    ! Function:  const std::string * getConstStringPtrAlloc +owner(library)
    ! Attrs:     +deref(allocatable)+intent(result)
    ! Requested: c_string_*_result_allocatable
    ! Match:     c_string_*_result
    ! start c_get_const_string_ptr_alloc
    interface
        function c_get_const_string_ptr_alloc() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ptr_alloc")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ptr_alloc
    end interface
    ! end c_get_const_string_ptr_alloc

    ! ----------------------------------------
    ! Function:  const std::string * getConstStringPtrAlloc +owner(library)
    ! Attrs:     +deref(allocatable)+intent(result)
    ! Exact:     c_string_*_result_buf_allocatable
    ! start c_get_const_string_ptr_alloc_bufferify
    interface
        subroutine c_get_const_string_ptr_alloc_bufferify(SHT_rv) &
                bind(C, name="STR_get_const_string_ptr_alloc_bufferify")
            import :: STR_SHROUD_array
            implicit none
            type(STR_SHROUD_array), intent(OUT) :: SHT_rv
        end subroutine c_get_const_string_ptr_alloc_bufferify
    end interface
    ! end c_get_const_string_ptr_alloc_bufferify

    interface
        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface
        ! helper copy_string
        ! Copy the char* or std::string in context into c_var.
        subroutine STR_SHROUD_copy_string_and_free(context, c_var, c_var_size) &
             bind(c,name="STR_ShroudCopyStringAndFree")
            use, intrinsic :: iso_c_binding, only : C_CHAR, C_SIZE_T
            import STR_SHROUD_array
            type(STR_SHROUD_array), intent(IN) :: context
            character(kind=C_CHAR), intent(OUT) :: c_var(*)
            integer(C_SIZE_T), value :: c_var_size
        end subroutine STR_SHROUD_copy_string_and_free
    end interface

contains

    ! Generated by arg_to_buffer
    ! ----------------------------------------
    ! Function:  const std::string * getConstStringPtrAlloc +owner(library)
    ! Attrs:     +deref(allocatable)+intent(result)
    ! Requested: f_string_*_result_buf_allocatable_library
    ! Match:     f_string_*_result_buf_allocatable
    ! Attrs:     +deref(allocatable)+intent(result)
    ! Exact:     c_string_*_result_buf_allocatable
    ! start get_const_string_ptr_alloc
    function get_const_string_ptr_alloc() &
            result(SHT_rv)
        character(len=:), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_ptr_alloc
        type(STR_SHROUD_array) :: SHT_ptr
        call c_get_const_string_ptr_alloc_bufferify(SHT_ptr)
        allocate(character(len=SHT_ptr%elem_len):: SHT_rv)
        call STR_SHROUD_copy_string_and_free(SHT_ptr, SHT_rv, SHT_ptr%elem_len)
        ! splicer end function.get_const_string_ptr_alloc
    end function get_const_string_ptr_alloc
    ! end get_const_string_ptr_alloc

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module memdoc_mod
