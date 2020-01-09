! wrapfpointers.f
! This is generated code, do not edit
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfpointers.f
!! \brief Shroud generated wrapper for pointers library
!<
! splicer begin file_top
! splicer end file_top
module pointers_mod
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    interface
        subroutine intargs(argin, arginout, argout) &
                bind(C, name="POI_intargs")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: argin
            integer(C_INT), intent(INOUT) :: arginout
            integer(C_INT), intent(OUT) :: argout
        end subroutine intargs
    end interface

    interface
        subroutine c_cos_doubles(in, out, sizein) &
                bind(C, name="POI_cos_doubles")
            use iso_c_binding, only : C_DOUBLE, C_INT
            implicit none
            real(C_DOUBLE), intent(IN) :: in(*)
            real(C_DOUBLE), intent(OUT) :: out(*)
            integer(C_INT), value, intent(IN) :: sizein
        end subroutine c_cos_doubles
    end interface

    interface
        subroutine c_truncate_to_int(in, out, sizein) &
                bind(C, name="POI_truncate_to_int")
            use iso_c_binding, only : C_DOUBLE, C_INT
            implicit none
            real(C_DOUBLE), intent(IN) :: in(*)
            integer(C_INT), intent(OUT) :: out(*)
            integer(C_INT), value, intent(IN) :: sizein
        end subroutine c_truncate_to_int
    end interface

    interface
        subroutine get_values(nvalues, values) &
                bind(C, name="POI_get_values")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), intent(OUT) :: nvalues
            integer(C_INT), intent(OUT) :: values(*)
        end subroutine get_values
    end interface

    interface
        subroutine get_values2(arg1, arg2) &
                bind(C, name="POI_get_values2")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), intent(OUT) :: arg1(*)
            integer(C_INT), intent(OUT) :: arg2(*)
        end subroutine get_values2
    end interface

    ! start c_sum
    interface
        subroutine c_sum(len, values, result) &
                bind(C, name="POI_sum")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: len
            integer(C_INT), intent(IN) :: values(*)
            integer(C_INT), intent(OUT) :: result
        end subroutine c_sum
    end interface
    ! end c_sum

    interface
        subroutine fill_int_array(out) &
                bind(C, name="POI_fill_int_array")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), intent(OUT) :: out(*)
        end subroutine fill_int_array
    end interface

    interface
        subroutine c_increment_int_array(array, sizein) &
                bind(C, name="POI_increment_int_array")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), intent(INOUT) :: array(*)
            integer(C_INT), value, intent(IN) :: sizein
        end subroutine c_increment_int_array
    end interface

    interface
        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

contains

    ! void cos_doubles(double * in +dimension(:)+intent(in), double * out +allocatable(mold=in)+intent(out), int sizein +implied(size(in))+intent(in)+value)
    !>
    !! \brief compute cos of IN and save in OUT
    !!
    !! allocate OUT same type as IN implied size of array
    !<
    subroutine cos_doubles(in, out)
        use iso_c_binding, only : C_DOUBLE, C_INT
        real(C_DOUBLE), intent(IN) :: in(:)
        real(C_DOUBLE), intent(OUT), allocatable :: out(:)
        integer(C_INT) :: SH_sizein
        ! splicer begin function.cos_doubles
        allocate(out(lbound(in,1):ubound(in,1)))
        SH_sizein = size(in,kind=C_INT)
        call c_cos_doubles(in, out, SH_sizein)
        ! splicer end function.cos_doubles
    end subroutine cos_doubles

    ! void truncate_to_int(double * in +dimension(:)+intent(in), int * out +allocatable(mold=in)+intent(out), int sizein +implied(size(in))+intent(in)+value)
    !>
    !! \brief truncate IN argument and save in OUT
    !!
    !! allocate OUT different type as IN
    !! implied size of array
    !<
    subroutine truncate_to_int(in, out)
        use iso_c_binding, only : C_DOUBLE, C_INT
        real(C_DOUBLE), intent(IN) :: in(:)
        integer(C_INT), intent(OUT), allocatable :: out(:)
        integer(C_INT) :: SH_sizein
        ! splicer begin function.truncate_to_int
        allocate(out(lbound(in,1):ubound(in,1)))
        SH_sizein = size(in,kind=C_INT)
        call c_truncate_to_int(in, out, SH_sizein)
        ! splicer end function.truncate_to_int
    end subroutine truncate_to_int

    ! void Sum(int len +implied(size(values))+intent(in)+value, int * values +dimension(:)+intent(in), int * result +intent(out))
    ! start sum
    subroutine sum(values, result)
        use iso_c_binding, only : C_INT
        integer(C_INT) :: SH_len
        integer(C_INT), intent(IN) :: values(:)
        integer(C_INT), intent(OUT) :: result
        ! splicer begin function.sum
        SH_len = size(values,kind=C_INT)
        call c_sum(SH_len, values, result)
        ! splicer end function.sum
    end subroutine sum
    ! end sum

    ! void incrementIntArray(int * array +dimension(:)+intent(inout), int sizein +implied(size(array))+intent(in)+value)
    !>
    !! Increment array in place using intent(INOUT).
    !<
    subroutine increment_int_array(array)
        use iso_c_binding, only : C_INT
        integer(C_INT), intent(INOUT) :: array(:)
        integer(C_INT) :: SH_sizein
        ! splicer begin function.increment_int_array
        SH_sizein = size(array,kind=C_INT)
        call c_increment_int_array(array, SH_sizein)
        ! splicer end function.increment_int_array
    end subroutine increment_int_array

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module pointers_mod
