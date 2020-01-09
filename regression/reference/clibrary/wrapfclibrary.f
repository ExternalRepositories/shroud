! wrapfclibrary.f
! This is generated code, do not edit
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfclibrary.f
!! \brief Shroud generated wrapper for Clibrary library
!<
! splicer begin file_top
! splicer end file_top
module clibrary_mod
    use iso_c_binding, only : C_INT
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    integer, parameter :: MAXNAME = 20
    ! splicer end module_top


    type, bind(C) :: array_info
        integer(C_INT) :: tc
    end type array_info

    ! start abstract callback1_incr
    abstract interface
        subroutine callback1_incr() bind(C)
            implicit none
        end subroutine callback1_incr
    end interface
    ! end abstract callback1_incr

    abstract interface
        subroutine callback2_incr(arg0) bind(C)
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT) :: arg0
        end subroutine callback2_incr
    end interface

    abstract interface
        subroutine callback3_incr(arg0) bind(C)
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT) :: arg0
        end subroutine callback3_incr
    end interface

    abstract interface
        subroutine callback_set_alloc_alloc(tc, arr) bind(C)
            use iso_c_binding, only : C_INT
            import :: array_info
            implicit none
            integer(C_INT), value, intent(IN) :: tc
            type(array_info), intent(INOUT) :: arr
        end subroutine callback_set_alloc_alloc
    end interface

    ! start no_return_no_arguments
    interface
        subroutine no_return_no_arguments() &
                bind(C, name="NoReturnNoArguments")
            implicit none
        end subroutine no_return_no_arguments
    end interface
    ! end no_return_no_arguments

    ! start pass_by_value
    interface
        function pass_by_value(arg1, arg2) &
                result(SHT_rv) &
                bind(C, name="PassByValue")
            use iso_c_binding, only : C_DOUBLE, C_INT
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            integer(C_INT), value, intent(IN) :: arg2
            real(C_DOUBLE) :: SHT_rv
        end function pass_by_value
    end interface
    ! end pass_by_value

    ! start pass_by_reference
    interface
        subroutine pass_by_reference(arg1, arg2) &
                bind(C, name="PassByReference")
            use iso_c_binding, only : C_DOUBLE, C_INT
            implicit none
            real(C_DOUBLE), intent(IN) :: arg1
            integer(C_INT), intent(OUT) :: arg2
        end subroutine pass_by_reference
    end interface
    ! end pass_by_reference

    ! start c_check_bool
    interface
        subroutine c_check_bool(arg1, arg2, arg3) &
                bind(C, name="checkBool")
            use iso_c_binding, only : C_BOOL
            implicit none
            logical(C_BOOL), value, intent(IN) :: arg1
            logical(C_BOOL), intent(OUT) :: arg2
            logical(C_BOOL), intent(INOUT) :: arg3
        end subroutine c_check_bool
    end interface
    ! end c_check_bool

    interface
        function c_function4a(arg1, arg2) &
                result(SHT_rv) &
                bind(C, name="Function4a")
            use iso_c_binding, only : C_CHAR, C_PTR
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            type(C_PTR) SHT_rv
        end function c_function4a
    end interface

    interface
        subroutine c_function4a_bufferify(arg1, arg2, SHF_rv, NSHF_rv) &
                bind(C, name="CLI_function4a_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            character(kind=C_CHAR), intent(OUT) :: SHF_rv(*)
            integer(C_INT), value, intent(IN) :: NSHF_rv
        end subroutine c_function4a_bufferify
    end interface

    ! start c_accept_name
    interface
        subroutine c_accept_name(name) &
                bind(C, name="acceptName")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
        end subroutine c_accept_name
    end interface
    ! end c_accept_name

    interface
        subroutine c_pass_char_ptr_in_out(s) &
                bind(C, name="passCharPtrInOut")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: s(*)
        end subroutine c_pass_char_ptr_in_out
    end interface

    interface
        subroutine c_pass_char_ptr_in_out_bufferify(s, Ls, Ns) &
                bind(C, name="CLI_pass_char_ptr_in_out_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: s(*)
            integer(C_INT), value, intent(IN) :: Ls
            integer(C_INT), value, intent(IN) :: Ns
        end subroutine c_pass_char_ptr_in_out_bufferify
    end interface

    ! start c_return_one_name
    interface
        subroutine c_return_one_name(name1) &
                bind(C, name="returnOneName")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: name1(*)
        end subroutine c_return_one_name
    end interface
    ! end c_return_one_name

    ! start c_return_one_name_bufferify
    interface
        subroutine c_return_one_name_bufferify(name1, Nname1) &
                bind(C, name="CLI_return_one_name_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: name1(*)
            integer(C_INT), value, intent(IN) :: Nname1
        end subroutine c_return_one_name_bufferify
    end interface
    ! end c_return_one_name_bufferify

    interface
        subroutine c_return_two_names(name1, name2) &
                bind(C, name="returnTwoNames")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: name1(*)
            character(kind=C_CHAR), intent(OUT) :: name2(*)
        end subroutine c_return_two_names
    end interface

    interface
        subroutine c_return_two_names_bufferify(name1, Nname1, name2, &
                Nname2) &
                bind(C, name="CLI_return_two_names_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: name1(*)
            integer(C_INT), value, intent(IN) :: Nname1
            character(kind=C_CHAR), intent(OUT) :: name2(*)
            integer(C_INT), value, intent(IN) :: Nname2
        end subroutine c_return_two_names_bufferify
    end interface

    ! start c_implied_text_len
    interface
        subroutine c_implied_text_len(text, ltext) &
                bind(C, name="ImpliedTextLen")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: text(*)
            integer(C_INT), value, intent(IN) :: ltext
        end subroutine c_implied_text_len
    end interface
    ! end c_implied_text_len

    ! start c_implied_text_len_bufferify
    interface
        subroutine c_implied_text_len_bufferify(text, Ntext, ltext) &
                bind(C, name="CLI_implied_text_len_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: text(*)
            integer(C_INT), value, intent(IN) :: Ntext
            integer(C_INT), value, intent(IN) :: ltext
        end subroutine c_implied_text_len_bufferify
    end interface
    ! end c_implied_text_len_bufferify

    interface
        function c_implied_len(text, ltext, flag) &
                result(SHT_rv) &
                bind(C, name="ImpliedLen")
            use iso_c_binding, only : C_BOOL, C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: text(*)
            integer(C_INT), value, intent(IN) :: ltext
            logical(C_BOOL), value, intent(IN) :: flag
            integer(C_INT) :: SHT_rv
        end function c_implied_len
    end interface

    interface
        function c_implied_len_trim(text, ltext, flag) &
                result(SHT_rv) &
                bind(C, name="ImpliedLenTrim")
            use iso_c_binding, only : C_BOOL, C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: text(*)
            integer(C_INT), value, intent(IN) :: ltext
            logical(C_BOOL), value, intent(IN) :: flag
            integer(C_INT) :: SHT_rv
        end function c_implied_len_trim
    end interface

    interface
        function c_implied_bool_true(flag) &
                result(SHT_rv) &
                bind(C, name="ImpliedBoolTrue")
            use iso_c_binding, only : C_BOOL
            implicit none
            logical(C_BOOL), value, intent(IN) :: flag
            logical(C_BOOL) :: SHT_rv
        end function c_implied_bool_true
    end interface

    interface
        function c_implied_bool_false(flag) &
                result(SHT_rv) &
                bind(C, name="ImpliedBoolFalse")
            use iso_c_binding, only : C_BOOL
            implicit none
            logical(C_BOOL), value, intent(IN) :: flag
            logical(C_BOOL) :: SHT_rv
        end function c_implied_bool_false
    end interface

    interface
        subroutine Fortran_bindC1a() &
                bind(C, name="bindC1")
            implicit none
        end subroutine Fortran_bindC1a
    end interface

    interface
        subroutine c_bind_c2(outbuf) &
                bind(C, name="bindC2")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
        end subroutine c_bind_c2
    end interface

    interface
        subroutine c_bind_c2_bufferify(outbuf, Noutbuf) &
                bind(C, name="CLI_bind_c2_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT), value, intent(IN) :: Noutbuf
        end subroutine c_bind_c2_bufferify
    end interface

    ! start pass_void_star_star
    interface
        subroutine pass_void_star_star(in, out) &
                bind(C, name="passVoidStarStar")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR), value, intent(IN) :: in
            type(C_PTR), intent(OUT) :: out
        end subroutine pass_void_star_star
    end interface
    ! end pass_void_star_star

    ! start pass_assumed_type
    interface
        function pass_assumed_type(arg) &
                result(SHT_rv) &
                bind(C, name="passAssumedType")
            use iso_c_binding, only : C_INT
            implicit none
            type(*) :: arg
            integer(C_INT) :: SHT_rv
        end function pass_assumed_type
    end interface
    ! end pass_assumed_type

    ! start pass_assumed_type_dim
    interface
        subroutine pass_assumed_type_dim(arg) &
                bind(C, name="passAssumedTypeDim")
            implicit none
            type(*) :: arg(*)
        end subroutine pass_assumed_type_dim
    end interface
    ! end pass_assumed_type_dim

    interface
        function c_pass_assumed_type_buf(arg, outbuf) &
                result(SHT_rv) &
                bind(C, name="passAssumedTypeBuf")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            type(*) :: arg
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT) :: SHT_rv
        end function c_pass_assumed_type_buf
    end interface

    interface
        function c_pass_assumed_type_buf_bufferify(arg, outbuf, Noutbuf) &
                result(SHT_rv) &
                bind(C, name="CLI_pass_assumed_type_buf_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            type(*) :: arg
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT), value, intent(IN) :: Noutbuf
            integer(C_INT) :: SHT_rv
        end function c_pass_assumed_type_buf_bufferify
    end interface

    ! start c_callback1
    interface
        function c_callback1(type, incr) &
                result(SHT_rv) &
                bind(C, name="callback1")
            use iso_c_binding, only : C_INT
            import :: callback1_incr
            implicit none
            integer(C_INT), value, intent(IN) :: type
            procedure(callback1_incr) :: incr
            integer(C_INT) :: SHT_rv
        end function c_callback1
    end interface
    ! end c_callback1

    interface
        subroutine c_callback2(type, in, incr) &
                bind(C, name="callback2")
            use iso_c_binding, only : C_INT
            import :: callback2_incr
            implicit none
            integer(C_INT), value, intent(IN) :: type
            type(*) :: in
            procedure(callback2_incr) :: incr
        end subroutine c_callback2
    end interface

    interface
        subroutine c_callback3(type, in, incr, outbuf) &
                bind(C, name="callback3")
            use iso_c_binding, only : C_CHAR
            import :: callback3_incr
            implicit none
            character(kind=C_CHAR), intent(IN) :: type(*)
            type(*) :: in
            procedure(callback3_incr) :: incr
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
        end subroutine c_callback3
    end interface

    interface
        subroutine c_callback3_bufferify(type, in, incr, outbuf, &
                Noutbuf) &
                bind(C, name="CLI_callback3_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            import :: callback3_incr
            implicit none
            character(kind=C_CHAR), intent(IN) :: type(*)
            type(*) :: in
            procedure(callback3_incr) :: incr
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT), value, intent(IN) :: Noutbuf
        end subroutine c_callback3_bufferify
    end interface

    interface
        subroutine callback_set_alloc(tc, arr, alloc) &
                bind(C, name="callback_set_alloc")
            use iso_c_binding, only : C_INT
            import :: array_info, callback_set_alloc_alloc
            implicit none
            integer(C_INT), value, intent(IN) :: tc
            type(array_info), intent(INOUT) :: arr
            procedure(callback_set_alloc_alloc) :: alloc
        end subroutine callback_set_alloc
    end interface

    interface
        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

contains

    ! void checkBool(const bool arg1 +intent(in)+value, bool * arg2 +intent(out), bool * arg3 +intent(inout))
    !>
    !! \brief Check intent with bool
    !!
    !<
    ! start check_bool
    subroutine check_bool(arg1, arg2, arg3)
        use iso_c_binding, only : C_BOOL
        logical, value, intent(IN) :: arg1
        logical, intent(OUT) :: arg2
        logical, intent(INOUT) :: arg3
        ! splicer begin function.check_bool
        logical(C_BOOL) SH_arg1
        logical(C_BOOL) SH_arg2
        logical(C_BOOL) SH_arg3
        SH_arg1 = arg1  ! coerce to C_BOOL
        SH_arg3 = arg3  ! coerce to C_BOOL
        call c_check_bool(SH_arg1, SH_arg2, SH_arg3)
        arg2 = SH_arg2  ! coerce to logical
        arg3 = SH_arg3  ! coerce to logical
        ! splicer end function.check_bool
    end subroutine check_bool
    ! end check_bool

    ! char * Function4a(const char * arg1 +intent(in), const char * arg2 +intent(in)) +deref(result_as_arg)+len(30)
    ! arg_to_buffer
    function function4a(arg1, arg2) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, C_NULL_CHAR
        character(len=*), intent(IN) :: arg1
        character(len=*), intent(IN) :: arg2
        character(len=30) :: SHT_rv
        ! splicer begin function.function4a
        call c_function4a_bufferify(trim(arg1)//C_NULL_CHAR, &
            trim(arg2)//C_NULL_CHAR, SHT_rv, len(SHT_rv, kind=C_INT))
        ! splicer end function.function4a
    end function function4a

    ! void acceptName(const char * name +intent(in))
    ! start accept_name
    subroutine accept_name(name)
        use iso_c_binding, only : C_NULL_CHAR
        character(len=*), intent(IN) :: name
        ! splicer begin function.accept_name
        call c_accept_name(trim(name)//C_NULL_CHAR)
        ! splicer end function.accept_name
    end subroutine accept_name
    ! end accept_name

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

    ! void returnOneName(char * name1 +charlen(MAXNAME)+intent(out))
    ! arg_to_buffer
    !>
    !! \brief Test charlen attribute
    !!
    !! Each argument is assumed to be at least MAXNAME long.
    !! This define is provided by the user.
    !! The function will copy into the user provided buffer.
    !<
    ! start return_one_name
    subroutine return_one_name(name1)
        use iso_c_binding, only : C_INT
        character(len=*), intent(OUT) :: name1
        ! splicer begin function.return_one_name
        call c_return_one_name_bufferify(name1, len(name1, kind=C_INT))
        ! splicer end function.return_one_name
    end subroutine return_one_name
    ! end return_one_name

    ! void returnTwoNames(char * name1 +charlen(MAXNAME)+intent(out), char * name2 +charlen(MAXNAME)+intent(out))
    ! arg_to_buffer
    !>
    !! \brief Test charlen attribute
    !!
    !! Each argument is assumed to be at least MAXNAME long.
    !! This define is provided by the user.
    !! The function will copy into the user provided buffer.
    !<
    subroutine return_two_names(name1, name2)
        use iso_c_binding, only : C_INT
        character(len=*), intent(OUT) :: name1
        character(len=*), intent(OUT) :: name2
        ! splicer begin function.return_two_names
        call c_return_two_names_bufferify(name1, len(name1, kind=C_INT), &
            name2, len(name2, kind=C_INT))
        ! splicer end function.return_two_names
    end subroutine return_two_names

    ! void ImpliedTextLen(char * text +charlen(MAXNAME)+intent(out), int ltext +implied(len(text))+intent(in)+value)
    ! arg_to_buffer
    !>
    !! \brief Fill text, at most ltext characters.
    !!
    !<
    ! start implied_text_len
    subroutine implied_text_len(text)
        use iso_c_binding, only : C_INT
        character(len=*), intent(OUT) :: text
        integer(C_INT) :: SH_ltext
        ! splicer begin function.implied_text_len
        SH_ltext = len(text,kind=C_INT)
        call c_implied_text_len_bufferify(text, len(text, kind=C_INT), &
            SH_ltext)
        ! splicer end function.implied_text_len
    end subroutine implied_text_len
    ! end implied_text_len

    ! int ImpliedLen(const char * text +intent(in), int ltext +implied(len(text))+intent(in)+value, bool flag +implied(false)+intent(in)+value)
    !>
    !! \brief Return the implied argument - text length
    !!
    !! Pass the Fortran length of the char argument directy to the C function.
    !! No need for the bufferify version which will needlessly copy the string.
    !<
    function implied_len(text) &
            result(SHT_rv)
        use iso_c_binding, only : C_BOOL, C_INT, C_NULL_CHAR
        character(len=*), intent(IN) :: text
        integer(C_INT) :: SH_ltext
        logical(C_BOOL) :: SH_flag
        integer(C_INT) :: SHT_rv
        ! splicer begin function.implied_len
        SH_ltext = len(text,kind=C_INT)
        SH_flag = .FALSE._C_BOOL
        SHT_rv = c_implied_len(trim(text)//C_NULL_CHAR, SH_ltext, &
            SH_flag)
        ! splicer end function.implied_len
    end function implied_len

    ! int ImpliedLenTrim(const char * text +intent(in), int ltext +implied(len_trim(text))+intent(in)+value, bool flag +implied(true)+intent(in)+value)
    !>
    !! \brief Return the implied argument - text length
    !!
    !! Pass the Fortran length of the char argument directy to the C function.
    !! No need for the bufferify version which will needlessly copy the string.
    !<
    function implied_len_trim(text) &
            result(SHT_rv)
        use iso_c_binding, only : C_BOOL, C_INT, C_NULL_CHAR
        character(len=*), intent(IN) :: text
        integer(C_INT) :: SH_ltext
        logical(C_BOOL) :: SH_flag
        integer(C_INT) :: SHT_rv
        ! splicer begin function.implied_len_trim
        SH_ltext = len_trim(text,kind=C_INT)
        SH_flag = .TRUE._C_BOOL
        SHT_rv = c_implied_len_trim(trim(text)//C_NULL_CHAR, SH_ltext, &
            SH_flag)
        ! splicer end function.implied_len_trim
    end function implied_len_trim

    ! bool ImpliedBoolTrue(bool flag +implied(true)+intent(in)+value)
    !>
    !! \brief Single, implied bool argument
    !!
    !<
    function implied_bool_true() &
            result(SHT_rv)
        use iso_c_binding, only : C_BOOL
        logical(C_BOOL) :: SH_flag
        logical :: SHT_rv
        ! splicer begin function.implied_bool_true
        SH_flag = .TRUE._C_BOOL
        SHT_rv = c_implied_bool_true(SH_flag)
        ! splicer end function.implied_bool_true
    end function implied_bool_true

    ! bool ImpliedBoolFalse(bool flag +implied(false)+intent(in)+value)
    !>
    !! \brief Single, implied bool argument
    !!
    !<
    function implied_bool_false() &
            result(SHT_rv)
        use iso_c_binding, only : C_BOOL
        logical(C_BOOL) :: SH_flag
        logical :: SHT_rv
        ! splicer begin function.implied_bool_false
        SH_flag = .FALSE._C_BOOL
        SHT_rv = c_implied_bool_false(SH_flag)
        ! splicer end function.implied_bool_false
    end function implied_bool_false

    ! void bindC2(char * outbuf +intent(out))
    ! arg_to_buffer
    !>
    !! \brief Rename Fortran name for interface only function
    !!
    !! This creates a Fortran bufferify function and an interface.
    !<
    subroutine Fortran_bindC2a(outbuf)
        use iso_c_binding, only : C_INT
        character(len=*), intent(OUT) :: outbuf
        ! splicer begin function.bind_c2
        call c_bind_c2_bufferify(outbuf, len(outbuf, kind=C_INT))
        ! splicer end function.bind_c2
    end subroutine Fortran_bindC2a

    ! int passAssumedTypeBuf(void * arg +assumedtype+intent(in), char * outbuf +intent(out))
    ! arg_to_buffer
    !>
    !! \brief Test assumed-type
    !!
    !! A bufferify function is created.
    !! Should only be call with an C_INT argument, and will
    !! return the value passed in.
    !<
    function pass_assumed_type_buf(arg, outbuf) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        type(*) :: arg
        character(len=*), intent(OUT) :: outbuf
        integer(C_INT) :: SHT_rv
        ! splicer begin function.pass_assumed_type_buf
        SHT_rv = c_pass_assumed_type_buf_bufferify(arg, outbuf, &
            len(outbuf, kind=C_INT))
        ! splicer end function.pass_assumed_type_buf
    end function pass_assumed_type_buf

    ! int callback1(int type +intent(in)+value, void ( * incr)() +external+intent(in)+value)
    !>
    !! \brief Test function pointer
    !!
    !<
    ! start callback1
    function callback1(type, incr) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT), value, intent(IN) :: type
        external :: incr
        integer(C_INT) :: SHT_rv
        ! splicer begin function.callback1
        SHT_rv = c_callback1(type, incr)
        ! splicer end function.callback1
    end function callback1
    ! end callback1

    ! void callback2(int type +intent(in)+value, void * in +assumedtype+intent(in), void ( * incr)(int *) +external+intent(in)+value)
    !>
    !! \brief Test function pointer
    !!
    !<
    subroutine callback2(type, in, incr)
        use iso_c_binding, only : C_INT
        integer(C_INT), value, intent(IN) :: type
        type(*) :: in
        external :: incr
        ! splicer begin function.callback2
        call c_callback2(type, in, incr)
        ! splicer end function.callback2
    end subroutine callback2

    ! void callback3(const char * type +intent(in), void * in +assumedtype+intent(in), void ( * incr)(int *) +external+intent(in)+value, char * outbuf +intent(out))
    ! arg_to_buffer
    !>
    !! \brief Test function pointer
    !!
    !! A bufferify function will be created.
    !<
    subroutine callback3(type, in, incr, outbuf)
        use iso_c_binding, only : C_INT, C_NULL_CHAR
        character(len=*), intent(IN) :: type
        type(*) :: in
        external :: incr
        character(len=*), intent(OUT) :: outbuf
        ! splicer begin function.callback3
        call c_callback3_bufferify(trim(type)//C_NULL_CHAR, in, incr, &
            outbuf, len(outbuf, kind=C_INT))
        ! splicer end function.callback3
    end subroutine callback3

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module clibrary_mod
