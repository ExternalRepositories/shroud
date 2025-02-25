! wrapftemplates.f
! This file is generated by Shroud nowrite-version. Do not edit.
! Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapftemplates.f
!! \brief Shroud generated wrapper for templates library
!<
! splicer begin file_top
! splicer end file_top
module templates_mod
    use iso_c_binding, only : C_INT, C_NULL_PTR, C_PTR
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    ! helper capsule_data_helper
    type, bind(C) :: TEM_SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type TEM_SHROUD_capsule_data

    type worker
        type(TEM_SHROUD_capsule_data) :: cxxmem
        ! splicer begin class.Worker.component_part
        ! splicer end class.Worker.component_part
    contains
        procedure :: get_instance => worker_get_instance
        procedure :: set_instance => worker_set_instance
        procedure :: associated => worker_associated
        ! splicer begin class.Worker.type_bound_procedure_part
        ! splicer end class.Worker.type_bound_procedure_part
    end type worker

    type user_int
        type(TEM_SHROUD_capsule_data) :: cxxmem
        ! splicer begin class.user_int.component_part
        ! splicer end class.user_int.component_part
    contains
        procedure :: nested_double => user_int_nested_double
        procedure :: get_instance => user_int_get_instance
        procedure :: set_instance => user_int_set_instance
        procedure :: associated => user_int_associated
        ! splicer begin class.user_int.type_bound_procedure_part
        ! splicer end class.user_int.type_bound_procedure_part
    end type user_int

    type structasclass_int
        type(TEM_SHROUD_capsule_data) :: cxxmem
        ! splicer begin class.structAsClass_int.component_part
        ! splicer end class.structAsClass_int.component_part
    contains
        procedure :: set_npts => structasclass_int_set_npts
        procedure :: get_npts => structasclass_int_get_npts
        procedure :: set_value => structasclass_int_set_value
        procedure :: get_value => structasclass_int_get_value
        procedure :: get_instance => structasclass_int_get_instance
        procedure :: set_instance => structasclass_int_set_instance
        procedure :: associated => structasclass_int_associated
        ! splicer begin class.structAsClass_int.type_bound_procedure_part
        ! splicer end class.structAsClass_int.type_bound_procedure_part
    end type structasclass_int

    type structasclass_double
        type(TEM_SHROUD_capsule_data) :: cxxmem
        ! splicer begin class.structAsClass_double.component_part
        ! splicer end class.structAsClass_double.component_part
    contains
        procedure :: set_npts => structasclass_double_set_npts
        procedure :: get_npts => structasclass_double_get_npts
        procedure :: set_value => structasclass_double_set_value
        procedure :: get_value => structasclass_double_get_value
        procedure :: get_instance => structasclass_double_get_instance
        procedure :: set_instance => structasclass_double_set_instance
        procedure :: associated => structasclass_double_associated
        ! splicer begin class.structAsClass_double.type_bound_procedure_part
        ! splicer end class.structAsClass_double.type_bound_procedure_part
    end type structasclass_double

    interface operator (.eq.)
        module procedure worker_eq
        module procedure user_int_eq
        module procedure structasclass_int_eq
        module procedure structasclass_double_eq
    end interface

    interface operator (.ne.)
        module procedure worker_ne
        module procedure user_int_ne
        module procedure structasclass_int_ne
        module procedure structasclass_double_ne
    end interface

    interface

        ! splicer begin class.Worker.additional_interfaces
        ! splicer end class.Worker.additional_interfaces

        ! ----------------------------------------
        ! Function:  void nested
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  int arg1 +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  double arg2 +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        subroutine c_user_int_nested_double(self, arg1, arg2) &
                bind(C, name="TEM_user_int_nested_double")
            use iso_c_binding, only : C_DOUBLE, C_INT
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: arg1
            real(C_DOUBLE), value, intent(IN) :: arg2
        end subroutine c_user_int_nested_double

        ! splicer begin class.user_int.additional_interfaces
        ! splicer end class.user_int.additional_interfaces

        ! ----------------------------------------
        ! Function:  structAsClass
        ! Attrs:     +intent(ctor)
        ! Exact:     c_function_shadow_scalar
        subroutine c_structasclass_int_ctor(SHT_rv) &
                bind(C, name="TEM_structAsClass_int_ctor")
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(OUT) :: SHT_rv
        end subroutine c_structasclass_int_ctor

        ! ----------------------------------------
        ! Function:  void set_npts
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  int n +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        subroutine c_structasclass_int_set_npts(self, n) &
                bind(C, name="TEM_structAsClass_int_set_npts")
            use iso_c_binding, only : C_INT
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: n
        end subroutine c_structasclass_int_set_npts

        ! ----------------------------------------
        ! Function:  int get_npts
        ! Attrs:     +intent(function)
        ! Requested: c_function_native_scalar
        ! Match:     c_function
        function c_structasclass_int_get_npts(self) &
                result(SHT_rv) &
                bind(C, name="TEM_structAsClass_int_get_npts")
            use iso_c_binding, only : C_INT
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT) :: SHT_rv
        end function c_structasclass_int_get_npts

        ! ----------------------------------------
        ! Function:  void set_value
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  int v +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        subroutine c_structasclass_int_set_value(self, v) &
                bind(C, name="TEM_structAsClass_int_set_value")
            use iso_c_binding, only : C_INT
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: v
        end subroutine c_structasclass_int_set_value

        ! ----------------------------------------
        ! Function:  int get_value
        ! Attrs:     +intent(function)
        ! Requested: c_function_native_scalar
        ! Match:     c_function
        function c_structasclass_int_get_value(self) &
                result(SHT_rv) &
                bind(C, name="TEM_structAsClass_int_get_value")
            use iso_c_binding, only : C_INT
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT) :: SHT_rv
        end function c_structasclass_int_get_value

        ! splicer begin class.structAsClass_int.additional_interfaces
        ! splicer end class.structAsClass_int.additional_interfaces

        ! ----------------------------------------
        ! Function:  structAsClass
        ! Attrs:     +intent(ctor)
        ! Exact:     c_function_shadow_scalar
        subroutine c_structasclass_double_ctor(SHT_rv) &
                bind(C, name="TEM_structAsClass_double_ctor")
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(OUT) :: SHT_rv
        end subroutine c_structasclass_double_ctor

        ! ----------------------------------------
        ! Function:  void set_npts
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  int n +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        subroutine c_structasclass_double_set_npts(self, n) &
                bind(C, name="TEM_structAsClass_double_set_npts")
            use iso_c_binding, only : C_INT
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT), value, intent(IN) :: n
        end subroutine c_structasclass_double_set_npts

        ! ----------------------------------------
        ! Function:  int get_npts
        ! Attrs:     +intent(function)
        ! Requested: c_function_native_scalar
        ! Match:     c_function
        function c_structasclass_double_get_npts(self) &
                result(SHT_rv) &
                bind(C, name="TEM_structAsClass_double_get_npts")
            use iso_c_binding, only : C_INT
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT) :: SHT_rv
        end function c_structasclass_double_get_npts

        ! ----------------------------------------
        ! Function:  void set_value
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  double v +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        subroutine c_structasclass_double_set_value(self, v) &
                bind(C, name="TEM_structAsClass_double_set_value")
            use iso_c_binding, only : C_DOUBLE
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(IN) :: self
            real(C_DOUBLE), value, intent(IN) :: v
        end subroutine c_structasclass_double_set_value

        ! ----------------------------------------
        ! Function:  double get_value
        ! Attrs:     +intent(function)
        ! Requested: c_function_native_scalar
        ! Match:     c_function
        function c_structasclass_double_get_value(self) &
                result(SHT_rv) &
                bind(C, name="TEM_structAsClass_double_get_value")
            use iso_c_binding, only : C_DOUBLE
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(IN) :: self
            real(C_DOUBLE) :: SHT_rv
        end function c_structasclass_double_get_value

        ! splicer begin class.structAsClass_double.additional_interfaces
        ! splicer end class.structAsClass_double.additional_interfaces

        ! ----------------------------------------
        ! Function:  user<int> returnUserType
        ! Attrs:     +intent(function)
        ! Exact:     c_function_shadow_scalar
        subroutine c_return_user_type(SHT_rv) &
                bind(C, name="TEM_return_user_type")
            import :: TEM_SHROUD_capsule_data
            implicit none
            type(TEM_SHROUD_capsule_data), intent(OUT) :: SHT_rv
        end subroutine c_return_user_type

        ! ----------------------------------------
        ! Function:  void FunctionTU
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  int arg1 +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  long arg2 +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        subroutine c_function_tu_0(arg1, arg2) &
                bind(C, name="TEM_function_tu_0")
            use iso_c_binding, only : C_INT, C_LONG
            implicit none
            integer(C_INT), value, intent(IN) :: arg1
            integer(C_LONG), value, intent(IN) :: arg2
        end subroutine c_function_tu_0

        ! ----------------------------------------
        ! Function:  void FunctionTU
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  float arg1 +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  double arg2 +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        subroutine c_function_tu_1(arg1, arg2) &
                bind(C, name="TEM_function_tu_1")
            use iso_c_binding, only : C_DOUBLE, C_FLOAT
            implicit none
            real(C_FLOAT), value, intent(IN) :: arg1
            real(C_DOUBLE), value, intent(IN) :: arg2
        end subroutine c_function_tu_1

        ! ----------------------------------------
        ! Function:  int UseImplWorker
        ! Attrs:     +intent(function)
        ! Requested: c_function_native_scalar
        ! Match:     c_function
        function c_use_impl_worker_internal_implworker1() &
                result(SHT_rv) &
                bind(C, name="TEM_use_impl_worker_internal_ImplWorker1")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT) :: SHT_rv
        end function c_use_impl_worker_internal_implworker1

        ! ----------------------------------------
        ! Function:  int UseImplWorker
        ! Attrs:     +intent(function)
        ! Requested: c_function_native_scalar
        ! Match:     c_function
        function c_use_impl_worker_internal_implworker2() &
                result(SHT_rv) &
                bind(C, name="TEM_use_impl_worker_internal_ImplWorker2")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT) :: SHT_rv
        end function c_use_impl_worker_internal_implworker2

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface function_tu
        module procedure function_tu_0
        module procedure function_tu_1
    end interface function_tu

    interface structasclass_double
        module procedure structasclass_double_ctor
    end interface structasclass_double

    interface structasclass_int
        module procedure structasclass_int_ctor
    end interface structasclass_int

