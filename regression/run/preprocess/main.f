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
! Test code generated by the preprocess test
!

program tester
  use fruit
  use iso_c_binding
  use preprocess_mod
  implicit none
  logical ok

  call init_fruit

  call test_User1

  call fruit_summary
  call fruit_finalize

  call is_all_successful(ok)
  if (.not. ok) then
     call exit(1)
  endif

contains

  subroutine test_User1
    type(user1) var

    call var%method1()
#if defined(USE_TWO)
    call var%method2()
#endif
  end subroutine test_User1

end program tester