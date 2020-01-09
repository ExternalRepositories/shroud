! wrapfstruct.f
! This is generated code, do not edit
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfstruct.f
!! \brief Shroud generated wrapper for struct library
!<
! splicer begin file_top
! splicer end file_top
module struct_mod
    use iso_c_binding, only : C_DOUBLE, C_INT
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    integer, parameter :: MAXNAME = 20
    ! splicer end module_top


    ! start derived-type cstruct1
    type, bind(C) :: cstruct1
        integer(C_INT) :: ifield
        real(C_DOUBLE) :: dfield
    end type cstruct1
    ! end derived-type cstruct1

    interface

        ! start pass_struct_by_value
        function pass_struct_by_value(arg) &
                result(SHT_rv) &
                bind(C, name="STR_pass_struct_by_value")
            use iso_c_binding, only : C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), value, intent(IN) :: arg
            integer(C_INT) :: SHT_rv
        end function pass_struct_by_value
        ! end pass_struct_by_value

        ! start pass_struct1
        function pass_struct1(arg) &
                result(SHT_rv) &
                bind(C, name="STR_pass_struct1")
            use iso_c_binding, only : C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: arg
            integer(C_INT) :: SHT_rv
        end function pass_struct1
        ! end pass_struct1

        function c_pass_struct2(s1, outbuf) &
                result(SHT_rv) &
                bind(C, name="STR_pass_struct2")
            use iso_c_binding, only : C_CHAR, C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: s1
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT) :: SHT_rv
        end function c_pass_struct2

        function c_pass_struct2_bufferify(s1, outbuf, Noutbuf) &
                result(SHT_rv) &
                bind(C, name="STR_pass_struct2_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: s1
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT), value, intent(IN) :: Noutbuf
            integer(C_INT) :: SHT_rv
        end function c_pass_struct2_bufferify

        function accept_struct_in_ptr(arg) &
                result(SHT_rv) &
                bind(C, name="STR_accept_struct_in_ptr")
            use iso_c_binding, only : C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: arg
            integer(C_INT) :: SHT_rv
        end function accept_struct_in_ptr

        subroutine accept_struct_out_ptr(arg, i, d) &
                bind(C, name="STR_accept_struct_out_ptr")
            use iso_c_binding, only : C_DOUBLE, C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(OUT) :: arg
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
        end subroutine accept_struct_out_ptr

        subroutine accept_struct_in_out_ptr(arg) &
                bind(C, name="STR_accept_struct_in_out_ptr")
            import :: cstruct1
            implicit none
            type(cstruct1), intent(INOUT) :: arg
        end subroutine accept_struct_in_out_ptr

        function return_struct_by_value(i, d) &
                result(SHT_rv) &
                bind(C, name="STR_return_struct_by_value")
            use iso_c_binding, only : C_DOUBLE, C_INT
            import :: cstruct1
            implicit none
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
            type(cstruct1) :: SHT_rv
        end function return_struct_by_value

        function return_const_struct_by_value(i, d) &
                result(SHT_rv) &
                bind(C, name="STR_return_const_struct_by_value")
            use iso_c_binding, only : C_DOUBLE, C_INT
            import :: cstruct1
            implicit none
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
            type(cstruct1) :: SHT_rv
        end function return_const_struct_by_value

        function c_return_struct_ptr1(i, d) &
                result(SHT_rv) &
                bind(C, name="STR_return_struct_ptr1")
            use iso_c_binding, only : C_DOUBLE, C_INT, C_PTR
            implicit none
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
            type(C_PTR) SHT_rv
        end function c_return_struct_ptr1

        function c_return_struct_ptr2(i, d, outbuf) &
                result(SHT_rv) &
                bind(C, name="STR_return_struct_ptr2")
            use iso_c_binding, only : C_CHAR, C_DOUBLE, C_INT, C_PTR
            implicit none
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            type(C_PTR) SHT_rv
        end function c_return_struct_ptr2

        function c_return_struct_ptr2_bufferify(i, d, outbuf, Noutbuf) &
                result(SHT_rv) &
                bind(C, name="STR_return_struct_ptr2_bufferify")
            use iso_c_binding, only : C_CHAR, C_DOUBLE, C_INT, C_PTR
            implicit none
            integer(C_INT), value, intent(IN) :: i
            real(C_DOUBLE), value, intent(IN) :: d
            character(kind=C_CHAR), intent(OUT) :: outbuf(*)
            integer(C_INT), value, intent(IN) :: Noutbuf
            type(C_PTR) SHT_rv
        end function c_return_struct_ptr2_bufferify

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

contains

    ! int passStruct2(Cstruct1 * s1 +intent(in), char * outbuf +charlen(LENOUTBUF)+intent(out))
    ! arg_to_buffer
    !>
    !! Pass name argument which will build a bufferify function.
    !<
    function pass_struct2(s1, outbuf) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        type(cstruct1), intent(IN) :: s1
        character(len=*), intent(OUT) :: outbuf
        integer(C_INT) :: SHT_rv
        ! splicer begin function.pass_struct2
        SHT_rv = c_pass_struct2_bufferify(s1, outbuf, &
            len(outbuf, kind=C_INT))
        ! splicer end function.pass_struct2
    end function pass_struct2

    ! Cstruct1 * returnStructPtr1(int i +intent(in)+value, double d +intent(in)+value)
    !>
    !! \brief Return a pointer to a struct
    !!
    !! Does not generate a bufferify C wrapper.
    !<
    function return_struct_ptr1(i, d) &
            result(SHT_rv)
        use iso_c_binding, only : C_DOUBLE, C_INT, C_PTR, c_f_pointer
        integer(C_INT), value, intent(IN) :: i
        real(C_DOUBLE), value, intent(IN) :: d
        type(cstruct1), pointer :: SHT_rv
        ! splicer begin function.return_struct_ptr1
        type(C_PTR) :: SHT_ptr
        SHT_ptr = c_return_struct_ptr1(i, d)
        call c_f_pointer(SHT_ptr, SHT_rv)
        ! splicer end function.return_struct_ptr1
    end function return_struct_ptr1

    ! Cstruct1 * returnStructPtr2(int i +intent(in)+value, double d +intent(in)+value, char * outbuf +charlen(LENOUTBUF)+intent(out))
    ! arg_to_buffer
    !>
    !! \brief Return a pointer to a struct
    !!
    !! Generates a bufferify C wrapper function.
    !<
    function return_struct_ptr2(i, d, outbuf) &
            result(SHT_rv)
        use iso_c_binding, only : C_DOUBLE, C_INT, C_PTR, c_f_pointer
        integer(C_INT), value, intent(IN) :: i
        real(C_DOUBLE), value, intent(IN) :: d
        character(len=*), intent(OUT) :: outbuf
        type(cstruct1), pointer :: SHT_rv
        ! splicer begin function.return_struct_ptr2
        type(C_PTR) :: SHT_ptr
        SHT_ptr = c_return_struct_ptr2_bufferify(i, d, outbuf, &
            len(outbuf, kind=C_INT))
        call c_f_pointer(SHT_ptr, SHT_rv)
        ! splicer end function.return_struct_ptr2
    end function return_struct_ptr2

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module struct_mod
