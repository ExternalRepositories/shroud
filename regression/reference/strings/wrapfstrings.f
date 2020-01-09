! wrapfstrings.f
! This is generated code, do not edit
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfstrings.f
!! \brief Shroud generated wrapper for strings library
!<
! splicer begin file_top
! splicer end file_top
module strings_mod
    use iso_c_binding, only : C_INT, C_NULL_PTR, C_PTR, C_SIZE_T
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    type, bind(C) :: SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_capsule_data

    ! start array_context
    type, bind(C) :: SHROUD_array
        ! address of C++ memory
        type(SHROUD_capsule_data) :: cxx
        ! address of data in cxx
        type(C_PTR) :: base_addr = C_NULL_PTR
        ! type of element
        integer(C_INT) :: type
        ! bytes-per-item or character len of data in cxx
        integer(C_SIZE_T) :: elem_len = 0_C_SIZE_T
        ! size of data in cxx
        integer(C_SIZE_T) :: size = 0_C_SIZE_T
    end type SHROUD_array
    ! end array_context

    interface
        subroutine pass_char(status) &
                bind(C, name="STR_pass_char")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), value, intent(IN) :: status
        end subroutine pass_char
    end interface

    interface
        function c_return_char() &
                result(SHT_rv) &
                bind(C, name="STR_return_char")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR) :: SHT_rv
        end function c_return_char
    end interface

    interface
        subroutine c_return_char_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_return_char_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_return_char_bufferify
    end interface

    ! start c_pass_char_ptr
    interface
        subroutine c_pass_char_ptr(dest, src) &
                bind(C, name="STR_pass_char_ptr")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: dest(*)
            character(kind=C_CHAR), intent(IN) :: src(*)
        end subroutine c_pass_char_ptr
    end interface
    ! end c_pass_char_ptr

    ! start c_pass_char_ptr_bufferify
    interface
        subroutine c_pass_char_ptr_bufferify(dest, Ndest, src) &
                bind(C, name="STR_pass_char_ptr_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: dest(*)
            integer(C_INT), value, intent(IN) :: Ndest
            character(kind=C_CHAR), intent(IN) :: src(*)
        end subroutine c_pass_char_ptr_bufferify
    end interface
    ! end c_pass_char_ptr_bufferify

    interface
        subroutine c_pass_char_ptr_in_out(s) &
                bind(C, name="STR_pass_char_ptr_in_out")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: s(*)
        end subroutine c_pass_char_ptr_in_out
    end interface

    interface
        subroutine c_pass_char_ptr_in_out_bufferify(s, Ls, Ns) &
                bind(C, name="STR_pass_char_ptr_in_out_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: s(*)
            integer(C_INT), value, intent(IN) :: Ls
            integer(C_INT), value, intent(IN) :: Ns
        end subroutine c_pass_char_ptr_in_out_bufferify
    end interface

    ! start c_get_char_ptr1
    interface
        function c_get_char_ptr1() &
                result(SHT_rv) &
                bind(C, name="STR_get_char_ptr1")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_char_ptr1
    end interface
    ! end c_get_char_ptr1

    ! start c_get_char_ptr1_bufferify
    interface
        subroutine c_get_char_ptr1_bufferify(DSHF_rv) &
                bind(C, name="STR_get_char_ptr1_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(OUT) :: DSHF_rv
        end subroutine c_get_char_ptr1_bufferify
    end interface
    ! end c_get_char_ptr1_bufferify

    ! start c_get_char_ptr2
    interface
        function c_get_char_ptr2() &
                result(SHT_rv) &
                bind(C, name="STR_get_char_ptr2")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_char_ptr2
    end interface
    ! end c_get_char_ptr2

    ! start c_get_char_ptr2_bufferify
    interface
        subroutine c_get_char_ptr2_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_char_ptr2_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_char_ptr2_bufferify
    end interface
    ! end c_get_char_ptr2_bufferify

    ! start c_get_char_ptr3
    interface
        function c_get_char_ptr3() &
                result(SHT_rv) &
                bind(C, name="STR_get_char_ptr3")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_char_ptr3
    end interface
    ! end c_get_char_ptr3

    ! start c_get_char_ptr3_bufferify
    interface
        subroutine c_get_char_ptr3_bufferify(output, Noutput) &
                bind(C, name="STR_get_char_ptr3_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: output(*)
            integer(C_INT), value, intent(IN) :: Noutput
        end subroutine c_get_char_ptr3_bufferify
    end interface
    ! end c_get_char_ptr3_bufferify

    interface
        subroutine c_get_const_string_result_bufferify(DSHF_rv) &
                bind(C, name="STR_get_const_string_result_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(OUT) :: DSHF_rv
        end subroutine c_get_const_string_result_bufferify
    end interface

    interface
        subroutine c_get_const_string_len_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_const_string_len_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_const_string_len_bufferify
    end interface

    interface
        subroutine c_get_const_string_as_arg_bufferify(output, Noutput) &
                bind(C, name="STR_get_const_string_as_arg_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: output(*)
            integer(C_INT), value, intent(IN) :: Noutput
        end subroutine c_get_const_string_as_arg_bufferify
    end interface

    interface
        subroutine c_get_const_string_alloc_bufferify(DSHF_rv) &
                bind(C, name="STR_get_const_string_alloc_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(OUT) :: DSHF_rv
        end subroutine c_get_const_string_alloc_bufferify
    end interface

    ! start c_get_const_string_ref_pure
    interface
        function c_get_const_string_ref_pure() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_pure")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_pure
    end interface
    ! end c_get_const_string_ref_pure

    ! start c_get_const_string_ref_pure_bufferify
    interface
        subroutine c_get_const_string_ref_pure_bufferify(DSHF_rv) &
                bind(C, name="STR_get_const_string_ref_pure_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(OUT) :: DSHF_rv
        end subroutine c_get_const_string_ref_pure_bufferify
    end interface
    ! end c_get_const_string_ref_pure_bufferify

    interface
        function c_get_const_string_ref_len() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_len")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_len
    end interface

    interface
        subroutine c_get_const_string_ref_len_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_const_string_ref_len_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_const_string_ref_len_bufferify
    end interface

    interface
        function c_get_const_string_ref_as_arg() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_as_arg")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_as_arg
    end interface

    interface
        subroutine c_get_const_string_ref_as_arg_bufferify(output, &
                Noutput) &
                bind(C, name="STR_get_const_string_ref_as_arg_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: output(*)
            integer(C_INT), value, intent(IN) :: Noutput
        end subroutine c_get_const_string_ref_as_arg_bufferify
    end interface

    interface
        function c_get_const_string_ref_len_empty() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_len_empty")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_len_empty
    end interface

    interface
        subroutine c_get_const_string_ref_len_empty_bufferify(SHF_rv, &
                NSHF_rv) &
                bind(C, name="STR_get_const_string_ref_len_empty_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_const_string_ref_len_empty_bufferify
    end interface

    interface
        function c_get_const_string_ref_alloc() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_alloc")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_alloc
    end interface

    interface
        subroutine c_get_const_string_ref_alloc_bufferify(DSHF_rv) &
                bind(C, name="STR_get_const_string_ref_alloc_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(OUT) :: DSHF_rv
        end subroutine c_get_const_string_ref_alloc_bufferify
    end interface

    interface
        function c_get_const_string_ptr_len() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ptr_len")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ptr_len
    end interface

    interface
        subroutine c_get_const_string_ptr_len_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_const_string_ptr_len_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_const_string_ptr_len_bufferify
    end interface

    interface
        function c_get_const_string_ptr_alloc() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ptr_alloc")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ptr_alloc
    end interface

    interface
        subroutine c_get_const_string_ptr_alloc_bufferify(DSHF_rv) &
                bind(C, name="STR_get_const_string_ptr_alloc_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(OUT) :: DSHF_rv
        end subroutine c_get_const_string_ptr_alloc_bufferify
    end interface

    interface
        function c_get_const_string_ptr_owns_alloc() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ptr_owns_alloc")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ptr_owns_alloc
    end interface

    interface
        subroutine c_get_const_string_ptr_owns_alloc_bufferify(DSHF_rv) &
                bind(C, name="STR_get_const_string_ptr_owns_alloc_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(OUT) :: DSHF_rv
        end subroutine c_get_const_string_ptr_owns_alloc_bufferify
    end interface

    interface
        function c_get_const_string_ptr_owns_alloc_pattern() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ptr_owns_alloc_pattern")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ptr_owns_alloc_pattern
    end interface

    interface
        subroutine c_get_const_string_ptr_owns_alloc_pattern_bufferify( &
                DSHF_rv) &
                bind(C, name="STR_get_const_string_ptr_owns_alloc_pattern_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(OUT) :: DSHF_rv
        end subroutine c_get_const_string_ptr_owns_alloc_pattern_bufferify
    end interface

    interface
        subroutine c_accept_string_const_reference(arg1) &
                bind(C, name="STR_accept_string_const_reference")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
        end subroutine c_accept_string_const_reference
    end interface

    interface
        subroutine c_accept_string_const_reference_bufferify(arg1, &
                Larg1) &
                bind(C, name="STR_accept_string_const_reference_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
        end subroutine c_accept_string_const_reference_bufferify
    end interface

    interface
        subroutine c_accept_string_reference_out(arg1) &
                bind(C, name="STR_accept_string_reference_out")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: arg1(*)
        end subroutine c_accept_string_reference_out
    end interface

    interface
        subroutine c_accept_string_reference_out_bufferify(arg1, Narg1) &
                bind(C, name="STR_accept_string_reference_out_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Narg1
        end subroutine c_accept_string_reference_out_bufferify
    end interface

    ! start c_accept_string_reference
    interface
        subroutine c_accept_string_reference(arg1) &
                bind(C, name="STR_accept_string_reference")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: arg1(*)
        end subroutine c_accept_string_reference
    end interface
    ! end c_accept_string_reference

    ! start c_accept_string_reference_bufferify
    interface
        subroutine c_accept_string_reference_bufferify(arg1, Larg1, &
                Narg1) &
                bind(C, name="STR_accept_string_reference_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            integer(C_INT), value, intent(IN) :: Narg1
        end subroutine c_accept_string_reference_bufferify
    end interface
    ! end c_accept_string_reference_bufferify

    interface
        subroutine c_accept_string_pointer(arg1) &
                bind(C, name="STR_accept_string_pointer")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: arg1(*)
        end subroutine c_accept_string_pointer
    end interface

    interface
        subroutine c_accept_string_pointer_bufferify(arg1, Larg1, Narg1) &
                bind(C, name="STR_accept_string_pointer_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            integer(C_INT), value, intent(IN) :: Narg1
        end subroutine c_accept_string_pointer_bufferify
    end interface

    interface
        subroutine c_explicit1(name) &
                bind(C, name="STR_explicit1")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
        end subroutine c_explicit1
    end interface

    interface
        subroutine c_explicit2(name) &
                bind(C, name="STR_explicit2")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: name(*)
        end subroutine c_explicit2
    end interface

    interface
        subroutine c_explicit2_bufferify(name, AAtrim) &
                bind(C, name="STR_explicit2_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: name(*)
            integer(C_INT), value, intent(IN) :: AAtrim
        end subroutine c_explicit2_bufferify
    end interface

    interface
        subroutine cpass_char(status) &
                bind(C, name="CpassChar")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), value, intent(IN) :: status
        end subroutine cpass_char
    end interface

    interface
        function c_creturn_char() &
                result(SHT_rv) &
                bind(C, name="CreturnChar")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR) :: SHT_rv
        end function c_creturn_char
    end interface

    interface
        subroutine c_creturn_char_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_creturn_char_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_creturn_char_bufferify
    end interface

    interface
        subroutine c_cpass_char_ptr(dest, src) &
                bind(C, name="CpassCharPtr")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: dest(*)
            character(kind=C_CHAR), intent(IN) :: src(*)
        end subroutine c_cpass_char_ptr
    end interface

    interface
        subroutine c_cpass_char_ptr_bufferify(dest, Ndest, src) &
                bind(C, name="STR_cpass_char_ptr_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: dest(*)
            integer(C_INT), value, intent(IN) :: Ndest
            character(kind=C_CHAR), intent(IN) :: src(*)
        end subroutine c_cpass_char_ptr_bufferify
    end interface

    interface
        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface
        ! helper function
        ! Copy the char* or std::string in context into c_var.
        subroutine SHROUD_copy_string_and_free(context, c_var, c_var_size) &
             bind(c,name="STR_ShroudCopyStringAndFree")
            use, intrinsic :: iso_c_binding, only : C_CHAR, C_SIZE_T
            import SHROUD_array
            type(SHROUD_array), intent(IN) :: context
            character(kind=C_CHAR), intent(OUT) :: c_var(*)
            integer(C_SIZE_T), value :: c_var_size
        end subroutine SHROUD_copy_string_and_free
    end interface

contains

    ! char returnChar()
    ! arg_to_buffer
    !>
    !! \brief return a char argument (non-pointer)
    !!
    !<
    function return_char() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        character :: SHT_rv
        ! splicer begin function.return_char
        call c_return_char_bufferify(SHT_rv, len(SHT_rv, kind=C_INT))
        ! splicer end function.return_char
    end function return_char

    ! void passCharPtr(char * dest +charlen(40)+intent(out), const char * src +intent(in))
    ! arg_to_buffer
    !>
    !! \brief strcpy like behavior
    !!
    !! dest is marked intent(OUT) to override the intent(INOUT) default
    !! This avoid a copy-in on dest.
    !! In Python, src must not be over 40 characters, defined by charlen.
    !<
    ! start pass_char_ptr
    subroutine pass_char_ptr(dest, src)
        use iso_c_binding, only : C_INT, C_NULL_CHAR
        character(len=*), intent(OUT) :: dest
        character(len=*), intent(IN) :: src
        ! splicer begin function.pass_char_ptr
        call c_pass_char_ptr_bufferify(dest, len(dest, kind=C_INT), &
            trim(src)//C_NULL_CHAR)
        ! splicer end function.pass_char_ptr
    end subroutine pass_char_ptr
    ! end pass_char_ptr

    ! void passCharPtrInOut(char * s +intent(inout))
    ! arg_to_buffer
    !>
    !! \brief toupper
    !!
    !! Change a string in-place.
    !! For Python, return a new string since strings are immutable.
    !<
    subroutine pass_char_ptr_in_out(s)
        use iso_c_binding, only : C_INT
        character(len=*), intent(INOUT) :: s
        ! splicer begin function.pass_char_ptr_in_out
        call c_pass_char_ptr_in_out_bufferify(s, &
            len_trim(s, kind=C_INT), len(s, kind=C_INT))
        ! splicer end function.pass_char_ptr_in_out
    end subroutine pass_char_ptr_in_out

    ! const char * getCharPtr1() +deref(allocatable)
    ! arg_to_buffer
    !>
    !! \brief return a 'const char *' as character(*)
    !!
    !<
    ! start get_char_ptr1
    function get_char_ptr1() &
            result(SHT_rv)
        type(SHROUD_array) :: DSHF_rv
        character(len=:), allocatable :: SHT_rv
        ! splicer begin function.get_char_ptr1
        call c_get_char_ptr1_bufferify(DSHF_rv)
        allocate(character(len=DSHF_rv%elem_len):: SHT_rv)
        call SHROUD_copy_string_and_free(DSHF_rv, SHT_rv, DSHF_rv%elem_len)
        ! splicer end function.get_char_ptr1
    end function get_char_ptr1
    ! end get_char_ptr1

    ! const char * getCharPtr2() +deref(result_as_arg)+len(30)
    ! arg_to_buffer
    !>
    !! \brief return 'const char *' with fixed size (len=30)
    !!
    !<
    ! start get_char_ptr2
    function get_char_ptr2() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        character(len=30) :: SHT_rv
        ! splicer begin function.get_char_ptr2
        call c_get_char_ptr2_bufferify(SHT_rv, len(SHT_rv, kind=C_INT))
        ! splicer end function.get_char_ptr2
    end function get_char_ptr2
    ! end get_char_ptr2

    ! void getCharPtr3(char * output +intent(out)+len(Noutput))
    ! arg_to_buffer - arg_to_buffer
    !>
    !! \brief return a 'const char *' as argument
    !!
    !<
    ! start get_char_ptr3
    subroutine get_char_ptr3(output)
        use iso_c_binding, only : C_INT
        character(len=*), intent(OUT) :: output
        ! splicer begin function.get_char_ptr3
        call c_get_char_ptr3_bufferify(output, len(output, kind=C_INT))
        ! splicer end function.get_char_ptr3
    end subroutine get_char_ptr3
    ! end get_char_ptr3

    ! const string getConstStringResult() +deref(allocatable)
    ! arg_to_buffer
    !>
    !! \brief return an ALLOCATABLE CHARACTER from std::string
    !!
    !<
    function get_const_string_result() &
            result(SHT_rv)
        type(SHROUD_array) :: DSHF_rv
        character(len=:), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_result
        call c_get_const_string_result_bufferify(DSHF_rv)
        allocate(character(len=DSHF_rv%elem_len):: SHT_rv)
        call SHROUD_copy_string_and_free(DSHF_rv, SHT_rv, DSHF_rv%elem_len)
        ! splicer end function.get_const_string_result
    end function get_const_string_result

    ! const string getConstStringLen() +deref(result_as_arg)+len(30)
    ! arg_to_buffer
    !>
    !! \brief return a 'const string' as argument
    !!
    !<
    function get_const_string_len() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        character(len=30) :: SHT_rv
        ! splicer begin function.get_const_string_len
        call c_get_const_string_len_bufferify(SHT_rv, &
            len(SHT_rv, kind=C_INT))
        ! splicer end function.get_const_string_len
    end function get_const_string_len

    ! void getConstStringAsArg(string * output +intent(out)+len(Noutput))
    ! arg_to_buffer - arg_to_buffer
    !>
    !! \brief return a 'const string' as argument
    !!
    !<
    subroutine get_const_string_as_arg(output)
        use iso_c_binding, only : C_INT
        character(len=*), intent(OUT) :: output
        ! splicer begin function.get_const_string_as_arg
        call c_get_const_string_as_arg_bufferify(output, &
            len(output, kind=C_INT))
        ! splicer end function.get_const_string_as_arg
    end subroutine get_const_string_as_arg

    ! const std::string getConstStringAlloc() +deref(allocatable)
    ! arg_to_buffer
    function get_const_string_alloc() &
            result(SHT_rv)
        type(SHROUD_array) :: DSHF_rv
        character(len=:), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_alloc
        call c_get_const_string_alloc_bufferify(DSHF_rv)
        allocate(character(len=DSHF_rv%elem_len):: SHT_rv)
        call SHROUD_copy_string_and_free(DSHF_rv, SHT_rv, DSHF_rv%elem_len)
        ! splicer end function.get_const_string_alloc
    end function get_const_string_alloc

    ! const string & getConstStringRefPure() +deref(allocatable)
    ! arg_to_buffer
    !>
    !! \brief return a 'const string&' as ALLOCATABLE character
    !!
    !<
    ! start get_const_string_ref_pure
    function get_const_string_ref_pure() &
            result(SHT_rv)
        type(SHROUD_array) :: DSHF_rv
        character(len=:), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_ref_pure
        call c_get_const_string_ref_pure_bufferify(DSHF_rv)
        allocate(character(len=DSHF_rv%elem_len):: SHT_rv)
        call SHROUD_copy_string_and_free(DSHF_rv, SHT_rv, DSHF_rv%elem_len)
        ! splicer end function.get_const_string_ref_pure
    end function get_const_string_ref_pure
    ! end get_const_string_ref_pure

    ! const string & getConstStringRefLen() +deref(result_as_arg)+len(30)
    ! arg_to_buffer
    !>
    !! \brief return 'const string&' with fixed size (len=30)
    !!
    !! Since +len(30) is provided, the result of the function
    !! will be copied directly into memory provided by Fortran.
    !! The function will not be ALLOCATABLE.
    !<
    function get_const_string_ref_len() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        character(len=30) :: SHT_rv
        ! splicer begin function.get_const_string_ref_len
        call c_get_const_string_ref_len_bufferify(SHT_rv, &
            len(SHT_rv, kind=C_INT))
        ! splicer end function.get_const_string_ref_len
    end function get_const_string_ref_len

    ! void getConstStringRefAsArg(string & output +intent(out)+len(Noutput))
    ! arg_to_buffer - arg_to_buffer
    !>
    !! \brief return a 'const string&' as argument
    !!
    !! Pass an additional argument which wil be used as the return value.
    !! The length of the output variable is declared by the caller.
    !<
    subroutine get_const_string_ref_as_arg(output)
        use iso_c_binding, only : C_INT
        character(len=*), intent(OUT) :: output
        ! splicer begin function.get_const_string_ref_as_arg
        call c_get_const_string_ref_as_arg_bufferify(output, &
            len(output, kind=C_INT))
        ! splicer end function.get_const_string_ref_as_arg
    end subroutine get_const_string_ref_as_arg

    ! const string & getConstStringRefLenEmpty() +deref(result_as_arg)+len(30)
    ! arg_to_buffer
    !>
    !! \brief Test returning empty string reference
    !!
    !<
    function get_const_string_ref_len_empty() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        character(len=30) :: SHT_rv
        ! splicer begin function.get_const_string_ref_len_empty
        call c_get_const_string_ref_len_empty_bufferify(SHT_rv, &
            len(SHT_rv, kind=C_INT))
        ! splicer end function.get_const_string_ref_len_empty
    end function get_const_string_ref_len_empty

    ! const std::string & getConstStringRefAlloc() +deref(allocatable)
    ! arg_to_buffer
    function get_const_string_ref_alloc() &
            result(SHT_rv)
        type(SHROUD_array) :: DSHF_rv
        character(len=:), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_ref_alloc
        call c_get_const_string_ref_alloc_bufferify(DSHF_rv)
        allocate(character(len=DSHF_rv%elem_len):: SHT_rv)
        call SHROUD_copy_string_and_free(DSHF_rv, SHT_rv, DSHF_rv%elem_len)
        ! splicer end function.get_const_string_ref_alloc
    end function get_const_string_ref_alloc

    ! const string * getConstStringPtrLen() +deref(result_as_arg)+len(30)
    ! arg_to_buffer
    !>
    !! \brief return a 'const string *' as character(30)
    !!
    !! It is the caller's responsibility to release the string
    !! created by the C++ library.
    !! This is accomplished with C_finalize_buf which is possible
    !! because +len(30) so the contents are copied before returning.
    !<
    function get_const_string_ptr_len() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        character(len=30) :: SHT_rv
        ! splicer begin function.get_const_string_ptr_len
        call c_get_const_string_ptr_len_bufferify(SHT_rv, &
            len(SHT_rv, kind=C_INT))
        ! splicer end function.get_const_string_ptr_len
    end function get_const_string_ptr_len

    ! const std::string * getConstStringPtrAlloc() +deref(allocatable)+owner(library)
    ! arg_to_buffer
    function get_const_string_ptr_alloc() &
            result(SHT_rv)
        type(SHROUD_array) :: DSHF_rv
        character(len=:), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_ptr_alloc
        call c_get_const_string_ptr_alloc_bufferify(DSHF_rv)
        allocate(character(len=DSHF_rv%elem_len):: SHT_rv)
        call SHROUD_copy_string_and_free(DSHF_rv, SHT_rv, DSHF_rv%elem_len)
        ! splicer end function.get_const_string_ptr_alloc
    end function get_const_string_ptr_alloc

    ! const std::string * getConstStringPtrOwnsAlloc() +deref(allocatable)+owner(caller)
    ! arg_to_buffer
    !>
    !! It is the caller's responsibility to release the string
    !! created by the C++ library.
    !! This is accomplished +owner(caller) which sets idtor.
    !! The contents are copied by Fortran so they must outlast
    !! the return from the C wrapper.
    !<
    function get_const_string_ptr_owns_alloc() &
            result(SHT_rv)
        type(SHROUD_array) :: DSHF_rv
        character(len=:), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_ptr_owns_alloc
        call c_get_const_string_ptr_owns_alloc_bufferify(DSHF_rv)
        allocate(character(len=DSHF_rv%elem_len):: SHT_rv)
        call SHROUD_copy_string_and_free(DSHF_rv, SHT_rv, DSHF_rv%elem_len)
        ! splicer end function.get_const_string_ptr_owns_alloc
    end function get_const_string_ptr_owns_alloc

    ! const std::string * getConstStringPtrOwnsAllocPattern() +deref(allocatable)+free_pattern(C_string_free)+owner(caller)
    ! arg_to_buffer
    !>
    !! Similar to getConstStringPtrOwnsAlloc, but uses pattern to release memory.
    !<
    function get_const_string_ptr_owns_alloc_pattern() &
            result(SHT_rv)
        type(SHROUD_array) :: DSHF_rv
        character(len=:), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_ptr_owns_alloc_pattern
        call c_get_const_string_ptr_owns_alloc_pattern_bufferify(DSHF_rv)
        allocate(character(len=DSHF_rv%elem_len):: SHT_rv)
        call SHROUD_copy_string_and_free(DSHF_rv, SHT_rv, DSHF_rv%elem_len)
        ! splicer end function.get_const_string_ptr_owns_alloc_pattern
    end function get_const_string_ptr_owns_alloc_pattern

    ! void acceptStringConstReference(const std::string & arg1 +intent(in))
    ! arg_to_buffer
    !>
    !! \brief Accept a const string reference
    !!
    !! Save contents of arg1.
    !! arg1 is assumed to be intent(IN) since it is const
    !! Will copy in.
    !<
    subroutine accept_string_const_reference(arg1)
        use iso_c_binding, only : C_INT
        character(len=*), intent(IN) :: arg1
        ! splicer begin function.accept_string_const_reference
        call c_accept_string_const_reference_bufferify(arg1, &
            len_trim(arg1, kind=C_INT))
        ! splicer end function.accept_string_const_reference
    end subroutine accept_string_const_reference

    ! void acceptStringReferenceOut(std::string & arg1 +intent(out))
    ! arg_to_buffer
    !>
    !! \brief Accept a string reference
    !!
    !! Set out to a constant string.
    !! arg1 is intent(OUT)
    !! Must copy out.
    !<
    subroutine accept_string_reference_out(arg1)
        use iso_c_binding, only : C_INT
        character(len=*), intent(OUT) :: arg1
        ! splicer begin function.accept_string_reference_out
        call c_accept_string_reference_out_bufferify(arg1, &
            len(arg1, kind=C_INT))
        ! splicer end function.accept_string_reference_out
    end subroutine accept_string_reference_out

    ! void acceptStringReference(std::string & arg1 +intent(inout))
    ! arg_to_buffer
    !>
    !! \brief Accept a string reference
    !!
    !! Append "dog" to the end of arg1.
    !! arg1 is assumed to be intent(INOUT)
    !! Must copy in and copy out.
    !<
    ! start accept_string_reference
    subroutine accept_string_reference(arg1)
        use iso_c_binding, only : C_INT
        character(len=*), intent(INOUT) :: arg1
        ! splicer begin function.accept_string_reference
        call c_accept_string_reference_bufferify(arg1, &
            len_trim(arg1, kind=C_INT), len(arg1, kind=C_INT))
        ! splicer end function.accept_string_reference
    end subroutine accept_string_reference
    ! end accept_string_reference

    ! void acceptStringPointer(std::string * arg1 +intent(inout))
    ! arg_to_buffer
    !>
    !! \brief Accept a string pointer
    !!
    !<
    subroutine accept_string_pointer(arg1)
        use iso_c_binding, only : C_INT
        character(len=*), intent(INOUT) :: arg1
        ! splicer begin function.accept_string_pointer
        call c_accept_string_pointer_bufferify(arg1, &
            len_trim(arg1, kind=C_INT), len(arg1, kind=C_INT))
        ! splicer end function.accept_string_pointer
    end subroutine accept_string_pointer

    ! void explicit1(char * name +intent(in)+len_trim(AAlen))
    subroutine explicit1(name)
        use iso_c_binding, only : C_NULL_CHAR
        character(len=*), intent(IN) :: name
        ! splicer begin function.explicit1
        call c_explicit1(trim(name)//C_NULL_CHAR)
        ! splicer end function.explicit1
    end subroutine explicit1

    ! void explicit2(char * name +intent(out)+len(AAtrim))
    ! arg_to_buffer
    subroutine explicit2(name)
        use iso_c_binding, only : C_INT
        character(len=*), intent(OUT) :: name
        ! splicer begin function.explicit2
        call c_explicit2_bufferify(name, len(name, kind=C_INT))
        ! splicer end function.explicit2
    end subroutine explicit2

    ! char CreturnChar()
    ! arg_to_buffer
    !>
    !! \brief return a char argument (non-pointer), extern "C"
    !!
    !<
    function creturn_char() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        character :: SHT_rv
        ! splicer begin function.creturn_char
        call c_creturn_char_bufferify(SHT_rv, len(SHT_rv, kind=C_INT))
        ! splicer end function.creturn_char
    end function creturn_char

    ! void CpassCharPtr(char * dest +intent(out), const char * src +intent(in))
    ! arg_to_buffer
    !>
    !! \brief strcpy like behavior
    !!
    !! dest is marked intent(OUT) to override the intent(INOUT) default
    !! This avoid a copy-in on dest.
    !! extern "C"
    !<
    subroutine cpass_char_ptr(dest, src)
        use iso_c_binding, only : C_INT, C_NULL_CHAR
        character(len=*), intent(OUT) :: dest
        character(len=*), intent(IN) :: src
        ! splicer begin function.cpass_char_ptr
        call c_cpass_char_ptr_bufferify(dest, len(dest, kind=C_INT), &
            trim(src)//C_NULL_CHAR)
        ! splicer end function.cpass_char_ptr
    end subroutine cpass_char_ptr

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module strings_mod
