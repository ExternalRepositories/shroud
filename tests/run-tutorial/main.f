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
!
! Test code generated by the tutorial test
!
function incr2(input) bind(C)
  use iso_c_binding
  integer(c_int), value :: input
  integer(c_int) :: incr2
  incr2 = input + 20
end function incr2

program tester
  use fruit
  use iso_c_binding
  use tutorial_mod
  implicit none
  logical ok

  logical rv_logical, wrk_logical
  integer rv_integer
  integer(C_INT) rv_int
  real(C_DOUBLE) rv_double
  character(30) rv_char

  call init_fruit

  call test_enums
  call test_functions

  call test_vector

  call test_callback

  call test_struct1
  call test_class1
  call test_singleton

  call fruit_summary
  call fruit_finalize

  call is_all_successful(ok)
  if (.not. ok) then
     call exit(1)
  endif

contains

  subroutine test_enums
    ! test values of enumerations
    integer(C_INT) rv_int

    call set_case_name("test_enums")

    call assert_equals(0, color_red)
    call assert_equals(1, color_blue)
    call assert_equals(2, color_white)

    call assert_equals(2, class1_direction_up)
    call assert_equals(3, class1_direction_down)
    call assert_equals(100, class1_direction_left)
    call assert_equals(101, class1_direction_right)

    rv_int = colorfunc(color_BLUE)
    call assert_true(rv_int .eq. color_RED)

  end subroutine test_enums

  subroutine test_functions

    integer(C_LONG_LONG) :: rv_ll
    integer(C_INT) :: minout, maxout
    integer(C_INT), pointer :: intp, intp1(:)

    call set_case_name("test_functions")

    call function1
    call assert_true(.true.)

    rv_double = function2(1.d0, 4)
    call assert_true(rv_double == 5.d0)

    rv_logical = function3(.false.)
    call assert_true(rv_logical)

    rv_logical = .true.
    wrk_logical = .true.
    call function3b(.true., rv_logical, wrk_logical)
    call assert_false(rv_logical)
    call assert_false(wrk_logical)

    rv_logical = .false.
    wrk_logical = .false.
    call function3b(.false., rv_logical, wrk_logical)
    call assert_true(rv_logical)
    call assert_true(wrk_logical)

    nullify(intp)
    intp => return_int_ptr()
    call assert_true(associated(intp))
    call assert_equals(1, intp, "return_int_ptr value")

    nullify(intp1)
    intp1 => return_int_ptr_dim()
    call assert_true(associated(intp1))
    call assert_equals(7 , size(intp1))
    call assert_true( all(intp1 == [1,2,3,4,5,6,7]), "return_int_ptr_dim value")

    call assert_true( function4a("dog", "cat") == "dogcat")

    call function4b("dog", "cat", rv_char)
    call assert_true( rv_char == "dogcat")

    call assert_equals(function5(), 13.1415d0)
    call assert_equals(function5(1.d0), 11.d0)
    call assert_equals(function5(1.d0, .false.), 1.d0)

    call function6("name")
    call assert_true(last_function_called() == "Function6(string)")
    call function6(1)
    call assert_true(last_function_called() == "Function6(int)")

    call function7(1)
    call assert_true(last_function_called() == "Function7<int>")
    call function7(10.d0)
    call assert_true(last_function_called() == "Function7<double>")

    ! return values set by calls to function7
    rv_integer = function8_int()
    call assert_true(rv_integer == 1)
    rv_double = function8_double()
    call assert_true(rv_double == 10.d0)

    call function9(1.0)
    call assert_true(.true.)
    call function9(1.d0)
    call assert_true(.true.)

    call function10()
    call assert_true(.true.)
    call function10("foo", 1.0e0)
    call assert_true(.true.)
    call function10("bar", 2.0d0)
    call assert_true(.true.)

    call sum([1,2,3,4,5], rv_int)
    call assert_true(rv_int .eq. 15)

    rv_ll = type_long_long( 2_c_long_long)
    call assert_true(rv_ll .eq. 4)

    rv_int = overload1(10)
    call assert_true(rv_int .eq. 10)
    rv_int = overload1(1.0d0, 10)
    call assert_true(rv_int .eq. 10)

    rv_int = overload1(10, 11, 12)
    call assert_true(rv_int .eq. 142)
    rv_int = overload1(1.0d0, 10, 11, 12)
    call assert_true(rv_int .eq. 142)

    rv_int = typefunc(2)
    call assert_true(rv_int .eq. 2)

    rv_int = enumfunc(1)
    call assert_true(rv_int .eq. 2)

    call get_min_max(minout, maxout)
    call assert_equals(-1, minout)
    call assert_equals(100, maxout)

  end subroutine test_functions

  subroutine test_vector
    integer(C_INT) intv(5)
    character(10) :: names(3)
    integer irv

    call set_case_name("test_vector")

    intv = [1,2,3,4,5]
    irv = vector_sum(intv)
    call assert_true(irv .eq. 15)

    intv(:) = 0
    call vector_iota(intv)
    call assert_true(all(intv(:) .eq. [1,2,3,4,5]))

    intv = [1,2,3,4,5]
    call vector_increment(intv)
    call assert_true(all(intv(:) .eq. [2,3,4,5,6]))

    ! count number of underscores
    names = [ "dog_cat   ", "bird_mouse", "__        " ]
    irv = vector_string_count(names)
    call assert_true(irv == 4)

    ! Fill strings into names
    names = " "
    irv = vector_string_fill(names)
    call assert_true(irv == 2)
    call assert_true( names(1) == "dog")
    call assert_true( names(2) == "bird")
    call assert_true( names(3) == " ")

    ! Append -like to names.
    ! Note that strings will be truncated to len(names)
    names = [ "fish      ", "toolong   ", "          " ]
    call vector_string_append(names)
    call assert_true( names(1) == "fish-like")
    call assert_true( names(2) == "toolong-li")
    call assert_true( names(3) == "-like")
 
  end subroutine test_vector

  subroutine test_callback

    integer irv
    interface
       function incr2(input) bind(C)
         use iso_c_binding
         integer(c_int), value :: input
         integer(c_int) :: incr2
       end function incr2
    end interface

    call set_case_name("test_callback")

    irv = callback1(2, incr2)
    call assert_true(irv == 22)

  end subroutine test_callback

  subroutine test_struct1
    type(struct1) str1
    type(struct1), pointer :: str2
    real(C_DOUBLE) rvd

    call set_case_name("test_struct")

    str1 = return_struct(1_C_INT, 2.5_C_DOUBLE)
    call assert_equals(1_C_INT,      str1%i, "return_struct i field")
    call assert_equals(2.5_C_DOUBLE, str1%d, "return_struct d field")

    str2 => return_struct_ptr(8_C_INT, 8.5_C_DOUBLE)

    str1%i = 2_C_INT
    str1%d = 2.0_C_DOUBLE
    rvd = accept_struct_in(str1)
    call assert_equals(4.0_C_DOUBLE, rvd, "accept_struct_in")

    str1%i = 3_C_INT
    str1%d = 3.0_C_DOUBLE
    rvd = accept_struct_in_ptr(str1)
    call assert_equals(6.0_C_DOUBLE, rvd, "accept_struct_in_ptr")

    str1%i = 0
    str1%d = 0.0
    call accept_struct_out_ptr(str1, 4_C_INT, 4.5_C_DOUBLE)
    call assert_equals(4_C_INT,      str1%i, "accept_struct_out_ptr i field")
    call assert_equals(4.5_C_DOUBLE, str1%d, "accept_struct_out_ptr d field")

    str1%i = 4_C_INT
    str1%d = 4.0_C_DOUBLE
    call accept_struct_in_out_ptr(str1)
    call assert_equals(5_C_INT,      str1%i, "accept_struct_in_out_ptr i field")
    call assert_equals(5.0_C_DOUBLE, str1%d, "accept_struct_in_out_ptr d field")

  end subroutine test_struct1

  subroutine test_class1
    integer iflag
    integer direction
    type(class1) obj0, obj1
    type(class1) obj0a
    type(c_ptr) ptr

    call set_case_name("test_class1")

    ! Test generic constructor
    obj0 = class1_new()
    ptr = obj0%get_instance()
    call assert_true(c_associated(ptr), "class1_new obj0")

    obj1 = class1_new(1)
    ptr = obj1%get_instance()
    call assert_true(c_associated(ptr), "class1_new obj1")

    iflag = obj0%method1()
    call assert_equals(iflag, 0, "method1 0")

    iflag = obj1%method1()
    call assert_equals(iflag, 1, "method1 1")

    call assert_true(obj0 .eq. obj0, "obj0 .eq obj0")
    call assert_true(obj0 .ne. obj1, "obj0 .ne. obj1")

    call assert_true(obj0%equivalent(obj0))
    call assert_false(obj0%equivalent(obj1))

    call obj0%return_this()

    direction = -1
    direction = obj0%direction_func(class1_direction_left)
    call assert_equals(class1_direction_left, direction, "obj0.directionFunc")

    direction = -1
    direction = direction_func(class1_direction_left)
    call assert_equals(class1_direction_right, direction, "directionFunc")

    ! use class assigns global_class1 returned by getclass
    iflag = useclass(obj0)
    call assert_equals(iflag, 0, "useclass")

    obj0a = getclass2()
    ptr = obj0a%get_instance()
    call assert_true(c_associated(ptr), "getclass2 obj0a")
    call assert_true(obj0 .eq. obj0a, "obj0 .eq. obj0a")

    call obj0%delete
    ptr = obj0%get_instance()
    call assert_true(.not. c_associated(ptr), "class1_delete obj0")

    call obj1%delete
    ptr = obj1%get_instance()
    call assert_true(.not. c_associated(ptr), "class1_delete obj1")

    ! obj0a has a dangling reference to a deleted object
  end subroutine test_class1

  subroutine test_singleton
    type(singleton) obj0, obj1

    call set_case_name("test_singleton")

    obj0 = obj0%get_reference()
    obj1 = obj1%get_reference()

    call assert_true(obj0 .eq. obj1, "obj0 .eq obj1")

  end subroutine test_singleton

end program tester
