! wrapftutorial.f
! This is generated code, do not edit
! #######################################################################
! Copyright (c) 2017, Lawrence Livermore National Security, LLC.
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
!! \file wrapftutorial.f
!! \brief Shroud generated wrapper for Tutorial library
!<
! splicer begin file_top
! splicer end file_top
module tutorial_mod
    use, intrinsic :: iso_c_binding, only : C_PTR
    ! splicer begin module_use
    ! splicer end module_use
    ! splicer begin class.Class1.module_use
    ! splicer end class.Class1.module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    ! splicer begin class.Class1.module_top
    ! splicer end class.Class1.module_top

    type class1
        type(C_PTR), private :: voidptr
        ! splicer begin class.Class1.component_part
        ! splicer end class.Class1.component_part
    contains
        procedure :: delete => class1_delete
        procedure :: method1 => class1_method1
        procedure :: get_instance => class1_get_instance
        procedure :: set_instance => class1_set_instance
        procedure :: associated => class1_associated
        ! splicer begin class.Class1.type_bound_procedure_part
        ! splicer end class.Class1.type_bound_procedure_part
    end type class1


    interface operator (.eq.)
        module procedure class1_eq
    end interface

    interface operator (.ne.)
        module procedure class1_ne
    end interface

    interface

        function c_class1_new() &
                result(SH_rv) &
                bind(C, name="TUT_class1_new")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) :: SH_rv
        end function c_class1_new

        subroutine c_class1_delete(self) &
                bind(C, name="TUT_class1_delete")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR), value, intent(IN) :: self
        end subroutine c_class1_delete

        subroutine c_class1_method1(self) &
                bind(C, name="TUT_class1_method1")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR), value, intent(IN) :: self
        end subroutine c_class1_method1

        ! splicer begin class.Class1.additional_interfaces
        ! splicer end class.Class1.additional_interfaces

        subroutine function1() &
                bind(C, name="TUT_function1")
            implicit none
        end subroutine function1

        function function2(arg1, arg2) &
                result(SH_rv) &
                bind(C, name="TUT_function2")
            use iso_c_binding, only : C_DOUBLE, C_INT
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            integer(C_INT), value, intent(IN) :: arg2
            real(C_DOUBLE) :: SH_rv
        end function function2

        subroutine sum(len, values, result) &
                bind(C, name="TUT_sum")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: len
            integer(C_INT), intent(IN) :: values(len)
            integer(C_INT), intent(OUT) :: result
        end subroutine sum

        function c_function3(arg) &
                result(SH_rv) &
                bind(C, name="TUT_function3")
            use iso_c_binding, only : C_BOOL
            implicit none
            logical(C_BOOL), value, intent(IN) :: arg
            logical(C_BOOL) :: SH_rv
        end function c_function3

        subroutine c_function3b(arg1, arg2, arg3) &
                bind(C, name="TUT_function3b")
            use iso_c_binding, only : C_BOOL
            implicit none
            logical(C_BOOL), value, intent(IN) :: arg1
            logical(C_BOOL), intent(OUT) :: arg2
            logical(C_BOOL), intent(INOUT) :: arg3
        end subroutine c_function3b

        subroutine c_function4a_bufferify(arg1, Larg1, arg2, Larg2, SH_F_rv, NSH_F_rv) &
                bind(C, name="TUT_function4a_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            integer(C_INT), value, intent(IN) :: Larg2
            character(kind=C_CHAR), intent(OUT) :: SH_F_rv(*)
            integer(C_INT), value, intent(IN) :: NSH_F_rv
        end subroutine c_function4a_bufferify

        function c_function4b(arg1, arg2) &
                result(SH_rv) &
                bind(C, name="TUT_function4b")
            use iso_c_binding, only : C_CHAR, C_PTR
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            type(C_PTR) SH_rv
        end function c_function4b

        subroutine c_function4b_bufferify(arg1, Larg1, arg2, Larg2, output, Noutput) &
                bind(C, name="TUT_function4b_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            integer(C_INT), value, intent(IN) :: Larg2
            character(kind=C_CHAR), intent(OUT) :: output(*)
            integer(C_INT), value, intent(IN) :: Noutput
        end subroutine c_function4b_bufferify

        function c_function5() &
                result(SH_rv) &
                bind(C, name="TUT_function5")
            use iso_c_binding, only : C_DOUBLE
            implicit none
            real(C_DOUBLE) :: SH_rv
        end function c_function5

        function c_function5_arg1(arg1) &
                result(SH_rv) &
                bind(C, name="TUT_function5_arg1")
            use iso_c_binding, only : C_DOUBLE
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            real(C_DOUBLE) :: SH_rv
        end function c_function5_arg1

        function c_function5_arg1_arg2(arg1, arg2) &
                result(SH_rv) &
                bind(C, name="TUT_function5_arg1_arg2")
            use iso_c_binding, only : C_BOOL, C_DOUBLE
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            logical(C_BOOL), value, intent(IN) :: arg2
            real(C_DOUBLE) :: SH_rv
        end function c_function5_arg1_arg2

        subroutine c_function6_from_name(name) &
                bind(C, name="TUT_function6_from_name")
            use iso_c_binding, only : C_CHAR
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
        end subroutine c_function6_from_name

        subroutine c_function6_from_name_bufferify(name, Lname) &
                bind(C, name="TUT_function6_from_name_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            integer(C_INT), value, intent(IN) :: Lname
        end subroutine c_function6_from_name_bufferify

        subroutine c_function6_from_index(indx) &
                bind(C, name="TUT_function6_from_index")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: indx
        end subroutine c_function6_from_index

        subroutine c_function7_int(arg) &
                bind(C, name="TUT_function7_int")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: arg
        end subroutine c_function7_int

        subroutine c_function7_double(arg) &
                bind(C, name="TUT_function7_double")
            use iso_c_binding, only : C_DOUBLE
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg
        end subroutine c_function7_double

        function c_function8_int() &
                result(SH_rv) &
                bind(C, name="TUT_function8_int")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT) :: SH_rv
        end function c_function8_int

        function c_function8_double() &
                result(SH_rv) &
                bind(C, name="TUT_function8_double")
            use iso_c_binding, only : C_DOUBLE
            implicit none
            real(C_DOUBLE) :: SH_rv
        end function c_function8_double

        subroutine c_function9(arg) &
                bind(C, name="TUT_function9")
            use iso_c_binding, only : C_DOUBLE
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg
        end subroutine c_function9

        subroutine c_function10_0() &
                bind(C, name="TUT_function10_0")
            implicit none
        end subroutine c_function10_0

        subroutine c_function10_1(name, arg2) &
                bind(C, name="TUT_function10_1")
            use iso_c_binding, only : C_CHAR, C_DOUBLE
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            real(C_DOUBLE), value, intent(IN) :: arg2
        end subroutine c_function10_1

        subroutine c_function10_1_bufferify(name, Lname, arg2) &
                bind(C, name="TUT_function10_1_bufferify")
            use iso_c_binding, only : C_CHAR, C_DOUBLE, C_INT
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            integer(C_INT), value, intent(IN) :: Lname
            real(C_DOUBLE), value, intent(IN) :: arg2
        end subroutine c_function10_1_bufferify

        function c_overload1_num(num) &
                result(SH_rv) &
                bind(C, name="TUT_overload1_num")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT) :: SH_rv
        end function c_overload1_num

        function c_overload1_num_offset(num, offset) &
                result(SH_rv) &
                bind(C, name="TUT_overload1_num_offset")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT) :: SH_rv
        end function c_overload1_num_offset

        function c_overload1_num_offset_stride(num, offset, stride) &
                result(SH_rv) &
                bind(C, name="TUT_overload1_num_offset_stride")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT), value, intent(IN) :: stride
            integer(C_INT) :: SH_rv
        end function c_overload1_num_offset_stride

        function c_overload1_3(type, num) &
                result(SH_rv) &
                bind(C, name="TUT_overload1_3")
            use iso_c_binding, only : C_DOUBLE, C_INT
            implicit none
            real(C_DOUBLE), value, intent(IN) :: type
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT) :: SH_rv
        end function c_overload1_3

        function c_overload1_4(type, num, offset) &
                result(SH_rv) &
                bind(C, name="TUT_overload1_4")
            use iso_c_binding, only : C_DOUBLE, C_INT
            implicit none
            real(C_DOUBLE), value, intent(IN) :: type
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT) :: SH_rv
        end function c_overload1_4

        function c_overload1_5(type, num, offset, stride) &
                result(SH_rv) &
                bind(C, name="TUT_overload1_5")
            use iso_c_binding, only : C_DOUBLE, C_INT
            implicit none
            real(C_DOUBLE), value, intent(IN) :: type
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT), value, intent(IN) :: stride
            integer(C_INT) :: SH_rv
        end function c_overload1_5

        function typefunc(arg) &
                result(SH_rv) &
                bind(C, name="TUT_typefunc")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: arg
            integer(C_INT) :: SH_rv
        end function typefunc

        function enumfunc(arg) &
                result(SH_rv) &
                bind(C, name="TUT_enumfunc")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: arg
            integer(C_INT) :: SH_rv
        end function enumfunc

        subroutine c_useclass(arg1) &
                bind(C, name="TUT_useclass")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR), value, intent(IN) :: arg1
        end subroutine c_useclass

        function c_vector_sum_bufferify(arg, Sarg) &
                result(SH_rv) &
                bind(C, name="TUT_vector_sum_bufferify")
            use iso_c_binding, only : C_INT, C_LONG
            implicit none
            integer(C_INT), intent(IN) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
            integer(C_INT) :: SH_rv
        end function c_vector_sum_bufferify

        subroutine c_vector_iota_bufferify(arg, Sarg) &
                bind(C, name="TUT_vector_iota_bufferify")
            use iso_c_binding, only : C_INT, C_LONG
            implicit none
            integer(C_INT), intent(OUT) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
        end subroutine c_vector_iota_bufferify

        subroutine c_vector_increment_bufferify(arg, Sarg) &
                bind(C, name="TUT_vector_increment_bufferify")
            use iso_c_binding, only : C_INT, C_LONG
            implicit none
            integer(C_INT), intent(INOUT) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
        end subroutine c_vector_increment_bufferify

        function c_vector_string_count_bufferify(arg, Sarg, Narg) &
                result(SH_rv) &
                bind(C, name="TUT_vector_string_count_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT, C_LONG
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
            integer(C_INT), value, intent(IN) :: Narg
            integer(C_INT) :: SH_rv
        end function c_vector_string_count_bufferify

        subroutine c_vector_string_fill_bufferify(arg, Sarg, Narg) &
                bind(C, name="TUT_vector_string_fill_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT, C_LONG
            implicit none
            character(kind=C_CHAR), intent(OUT) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
            integer(C_INT), value, intent(IN) :: Narg
        end subroutine c_vector_string_fill_bufferify

        subroutine c_vector_string_append_bufferify(arg, Sarg, Narg) &
                bind(C, name="TUT_vector_string_append_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT, C_LONG
            implicit none
            character(kind=C_CHAR), intent(INOUT) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
            integer(C_INT), value, intent(IN) :: Narg
        end subroutine c_vector_string_append_bufferify

        pure function c_last_function_called() &
                result(SH_rv) &
                bind(C, name="TUT_last_function_called")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SH_rv
        end function c_last_function_called

        subroutine c_last_function_called_bufferify(SH_F_rv, NSH_F_rv) &
                bind(C, name="TUT_last_function_called_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            implicit none
            character(kind=C_CHAR), intent(OUT) :: SH_F_rv(*)
            integer(C_INT), value, intent(IN) :: NSH_F_rv
        end subroutine c_last_function_called_bufferify

        ! splicer begin additional_interfaces
        subroutine all_test1(array)
          implicit none
          integer, dimension(:), allocatable :: array
        end subroutine all_test1
        ! splicer end additional_interfaces
    end interface

    interface function10
        module procedure function10_0
        module procedure function10_1_float
        module procedure function10_1_double
    end interface function10

    interface function5
        module procedure function5
        module procedure function5_arg1
        module procedure function5_arg1_arg2
    end interface function5

    interface function6
        module procedure function6_from_name
        module procedure function6_from_index
    end interface function6

    interface function7
        module procedure function7_int
        module procedure function7_double
    end interface function7

    interface function9
        module procedure function9_float
        module procedure function9_double
    end interface function9

    interface overload1
        module procedure overload1_num
        module procedure overload1_num_offset
        module procedure overload1_num_offset_stride
        module procedure overload1_3
        module procedure overload1_4
        module procedure overload1_5
    end interface overload1

    private fstr_ptr, strlen_ptr

    interface
       pure function strlen_ptr(s) result(result) bind(c,name="strlen")
         use, intrinsic :: iso_c_binding
         integer(c_int) :: result
         type(c_ptr), value, intent(in) :: s
       end function strlen_ptr
    end interface

contains

    ! Class1 * new()+constructor
    ! function_index=0
    function class1_new() result(SH_rv)
        type(class1) :: SH_rv
        ! splicer begin class.Class1.method.new
        SH_rv%voidptr = c_class1_new()
        ! splicer end class.Class1.method.new
    end function class1_new

    ! void delete()+destructor
    ! function_index=1
    subroutine class1_delete(obj)
        use iso_c_binding, only : C_NULL_PTR
        class(class1) :: obj
        ! splicer begin class.Class1.method.delete
        call c_class1_delete(obj%voidptr)
        obj%voidptr = C_NULL_PTR
        ! splicer end class.Class1.method.delete
    end subroutine class1_delete

    ! void Method1()
    ! function_index=2
    subroutine class1_method1(obj)
        class(class1) :: obj
        ! splicer begin class.Class1.method.method1
        call c_class1_method1(obj%voidptr)
        ! splicer end class.Class1.method.method1
    end subroutine class1_method1

    function class1_get_instance(obj) result (voidptr)
        use iso_c_binding, only: C_PTR
        implicit none
        class(class1), intent(IN) :: obj
        type(C_PTR) :: voidptr
        voidptr = obj%voidptr
    end function class1_get_instance

    subroutine class1_set_instance(obj, voidptr)
        use iso_c_binding, only: C_PTR
        implicit none
        class(class1), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: voidptr
        obj%voidptr = voidptr
    end subroutine class1_set_instance

    function class1_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        implicit none
        class(class1), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%voidptr)
    end function class1_associated

    ! splicer begin class.Class1.additional_functions
    ! splicer end class.Class1.additional_functions

    ! bool Function3(bool arg+intent(in)+value)
    ! function_index=6
    function function3(arg) result(SH_rv)
        use iso_c_binding, only : C_BOOL
        logical, value, intent(IN) :: arg
        logical(C_BOOL) SH_arg
        logical :: SH_rv
        SH_arg = arg  ! coerce to C_BOOL
        ! splicer begin function.function3
        SH_rv = c_function3(SH_arg)
        ! splicer end function.function3
    end function function3

    ! void Function3b(const bool arg1+intent(in)+value, bool * arg2+intent(out), bool * arg3+intent(inout))
    ! function_index=7
    subroutine function3b(arg1, arg2, arg3)
        use iso_c_binding, only : C_BOOL
        logical, value, intent(IN) :: arg1
        logical(C_BOOL) SH_arg1
        logical, intent(OUT) :: arg2
        logical(C_BOOL) SH_arg2
        logical, intent(INOUT) :: arg3
        logical(C_BOOL) SH_arg3
        SH_arg1 = arg1  ! coerce to C_BOOL
        SH_arg3 = arg3  ! coerce to C_BOOL
        ! splicer begin function.function3b
        call c_function3b(  &
            SH_arg1,  &
            SH_arg2,  &
            SH_arg3)
        ! splicer end function.function3b
        arg2 = SH_arg2  ! coerce to logical
        arg3 = SH_arg3  ! coerce to logical
    end subroutine function3b

    ! const std::string Function4a(const std::string & arg1+intent(in), const std::string & arg2+intent(in))
    ! arg_to_buffer
    ! function_index=8
    function function4a(arg1, arg2) result(SH_rv)
        use iso_c_binding, only : C_CHAR, C_INT
        character(*), intent(IN) :: arg1
        character(*), intent(IN) :: arg2
        character(kind=C_CHAR, len=30) :: SH_rv
        ! splicer begin function.function4a
        call c_function4a_bufferify(  &
            arg1,  &
            len_trim(arg1, kind=C_INT),  &
            arg2,  &
            len_trim(arg2, kind=C_INT),  &
            SH_rv,  &
            len(SH_rv, kind=C_INT))
        ! splicer end function.function4a
    end function function4a

    ! void Function4b(const std::string & arg1+intent(in)+len_trim(Larg1), const std::string & arg2+intent(in)+len_trim(Larg2), std::string & output+intent(out)+len(Noutput))
    ! arg_to_buffer - arg_to_buffer
    ! function_index=42
    subroutine function4b(arg1, arg2, output)
        use iso_c_binding, only : C_INT
        character(*), intent(IN) :: arg1
        character(*), intent(IN) :: arg2
        character(*), intent(OUT) :: output
        ! splicer begin function.function4b
        call c_function4b_bufferify(  &
            arg1,  &
            len_trim(arg1, kind=C_INT),  &
            arg2,  &
            len_trim(arg2, kind=C_INT),  &
            output,  &
            len(output, kind=C_INT))
        ! splicer end function.function4b
    end subroutine function4b

    ! double Function5()
    ! has_default_arg
    ! function_index=30
    function function5() result(SH_rv)
        use iso_c_binding, only : C_DOUBLE
        real(C_DOUBLE) :: SH_rv
        ! splicer begin function.function5
        SH_rv = c_function5()
        ! splicer end function.function5
    end function function5

    ! double Function5(double arg1+default(3.1415)+intent(in)+value)
    ! has_default_arg
    ! function_index=31
    function function5_arg1(arg1) result(SH_rv)
        use iso_c_binding, only : C_DOUBLE
        real(C_DOUBLE), value, intent(IN) :: arg1
        real(C_DOUBLE) :: SH_rv
        ! splicer begin function.function5_arg1
        SH_rv = c_function5_arg1(arg1)
        ! splicer end function.function5_arg1
    end function function5_arg1

    ! double Function5(double arg1+default(3.1415)+intent(in)+value, bool arg2+default(true)+intent(in)+value)
    ! function_index=10
    function function5_arg1_arg2(arg1, arg2) result(SH_rv)
        use iso_c_binding, only : C_BOOL, C_DOUBLE
        real(C_DOUBLE), value, intent(IN) :: arg1
        logical, value, intent(IN) :: arg2
        logical(C_BOOL) SH_arg2
        real(C_DOUBLE) :: SH_rv
        SH_arg2 = arg2  ! coerce to C_BOOL
        ! splicer begin function.function5_arg1_arg2
        SH_rv = c_function5_arg1_arg2(  &
            arg1,  &
            SH_arg2)
        ! splicer end function.function5_arg1_arg2
    end function function5_arg1_arg2

    ! void Function6(const std::string & name+intent(in))
    ! arg_to_buffer
    ! function_index=11
    subroutine function6_from_name(name)
        use iso_c_binding, only : C_INT
        character(*), intent(IN) :: name
        ! splicer begin function.function6_from_name
        call c_function6_from_name_bufferify(  &
            name,  &
            len_trim(name, kind=C_INT))
        ! splicer end function.function6_from_name
    end subroutine function6_from_name

    ! void Function6(int indx+intent(in)+value)
    ! function_index=12
    subroutine function6_from_index(indx)
        use iso_c_binding, only : C_INT
        integer(C_INT), value, intent(IN) :: indx
        ! splicer begin function.function6_from_index
        call c_function6_from_index(indx)
        ! splicer end function.function6_from_index
    end subroutine function6_from_index

    ! void Function7(int arg+intent(in)+value)
    ! cpp_template
    ! function_index=32
    subroutine function7_int(arg)
        use iso_c_binding, only : C_INT
        integer(C_INT), value, intent(IN) :: arg
        ! splicer begin function.function7_int
        call c_function7_int(arg)
        ! splicer end function.function7_int
    end subroutine function7_int

    ! void Function7(double arg+intent(in)+value)
    ! cpp_template
    ! function_index=33
    subroutine function7_double(arg)
        use iso_c_binding, only : C_DOUBLE
        real(C_DOUBLE), value, intent(IN) :: arg
        ! splicer begin function.function7_double
        call c_function7_double(arg)
        ! splicer end function.function7_double
    end subroutine function7_double

    ! int Function8()
    ! cpp_template
    ! function_index=34
    function function8_int() result(SH_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT) :: SH_rv
        ! splicer begin function.function8_int
        SH_rv = c_function8_int()
        ! splicer end function.function8_int
    end function function8_int

    ! double Function8()
    ! cpp_template
    ! function_index=35
    function function8_double() result(SH_rv)
        use iso_c_binding, only : C_DOUBLE
        real(C_DOUBLE) :: SH_rv
        ! splicer begin function.function8_double
        SH_rv = c_function8_double()
        ! splicer end function.function8_double
    end function function8_double

    ! void Function9(float arg+intent(in)+value)
    ! fortran_generic
    ! function_index=52
    subroutine function9_float(arg)
        use iso_c_binding, only : C_DOUBLE, C_FLOAT
        real(C_FLOAT), value, intent(IN) :: arg
        ! splicer begin function.function9_float
        call c_function9(real(arg, C_DOUBLE))
        ! splicer end function.function9_float
    end subroutine function9_float

    ! void Function9(double arg+intent(in)+value)
    ! fortran_generic
    ! function_index=53
    subroutine function9_double(arg)
        use iso_c_binding, only : C_DOUBLE
        real(C_DOUBLE), value, intent(IN) :: arg
        ! splicer begin function.function9_double
        call c_function9(arg)
        ! splicer end function.function9_double
    end subroutine function9_double

    ! void Function10()
    ! function_index=16
    subroutine function10_0()
        ! splicer begin function.function10_0
        call c_function10_0()
        ! splicer end function.function10_0
    end subroutine function10_0

    ! void Function10(const std::string & name+intent(in), float arg2+intent(in)+value)
    ! fortran_generic - arg_to_buffer
    ! function_index=54
    subroutine function10_1_float(name, arg2)
        use iso_c_binding, only : C_DOUBLE, C_FLOAT, C_INT
        character(*), intent(IN) :: name
        real(C_FLOAT), value, intent(IN) :: arg2
        ! splicer begin function.function10_1_float
        call c_function10_1_bufferify(  &
            name,  &
            len_trim(name, kind=C_INT),  &
            real(arg2, C_DOUBLE))
        ! splicer end function.function10_1_float
    end subroutine function10_1_float

    ! void Function10(const std::string & name+intent(in), double arg2+intent(in)+value)
    ! fortran_generic - arg_to_buffer
    ! function_index=55
    subroutine function10_1_double(name, arg2)
        use iso_c_binding, only : C_DOUBLE, C_INT
        character(*), intent(IN) :: name
        real(C_DOUBLE), value, intent(IN) :: arg2
        ! splicer begin function.function10_1_double
        call c_function10_1_bufferify(  &
            name,  &
            len_trim(name, kind=C_INT),  &
            arg2)
        ! splicer end function.function10_1_double
    end subroutine function10_1_double

    ! int overload1(int num+intent(in)+value)
    ! has_default_arg
    ! function_index=36
    function overload1_num(num) result(SH_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT) :: SH_rv
        ! splicer begin function.overload1_num
        SH_rv = c_overload1_num(num)
        ! splicer end function.overload1_num
    end function overload1_num

    ! int overload1(int num+intent(in)+value, int offset+default(0)+intent(in)+value)
    ! has_default_arg
    ! function_index=37
    function overload1_num_offset(num, offset) result(SH_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT) :: SH_rv
        ! splicer begin function.overload1_num_offset
        SH_rv = c_overload1_num_offset(  &
            num,  &
            offset)
        ! splicer end function.overload1_num_offset
    end function overload1_num_offset

    ! int overload1(int num+intent(in)+value, int offset+default(0)+intent(in)+value, int stride+default(1)+intent(in)+value)
    ! function_index=18
    function overload1_num_offset_stride(num, offset, stride) result(SH_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT), value, intent(IN) :: stride
        integer(C_INT) :: SH_rv
        ! splicer begin function.overload1_num_offset_stride
        SH_rv = c_overload1_num_offset_stride(  &
            num,  &
            offset,  &
            stride)
        ! splicer end function.overload1_num_offset_stride
    end function overload1_num_offset_stride

    ! int overload1(double type+intent(in)+value, int num+intent(in)+value)
    ! has_default_arg
    ! function_index=38
    function overload1_3(type, num) result(SH_rv)
        use iso_c_binding, only : C_DOUBLE, C_INT
        real(C_DOUBLE), value, intent(IN) :: type
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT) :: SH_rv
        ! splicer begin function.overload1_3
        SH_rv = c_overload1_3(  &
            type,  &
            num)
        ! splicer end function.overload1_3
    end function overload1_3

    ! int overload1(double type+intent(in)+value, int num+intent(in)+value, int offset+default(0)+intent(in)+value)
    ! has_default_arg
    ! function_index=39
    function overload1_4(type, num, offset) result(SH_rv)
        use iso_c_binding, only : C_DOUBLE, C_INT
        real(C_DOUBLE), value, intent(IN) :: type
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT) :: SH_rv
        ! splicer begin function.overload1_4
        SH_rv = c_overload1_4(  &
            type,  &
            num,  &
            offset)
        ! splicer end function.overload1_4
    end function overload1_4

    ! int overload1(double type+intent(in)+value, int num+intent(in)+value, int offset+default(0)+intent(in)+value, int stride+default(1)+intent(in)+value)
    ! function_index=19
    function overload1_5(type, num, offset, stride) result(SH_rv)
        use iso_c_binding, only : C_DOUBLE, C_INT
        real(C_DOUBLE), value, intent(IN) :: type
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT), value, intent(IN) :: stride
        integer(C_INT) :: SH_rv
        ! splicer begin function.overload1_5
        SH_rv = c_overload1_5(  &
            type,  &
            num,  &
            offset,  &
            stride)
        ! splicer end function.overload1_5
    end function overload1_5

    ! void useclass(const Class1 * arg1+intent(in)+value)
    ! function_index=22
    subroutine useclass(arg1)
        type(class1), value, intent(IN) :: arg1
        ! splicer begin function.useclass
        call c_useclass(arg1%get_instance())
        ! splicer end function.useclass
    end subroutine useclass

    ! int vector_sum(const std::vector & arg+dimension(:)+intent(in)+template(int))
    ! arg_to_buffer
    ! function_index=23
    function vector_sum(arg) result(SH_rv)
        use iso_c_binding, only : C_INT, C_LONG
        integer(C_INT), intent(IN) :: arg(:)
        integer(C_INT) :: SH_rv
        ! splicer begin function.vector_sum
        SH_rv = c_vector_sum_bufferify(  &
            arg,  &
            size(arg, kind=C_LONG))
        ! splicer end function.vector_sum
    end function vector_sum

    ! void vector_iota(std::vector & arg+dimension(:)+intent(out)+template(int))
    ! arg_to_buffer
    ! function_index=24
    subroutine vector_iota(arg)
        use iso_c_binding, only : C_INT, C_LONG
        integer(C_INT), intent(OUT) :: arg(:)
        ! splicer begin function.vector_iota
        call c_vector_iota_bufferify(  &
            arg,  &
            size(arg, kind=C_LONG))
        ! splicer end function.vector_iota
    end subroutine vector_iota

    ! void vector_increment(std::vector & arg+dimension(:)+intent(inout)+template(int))
    ! arg_to_buffer
    ! function_index=25
    subroutine vector_increment(arg)
        use iso_c_binding, only : C_INT, C_LONG
        integer(C_INT), intent(INOUT) :: arg(:)
        ! splicer begin function.vector_increment
        call c_vector_increment_bufferify(  &
            arg,  &
            size(arg, kind=C_LONG))
        ! splicer end function.vector_increment
    end subroutine vector_increment

    ! int vector_string_count(const std::vector & arg+dimension(:)+intent(in)+template(std::string))
    ! arg_to_buffer
    ! function_index=26
    !>
    !! \brief count number of underscore in vector of strings
    !!
    !<
    function vector_string_count(arg) result(SH_rv)
        use iso_c_binding, only : C_INT, C_LONG
        character(*), intent(IN) :: arg(:)
        integer(C_INT) :: SH_rv
        ! splicer begin function.vector_string_count
        SH_rv = c_vector_string_count_bufferify(  &
            arg,  &
            size(arg, kind=C_LONG),  &
            len(arg, kind=C_INT))
        ! splicer end function.vector_string_count
    end function vector_string_count

    ! void vector_string_fill(std::vector & arg+dimension(:)+intent(out)+template(std::string))
    ! arg_to_buffer
    ! function_index=27
    !>
    !! \brief Fill in arg with some animal names
    !!
    !<
    subroutine vector_string_fill(arg)
        use iso_c_binding, only : C_INT, C_LONG
        character(*), intent(OUT) :: arg(:)
        ! splicer begin function.vector_string_fill
        call c_vector_string_fill_bufferify(  &
            arg,  &
            size(arg, kind=C_LONG),  &
            len(arg, kind=C_INT))
        ! splicer end function.vector_string_fill
    end subroutine vector_string_fill

    ! void vector_string_append(std::vector & arg+dimension(:)+intent(inout)+template(std::string))
    ! arg_to_buffer
    ! function_index=28
    !>
    !! \brief append '-like' to names.
    !!
    !<
    subroutine vector_string_append(arg)
        use iso_c_binding, only : C_INT, C_LONG
        character(*), intent(INOUT) :: arg(:)
        ! splicer begin function.vector_string_append
        call c_vector_string_append_bufferify(  &
            arg,  &
            size(arg, kind=C_LONG),  &
            len(arg, kind=C_INT))
        ! splicer end function.vector_string_append
    end subroutine vector_string_append

    ! const std::string & LastFunctionCalled()+pure
    ! function_index=29
    function last_function_called() result(SH_rv)
        use iso_c_binding, only : C_CHAR
        character(kind=C_CHAR, len=strlen_ptr(c_last_function_called())) :: SH_rv
        ! splicer begin function.last_function_called
        SH_rv = fstr_ptr(c_last_function_called())
        ! splicer end function.last_function_called
    end function last_function_called

    ! splicer begin additional_functions
    ! splicer end additional_functions

    function class1_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        implicit none
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%voidptr, b%voidptr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_eq

    function class1_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        implicit none
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%voidptr, b%voidptr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_ne

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

end module tutorial_mod
