! wrapfcdesc.f
! This file is generated by Shroud 0.12.0. Do not edit.
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfcdesc.f
!! \brief Shroud generated wrapper for cdesc library
!<
! splicer begin file_top
! splicer end file_top
module cdesc_mod
    use iso_c_binding, only : C_INT, C_LONG, C_NULL_PTR, C_PTR, C_SIZE_T
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    ! helper ShroudTypeDefines
    ! Shroud type defines from helper ShroudTypeDefines
    integer, parameter, private :: &
        SH_TYPE_SIGNED_CHAR= 1, &
        SH_TYPE_SHORT      = 2, &
        SH_TYPE_INT        = 3, &
        SH_TYPE_LONG       = 4, &
        SH_TYPE_LONG_LONG  = 5, &
        SH_TYPE_SIZE_T     = 6, &
        SH_TYPE_UNSIGNED_SHORT      = SH_TYPE_SHORT + 100, &
        SH_TYPE_UNSIGNED_INT        = SH_TYPE_INT + 100, &
        SH_TYPE_UNSIGNED_LONG       = SH_TYPE_LONG + 100, &
        SH_TYPE_UNSIGNED_LONG_LONG  = SH_TYPE_LONG_LONG + 100, &
        SH_TYPE_INT8_T    =  7, &
        SH_TYPE_INT16_T   =  8, &
        SH_TYPE_INT32_T   =  9, &
        SH_TYPE_INT64_T   = 10, &
        SH_TYPE_UINT8_T  =  SH_TYPE_INT8_T + 100, &
        SH_TYPE_UINT16_T =  SH_TYPE_INT16_T + 100, &
        SH_TYPE_UINT32_T =  SH_TYPE_INT32_T + 100, &
        SH_TYPE_UINT64_T =  SH_TYPE_INT64_T + 100, &
        SH_TYPE_FLOAT       = 22, &
        SH_TYPE_DOUBLE      = 23, &
        SH_TYPE_LONG_DOUBLE = 24, &
        SH_TYPE_FLOAT_COMPLEX      = 25, &
        SH_TYPE_DOUBLE_COMPLEX     = 26, &
        SH_TYPE_LONG_DOUBLE_COMPLEX= 27, &
        SH_TYPE_BOOL      = 28, &
        SH_TYPE_CHAR      = 29, &
        SH_TYPE_CPTR      = 30, &
        SH_TYPE_STRUCT    = 31, &
        SH_TYPE_OTHER     = 32

    ! helper capsule_data_helper
    type, bind(C) :: SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type SHROUD_capsule_data

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
        integer(C_LONG) :: shape(7) = 0
    end type SHROUD_array

    interface

        ! ----------------------------------------
        ! Function:  void Rank2In
        ! Requested: c_void_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  int * arg +cdesc+context(Darg)+intent(in)+rank(2)
        ! Requested: c_native_*_in_cdesc
        ! Match:     c_native_*_cdesc
        subroutine c_rank2_in(Darg) &
                bind(C, name="CDE_rank2_in")
            import :: SHROUD_array
            implicit none
            type(SHROUD_array), intent(INOUT) :: Darg
        end subroutine c_rank2_in

        ! ----------------------------------------
        ! Function:  void GetScalar1
        ! Requested: c_void_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  std::string & name +intent(in)
        ! Requested: c_string_&_in
        ! Match:     c_string_in
        ! ----------------------------------------
        ! Argument:  void * value +cdesc+context(Dvalue)+intent(out)+rank(0)+value
        ! Requested: c_void_*_out_cdesc
        ! Match:     c_void_*_cdesc
        subroutine c_get_scalar1(name, Dvalue) &
                bind(C, name="CDE_get_scalar1")
            use iso_c_binding, only : C_CHAR
            import :: SHROUD_array
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            type(SHROUD_array), intent(INOUT) :: Dvalue
        end subroutine c_get_scalar1

        ! ----------------------------------------
        ! Function:  void GetScalar1
        ! Requested: c_void_scalar_result_buf
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  std::string & name +intent(in)+len_trim(Lname)
        ! Requested: c_string_&_in_buf
        ! Match:     c_string_in_buf
        ! ----------------------------------------
        ! Argument:  void * value +cdesc+context(Dvalue)+intent(out)+rank(0)+value
        ! Requested: c_void_*_out_buf_cdesc
        ! Match:     c_void_*_cdesc
        subroutine c_get_scalar1_bufferify(name, Lname, Dvalue) &
                bind(C, name="CDE_get_scalar1_bufferify")
            use iso_c_binding, only : C_CHAR, C_INT
            import :: SHROUD_array
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            integer(C_INT), value, intent(IN) :: Lname
            type(SHROUD_array), intent(INOUT) :: Dvalue
        end subroutine c_get_scalar1_bufferify

        ! ----------------------------------------
        ! Function:  int getData
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        function c_get_data_int() &
                result(SHT_rv) &
                bind(C, name="CDE_get_data_int")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT) :: SHT_rv
        end function c_get_data_int

        ! ----------------------------------------
        ! Function:  double getData
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        function c_get_data_double() &
                result(SHT_rv) &
                bind(C, name="CDE_get_data_double")
            use iso_c_binding, only : C_DOUBLE
            implicit none
            real(C_DOUBLE) :: SHT_rv
        end function c_get_data_double

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface get_scalar1
        module procedure get_scalar1_0
        module procedure get_scalar1_1
    end interface get_scalar1

    interface get_scalar2
        module procedure get_scalar2_0
        module procedure get_scalar2_1
    end interface get_scalar2

