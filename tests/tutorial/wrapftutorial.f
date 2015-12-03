! wrapftutorial.f
! This is generated code, do not edit
module tutorial_mod
    use fstr_mod
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
        type(C_PTR) voidptr
        ! splicer begin class.Class1.component_part
        ! splicer end class.Class1.component_part
    contains
        procedure :: delete => class1_delete
        procedure :: method1 => class1_method1
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
        
        function tut_class1_new() result(rv) &
                bind(C, name="TUT_class1_new")
            use iso_c_binding
            implicit none
            type(C_PTR) :: rv
        end function tut_class1_new
        
        subroutine tut_class1_delete(self) &
                bind(C, name="TUT_class1_delete")
            use iso_c_binding
            implicit none
            type(C_PTR), value, intent(IN) :: self
        end subroutine tut_class1_delete
        
        subroutine tut_class1_method1(self) &
                bind(C, name="TUT_class1_method1")
            use iso_c_binding
            implicit none
            type(C_PTR), value, intent(IN) :: self
        end subroutine tut_class1_method1
        
        ! splicer begin class.Class1.additional_interfaces
        ! splicer end class.Class1.additional_interfaces
        
        subroutine function1() &
                bind(C, name="TUT_function1")
            use iso_c_binding
            implicit none
        end subroutine function1
        
        function function2(arg1, arg2) result(rv) &
                bind(C, name="TUT_function2")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            integer(C_INT), value, intent(IN) :: arg2
            real(C_DOUBLE) :: rv
        end function function2
        
        subroutine sum(len, values, result) &
                bind(C, name="TUT_sum")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: len
            integer(C_INT), intent(IN) :: values(*)
            integer(C_INT), intent(OUT) :: result
        end subroutine sum
        
        function tut_function3(arg) result(rv) &
                bind(C, name="TUT_function3")
            use iso_c_binding
            implicit none
            logical(C_BOOL), value, intent(IN) :: arg
            logical(C_BOOL) :: rv
        end function tut_function3
        
        pure function tut_function4a(arg1, arg2) result(rv) &
                bind(C, name="TUT_function4a")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            type(C_PTR) rv
        end function tut_function4a
        
        pure function tut_function4a_bufferify(arg1, Larg1, arg2, Larg2) result(rv) &
                bind(C, name="TUT_function4a_bufferify")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            integer(C_INT), value, intent(IN) :: Larg2
            type(C_PTR) rv
        end function tut_function4a_bufferify
        
        function tut_function4b(arg1, arg2) result(rv) &
                bind(C, name="TUT_function4b")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            type(C_PTR) rv
        end function tut_function4b
        
        function tut_function4b_bufferify(arg1, Larg1, arg2, Larg2) result(rv) &
                bind(C, name="TUT_function4b_bufferify")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: arg1(*)
            integer(C_INT), value, intent(IN) :: Larg1
            character(kind=C_CHAR), intent(IN) :: arg2(*)
            integer(C_INT), value, intent(IN) :: Larg2
            type(C_PTR) rv
        end function tut_function4b_bufferify
        
        function tut_function5_0() result(rv) &
                bind(C, name="TUT_function5_0")
            use iso_c_binding
            implicit none
            real(C_DOUBLE) :: rv
        end function tut_function5_0
        
        function tut_function5_1(arg1) result(rv) &
                bind(C, name="TUT_function5_1")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            real(C_DOUBLE) :: rv
        end function tut_function5_1
        
        function tut_function5_2(arg1, arg2) result(rv) &
                bind(C, name="TUT_function5_2")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg1
            logical(C_BOOL), value, intent(IN) :: arg2
            real(C_DOUBLE) :: rv
        end function tut_function5_2
        
        subroutine tut_function6_from_name(name) &
                bind(C, name="TUT_function6_from_name")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
        end subroutine tut_function6_from_name
        
        subroutine tut_function6_from_name_bufferify(name, Lname) &
                bind(C, name="TUT_function6_from_name_bufferify")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            integer(C_INT), value, intent(IN) :: Lname
        end subroutine tut_function6_from_name_bufferify
        
        subroutine tut_function6_from_index(indx) &
                bind(C, name="TUT_function6_from_index")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: indx
        end subroutine tut_function6_from_index
        
        subroutine tut_function7_int(arg) &
                bind(C, name="TUT_function7_int")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: arg
        end subroutine tut_function7_int
        
        subroutine tut_function7_double(arg) &
                bind(C, name="TUT_function7_double")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg
        end subroutine tut_function7_double
        
        function tut_function8_int() result(rv) &
                bind(C, name="TUT_function8_int")
            use iso_c_binding
            implicit none
            integer(C_INT) :: rv
        end function tut_function8_int
        
        function tut_function8_double() result(rv) &
                bind(C, name="TUT_function8_double")
            use iso_c_binding
            implicit none
            real(C_DOUBLE) :: rv
        end function tut_function8_double
        
        subroutine tut_function9(arg) &
                bind(C, name="TUT_function9")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg
        end subroutine tut_function9
        
        subroutine tut_function10_0() &
                bind(C, name="TUT_function10_0")
            use iso_c_binding
            implicit none
        end subroutine tut_function10_0
        
        subroutine tut_function10_1(name, arg2) &
                bind(C, name="TUT_function10_1")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            real(C_DOUBLE), value, intent(IN) :: arg2
        end subroutine tut_function10_1
        
        subroutine tut_function10_1_bufferify(name, Lname, arg2) &
                bind(C, name="TUT_function10_1_bufferify")
            use iso_c_binding
            implicit none
            character(kind=C_CHAR), intent(IN) :: name(*)
            integer(C_INT), value, intent(IN) :: Lname
            real(C_DOUBLE), value, intent(IN) :: arg2
        end subroutine tut_function10_1_bufferify
        
        function tut_overload1_0(num) result(rv) &
                bind(C, name="TUT_overload1_0")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT) :: rv
        end function tut_overload1_0
        
        function tut_overload1_1(num, offset) result(rv) &
                bind(C, name="TUT_overload1_1")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT) :: rv
        end function tut_overload1_1
        
        function tut_overload1_2(num, offset, stride) result(rv) &
                bind(C, name="TUT_overload1_2")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT), value, intent(IN) :: stride
            integer(C_INT) :: rv
        end function tut_overload1_2
        
        function tut_overload1_3(type, num) result(rv) &
                bind(C, name="TUT_overload1_3")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: type
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT) :: rv
        end function tut_overload1_3
        
        function tut_overload1_4(type, num, offset) result(rv) &
                bind(C, name="TUT_overload1_4")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: type
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT) :: rv
        end function tut_overload1_4
        
        function tut_overload1_5(type, num, offset, stride) result(rv) &
                bind(C, name="TUT_overload1_5")
            use iso_c_binding
            implicit none
            real(C_DOUBLE), value, intent(IN) :: type
            integer(C_INT), value, intent(IN) :: num
            integer(C_INT), value, intent(IN) :: offset
            integer(C_INT), value, intent(IN) :: stride
            integer(C_INT) :: rv
        end function tut_overload1_5
        
        function typefunc(arg) result(rv) &
                bind(C, name="TUT_typefunc")
            use iso_c_binding
            implicit none
            integer(C_INT), value, intent(IN) :: arg
            integer(C_INT) :: rv
        end function typefunc
        
        pure function tut_last_function_called() result(rv) &
                bind(C, name="TUT_last_function_called")
            use iso_c_binding
            implicit none
            type(C_PTR) rv
        end function tut_last_function_called
        
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
        module procedure function5_0
        module procedure function5_1
        module procedure function5_2
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
        module procedure overload1_0
        module procedure overload1_1
        module procedure overload1_2
        module procedure overload1_3
        module procedure overload1_4
        module procedure overload1_5
    end interface overload1

