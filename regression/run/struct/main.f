! Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC. 
!
! Produced at the Lawrence Livermore National Laboratory 
!
! LLNL-CODE-738041.
!
! All rights reserved. 
!
! This file is part of Shroud.
!
! For details about use and distribution, please read LICENSE.
!
! #######################################################################
!
! Test code generated by the struct test
!
program tester
  use fruit
  use iso_c_binding
  use struct_mod
  implicit none
  logical ok

  integer, parameter :: lenoutbuf = 40

  call init_fruit

  call test_struct
  call test_struct2

  call fruit_summary
  call fruit_finalize

  call is_all_successful(ok)
  if (.not. ok) then
     call exit(1)
  endif

contains

  subroutine test_struct
    character(lenoutbuf)  :: outbuf
    type(cstruct1) str1
    integer(C_INT) rvi

    call set_case_name("test_struct")

    str1%ifield = 2_C_INT
    str1%dfield = 2.0_C_DOUBLE
    rvi = pass_struct_by_value(str1)
    call assert_equals(4, rvi, "pass_struct_by_value")
    ! Make sure str1 was passed by value.
    call assert_equals(2_C_INT, str1%ifield, "pass_struct_by_value ifield")
    call assert_equals(2.0_C_DOUBLE, str1%dfield, "pass_struct_by_value dfield")

    str1%ifield = 12
    str1%dfield = 12.6
    call assert_equals(12, pass_struct1(str1), "passStruct1")

    str1%ifield = 22
    str1%dfield = 22.8
    call assert_equals(22, pass_struct2(str1, outbuf), "passStruct2")

    str1%ifield = 3_C_INT
    str1%dfield = 3.0_C_DOUBLE
    rvi = accept_struct_in_ptr(str1)
    call assert_equals(6, rvi, "accept_struct_in_ptr")
    ! ifield changed by routine.
    call assert_equals(4, str1%ifield, "accept_struct_in_ptr ifield")

    str1%ifield = 0
    str1%dfield = 0.0
    call accept_struct_out_ptr(str1, 4_C_INT, 4.5_C_DOUBLE)
    call assert_equals(4_C_INT,      str1%ifield, "accept_struct_out_ptr i field")
    call assert_equals(4.5_C_DOUBLE, str1%dfield, "accept_struct_out_ptr d field")

    str1%ifield = 4_C_INT
    str1%dfield = 4.0_C_DOUBLE
    call accept_struct_in_out_ptr(str1)
    call assert_equals(5_C_INT,      str1%ifield, "accept_struct_in_out_ptr i field")
    call assert_equals(5.0_C_DOUBLE, str1%dfield, "accept_struct_in_out_ptr d field")

  end subroutine test_struct

  subroutine test_struct2
    ! return structs

    character(lenoutbuf)  :: outbuf
    type(cstruct1) :: str1
    type(cstruct1), pointer :: str2

    call set_case_name("test_struct2")

    str1 = return_struct(1_C_INT, 2.5_C_DOUBLE)
    call assert_equals(1_C_INT,      str1%ifield, "return_struct i field")
    call assert_equals(2.5_C_DOUBLE, str1%dfield, "return_struct d field")

    nullify(str2)
    str2 => return_struct_ptr1(33, 33.5d0)
    call assert_true(associated(str2), "returnStructPtr1")
    call assert_equals(33, str2%ifield, "returnStructPtr2")

    nullify(str2)
    str2 => return_struct_ptr2(35, 35.5d0, outbuf)
    call assert_true(associated(str2), "returnStructPtr2")
    call assert_equals(35, str2%ifield, "returnStructPtr2")

  end subroutine test_struct2

end program tester