contains

    ! Return pointer to C++ memory.
    function worker_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(worker), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function worker_get_instance

    subroutine worker_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(worker), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine worker_set_instance

    function worker_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(worker), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function worker_associated

    ! splicer begin class.Worker.additional_functions
    ! splicer end class.Worker.additional_functions

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  void nested
    ! Attrs:     +intent(subroutine)
    ! Exact:     f_subroutine
    ! Attrs:     +intent(subroutine)
    ! Exact:     c_subroutine
    ! ----------------------------------------
    ! Argument:  int arg1 +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  double arg2 +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    subroutine user_int_nested_double(obj, arg1, arg2)
        use iso_c_binding, only : C_DOUBLE, C_INT
        class(user_int) :: obj
        integer(C_INT), value, intent(IN) :: arg1
        real(C_DOUBLE), value, intent(IN) :: arg2
        ! splicer begin class.user_int.method.nested_double
        call c_user_int_nested_double(obj%cxxmem, arg1, arg2)
        ! splicer end class.user_int.method.nested_double
    end subroutine user_int_nested_double

    ! Return pointer to C++ memory.
    function user_int_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(user_int), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function user_int_get_instance

    subroutine user_int_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(user_int), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine user_int_set_instance

    function user_int_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(user_int), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function user_int_associated

    ! splicer begin class.user_int.additional_functions
    ! splicer end class.user_int.additional_functions

    ! ----------------------------------------
    ! Function:  structAsClass
    ! Attrs:     +intent(ctor)
    ! Exact:     f_ctor
    ! Attrs:     +intent(ctor)
    ! Exact:     c_ctor
    function structasclass_int_ctor() &
            result(SHT_rv)
        type(structasclass_int) :: SHT_rv
        ! splicer begin class.structAsClass_int.method.ctor
        call c_structasclass_int_ctor(SHT_rv%cxxmem)
        ! splicer end class.structAsClass_int.method.ctor
    end function structasclass_int_ctor

    ! ----------------------------------------
    ! Function:  void set_npts
    ! Attrs:     +intent(subroutine)
    ! Exact:     f_subroutine
    ! Attrs:     +intent(subroutine)
    ! Exact:     c_subroutine
    ! ----------------------------------------
    ! Argument:  int n +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    subroutine structasclass_int_set_npts(obj, n)
        use iso_c_binding, only : C_INT
        class(structasclass_int) :: obj
        integer(C_INT), value, intent(IN) :: n
        ! splicer begin class.structAsClass_int.method.set_npts
        call c_structasclass_int_set_npts(obj%cxxmem, n)
        ! splicer end class.structAsClass_int.method.set_npts
    end subroutine structasclass_int_set_npts

    ! ----------------------------------------
    ! Function:  int get_npts
    ! Attrs:     +intent(function)
    ! Requested: f_function_native_scalar
    ! Match:     f_function
    ! Attrs:     +intent(function)
    ! Requested: c_function_native_scalar
    ! Match:     c_function
    function structasclass_int_get_npts(obj) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        class(structasclass_int) :: obj
        integer(C_INT) :: SHT_rv
        ! splicer begin class.structAsClass_int.method.get_npts
        SHT_rv = c_structasclass_int_get_npts(obj%cxxmem)
        ! splicer end class.structAsClass_int.method.get_npts
    end function structasclass_int_get_npts

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  void set_value
    ! Attrs:     +intent(subroutine)
    ! Exact:     f_subroutine
    ! Attrs:     +intent(subroutine)
    ! Exact:     c_subroutine
    ! ----------------------------------------
    ! Argument:  int v +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    subroutine structasclass_int_set_value(obj, v)
        use iso_c_binding, only : C_INT
        class(structasclass_int) :: obj
        integer(C_INT), value, intent(IN) :: v
        ! splicer begin class.structAsClass_int.method.set_value
        call c_structasclass_int_set_value(obj%cxxmem, v)
        ! splicer end class.structAsClass_int.method.set_value
    end subroutine structasclass_int_set_value

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  int get_value
    ! Attrs:     +intent(function)
    ! Requested: f_function_native_scalar
    ! Match:     f_function
    ! Attrs:     +intent(function)
    ! Requested: c_function_native_scalar
    ! Match:     c_function
    function structasclass_int_get_value(obj) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        class(structasclass_int) :: obj
        integer(C_INT) :: SHT_rv
        ! splicer begin class.structAsClass_int.method.get_value
        SHT_rv = c_structasclass_int_get_value(obj%cxxmem)
        ! splicer end class.structAsClass_int.method.get_value
    end function structasclass_int_get_value

    ! Return pointer to C++ memory.
    function structasclass_int_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(structasclass_int), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function structasclass_int_get_instance

    subroutine structasclass_int_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(structasclass_int), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine structasclass_int_set_instance

    function structasclass_int_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(structasclass_int), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function structasclass_int_associated

    ! splicer begin class.structAsClass_int.additional_functions
    ! splicer end class.structAsClass_int.additional_functions

    ! ----------------------------------------
    ! Function:  structAsClass
    ! Attrs:     +intent(ctor)
    ! Exact:     f_ctor
    ! Attrs:     +intent(ctor)
    ! Exact:     c_ctor
    function structasclass_double_ctor() &
            result(SHT_rv)
        type(structasclass_double) :: SHT_rv
        ! splicer begin class.structAsClass_double.method.ctor
        call c_structasclass_double_ctor(SHT_rv%cxxmem)
        ! splicer end class.structAsClass_double.method.ctor
    end function structasclass_double_ctor

    ! ----------------------------------------
    ! Function:  void set_npts
    ! Attrs:     +intent(subroutine)
    ! Exact:     f_subroutine
    ! Attrs:     +intent(subroutine)
    ! Exact:     c_subroutine
    ! ----------------------------------------
    ! Argument:  int n +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    subroutine structasclass_double_set_npts(obj, n)
        use iso_c_binding, only : C_INT
        class(structasclass_double) :: obj
        integer(C_INT), value, intent(IN) :: n
        ! splicer begin class.structAsClass_double.method.set_npts
        call c_structasclass_double_set_npts(obj%cxxmem, n)
        ! splicer end class.structAsClass_double.method.set_npts
    end subroutine structasclass_double_set_npts

    ! ----------------------------------------
    ! Function:  int get_npts
    ! Attrs:     +intent(function)
    ! Requested: f_function_native_scalar
    ! Match:     f_function
    ! Attrs:     +intent(function)
    ! Requested: c_function_native_scalar
    ! Match:     c_function
    function structasclass_double_get_npts(obj) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        class(structasclass_double) :: obj
        integer(C_INT) :: SHT_rv
        ! splicer begin class.structAsClass_double.method.get_npts
        SHT_rv = c_structasclass_double_get_npts(obj%cxxmem)
        ! splicer end class.structAsClass_double.method.get_npts
    end function structasclass_double_get_npts

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  void set_value
    ! Attrs:     +intent(subroutine)
    ! Exact:     f_subroutine
    ! Attrs:     +intent(subroutine)
    ! Exact:     c_subroutine
    ! ----------------------------------------
    ! Argument:  double v +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    subroutine structasclass_double_set_value(obj, v)
        use iso_c_binding, only : C_DOUBLE
        class(structasclass_double) :: obj
        real(C_DOUBLE), value, intent(IN) :: v
        ! splicer begin class.structAsClass_double.method.set_value
        call c_structasclass_double_set_value(obj%cxxmem, v)
        ! splicer end class.structAsClass_double.method.set_value
    end subroutine structasclass_double_set_value

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  double get_value
    ! Attrs:     +intent(function)
    ! Requested: f_function_native_scalar
    ! Match:     f_function
    ! Attrs:     +intent(function)
    ! Requested: c_function_native_scalar
    ! Match:     c_function
    function structasclass_double_get_value(obj) &
            result(SHT_rv)
        use iso_c_binding, only : C_DOUBLE
        class(structasclass_double) :: obj
        real(C_DOUBLE) :: SHT_rv
        ! splicer begin class.structAsClass_double.method.get_value
        SHT_rv = c_structasclass_double_get_value(obj%cxxmem)
        ! splicer end class.structAsClass_double.method.get_value
    end function structasclass_double_get_value

    ! Return pointer to C++ memory.
    function structasclass_double_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(structasclass_double), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function structasclass_double_get_instance

    subroutine structasclass_double_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(structasclass_double), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine structasclass_double_set_instance

    function structasclass_double_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(structasclass_double), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function structasclass_double_associated

    ! splicer begin class.structAsClass_double.additional_functions
    ! splicer end class.structAsClass_double.additional_functions

    ! ----------------------------------------
    ! Function:  user<int> returnUserType
    ! Attrs:     +intent(function)
    ! Requested: f_function_shadow_scalar
    ! Match:     f_function_shadow
    ! Attrs:     +intent(function)
    ! Exact:     c_function_shadow_scalar
    function return_user_type() &
            result(SHT_rv)
        type(user_int) :: SHT_rv
        ! splicer begin function.return_user_type
        call c_return_user_type(SHT_rv%cxxmem)
        ! splicer end function.return_user_type
    end function return_user_type

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  void FunctionTU
    ! Attrs:     +intent(subroutine)
    ! Exact:     f_subroutine
    ! Attrs:     +intent(subroutine)
    ! Exact:     c_subroutine
    ! ----------------------------------------
    ! Argument:  int arg1 +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  long arg2 +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    !>
    !! \brief Function template with two template parameters.
    !!
    !<
    subroutine function_tu_0(arg1, arg2)
        use iso_c_binding, only : C_INT, C_LONG
        integer(C_INT), value, intent(IN) :: arg1
        integer(C_LONG), value, intent(IN) :: arg2
        ! splicer begin function.function_tu_0
        call c_function_tu_0(arg1, arg2)
        ! splicer end function.function_tu_0
    end subroutine function_tu_0

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  void FunctionTU
    ! Attrs:     +intent(subroutine)
    ! Exact:     f_subroutine
    ! Attrs:     +intent(subroutine)
    ! Exact:     c_subroutine
    ! ----------------------------------------
    ! Argument:  float arg1 +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  double arg2 +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    !>
    !! \brief Function template with two template parameters.
    !!
    !<
    subroutine function_tu_1(arg1, arg2)
        use iso_c_binding, only : C_DOUBLE, C_FLOAT
        real(C_FLOAT), value, intent(IN) :: arg1
        real(C_DOUBLE), value, intent(IN) :: arg2
        ! splicer begin function.function_tu_1
        call c_function_tu_1(arg1, arg2)
        ! splicer end function.function_tu_1
    end subroutine function_tu_1

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  int UseImplWorker
    ! Attrs:     +intent(function)
    ! Requested: f_function_native_scalar
    ! Match:     f_function
    ! Attrs:     +intent(function)
    ! Requested: c_function_native_scalar
    ! Match:     c_function
    !>
    !! \brief Function which uses a templated T in the implemetation.
    !!
    !<
    function use_impl_worker_internal_ImplWorker1() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT) :: SHT_rv
        ! splicer begin function.use_impl_worker_internal_ImplWorker1
        SHT_rv = c_use_impl_worker_internal_implworker1()
        ! splicer end function.use_impl_worker_internal_ImplWorker1
    end function use_impl_worker_internal_ImplWorker1

    ! Generated by cxx_template
    ! ----------------------------------------
    ! Function:  int UseImplWorker
    ! Attrs:     +intent(function)
    ! Requested: f_function_native_scalar
    ! Match:     f_function
    ! Attrs:     +intent(function)
    ! Requested: c_function_native_scalar
    ! Match:     c_function
    !>
    !! \brief Function which uses a templated T in the implemetation.
    !!
    !<
    function use_impl_worker_internal_ImplWorker2() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT) :: SHT_rv
        ! splicer begin function.use_impl_worker_internal_ImplWorker2
        SHT_rv = c_use_impl_worker_internal_implworker2()
        ! splicer end function.use_impl_worker_internal_ImplWorker2
    end function use_impl_worker_internal_ImplWorker2

    ! splicer begin additional_functions
    ! splicer end additional_functions

    function worker_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(worker), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function worker_eq

    function worker_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(worker), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function worker_ne

    function user_int_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(user_int), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function user_int_eq

    function user_int_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(user_int), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function user_int_ne

    function structasclass_int_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(structasclass_int), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function structasclass_int_eq

    function structasclass_int_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(structasclass_int), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function structasclass_int_ne

    function structasclass_double_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(structasclass_double), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function structasclass_double_eq

    function structasclass_double_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(structasclass_double), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function structasclass_double_ne

end module templates_mod
