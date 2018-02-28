! wrapfstrings.f
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
!! \file wrapfstrings.f
!! \brief Shroud generated wrapper for strings library
!<
! splicer begin file_top
! splicer end file_top
module strings_mod
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    interface

        subroutine pass_char(status) &
                bind(C, name="STR_pass_char")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), value, intent(IN) :: status
        end subroutine pass_char

        function c_return_char() &
                result(SHT_rv) &
                bind(C, name="STR_return_char")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR) :: SHT_rv
        end function c_return_char

        subroutine c_return_char_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_return_char_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_return_char_bufferify

        subroutine c_pass_char_ptr(dest, src) &
                bind(C, name="STR_pass_char_ptr")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: dest(*)
            character(kind=C_CHAR), intent(IN) :: src(*)
        end subroutine c_pass_char_ptr

        subroutine c_pass_char_ptr_bufferify(dest, Ndest, src, Lsrc) &
                bind(C, name="STR_pass_char_ptr_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: dest(*)
            integer(C_INT), value, intent(IN) :: Ndest
            character(kind=C_CHAR), intent(IN) :: src(*)
            integer(C_INT), value, intent(IN) :: Lsrc
        end subroutine c_pass_char_ptr_bufferify

        subroutine c_pass_char_ptr_in_out(s) &
                bind(C, name="STR_pass_char_ptr_in_out")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: s(*)
        end subroutine c_pass_char_ptr_in_out

        subroutine c_pass_char_ptr_in_out_bufferify(s, Ls, Ns) &
                bind(C, name="STR_pass_char_ptr_in_out_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: s(*)
            integer(C_INT), value, intent(IN) :: Ls
            integer(C_INT), value, intent(IN) :: Ns
        end subroutine c_pass_char_ptr_in_out_bufferify

        pure function c_get_char_ptr1() &
                result(SHT_rv) &
                bind(C, name="STR_get_char_ptr1")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_char_ptr1

        subroutine c_get_char_ptr1_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_char_ptr1_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_char_ptr1_bufferify

        function c_get_char_ptr2() &
                result(SHT_rv) &
                bind(C, name="STR_get_char_ptr2")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_char_ptr2

        subroutine c_get_char_ptr2_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_char_ptr2_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_char_ptr2_bufferify

        function c_get_char_ptr3() &
                result(SHT_rv) &
                bind(C, name="STR_get_char_ptr3")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_char_ptr3

        subroutine c_get_char_ptr3_bufferify(output, Noutput) &
                bind(C, name="STR_get_char_ptr3_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: output(*)
            integer(C_INT), value, intent(IN) :: Noutput
        end subroutine c_get_char_ptr3_bufferify

        pure function c_get_const_string_ref_pure() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_pure")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_pure

        subroutine c_get_const_string_ref_pure_bufferify(SHF_rv, &
                NSHF_rv) &
                bind(C, name="STR_get_const_string_ref_pure_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_const_string_ref_pure_bufferify

        function c_get_const_string_ref_len() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_len")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_len

        subroutine c_get_const_string_ref_len_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_const_string_ref_len_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_const_string_ref_len_bufferify

        function c_get_const_string_ref_as_arg() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_as_arg")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_as_arg

        subroutine c_get_const_string_ref_as_arg_bufferify(output, &
                Noutput) &
                bind(C, name="STR_get_const_string_ref_as_arg_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: output(*)
            integer(C_INT), value, intent(IN) :: Noutput
        end subroutine c_get_const_string_ref_as_arg_bufferify

        function c_get_const_string_ref_len_empty() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_len_empty")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_len_empty

        subroutine c_get_const_string_ref_len_empty_bufferify(SHF_rv, &
                NSHF_rv) &
                bind(C, name="STR_get_const_string_ref_len_empty_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_const_string_ref_len_empty_bufferify

        function c_get_const_string_ref_alloc() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ref_alloc")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ref_alloc

        subroutine c_get_const_string_ref_alloc_bufferify(SHF_rv, &
                NSHF_rv) &
                bind(C, name="STR_get_const_string_ref_alloc_bufferify")
            use iso_c_binding, only : C_PTR, C_SIZE_T
            implicit none
            type(C_PTR), intent(OUT) :: SHF_rv
            integer(C_SIZE_T), intent(OUT) :: NSHF_rv
        end subroutine c_get_const_string_ref_alloc_bufferify

        subroutine c_get_const_string_len_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_const_string_len_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_const_string_len_bufferify

        subroutine c_get_const_string_as_arg_bufferify(output, Noutput) &
                bind(C, name="STR_get_const_string_as_arg_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: output(*)
            integer(C_INT), value, intent(IN) :: Noutput
        end subroutine c_get_const_string_as_arg_bufferify

        subroutine c_get_const_string_alloc_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_const_string_alloc_bufferify")
            use iso_c_binding, only : C_PTR, C_SIZE_T
            implicit none
            type(C_PTR), intent(OUT) :: SHF_rv
            integer(C_SIZE_T), intent(OUT) :: NSHF_rv
        end subroutine c_get_const_string_alloc_bufferify

        function c_get_string7() &
                result(SHT_rv) &
                bind(C, name="STR_get_string7")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_string7

        subroutine c_get_string7_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_get_string7_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_get_string7_bufferify

        function c_get_const_string_ptr_alloc() &
                result(SHT_rv) &
                bind(C, name="STR_get_const_string_ptr_alloc")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_get_const_string_ptr_alloc

        subroutine c_get_const_string_ptr_alloc_bufferify(SHF_rv, &
                NSHF_rv) &
                bind(C, name="STR_get_const_string_ptr_alloc_bufferify")
            use iso_c_binding, only : C_PTR, C_SIZE_T
            implicit none
            type(C_PTR), intent(OUT) :: SHF_rv
            integer(C_SIZE_T), intent(OUT) :: NSHF_rv
        end subroutine c_get_const_string_ptr_alloc_bufferify

        subroutine c_accept_string_const_reference(arg1) &
                bind(C, name="STR_accept_string_const_reference")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
        end subroutine c_accept_string_const_reference

        subroutine c_accept_string_const_reference_bufferify(arg1, &
                Larg1) &
                bind(C, name="STR_accept_string_const_reference_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
        end subroutine c_accept_string_const_reference_bufferify

        subroutine c_accept_string_reference_out(arg1) &
                bind(C, name="STR_accept_string_reference_out")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: arg1(*)
        end subroutine c_accept_string_reference_out

        subroutine c_accept_string_reference_out_bufferify(arg1, Narg1) &
                bind(C, name="STR_accept_string_reference_out_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Narg1
        end subroutine c_accept_string_reference_out_bufferify

        subroutine c_accept_string_reference(arg1) &
                bind(C, name="STR_accept_string_reference")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: arg1(*)
        end subroutine c_accept_string_reference

        subroutine c_accept_string_reference_bufferify(arg1, Larg1, &
                Narg1) &
                bind(C, name="STR_accept_string_reference_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            integer(C_INT), value, intent(IN) :: Narg1
        end subroutine c_accept_string_reference_bufferify

        subroutine c_accept_string_pointer(arg1) &
                bind(C, name="STR_accept_string_pointer")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: arg1(*)
        end subroutine c_accept_string_pointer

        subroutine c_accept_string_pointer_bufferify(arg1, Larg1, Narg1) &
                bind(C, name="STR_accept_string_pointer_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            integer(C_INT), value, intent(IN) :: Narg1
        end subroutine c_accept_string_pointer_bufferify

        subroutine c_explicit1(name) &
                bind(C, name="STR_explicit1")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
        end subroutine c_explicit1

        subroutine c_explicit1_buffer(name, AAlen) &
                bind(C, name="STR_explicit1_BUFFER")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            integer(C_INT), value, intent(IN) :: AAlen
        end subroutine c_explicit1_buffer

        subroutine c_explicit2(name) &
                bind(C, name="STR_explicit2")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: name(*)
        end subroutine c_explicit2

        subroutine c_explicit2_bufferify(name, AAtrim) &
                bind(C, name="STR_explicit2_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: name(*)
            integer(C_INT), value, intent(IN) :: AAtrim
        end subroutine c_explicit2_bufferify

        subroutine cpass_char(status) &
                bind(C, name="CpassChar")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), value, intent(IN) :: status
        end subroutine cpass_char

        function c_creturn_char() &
                result(SHT_rv) &
                bind(C, name="CreturnChar")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR) :: SHT_rv
        end function c_creturn_char

        subroutine c_creturn_char_bufferify(SHF_rv, NSHF_rv) &
                bind(C, name="STR_creturn_char_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SHF_rv
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_creturn_char_bufferify

        subroutine c_cpass_char_ptr(dest, src) &
                bind(C, name="CpassCharPtr")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: dest(*)
            character(kind=C_CHAR), intent(IN) :: src(*)
        end subroutine c_cpass_char_ptr

        subroutine c_cpass_char_ptr_bufferify(dest, Ndest, src, Lsrc) &
                bind(C, name="STR_cpass_char_ptr_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: dest(*)
            integer(C_INT), value, intent(IN) :: Ndest
            character(kind=C_CHAR), intent(IN) :: src(*)
            integer(C_INT), value, intent(IN) :: Lsrc
        end subroutine c_cpass_char_ptr_bufferify

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    private fstr_ptr, strlen_ptr

    interface
       subroutine SHROUD_string_copy_and_free(cptr, str) &
         bind(c,name="ShroudStringCopyAndFree")
         use, intrinsic :: iso_c_binding, only : C_PTR, C_CHAR
         type(C_PTR), value, intent(in) :: cptr
         character(kind=C_CHAR) :: str(*)
       end subroutine SHROUD_string_copy_and_free
    end interface

    interface
       pure function strlen_ptr(s) result(result) bind(c,name="strlen")
         use, intrinsic :: iso_c_binding
         integer(c_int) :: result
         type(c_ptr), value, intent(in) :: s
       end function strlen_ptr
    end interface

contains

    ! char_scalar returnChar()
    ! arg_to_buffer
    ! function_index=1
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

    ! void passCharPtr(char * dest +intent(out), const char * src +intent(in))
    ! arg_to_buffer
    ! function_index=2
    !>
    !! \brief strcpy like behavior
    !!
    !! dest is marked intent(OUT) to override the intent(INOUT) default
    !! This avoid a copy-in on dest.
    !<
    subroutine pass_char_ptr(dest, src)
        use iso_c_binding, only : C_INT
        character(*), intent(OUT) :: dest
        character(*), intent(IN) :: src
        ! splicer begin function.pass_char_ptr
        call c_pass_char_ptr_bufferify(dest, len(dest, kind=C_INT), src, &
            len_trim(src, kind=C_INT))
        ! splicer end function.pass_char_ptr
    end subroutine pass_char_ptr

    ! void passCharPtrInOut(char * s +intent(inout))
    ! arg_to_buffer
    ! function_index=3
    !>
    !! \brief toupper
    !!
    !! Change a string in-place.
    !! For Python, return a new string since strings are immutable.
    !<
    subroutine pass_char_ptr_in_out(s)
        use iso_c_binding, only : C_INT
        character(*), intent(INOUT) :: s
        ! splicer begin function.pass_char_ptr_in_out
        call c_pass_char_ptr_in_out_bufferify(s, &
            len_trim(s, kind=C_INT), len(s, kind=C_INT))
        ! splicer end function.pass_char_ptr_in_out
    end subroutine pass_char_ptr_in_out

    ! const char * getCharPtr1() +pure
    ! function_index=4
    !>
    !! \brief return a 'const char *' as character(*)
    !!
    !<
    function get_char_ptr1() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR
        character(kind=C_CHAR, len=strlen_ptr(c_get_char_ptr1())) &
            :: SHT_rv
        ! splicer begin function.get_char_ptr1
        SHT_rv = fstr_ptr(c_get_char_ptr1())
        ! splicer end function.get_char_ptr1
    end function get_char_ptr1

    ! const char * getCharPtr2() +len(30)
    ! arg_to_buffer
    ! function_index=5
    !>
    !! \brief return 'const char *' with fixed size (len=30)
    !!
    !<
    function get_char_ptr2() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR, C_INT
        character(kind=C_CHAR, len=30) :: SHT_rv
        ! splicer begin function.get_char_ptr2
        call c_get_char_ptr2_bufferify(SHT_rv, len(SHT_rv, kind=C_INT))
        ! splicer end function.get_char_ptr2
    end function get_char_ptr2

    ! void getCharPtr3(char * output +intent(out)+len(Noutput))
    ! arg_to_buffer - arg_to_buffer
    ! function_index=34
    !>
    !! \brief return a 'const char *' as argument
    !!
    !<
    subroutine get_char_ptr3(output)
        use iso_c_binding, only : C_INT
        character(*), intent(OUT) :: output
        ! splicer begin function.get_char_ptr3
        call c_get_char_ptr3_bufferify(output, len(output, kind=C_INT))
        ! splicer end function.get_char_ptr3
    end subroutine get_char_ptr3

    ! const string & getConstStringRefPure() +pure
    ! function_index=7
    !>
    !! \brief return a 'const string&' as character(*)
    !!
    !<
    function get_const_string_ref_pure() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR
        character(kind=C_CHAR, len=strlen_ptr( &
            c_get_const_string_ref_pure())) :: SHT_rv
        ! splicer begin function.get_const_string_ref_pure
        SHT_rv = fstr_ptr(c_get_const_string_ref_pure())
        ! splicer end function.get_const_string_ref_pure
    end function get_const_string_ref_pure

    ! const string & getConstStringRefLen() +len(30)
    ! arg_to_buffer
    ! function_index=8
    !>
    !! \brief return 'const string&' with fixed size (len=30)
    !!
    !<
    function get_const_string_ref_len() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR, C_INT
        character(kind=C_CHAR, len=30) :: SHT_rv
        ! splicer begin function.get_const_string_ref_len
        call c_get_const_string_ref_len_bufferify(SHT_rv, &
            len(SHT_rv, kind=C_INT))
        ! splicer end function.get_const_string_ref_len
    end function get_const_string_ref_len

    ! void getConstStringRefAsArg(string & output +intent(out)+len(Noutput))
    ! arg_to_buffer - arg_to_buffer
    ! function_index=38
    !>
    !! \brief return a 'const string&' as argument
    !!
    !<
    subroutine get_const_string_ref_as_arg(output)
        use iso_c_binding, only : C_INT
        character(*), intent(OUT) :: output
        ! splicer begin function.get_const_string_ref_as_arg
        call c_get_const_string_ref_as_arg_bufferify(output, &
            len(output, kind=C_INT))
        ! splicer end function.get_const_string_ref_as_arg
    end subroutine get_const_string_ref_as_arg

    ! const string & getConstStringRefLenEmpty() +len(30)
    ! arg_to_buffer
    ! function_index=10
    !>
    !! \brief Test returning empty string reference
    !!
    !<
    function get_const_string_ref_len_empty() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR, C_INT
        character(kind=C_CHAR, len=30) :: SHT_rv
        ! splicer begin function.get_const_string_ref_len_empty
        call c_get_const_string_ref_len_empty_bufferify(SHT_rv, &
            len(SHT_rv, kind=C_INT))
        ! splicer end function.get_const_string_ref_len_empty
    end function get_const_string_ref_len_empty

    ! const std::string & getConstStringRefAlloc() +allocatable
    ! arg_to_buffer
    ! function_index=11
    function get_const_string_ref_alloc() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR, C_PTR, C_SIZE_T
        type(C_PTR) :: SHP_SHF_rv
        integer(C_SIZE_T) :: NSHF_rv
        character(len=:,kind=C_CHAR), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_ref_alloc
        call c_get_const_string_ref_alloc_bufferify(SHP_SHF_rv, NSHF_rv)
        ! splicer end function.get_const_string_ref_alloc
        allocate(character(len=NSHF_rv, kind=C_CHAR):: SHT_rv)
        call SHROUD_string_copy_and_free(SHP_SHF_rv, SHT_rv)
    end function get_const_string_ref_alloc

    ! const string getConstStringLen() +len(30)
    ! arg_to_buffer
    ! function_index=12
    !>
    !! \brief return a 'const string' as argument
    !!
    !<
    function get_const_string_len() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR, C_INT
        character(kind=C_CHAR, len=30) :: SHT_rv
        ! splicer begin function.get_const_string_len
        call c_get_const_string_len_bufferify(SHT_rv, &
            len(SHT_rv, kind=C_INT))
        ! splicer end function.get_const_string_len
    end function get_const_string_len

    ! void getConstStringAsArg(string * output +intent(out)+len(Noutput))
    ! arg_to_buffer - arg_to_buffer
    ! function_index=43
    !>
    !! \brief return a 'const string' as argument
    !!
    !<
    subroutine get_const_string_as_arg(output)
        use iso_c_binding, only : C_INT
        character(*), intent(OUT) :: output
        ! splicer begin function.get_const_string_as_arg
        call c_get_const_string_as_arg_bufferify(output, &
            len(output, kind=C_INT))
        ! splicer end function.get_const_string_as_arg
    end subroutine get_const_string_as_arg

    ! const std::string getConstStringAlloc() +allocatable
    ! arg_to_buffer
    ! function_index=14
    function get_const_string_alloc() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR, C_PTR, C_SIZE_T
        type(C_PTR) :: SHP_SHF_rv
        integer(C_SIZE_T) :: NSHF_rv
        character(len=:,kind=C_CHAR), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_alloc
        call c_get_const_string_alloc_bufferify(SHP_SHF_rv, NSHF_rv)
        ! splicer end function.get_const_string_alloc
        allocate(character(len=NSHF_rv, kind=C_CHAR):: SHT_rv)
        call SHROUD_string_copy_and_free(SHP_SHF_rv, SHT_rv)
    end function get_const_string_alloc

    ! const string * getString7() +len(30)
    ! arg_to_buffer
    ! function_index=15
    !>
    !! \brief return a 'const string *' as character(*)
    !!
    !<
    function get_string7() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR, C_INT
        character(kind=C_CHAR, len=30) :: SHT_rv
        ! splicer begin function.get_string7
        call c_get_string7_bufferify(SHT_rv, len(SHT_rv, kind=C_INT))
        ! splicer end function.get_string7
    end function get_string7

    ! const std::string * getConstStringPtrAlloc() +allocatable
    ! arg_to_buffer
    ! function_index=16
    function get_const_string_ptr_alloc() &
            result(SHT_rv)
        use iso_c_binding, only : C_CHAR, C_PTR, C_SIZE_T
        type(C_PTR) :: SHP_SHF_rv
        integer(C_SIZE_T) :: NSHF_rv
        character(len=:,kind=C_CHAR), allocatable :: SHT_rv
        ! splicer begin function.get_const_string_ptr_alloc
        call c_get_const_string_ptr_alloc_bufferify(SHP_SHF_rv, NSHF_rv)
        ! splicer end function.get_const_string_ptr_alloc
        allocate(character(len=NSHF_rv, kind=C_CHAR):: SHT_rv)
        call SHROUD_string_copy_and_free(SHP_SHF_rv, SHT_rv)
    end function get_const_string_ptr_alloc

    ! void acceptStringConstReference(const std::string & arg1 +intent(in))
    ! arg_to_buffer
    ! function_index=17
    !>
    !! \brief Accept a const string reference
    !!
    !! Save contents of arg1.
    !! arg1 is assumed to be intent(IN) since it is const
    !! Will copy in.
    !<
    subroutine accept_string_const_reference(arg1)
        use iso_c_binding, only : C_INT
        character(*), intent(IN) :: arg1
        ! splicer begin function.accept_string_const_reference
        call c_accept_string_const_reference_bufferify(arg1, &
            len_trim(arg1, kind=C_INT))
        ! splicer end function.accept_string_const_reference
    end subroutine accept_string_const_reference

    ! void acceptStringReferenceOut(std::string & arg1 +intent(out))
    ! arg_to_buffer
    ! function_index=18
    !>
    !! \brief Accept a string reference
    !!
    !! Set out to a constant string.
    !! arg1 is intent(OUT)
    !! Must copy out.
    !<
    subroutine accept_string_reference_out(arg1)
        use iso_c_binding, only : C_INT
        character(*), intent(OUT) :: arg1
        ! splicer begin function.accept_string_reference_out
        call c_accept_string_reference_out_bufferify(arg1, &
            len(arg1, kind=C_INT))
        ! splicer end function.accept_string_reference_out
    end subroutine accept_string_reference_out

    ! void acceptStringReference(std::string & arg1 +intent(inout))
    ! arg_to_buffer
    ! function_index=19
    !>
    !! \brief Accept a string reference
    !!
    !! Append "dog" to the end of arg1.
    !! arg1 is assumed to be intent(INOUT)
    !! Must copy in and copy out.
    !<
    subroutine accept_string_reference(arg1)
        use iso_c_binding, only : C_INT
        character(*), intent(INOUT) :: arg1
        ! splicer begin function.accept_string_reference
        call c_accept_string_reference_bufferify(arg1, &
            len_trim(arg1, kind=C_INT), len(arg1, kind=C_INT))
        ! splicer end function.accept_string_reference
    end subroutine accept_string_reference

    ! void acceptStringPointer(std::string * arg1 +intent(inout))
    ! arg_to_buffer
    ! function_index=20
    !>
    !! \brief Accept a string pointer
    !!
    !<
    subroutine accept_string_pointer(arg1)
        use iso_c_binding, only : C_INT
        character(*), intent(INOUT) :: arg1
        ! splicer begin function.accept_string_pointer
        call c_accept_string_pointer_bufferify(arg1, &
            len_trim(arg1, kind=C_INT), len(arg1, kind=C_INT))
        ! splicer end function.accept_string_pointer
    end subroutine accept_string_pointer

    ! void explicit1(char * name +intent(in)+len_trim(AAlen))
    ! arg_to_buffer
    ! function_index=23
    subroutine explicit1(name)
        use iso_c_binding, only : C_INT
        character(*), intent(IN) :: name
        ! splicer begin function.explicit1
        call c_explicit1_buffer(name, len_trim(name, kind=C_INT))
        ! splicer end function.explicit1
    end subroutine explicit1

    ! void explicit2(char * name +intent(out)+len(AAtrim))
    ! arg_to_buffer
    ! function_index=24
    subroutine explicit2(name)
        use iso_c_binding, only : C_INT
        character(*), intent(OUT) :: name
        ! splicer begin function.explicit2
        call c_explicit2_bufferify(name, len(name, kind=C_INT))
        ! splicer end function.explicit2
    end subroutine explicit2

    ! char_scalar CreturnChar()
    ! arg_to_buffer
    ! function_index=26
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
    ! function_index=27
    !>
    !! \brief strcpy like behavior
    !!
    !! dest is marked intent(OUT) to override the intent(INOUT) default
    !! This avoid a copy-in on dest.
    !! extern "C"
    !<
    subroutine cpass_char_ptr(dest, src)
        use iso_c_binding, only : C_INT
        character(*), intent(OUT) :: dest
        character(*), intent(IN) :: src
        ! splicer begin function.cpass_char_ptr
        call c_cpass_char_ptr_bufferify(dest, len(dest, kind=C_INT), &
            src, len_trim(src, kind=C_INT))
        ! splicer end function.cpass_char_ptr
    end subroutine cpass_char_ptr

    ! splicer begin additional_functions
    ! splicer end additional_functions

    ! Convert a null-terminated C "char *" pointer to a Fortran string.
    function fstr_ptr(s) result(fs)
      use, intrinsic :: iso_c_binding, only: c_char, c_ptr, c_f_pointer
      type(c_ptr), intent(in) :: s
      character(kind=c_char, len=strlen_ptr(s)) :: fs
      character(kind=c_char), pointer :: cptr(:)
      integer :: i
      call c_f_pointer(s, cptr, [len(fs)])
      do i=1, len(fs)
         fs(i:i) = cptr(i)
      enddo
    end function fstr_ptr

end module strings_mod