contains
    
    ! Class1 * new()+constructor
    ! function_index=0
    function class1_new() result(rv)
        use iso_c_binding
        implicit none
        type(class1) :: rv
        ! splicer begin class.Class1.method.new
        rv%voidptr = tut_class1_new()
        ! splicer end class.Class1.method.new
    end function class1_new
    
    ! void delete()+destructor
    ! function_index=1
    subroutine class1_delete(obj)
        use iso_c_binding
        implicit none
        class(class1) :: obj
        ! splicer begin class.Class1.method.delete
        call tut_class1_delete(obj%voidptr)
        obj%voidptr = C_NULL_PTR
        ! splicer end class.Class1.method.delete
    end subroutine class1_delete
    
    ! void Method1()
    ! function_index=2
    subroutine class1_method1(obj)
        use iso_c_binding
        implicit none
        class(class1) :: obj
        ! splicer begin class.Class1.method.method1
        call tut_class1_method1(obj%voidptr)
        ! splicer end class.Class1.method.method1
    end subroutine class1_method1
    
    ! splicer begin class.Class1.additional_functions
    ! splicer end class.Class1.additional_functions
    
    ! bool Function3(bool arg+intent(in)+value)
    ! function_index=6
    function function3(arg) result(rv)
        use iso_c_binding
        implicit none
        logical, value, intent(IN) :: arg
        logical(C_BOOL) tmp_arg
        logical :: rv
        tmp_arg = arg  ! coerce to C_BOOL
        ! splicer begin function3
        rv = tut_function3(tmp_arg)
        ! splicer end function3
    end function function3
    
    ! const std::string & Function4a(const std::string & arg1+intent(in), const std::string & arg2+intent(in))+pure
    ! string_to_buffer_and_len
    ! function_index=7
    function function4a(arg1, arg2) result(rv)
        use iso_c_binding
        implicit none
        character(*), intent(IN) :: arg1
        character(*), intent(IN) :: arg2
        character(kind=C_CHAR, len=strlen_ptr(tut_function4a_bufferify(arg1, len_trim(arg1), arg2, len_trim(arg2)))) :: rv
        ! splicer begin function4a
        rv = fstr(tut_function4a_bufferify(  &
            arg1,  &
            len_trim(arg1),  &
            arg2,  &
            len_trim(arg2)))
        ! splicer end function4a
    end function function4a
    
    ! const std::string & Function4b(const std::string & arg1+intent(in), const std::string & arg2+intent(in))
    ! string_to_buffer_and_len
    ! function_index=8
    subroutine function4b(arg1, arg2, output)
        use iso_c_binding
        implicit none
        character(*), intent(IN) :: arg1
        character(*), intent(IN) :: arg2
        character(*), intent(OUT) :: output
        type(C_PTR) :: rv
        ! splicer begin function4b
        rv = tut_function4b_bufferify(  &
            arg1,  &
            len_trim(arg1),  &
            arg2,  &
            len_trim(arg2))
        call FccCopyPtr(output, len(output), rv)
        ! splicer end function4b
    end subroutine function4b
    
    ! double Function5()
    ! has_default_arg
    ! function_index=21
    function function5_0() result(rv)
        use iso_c_binding
        implicit none
        real(C_DOUBLE) :: rv
        ! splicer begin function5_0
        rv = tut_function5_0()
        ! splicer end function5_0
    end function function5_0
    
    ! double Function5(double arg1+default(3.1415)+intent(in)+value)
    ! has_default_arg
    ! function_index=22
    function function5_1(arg1) result(rv)
        use iso_c_binding
        implicit none
        real(C_DOUBLE), value, intent(IN) :: arg1
        real(C_DOUBLE) :: rv
        ! splicer begin function5_1
        rv = tut_function5_1(arg1)
        ! splicer end function5_1
    end function function5_1
    
    ! double Function5(double arg1+default(3.1415)+intent(in)+value, bool arg2+default(true)+intent(in)+value)
    ! function_index=9
    function function5_2(arg1, arg2) result(rv)
        use iso_c_binding
        implicit none
        real(C_DOUBLE), value, intent(IN) :: arg1
        logical, value, intent(IN) :: arg2
        logical(C_BOOL) tmp_arg2
        real(C_DOUBLE) :: rv
        tmp_arg2 = arg2  ! coerce to C_BOOL
        ! splicer begin function5_2
        rv = tut_function5_2(  &
            arg1,  &
            tmp_arg2)
        ! splicer end function5_2
    end function function5_2
    
    ! void Function6(const std::string & name+intent(in))
    ! string_to_buffer_and_len
    ! function_index=10
    subroutine function6_from_name(name)
        use iso_c_binding
        implicit none
        character(*), intent(IN) :: name
        ! splicer begin function6_from_name
        call tut_function6_from_name_bufferify(  &
            name,  &
            len_trim(name))
        ! splicer end function6_from_name
    end subroutine function6_from_name
    
    ! void Function6(int indx+intent(in)+value)
    ! function_index=11
    subroutine function6_from_index(indx)
        use iso_c_binding
        implicit none
        integer(C_INT), value, intent(IN) :: indx
        ! splicer begin function6_from_index
        call tut_function6_from_index(indx)
        ! splicer end function6_from_index
    end subroutine function6_from_index
    
    ! void Function7(int arg+intent(in)+value)
    ! cpp_template
    ! function_index=23
    subroutine function7_int(arg)
        use iso_c_binding
        implicit none
        integer(C_INT), value, intent(IN) :: arg
        ! splicer begin function7_int
        call tut_function7_int(arg)
        ! splicer end function7_int
    end subroutine function7_int
    
    ! void Function7(double arg+intent(in)+value)
    ! cpp_template
    ! function_index=24
    subroutine function7_double(arg)
        use iso_c_binding
        implicit none
        real(C_DOUBLE), value, intent(IN) :: arg
        ! splicer begin function7_double
        call tut_function7_double(arg)
        ! splicer end function7_double
    end subroutine function7_double
    
    ! int Function8()
    ! cpp_template
    ! function_index=25
    function function8_int() result(rv)
        use iso_c_binding
        implicit none
        integer(C_INT) :: rv
        ! splicer begin function8_int
        rv = tut_function8_int()
        ! splicer end function8_int
    end function function8_int
    
    ! double Function8()
    ! cpp_template
    ! function_index=26
    function function8_double() result(rv)
        use iso_c_binding
        implicit none
        real(C_DOUBLE) :: rv
        ! splicer begin function8_double
        rv = tut_function8_double()
        ! splicer end function8_double
    end function function8_double
    
    ! void Function9(float arg+intent(in)+value)
    ! fortran_generic
    ! function_index=35
    subroutine function9_float(arg)
        use iso_c_binding
        implicit none
        real(C_FLOAT), value, intent(IN) :: arg
        ! splicer begin function9_float
        call tut_function9(real(arg, C_DOUBLE))
        ! splicer end function9_float
    end subroutine function9_float
    
    ! void Function9(double arg+intent(in)+value)
    ! fortran_generic
    ! function_index=36
    subroutine function9_double(arg)
        use iso_c_binding
        implicit none
        real(C_DOUBLE), value, intent(IN) :: arg
        ! splicer begin function9_double
        call tut_function9(arg)
        ! splicer end function9_double
    end subroutine function9_double
    
    ! void Function10()
    ! function_index=15
    subroutine function10_0()
        use iso_c_binding
        implicit none
        ! splicer begin function10_0
        call tut_function10_0()
        ! splicer end function10_0
    end subroutine function10_0
    
    ! void Function10(const std::string & name+intent(in), float arg2+intent(in)+value)
    ! fortran_generic - string_to_buffer_and_len
    ! function_index=37
    subroutine function10_1_float(name, arg2)
        use iso_c_binding
        implicit none
        character(*), intent(IN) :: name
        real(C_FLOAT), value, intent(IN) :: arg2
        ! splicer begin function10_1_float
        call tut_function10_1_bufferify(  &
            name,  &
            len_trim(name),  &
            real(arg2, C_DOUBLE))
        ! splicer end function10_1_float
    end subroutine function10_1_float
    
    ! void Function10(const std::string & name+intent(in), double arg2+intent(in)+value)
    ! fortran_generic - string_to_buffer_and_len
    ! function_index=38
    subroutine function10_1_double(name, arg2)
        use iso_c_binding
        implicit none
        character(*), intent(IN) :: name
        real(C_DOUBLE), value, intent(IN) :: arg2
        ! splicer begin function10_1_double
        call tut_function10_1_bufferify(  &
            name,  &
            len_trim(name),  &
            arg2)
        ! splicer end function10_1_double
    end subroutine function10_1_double
    
    ! int overload1(int num+intent(in)+value)
    ! has_default_arg
    ! function_index=27
    function overload1_0(num) result(rv)
        use iso_c_binding
        implicit none
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT) :: rv
        ! splicer begin overload1_0
        rv = tut_overload1_0(num)
        ! splicer end overload1_0
    end function overload1_0
    
    ! int overload1(int num+intent(in)+value, int offset+default(0)+intent(in)+value)
    ! has_default_arg
    ! function_index=28
    function overload1_1(num, offset) result(rv)
        use iso_c_binding
        implicit none
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT) :: rv
        ! splicer begin overload1_1
        rv = tut_overload1_1(  &
            num,  &
            offset)
        ! splicer end overload1_1
    end function overload1_1
    
    ! int overload1(int num+intent(in)+value, int offset+default(0)+intent(in)+value, int stride+default(1)+intent(in)+value)
    ! function_index=17
    function overload1_2(num, offset, stride) result(rv)
        use iso_c_binding
        implicit none
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT), value, intent(IN) :: stride
        integer(C_INT) :: rv
        ! splicer begin overload1_2
        rv = tut_overload1_2(  &
            num,  &
            offset,  &
            stride)
        ! splicer end overload1_2
    end function overload1_2
    
    ! int overload1(double type+intent(in)+value, int num+intent(in)+value)
    ! has_default_arg
    ! function_index=29
    function overload1_3(type, num) result(rv)
        use iso_c_binding
        implicit none
        real(C_DOUBLE), value, intent(IN) :: type
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT) :: rv
        ! splicer begin overload1_3
        rv = tut_overload1_3(  &
            type,  &
            num)
        ! splicer end overload1_3
    end function overload1_3
    
    ! int overload1(double type+intent(in)+value, int num+intent(in)+value, int offset+default(0)+intent(in)+value)
    ! has_default_arg
    ! function_index=30
    function overload1_4(type, num, offset) result(rv)
        use iso_c_binding
        implicit none
        real(C_DOUBLE), value, intent(IN) :: type
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT) :: rv
        ! splicer begin overload1_4
        rv = tut_overload1_4(  &
            type,  &
            num,  &
            offset)
        ! splicer end overload1_4
    end function overload1_4
    
    ! int overload1(double type+intent(in)+value, int num+intent(in)+value, int offset+default(0)+intent(in)+value, int stride+default(1)+intent(in)+value)
    ! function_index=18
    function overload1_5(type, num, offset, stride) result(rv)
        use iso_c_binding
        implicit none
        real(C_DOUBLE), value, intent(IN) :: type
        integer(C_INT), value, intent(IN) :: num
        integer(C_INT), value, intent(IN) :: offset
        integer(C_INT), value, intent(IN) :: stride
        integer(C_INT) :: rv
        ! splicer begin overload1_5
        rv = tut_overload1_5(  &
            type,  &
            num,  &
            offset,  &
            stride)
        ! splicer end overload1_5
    end function overload1_5
    
    ! const std::string & LastFunctionCalled()+pure
    ! function_index=20
    function last_function_called() result(rv)
        use iso_c_binding
        implicit none
        character(kind=C_CHAR, len=strlen_ptr(tut_last_function_called())) :: rv
        ! splicer begin last_function_called
        rv = fstr(tut_last_function_called())
        ! splicer end last_function_called
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

end module tutorial_mod