contains

    ! ----------------------------------------
    ! Function:  void Rank2In
    ! void Rank2In
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  int * arg +cdesc+context(Darg)+intent(in)+rank(2)
    ! Exact:     f_native_*_in_cdesc
    ! Requested: c_native_*_in_cdesc
    ! Match:     c_native_*_cdesc
    subroutine rank2_in(arg)
        use iso_c_binding, only : C_INT, C_LOC
        integer(C_INT), intent(IN), target :: arg(:,:)
        type(SHROUD_array) :: Darg
        ! splicer begin function.rank2_in
        Darg%base_addr = C_LOC(arg)
        Darg%type = SH_TYPE_INT
        ! Darg%elem_len = C_SIZEOF()
        Darg%size = size(arg)
        Darg%rank = 2
        Darg%shape(1:2) = shape(arg)
        call c_rank2_in(Darg)
        ! splicer end function.rank2_in
    end subroutine rank2_in

    ! Generated by fortran_generic - arg_to_buffer
    ! ----------------------------------------
    ! Function:  void GetScalar1
    ! void GetScalar1
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  std::string & name +intent(in)
    ! Requested: f_string_&_in
    ! Match:     f_default
    ! Argument:  std::string & name +intent(in)+len_trim(Lname)
    ! Requested: c_string_&_in_buf
    ! Match:     c_string_in_buf
    ! ----------------------------------------
    ! Argument:  int * value +cdesc+context(Dvalue)+intent(out)+rank(0)
    ! Exact:     f_native_*_out_cdesc
    ! Argument:  void * value +cdesc+context(Dvalue)+intent(out)+rank(0)+value
    ! Requested: c_void_*_out_buf_cdesc
    ! Match:     c_void_*_cdesc
    !>
    !! Create several Fortran generic functions which call a single
    !! C wrapper that checkes the type of the Fortran argument
    !! and calls the correct templated function.
    !! Adding the string argument forces a bufferified function
    !! to be create.
    !! XXX The non-bufferified version should not be created since
    !! users will not manually create a context struct.
    !<
    subroutine get_scalar1_0(name, value)
        use iso_c_binding, only : C_INT, C_LOC
        character(len=*), intent(IN) :: name
        integer(C_INT), intent(OUT), target :: value
        type(SHROUD_array) :: Dvalue
        ! splicer begin function.get_scalar1_0
        Dvalue%base_addr = C_LOC(value)
        Dvalue%type = SH_TYPE_INT
        ! Dvalue%elem_len = C_SIZEOF()
        Dvalue%size = 1
        Dvalue%rank = 0
        Dvalue%shape(1:0) = shape(value)
        call c_get_scalar1_bufferify(name, len_trim(name, kind=C_INT), &
            Dvalue)
        ! splicer end function.get_scalar1_0
    end subroutine get_scalar1_0

    ! Generated by fortran_generic - arg_to_buffer
    ! ----------------------------------------
    ! Function:  void GetScalar1
    ! void GetScalar1
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  std::string & name +intent(in)
    ! Requested: f_string_&_in
    ! Match:     f_default
    ! Argument:  std::string & name +intent(in)+len_trim(Lname)
    ! Requested: c_string_&_in_buf
    ! Match:     c_string_in_buf
    ! ----------------------------------------
    ! Argument:  double * value +cdesc+context(Dvalue)+intent(out)+rank(0)
    ! Exact:     f_native_*_out_cdesc
    ! Argument:  void * value +cdesc+context(Dvalue)+intent(out)+rank(0)+value
    ! Requested: c_void_*_out_buf_cdesc
    ! Match:     c_void_*_cdesc
    !>
    !! Create several Fortran generic functions which call a single
    !! C wrapper that checkes the type of the Fortran argument
    !! and calls the correct templated function.
    !! Adding the string argument forces a bufferified function
    !! to be create.
    !! XXX The non-bufferified version should not be created since
    !! users will not manually create a context struct.
    !<
    subroutine get_scalar1_1(name, value)
        use iso_c_binding, only : C_DOUBLE, C_INT, C_LOC
        character(len=*), intent(IN) :: name
        real(C_DOUBLE), intent(OUT), target :: value
        type(SHROUD_array) :: Dvalue
        ! splicer begin function.get_scalar1_1
        Dvalue%base_addr = C_LOC(value)
        Dvalue%type = SH_TYPE_DOUBLE
        ! Dvalue%elem_len = C_SIZEOF()
        Dvalue%size = 1
        Dvalue%rank = 0
        Dvalue%shape(1:0) = shape(value)
        call c_get_scalar1_bufferify(name, len_trim(name, kind=C_INT), &
            Dvalue)
        ! splicer end function.get_scalar1_1
    end subroutine get_scalar1_1

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  int getData
    ! int getData
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result
    ! Match:     c_default
    !>
    !! Wrapper for function which is templated on the return value.
    !<
    function get_data_int() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT) :: SHT_rv
        ! splicer begin function.get_data_int
        SHT_rv = c_get_data_int()
        ! splicer end function.get_data_int
    end function get_data_int

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  double getData
    ! double getData
    ! Requested: f_native_scalar_result
    ! Match:     f_default
    ! Requested: c_native_scalar_result
    ! Match:     c_default
    !>
    !! Wrapper for function which is templated on the return value.
    !<
    function get_data_double() &
            result(SHT_rv)
        use iso_c_binding, only : C_DOUBLE
        real(C_DOUBLE) :: SHT_rv
        ! splicer begin function.get_data_double
        SHT_rv = c_get_data_double()
        ! splicer end function.get_data_double
    end function get_data_double

    ! Generated by fortran_generic
    ! ----------------------------------------
    ! Function:  void GetScalar2
    ! void GetScalar2
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  std::string & name +intent(in)
    ! Requested: f_string_&_in
    ! Match:     f_default
    ! Requested: c_string_&_in
    ! Match:     c_string_in
    ! ----------------------------------------
    ! Argument:  int * value +intent(out)
    ! Requested: f_native_*_out
    ! Match:     f_default
    ! Argument:  void * value +intent(out)+value
    ! Requested: c_void_*_out
    ! Match:     c_default
    !>
    !! Call a C++ function which is templated on the return value.
    !! Create a Fortran function with the result passed in as an
    !! argument.  Change the function call clause to directly call the
    !! wrapped templated function.  fstatements is required instead of
    !! splicer in order to get {stype} expanded.
    !<
    subroutine get_scalar2_0(name, value)
        use iso_c_binding, only : C_INT
        character(len=*), intent(IN) :: name
        integer(C_INT), intent(OUT) :: value
        ! splicer begin function.get_scalar2_0
        value = c_get_data_int()
        ! splicer end function.get_scalar2_0
    end subroutine get_scalar2_0

    ! Generated by fortran_generic
    ! ----------------------------------------
    ! Function:  void GetScalar2
    ! void GetScalar2
    ! Requested: f_subroutine
    ! Match:     f_default
    ! Requested: c
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  std::string & name +intent(in)
    ! Requested: f_string_&_in
    ! Match:     f_default
    ! Requested: c_string_&_in
    ! Match:     c_string_in
    ! ----------------------------------------
    ! Argument:  double * value +intent(out)
    ! Requested: f_native_*_out
    ! Match:     f_default
    ! Argument:  void * value +intent(out)+value
    ! Requested: c_void_*_out
    ! Match:     c_default
    !>
    !! Call a C++ function which is templated on the return value.
    !! Create a Fortran function with the result passed in as an
    !! argument.  Change the function call clause to directly call the
    !! wrapped templated function.  fstatements is required instead of
    !! splicer in order to get {stype} expanded.
    !<
    subroutine get_scalar2_1(name, value)
        use iso_c_binding, only : C_DOUBLE
        character(len=*), intent(IN) :: name
        real(C_DOUBLE), intent(OUT) :: value
        ! splicer begin function.get_scalar2_1
        value = c_get_data_double()
        ! splicer end function.get_scalar2_1
    end subroutine get_scalar2_1

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module cdesc_mod
