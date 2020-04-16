! wrapfvectors.f
! This file is generated by Shroud 0.11.0. Do not edit.
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfvectors.f
!! \brief Shroud generated wrapper for vectors library
!<
! splicer begin file_top
! splicer end file_top
module vectors_mod
    use iso_c_binding, only : C_INT, C_NULL_PTR, C_PTR, C_SIZE_T
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    ! helper capsule_data_helper
    type, bind(C) :: SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_capsule_data

    ! start array_context
    ! helper array_context
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
        ! number of dimensions
        integer(C_INT) :: rank = -1
    end type SHROUD_array
    ! end array_context

    ! ----------------------------------------
    ! Result
    ! Requested: c_native_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: c_vector_&_in_buf_native
    ! Match:     c_vector_in_buf
    ! start c_vector_sum_bufferify
    interface
        function c_vector_sum_bufferify(arg, Sarg) &
                result(SHT_rv) &
                bind(C, name="VEC_vector_sum_bufferify")
            use iso_c_binding, only : C_INT, C_LONG
            implicit none
            integer(C_INT), intent(IN) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
            integer(C_INT) :: SHT_rv
        end function c_vector_sum_bufferify
    end interface
    ! end c_vector_sum_bufferify

    ! ----------------------------------------
    ! Result
    ! Requested: c_unknown_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: c_vector_&_out_buf_native
    ! Match:     c_vector_out_buf
    ! start c_vector_iota_out_bufferify
    interface
        subroutine c_vector_iota_out_bufferify(Darg) &
                bind(C, name="VEC_vector_iota_out_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(INOUT) :: Darg
        end subroutine c_vector_iota_out_bufferify
    end interface
    ! end c_vector_iota_out_bufferify

    ! ----------------------------------------
    ! Result
    ! Requested: c_unknown_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: c_vector_&_out_buf_native
    ! Match:     c_vector_out_buf
    ! start c_vector_iota_out_with_num_bufferify
    interface
        function c_vector_iota_out_with_num_bufferify(Darg) &
                result(SHT_rv) &
                bind(C, name="VEC_vector_iota_out_with_num_bufferify")
            use iso_c_binding, only : C_LONG
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(INOUT) :: Darg
            integer(C_LONG) SHT_rv
        end function c_vector_iota_out_with_num_bufferify
    end interface
    ! end c_vector_iota_out_with_num_bufferify

    ! ----------------------------------------
    ! Result
    ! Requested: c_unknown_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: c_vector_&_out_buf_native
    ! Match:     c_vector_out_buf
    ! start c_vector_iota_out_with_num2_bufferify
    interface
        subroutine c_vector_iota_out_with_num2_bufferify(Darg) &
                bind(C, name="VEC_vector_iota_out_with_num2_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(INOUT) :: Darg
        end subroutine c_vector_iota_out_with_num2_bufferify
    end interface
    ! end c_vector_iota_out_with_num2_bufferify

    ! ----------------------------------------
    ! Result
    ! Requested: c_unknown_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: c_vector_&_out_buf_allocatable_native
    ! Match:     c_vector_out_buf
    ! start c_vector_iota_out_alloc_bufferify
    interface
        subroutine c_vector_iota_out_alloc_bufferify(Darg) &
                bind(C, name="VEC_vector_iota_out_alloc_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(INOUT) :: Darg
        end subroutine c_vector_iota_out_alloc_bufferify
    end interface
    ! end c_vector_iota_out_alloc_bufferify

    ! ----------------------------------------
    ! Result
    ! Requested: c_unknown_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: c_vector_&_inout_buf_allocatable_native
    ! Match:     c_vector_inout_buf
    ! start c_vector_iota_inout_alloc_bufferify
    interface
        subroutine c_vector_iota_inout_alloc_bufferify(arg, Sarg, Darg) &
                bind(C, name="VEC_vector_iota_inout_alloc_bufferify")
            use iso_c_binding, only : C_INT, C_LONG
            import :: SHROUD_array
            implicit none
            integer(C_INT), intent(INOUT) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
            type(SHROUD_array), intent(INOUT) :: Darg
        end subroutine c_vector_iota_inout_alloc_bufferify
    end interface
    ! end c_vector_iota_inout_alloc_bufferify

    ! ----------------------------------------
    ! Result
    ! Requested: c_unknown_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: c_vector_&_inout_buf_native
    ! Match:     c_vector_inout_buf
    interface
        subroutine c_vector_increment_bufferify(arg, Sarg, Darg) &
                bind(C, name="VEC_vector_increment_bufferify")
            use iso_c_binding, only : C_INT, C_LONG
            import :: SHROUD_array
            implicit none
            integer(C_INT), intent(INOUT) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
            type(SHROUD_array), intent(INOUT) :: Darg
        end subroutine c_vector_increment_bufferify
    end interface

    ! ----------------------------------------
    ! Result
    ! Requested: c_unknown_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: c_vector_&_out_buf_native
    ! Match:     c_vector_out_buf
    interface
        subroutine c_vector_iota_out_d_bufferify(Darg) &
                bind(C, name="VEC_vector_iota_out_d_bufferify")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(INOUT) :: Darg
        end subroutine c_vector_iota_out_d_bufferify
    end interface

    ! ----------------------------------------
    ! Result
    ! Requested: c_native_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: c_vector_&_in_buf_string
    ! Match:     c_vector_in_buf_string
    interface
        function c_vector_string_count_bufferify(arg, Sarg, Narg) &
                result(SHT_rv) &
                bind(C, name="VEC_vector_string_count_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT, C_LONG
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg(*)
            integer(C_LONG), value, intent(IN) :: Sarg
            integer(C_INT), value, intent(IN) :: Narg
            integer(C_INT) :: SHT_rv
        end function c_vector_string_count_bufferify
    end interface

    ! ----------------------------------------
    ! Result
    ! Requested: c_unknown_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  n
    ! Requested: c_native_scalar_in_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  SHF_rv
    ! Requested: c_vector_*_result_buf_allocatable_native
    ! Match:     c_vector_result_buf
    interface
        subroutine c_return_vector_alloc_bufferify(n, DSHF_rv) &
                bind(C, name="VEC_return_vector_alloc_bufferify")
            use iso_c_binding, only : C_INT
            import :: SHROUD_array
            implicit none
            integer(C_INT), value, intent(IN) :: n
            type(SHROUD_array), intent(OUT) :: DSHF_rv
        end subroutine c_return_vector_alloc_bufferify
    end interface

    interface
        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface
        ! helper copy_array_double
        ! Copy contents of context into c_var.
        subroutine SHROUD_copy_array_double(context, c_var, c_var_size) &
            bind(C, name="VEC_ShroudCopyArray")
            use iso_c_binding, only : C_DOUBLE, C_SIZE_T
            import SHROUD_array
            type(SHROUD_array), intent(IN) :: context
            real(C_DOUBLE), intent(OUT) :: c_var(*)
            integer(C_SIZE_T), value :: c_var_size
        end subroutine SHROUD_copy_array_double
    end interface

    interface
        ! helper copy_array_int
        ! Copy contents of context into c_var.
        subroutine SHROUD_copy_array_int(context, c_var, c_var_size) &
            bind(C, name="VEC_ShroudCopyArray")
            use iso_c_binding, only : C_INT, C_SIZE_T
            import SHROUD_array
            type(SHROUD_array), intent(IN) :: context
            integer(C_INT), intent(OUT) :: c_var(*)
            integer(C_SIZE_T), value :: c_var_size
        end subroutine SHROUD_copy_array_int
    end interface

contains

    ! int vector_sum(const std::vector<int> & arg +dimension(:)+intent(in))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: f_vector_&_in_native
    ! Match:     f_default
    ! Requested: c_vector_&_in_buf_native
    ! Match:     c_vector_in_buf
    ! start vector_sum
    function vector_sum(arg) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, C_LONG
        integer(C_INT), intent(IN) :: arg(:)
        integer(C_INT) :: SHT_rv
        ! splicer begin function.vector_sum
        SHT_rv = c_vector_sum_bufferify(arg, size(arg, kind=C_LONG))
        ! splicer end function.vector_sum
    end function vector_sum
    ! end vector_sum

    ! void vector_iota_out(std::vector<int> & arg +dimension(:)+intent(out))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: f_vector_&_out_native
    ! Match:     f_vector_out
    ! Requested: c_vector_&_out_buf_native
    ! Match:     c_vector_out_buf
    !>
    !! \brief Copy vector into Fortran input array
    !!
    !<
    ! start vector_iota_out
    subroutine vector_iota_out(arg)
        use iso_c_binding, only : C_INT, C_SIZE_T
        integer(C_INT), intent(OUT) :: arg(:)
        type(SHROUD_array) :: Darg
        ! splicer begin function.vector_iota_out
        call c_vector_iota_out_bufferify(Darg)
        call SHROUD_copy_array_int(Darg, arg, size(arg,kind=C_SIZE_T))
        ! splicer end function.vector_iota_out
    end subroutine vector_iota_out
    ! end vector_iota_out

    ! void vector_iota_out_with_num(std::vector<int> & arg +dimension(:)+intent(out))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: f_vector_&_out_native
    ! Match:     f_vector_out
    ! Requested: c_vector_&_out_buf_native
    ! Match:     c_vector_out_buf
    !>
    !! \brief Copy vector into Fortran input array
    !!
    !! Return the number of items copied into argument
    !! by setting fstatements for both C and Fortran.
    !<
    ! start vector_iota_out_with_num
    function vector_iota_out_with_num(arg) &
            result(num)
        use iso_c_binding, only : C_INT, C_LONG, C_SIZE_T
        integer(C_INT), intent(OUT) :: arg(:)
        type(SHROUD_array) :: Darg
        ! splicer begin function.vector_iota_out_with_num
        integer(C_LONG) :: num
        num = c_vector_iota_out_with_num_bufferify(Darg)
        call SHROUD_copy_array_int(Darg, arg, size(arg,kind=C_SIZE_T))
        ! splicer end function.vector_iota_out_with_num
    end function vector_iota_out_with_num
    ! end vector_iota_out_with_num

    ! void vector_iota_out_with_num2(std::vector<int> & arg +dimension(:)+intent(out))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: f_vector_&_out_native
    ! Match:     f_vector_out
    ! Requested: c_vector_&_out_buf_native
    ! Match:     c_vector_out_buf
    !>
    !! \brief Copy vector into Fortran input array
    !!
    !! Return the number of items copied into argument
    !! by setting fstatements for the Fortran wrapper only.
    !<
    ! start vector_iota_out_with_num2
    function vector_iota_out_with_num2(arg) &
            result(num)
        use iso_c_binding, only : C_INT, C_LONG, C_SIZE_T
        integer(C_INT), intent(OUT) :: arg(:)
        type(SHROUD_array) :: Darg
        ! splicer begin function.vector_iota_out_with_num2
        integer(C_LONG) :: num
        call c_vector_iota_out_with_num2_bufferify(Darg)
        call SHROUD_copy_array_int(Darg, arg, size(arg,kind=C_SIZE_T))
        num = Darg%size
        ! splicer end function.vector_iota_out_with_num2
    end function vector_iota_out_with_num2
    ! end vector_iota_out_with_num2

    ! void vector_iota_out_alloc(std::vector<int> & arg +deref(allocatable)+dimension(:)+intent(out))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: f_vector_&_out_allocatable_native
    ! Match:     f_vector_out_allocatable
    ! Requested: c_vector_&_out_buf_native
    ! Match:     c_vector_out_buf
    !>
    !! \brief Copy vector into Fortran allocatable array
    !!
    !<
    ! start vector_iota_out_alloc
    subroutine vector_iota_out_alloc(arg)
        use iso_c_binding, only : C_INT, C_SIZE_T
        integer(C_INT), intent(OUT), allocatable :: arg(:)
        type(SHROUD_array) :: Darg
        ! splicer begin function.vector_iota_out_alloc
        call c_vector_iota_out_alloc_bufferify(Darg)
        allocate(arg(Darg%size))
        call SHROUD_copy_array_int(Darg, arg, size(arg,kind=C_SIZE_T))
        ! splicer end function.vector_iota_out_alloc
    end subroutine vector_iota_out_alloc
    ! end vector_iota_out_alloc

    ! void vector_iota_inout_alloc(std::vector<int> & arg +deref(allocatable)+dimension(:)+intent(inout))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: f_vector_&_inout_allocatable_native
    ! Match:     f_vector_inout_allocatable
    ! Requested: c_vector_&_inout_buf_native
    ! Match:     c_vector_inout_buf
    !>
    !! \brief Copy vector into Fortran allocatable array
    !!
    !<
    ! start vector_iota_inout_alloc
    subroutine vector_iota_inout_alloc(arg)
        use iso_c_binding, only : C_INT, C_LONG, C_SIZE_T
        integer(C_INT), intent(INOUT), allocatable :: arg(:)
        type(SHROUD_array) :: Darg
        ! splicer begin function.vector_iota_inout_alloc
        call c_vector_iota_inout_alloc_bufferify(arg, &
            size(arg, kind=C_LONG), Darg)
        if (allocated(arg)) deallocate(arg)
        allocate(arg(Darg%size))
        call SHROUD_copy_array_int(Darg, arg, size(arg,kind=C_SIZE_T))
        ! splicer end function.vector_iota_inout_alloc
    end subroutine vector_iota_inout_alloc
    ! end vector_iota_inout_alloc

    ! void vector_increment(std::vector<int> & arg +dimension(:)+intent(inout))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: f_vector_&_inout_native
    ! Match:     f_vector_inout
    ! Requested: c_vector_&_inout_buf_native
    ! Match:     c_vector_inout_buf
    subroutine vector_increment(arg)
        use iso_c_binding, only : C_INT, C_LONG, C_SIZE_T
        integer(C_INT), intent(INOUT) :: arg(:)
        type(SHROUD_array) :: Darg
        ! splicer begin function.vector_increment
        call c_vector_increment_bufferify(arg, size(arg, kind=C_LONG), &
            Darg)
        call SHROUD_copy_array_int(Darg, arg, size(arg,kind=C_SIZE_T))
        ! splicer end function.vector_increment
    end subroutine vector_increment

    ! void vector_iota_out_d(std::vector<double> & arg +dimension(:)+intent(out))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: f_vector_&_out_native
    ! Match:     f_vector_out
    ! Requested: c_vector_&_out_buf_native
    ! Match:     c_vector_out_buf
    !>
    !! \brief Copy vector into Fortran input array
    !!
    !<
    subroutine vector_iota_out_d(arg)
        use iso_c_binding, only : C_DOUBLE, C_SIZE_T
        real(C_DOUBLE), intent(OUT) :: arg(:)
        type(SHROUD_array) :: Darg
        ! splicer begin function.vector_iota_out_d
        call c_vector_iota_out_d_bufferify(Darg)
        call SHROUD_copy_array_double(Darg, arg, size(arg,kind=C_SIZE_T))
        ! splicer end function.vector_iota_out_d
    end subroutine vector_iota_out_d

    ! int vector_string_count(const std::vector<std::string> & arg +dimension(:)+intent(in))
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  arg
    ! Requested: f_vector_&_in_string
    ! Match:     f_default
    ! Requested: c_vector_&_in_buf_string
    ! Match:     c_vector_in_buf_string
    !>
    !! \brief count number of underscore in vector of strings
    !!
    !<
    function vector_string_count(arg) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, C_LONG
        character(len=*), intent(IN) :: arg(:)
        integer(C_INT) :: SHT_rv
        ! splicer begin function.vector_string_count
        SHT_rv = c_vector_string_count_bufferify(arg, &
            size(arg, kind=C_LONG), len(arg, kind=C_INT))
        ! splicer end function.vector_string_count
    end function vector_string_count

    ! std::vector<int> ReturnVectorAlloc(int n +intent(in)+value) +deref(allocatable)+dimension(:)
    ! arg_to_buffer
    ! ----------------------------------------
    ! Result
    ! Requested: f_vector_scalar_result_allocatable
    ! Match:     f_vector_result_allocatable
    ! Requested: c_vector_scalar_result_buf
    ! Match:     c_vector_result_buf
    ! ----------------------------------------
    ! Argument:  n
    ! Requested: f_native_scalar_in
    ! Match:     f_default
    ! Requested: c_native_scalar_in_buf
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  SHF_rv
    ! Requested: f_vector_*_result_allocatable_native
    ! Match:     f_vector_result_allocatable
    ! Requested: c_vector_*_result_buf_allocatable_native
    ! Match:     c_vector_result_buf
    !>
    !! Implement iota function.
    !! Return a vector as an ALLOCATABLE array.
    !! Copy results into the new array.
    !<
    function return_vector_alloc(n) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, C_SIZE_T
        integer(C_INT), value, intent(IN) :: n
        type(SHROUD_array) :: DSHF_rv
        integer(C_INT), allocatable :: SHT_rv(:)
        ! splicer begin function.return_vector_alloc
        call c_return_vector_alloc_bufferify(n, DSHF_rv)
        allocate(SHT_rv(DSHF_rv%size))
        call SHROUD_copy_array_int(DSHF_rv, SHT_rv, size(SHT_rv,kind=C_SIZE_T))
        ! splicer end function.return_vector_alloc
    end function return_vector_alloc

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module vectors_mod
