! wrapfownership.f
! This file is generated by Shroud nowrite-version. Do not edit.
! Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfownership.f
!! \brief Shroud generated wrapper for ownership library
!<
! splicer begin file_top
! splicer end file_top
module ownership_mod
    use iso_c_binding, only : C_INT, C_LONG, C_NULL_PTR, C_PTR, C_SIZE_T
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    ! helper capsule_data_helper
    type, bind(C) :: OWN_SHROUD_capsule_data
        type(C_PTR) :: addr = C_NULL_PTR  ! address of C++ memory
        integer(C_INT) :: idtor = 0       ! index of destructor
    end type OWN_SHROUD_capsule_data

    ! helper array_context
    type, bind(C) :: OWN_SHROUD_array
        ! address of C++ memory
        type(OWN_SHROUD_capsule_data) :: cxx
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
    end type OWN_SHROUD_array

    ! helper capsule_helper
    type :: OWN_SHROUD_capsule
        private
        type(OWN_SHROUD_capsule_data) :: mem
    contains
        final :: SHROUD_capsule_final
        procedure :: delete => SHROUD_capsule_delete
    end type OWN_SHROUD_capsule

    type class1
        type(OWN_SHROUD_capsule_data) :: cxxmem
        ! splicer begin class.Class1.component_part
        ! splicer end class.Class1.component_part
    contains
        procedure :: dtor => class1_dtor
        procedure :: get_flag => class1_get_flag
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

        ! ----------------------------------------
        ! Function:  ~Class1
        ! Attrs:     +intent(dtor)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        subroutine c_class1_dtor(self) &
                bind(C, name="OWN_Class1_dtor")
            import :: OWN_SHROUD_capsule_data
            implicit none
            type(OWN_SHROUD_capsule_data), intent(IN) :: self
        end subroutine c_class1_dtor

        ! ----------------------------------------
        ! Function:  int getFlag
        ! Attrs:     +intent(getter)
        ! Exact:     c_getter_native_scalar
        function c_class1_get_flag(self) &
                result(SHT_rv) &
                bind(C, name="OWN_Class1_get_flag")
            use iso_c_binding, only : C_INT
            import :: OWN_SHROUD_capsule_data
            implicit none
            type(OWN_SHROUD_capsule_data), intent(IN) :: self
            integer(C_INT) :: SHT_rv
        end function c_class1_get_flag

        ! splicer begin class.Class1.additional_interfaces
        ! splicer end class.Class1.additional_interfaces

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrRaw +deref(raw)
        ! Attrs:     +deref(raw)+intent(function)
        ! Requested: c_function_native_*_raw
        ! Match:     c_function_native_*
        function c_return_int_ptr_raw() &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_raw")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_raw

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrScalar +deref(scalar)
        ! Attrs:     +deref(scalar)+intent(function)
        ! Exact:     c_function_native_*_scalar
        function return_int_ptr_scalar() &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_scalar")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT) :: SHT_rv
        end function return_int_ptr_scalar

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrPointer +deref(pointer)
        ! Attrs:     +deref(pointer)+intent(function)
        ! Requested: c_function_native_*_pointer
        ! Match:     c_function_native_*
        function c_return_int_ptr_pointer() &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_pointer")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_pointer

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrPointer +deref(pointer)
        ! Attrs:     +api(buf)+deref(pointer)+intent(function)
        ! Requested: c_function_native_*_buf_pointer
        ! Match:     c_function_native_*
        function c_return_int_ptr_pointer_bufferify() &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_pointer_bufferify")
            use iso_c_binding, only : C_PTR
            implicit none
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_pointer_bufferify

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimRaw +deref(raw)
        ! Attrs:     +deref(raw)+intent(function)
        ! Requested: c_function_native_*_raw
        ! Match:     c_function_native_*
        ! ----------------------------------------
        ! Argument:  int * len +intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        function c_return_int_ptr_dim_raw(len) &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_raw")
            use iso_c_binding, only : C_INT, C_PTR
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_dim_raw

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimPointer +deref(pointer)+dimension(len)
        ! Attrs:     +deref(pointer)+intent(function)
        ! Requested: c_function_native_*_pointer
        ! Match:     c_function_native_*
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        function c_return_int_ptr_dim_pointer(len) &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_pointer")
            use iso_c_binding, only : C_INT, C_PTR
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_dim_pointer

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimPointer +deref(pointer)+dimension(len)
        ! Attrs:     +api(cdesc)+deref(pointer)+intent(function)
        ! Requested: c_function_native_*_cdesc_pointer
        ! Match:     c_function_native_*_cdesc
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        subroutine c_return_int_ptr_dim_pointer_bufferify(len, SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_pointer_bufferify")
            use iso_c_binding, only : C_INT
            import :: OWN_SHROUD_array
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(OWN_SHROUD_array), intent(OUT) :: SHT_rv
        end subroutine c_return_int_ptr_dim_pointer_bufferify

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimAlloc +deref(allocatable)+dimension(len)
        ! Attrs:     +deref(allocatable)+intent(function)
        ! Requested: c_function_native_*_allocatable
        ! Match:     c_function_native_*
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        function c_return_int_ptr_dim_alloc(len) &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_alloc")
            use iso_c_binding, only : C_INT, C_PTR
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_dim_alloc

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimAlloc +deref(allocatable)+dimension(len)
        ! Attrs:     +api(cdesc)+deref(allocatable)+intent(function)
        ! Requested: c_function_native_*_cdesc_allocatable
        ! Match:     c_function_native_*_cdesc
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        subroutine c_return_int_ptr_dim_alloc_bufferify(len, SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_alloc_bufferify")
            use iso_c_binding, only : C_INT
            import :: OWN_SHROUD_array
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(OWN_SHROUD_array), intent(OUT) :: SHT_rv
        end subroutine c_return_int_ptr_dim_alloc_bufferify

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimDefault +dimension(len)
        ! Attrs:     +deref(pointer)+intent(function)
        ! Requested: c_function_native_*_pointer
        ! Match:     c_function_native_*
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        function c_return_int_ptr_dim_default(len) &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_default")
            use iso_c_binding, only : C_INT, C_PTR
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_dim_default

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimDefault +dimension(len)
        ! Attrs:     +api(cdesc)+deref(pointer)+intent(function)
        ! Requested: c_function_native_*_cdesc_pointer
        ! Match:     c_function_native_*_cdesc
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        subroutine c_return_int_ptr_dim_default_bufferify(len, SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_default_bufferify")
            use iso_c_binding, only : C_INT
            import :: OWN_SHROUD_array
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(OWN_SHROUD_array), intent(OUT) :: SHT_rv
        end subroutine c_return_int_ptr_dim_default_bufferify

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimRawNew +dimension(len)+owner(caller)
        ! Attrs:     +capsule+deref(pointer)+intent(function)
        ! Requested: c_function_native_*_pointer
        ! Match:     c_function_native_*
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        function c_return_int_ptr_dim_raw_new(len) &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_raw_new")
            use iso_c_binding, only : C_INT, C_PTR
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_dim_raw_new

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimPointerNew +deref(pointer)+dimension(len)+owner(caller)
        ! Attrs:     +capsule+deref(pointer)+intent(function)
        ! Requested: c_function_native_*_pointer
        ! Match:     c_function_native_*
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        function c_return_int_ptr_dim_pointer_new(len) &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_pointer_new")
            use iso_c_binding, only : C_INT, C_PTR
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_dim_pointer_new

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimPointerNew +deref(pointer)+dimension(len)+owner(caller)
        ! Attrs:     +api(cdesc)+capsule+deref(pointer)+intent(function)
        ! Requested: c_function_native_*_cdesc_pointer
        ! Match:     c_function_native_*_cdesc
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        subroutine c_return_int_ptr_dim_pointer_new_bufferify(len, &
                SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_pointer_new_bufferify")
            use iso_c_binding, only : C_INT
            import :: OWN_SHROUD_array
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(OWN_SHROUD_array), intent(OUT) :: SHT_rv
        end subroutine c_return_int_ptr_dim_pointer_new_bufferify

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimAllocNew +deref(allocatable)+dimension(len)+owner(caller)
        ! Attrs:     +deref(allocatable)+intent(function)
        ! Requested: c_function_native_*_allocatable
        ! Match:     c_function_native_*
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        function c_return_int_ptr_dim_alloc_new(len) &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_alloc_new")
            use iso_c_binding, only : C_INT, C_PTR
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_dim_alloc_new

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimDefaultNew +dimension(len)+owner(caller)
        ! Attrs:     +capsule+deref(pointer)+intent(function)
        ! Requested: c_function_native_*_pointer
        ! Match:     c_function_native_*
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        function c_return_int_ptr_dim_default_new(len) &
                result(SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_default_new")
            use iso_c_binding, only : C_INT, C_PTR
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(C_PTR) SHT_rv
        end function c_return_int_ptr_dim_default_new

        ! ----------------------------------------
        ! Function:  int * ReturnIntPtrDimDefaultNew +dimension(len)+owner(caller)
        ! Attrs:     +api(cdesc)+capsule+deref(pointer)+intent(function)
        ! Requested: c_function_native_*_cdesc_pointer
        ! Match:     c_function_native_*_cdesc
        ! ----------------------------------------
        ! Argument:  int * len +hidden+intent(out)
        ! Attrs:     +intent(out)
        ! Requested: c_out_native_*
        ! Match:     c_default
        subroutine c_return_int_ptr_dim_default_new_bufferify(len, &
                SHT_rv) &
                bind(C, name="OWN_return_int_ptr_dim_default_new_bufferify")
            use iso_c_binding, only : C_INT
            import :: OWN_SHROUD_array
            implicit none
            integer(C_INT), intent(OUT) :: len
            type(OWN_SHROUD_array), intent(OUT) :: SHT_rv
        end subroutine c_return_int_ptr_dim_default_new_bufferify

        ! ----------------------------------------
        ! Function:  void createClassStatic
        ! Attrs:     +intent(subroutine)
        ! Requested: c_subroutine_void_scalar
        ! Match:     c_subroutine
        ! ----------------------------------------
        ! Argument:  int flag +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        subroutine create_class_static(flag) &
                bind(C, name="OWN_create_class_static")
            use iso_c_binding, only : C_INT
            implicit none
            integer(C_INT), value, intent(IN) :: flag
        end subroutine create_class_static

        ! ----------------------------------------
        ! Function:  Class1 * getClassStatic +owner(library)
        ! Attrs:     +intent(function)
        ! Requested: c_function_shadow_*
        ! Match:     c_function_shadow
        subroutine c_get_class_static(SHT_rv) &
                bind(C, name="OWN_get_class_static")
            import :: OWN_SHROUD_capsule_data
            implicit none
            type(OWN_SHROUD_capsule_data), intent(OUT) :: SHT_rv
        end subroutine c_get_class_static

        ! ----------------------------------------
        ! Function:  Class1 * getClassNew +owner(caller)
        ! Attrs:     +intent(function)
        ! Requested: c_function_shadow_*
        ! Match:     c_function_shadow
        ! ----------------------------------------
        ! Argument:  int flag +value
        ! Attrs:     +intent(in)
        ! Requested: c_in_native_scalar
        ! Match:     c_default
        subroutine c_get_class_new(flag, SHT_rv) &
                bind(C, name="OWN_get_class_new")
            use iso_c_binding, only : C_INT
            import :: OWN_SHROUD_capsule_data
            implicit none
            integer(C_INT), value, intent(IN) :: flag
            type(OWN_SHROUD_capsule_data), intent(OUT) :: SHT_rv
        end subroutine c_get_class_new

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface
        ! helper capsule_dtor
        ! Delete memory in a capsule.
        subroutine OWN_SHROUD_capsule_dtor(ptr) &
            bind(C, name="OWN_SHROUD_memory_destructor")
            import OWN_SHROUD_capsule_data
            implicit none
            type(OWN_SHROUD_capsule_data), intent(INOUT) :: ptr
        end subroutine OWN_SHROUD_capsule_dtor
    end interface

    interface
        ! helper copy_array_int
        ! Copy contents of context into c_var.
        subroutine OWN_SHROUD_copy_array_int(context, c_var, c_var_size) &
            bind(C, name="OWN_ShroudCopyArray")
            use iso_c_binding, only : C_INT, C_SIZE_T
            import OWN_SHROUD_array
            type(OWN_SHROUD_array), intent(IN) :: context
            integer(C_INT), intent(OUT) :: c_var(*)
            integer(C_SIZE_T), value :: c_var_size
        end subroutine OWN_SHROUD_copy_array_int
    end interface

contains

    ! ----------------------------------------
    ! Function:  ~Class1
    ! Attrs:     +intent(dtor)
    ! Exact:     f_dtor
    ! Attrs:     +intent(dtor)
    ! Exact:     c_dtor
    subroutine class1_dtor(obj)
        class(class1) :: obj
        ! splicer begin class.Class1.method.dtor
        call c_class1_dtor(obj%cxxmem)
        ! splicer end class.Class1.method.dtor
    end subroutine class1_dtor

    ! Generated by getter/setter
    ! ----------------------------------------
    ! Function:  int getFlag
    ! Attrs:     +intent(getter)
    ! Requested: f_function_native_scalar
    ! Match:     f_function
    ! Attrs:     +intent(getter)
    ! Requested: c_function_native_scalar
    ! Match:     c_function
    function class1_get_flag(obj) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        class(class1) :: obj
        integer(C_INT) :: SHT_rv
        ! splicer begin class.Class1.method.get_flag
        SHT_rv = c_class1_get_flag(obj%cxxmem)
        ! splicer end class.Class1.method.get_flag
    end function class1_get_flag

    ! Return pointer to C++ memory.
    function class1_get_instance(obj) result (cxxptr)
        use iso_c_binding, only: C_PTR
        class(class1), intent(IN) :: obj
        type(C_PTR) :: cxxptr
        cxxptr = obj%cxxmem%addr
    end function class1_get_instance

    subroutine class1_set_instance(obj, cxxmem)
        use iso_c_binding, only: C_PTR
        class(class1), intent(INOUT) :: obj
        type(C_PTR), intent(IN) :: cxxmem
        obj%cxxmem%addr = cxxmem
        obj%cxxmem%idtor = 0
    end subroutine class1_set_instance

    function class1_associated(obj) result (rv)
        use iso_c_binding, only: c_associated
        class(class1), intent(IN) :: obj
        logical rv
        rv = c_associated(obj%cxxmem%addr)
    end function class1_associated

    ! splicer begin class.Class1.additional_functions
    ! splicer end class.Class1.additional_functions

    ! Generated by arg_to_buffer
    ! ----------------------------------------
    ! Function:  int * ReturnIntPtrPointer +deref(pointer)
    ! Attrs:     +deref(pointer)+intent(function)
    ! Exact:     f_function_native_*_buf_pointer
    ! Attrs:     +api(buf)+deref(pointer)+intent(function)
    ! Requested: c_function_native_*_buf_pointer
    ! Match:     c_function_native_*
    function return_int_ptr_pointer() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, C_PTR, c_f_pointer
        integer(C_INT), pointer :: SHT_rv
        ! splicer begin function.return_int_ptr_pointer
        type(C_PTR) :: SHC_rv_ptr
        SHC_rv_ptr = c_return_int_ptr_pointer_bufferify()
        call c_f_pointer(SHC_rv_ptr, SHT_rv)
        ! splicer end function.return_int_ptr_pointer
    end function return_int_ptr_pointer

    ! Generated by arg_to_buffer
    ! ----------------------------------------
    ! Function:  int * ReturnIntPtrDimPointer +deref(pointer)+dimension(len)
    ! Attrs:     +deref(pointer)+intent(function)
    ! Exact:     f_function_native_*_cdesc_pointer
    ! Attrs:     +api(cdesc)+deref(pointer)+intent(function)
    ! Requested: c_function_native_*_cdesc_pointer
    ! Match:     c_function_native_*_cdesc
    ! ----------------------------------------
    ! Argument:  int * len +hidden+intent(out)
    ! Attrs:     +intent(out)
    ! Requested: f_out_native_*
    ! Match:     f_default
    ! Attrs:     +intent(out)
    ! Requested: c_out_native_*
    ! Match:     c_default
    function return_int_ptr_dim_pointer() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, c_f_pointer
        integer(C_INT) :: len
        integer(C_INT), pointer :: SHT_rv(:)
        ! splicer begin function.return_int_ptr_dim_pointer
        type(OWN_SHROUD_array) :: SHT_rv_cdesc
        call c_return_int_ptr_dim_pointer_bufferify(len, SHT_rv_cdesc)
        call c_f_pointer(SHT_rv_cdesc%base_addr, SHT_rv, &
            SHT_rv_cdesc%shape(1:1))
        ! splicer end function.return_int_ptr_dim_pointer
    end function return_int_ptr_dim_pointer

    ! Generated by arg_to_buffer
    ! ----------------------------------------
    ! Function:  int * ReturnIntPtrDimAlloc +deref(allocatable)+dimension(len)
    ! Attrs:     +deref(allocatable)+intent(function)
    ! Exact:     f_function_native_*_cdesc_allocatable
    ! Attrs:     +api(cdesc)+deref(allocatable)+intent(function)
    ! Requested: c_function_native_*_cdesc_allocatable
    ! Match:     c_function_native_*_cdesc
    ! ----------------------------------------
    ! Argument:  int * len +hidden+intent(out)
    ! Attrs:     +intent(out)
    ! Requested: f_out_native_*
    ! Match:     f_default
    ! Attrs:     +intent(out)
    ! Requested: c_out_native_*
    ! Match:     c_default
    function return_int_ptr_dim_alloc() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT) :: len
        integer(C_INT), allocatable :: SHT_rv(:)
        ! splicer begin function.return_int_ptr_dim_alloc
        type(OWN_SHROUD_array) :: SHT_rv_cdesc
        call c_return_int_ptr_dim_alloc_bufferify(len, SHT_rv_cdesc)
        allocate(SHT_rv((len)))
        call OWN_SHROUD_copy_array_int(SHT_rv_cdesc, SHT_rv, &
            size(SHT_rv, kind=C_SIZE_T))
        ! splicer end function.return_int_ptr_dim_alloc
    end function return_int_ptr_dim_alloc

    ! Generated by arg_to_buffer
    ! ----------------------------------------
    ! Function:  int * ReturnIntPtrDimDefault +dimension(len)
    ! Attrs:     +deref(pointer)+intent(function)
    ! Exact:     f_function_native_*_cdesc_pointer
    ! Attrs:     +api(cdesc)+deref(pointer)+intent(function)
    ! Requested: c_function_native_*_cdesc_pointer
    ! Match:     c_function_native_*_cdesc
    ! ----------------------------------------
    ! Argument:  int * len +hidden+intent(out)
    ! Attrs:     +intent(out)
    ! Requested: f_out_native_*
    ! Match:     f_default
    ! Attrs:     +intent(out)
    ! Requested: c_out_native_*
    ! Match:     c_default
    function return_int_ptr_dim_default() &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, c_f_pointer
        integer(C_INT) :: len
        integer(C_INT), pointer :: SHT_rv(:)
        ! splicer begin function.return_int_ptr_dim_default
        type(OWN_SHROUD_array) :: SHT_rv_cdesc
        call c_return_int_ptr_dim_default_bufferify(len, SHT_rv_cdesc)
        call c_f_pointer(SHT_rv_cdesc%base_addr, SHT_rv, &
            SHT_rv_cdesc%shape(1:1))
        ! splicer end function.return_int_ptr_dim_default
    end function return_int_ptr_dim_default

    ! Generated by arg_to_buffer
    ! ----------------------------------------
    ! Function:  int * ReturnIntPtrDimPointerNew +deref(pointer)+dimension(len)+owner(caller)
    ! Attrs:     +capsule+deref(pointer)+intent(function)
    ! Exact:     f_function_native_*_cdesc_pointer_caller
    ! Attrs:     +api(cdesc)+capsule+deref(pointer)+intent(function)
    ! Requested: c_function_native_*_cdesc_pointer
    ! Match:     c_function_native_*_cdesc
    ! ----------------------------------------
    ! Argument:  int * len +hidden+intent(out)
    ! Attrs:     +intent(out)
    ! Requested: f_out_native_*
    ! Match:     f_default
    ! Attrs:     +intent(out)
    ! Requested: c_out_native_*
    ! Match:     c_default
    function return_int_ptr_dim_pointer_new(Crv) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, c_f_pointer
        integer(C_INT) :: len
        integer(C_INT), pointer :: SHT_rv(:)
        type(OWN_SHROUD_capsule), intent(OUT) :: Crv
        ! splicer begin function.return_int_ptr_dim_pointer_new
        type(OWN_SHROUD_array) :: SHT_rv_cdesc
        call c_return_int_ptr_dim_pointer_new_bufferify(len, &
            SHT_rv_cdesc)
        call c_f_pointer(SHT_rv_cdesc%base_addr, SHT_rv, &
            SHT_rv_cdesc%shape(1:1))
        Crv%mem = SHT_rv_cdesc%cxx
        ! splicer end function.return_int_ptr_dim_pointer_new
    end function return_int_ptr_dim_pointer_new

    ! Generated by arg_to_buffer
    ! ----------------------------------------
    ! Function:  int * ReturnIntPtrDimDefaultNew +dimension(len)+owner(caller)
    ! Attrs:     +capsule+deref(pointer)+intent(function)
    ! Exact:     f_function_native_*_cdesc_pointer_caller
    ! Attrs:     +api(cdesc)+capsule+deref(pointer)+intent(function)
    ! Requested: c_function_native_*_cdesc_pointer
    ! Match:     c_function_native_*_cdesc
    ! ----------------------------------------
    ! Argument:  int * len +hidden+intent(out)
    ! Attrs:     +intent(out)
    ! Requested: f_out_native_*
    ! Match:     f_default
    ! Attrs:     +intent(out)
    ! Requested: c_out_native_*
    ! Match:     c_default
    function return_int_ptr_dim_default_new(Crv) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, c_f_pointer
        integer(C_INT) :: len
        integer(C_INT), pointer :: SHT_rv(:)
        type(OWN_SHROUD_capsule), intent(OUT) :: Crv
        ! splicer begin function.return_int_ptr_dim_default_new
        type(OWN_SHROUD_array) :: SHT_rv_cdesc
        call c_return_int_ptr_dim_default_new_bufferify(len, &
            SHT_rv_cdesc)
        call c_f_pointer(SHT_rv_cdesc%base_addr, SHT_rv, &
            SHT_rv_cdesc%shape(1:1))
        Crv%mem = SHT_rv_cdesc%cxx
        ! splicer end function.return_int_ptr_dim_default_new
    end function return_int_ptr_dim_default_new

    ! ----------------------------------------
    ! Function:  Class1 * getClassStatic +owner(library)
    ! Attrs:     +intent(function)
    ! Requested: f_function_shadow_*_library
    ! Match:     f_function_shadow
    ! Attrs:     +intent(function)
    ! Requested: c_function_shadow_*
    ! Match:     c_function_shadow
    function get_class_static() &
            result(SHT_rv)
        type(class1) :: SHT_rv
        ! splicer begin function.get_class_static
        call c_get_class_static(SHT_rv%cxxmem)
        ! splicer end function.get_class_static
    end function get_class_static

    ! ----------------------------------------
    ! Function:  Class1 * getClassNew +owner(caller)
    ! Attrs:     +intent(function)
    ! Requested: f_function_shadow_*_caller
    ! Match:     f_function_shadow
    ! Attrs:     +intent(function)
    ! Requested: c_function_shadow_*
    ! Match:     c_function_shadow
    ! ----------------------------------------
    ! Argument:  int flag +value
    ! Attrs:     +intent(in)
    ! Requested: f_in_native_scalar
    ! Match:     f_default
    ! Attrs:     +intent(in)
    ! Requested: c_in_native_scalar
    ! Match:     c_default
    !>
    !! \brief Return pointer to new Class1 instance.
    !!
    !<
    function get_class_new(flag) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT
        integer(C_INT), value, intent(IN) :: flag
        type(class1) :: SHT_rv
        ! splicer begin function.get_class_new
        call c_get_class_new(flag, SHT_rv%cxxmem)
        ! splicer end function.get_class_new
    end function get_class_new

    ! splicer begin additional_functions
    ! splicer end additional_functions

    function class1_eq(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_eq

    function class1_ne(a,b) result (rv)
        use iso_c_binding, only: c_associated
        type(class1), intent(IN) ::a,b
        logical :: rv
        if (.not. c_associated(a%cxxmem%addr, b%cxxmem%addr)) then
            rv = .true.
        else
            rv = .false.
        endif
    end function class1_ne

    ! helper capsule_helper
    ! finalize a static OWN_SHROUD_capsule_data
    subroutine SHROUD_capsule_final(cap)
        type(OWN_SHROUD_capsule), intent(INOUT) :: cap
        call OWN_SHROUD_capsule_dtor(cap%mem)
    end subroutine SHROUD_capsule_final

    subroutine SHROUD_capsule_delete(cap)
        class(OWN_SHROUD_capsule) :: cap
        call OWN_SHROUD_capsule_dtor(cap%mem)
    end subroutine SHROUD_capsule_delete

end module ownership_mod
