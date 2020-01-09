.. Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
   other Shroud Project Developers.
   See the top-level COPYRIGHT file for details.

   SPDX-License-Identifier: (BSD-3-Clause)


Typemaps
========

Typemaps are used to add code to the generated wrappers
to replace the default code.

The typemaps work together to pass variables and metadata between
Fortran and C.


Fortran
-------

A Fortran wrapper is created out of several segments.

.. code-block:: text

      {F_subprogram} {F_name_impl}({F_arguments}){F_result_clause}
        arg_f_use
        arg_f_decl
        ! splicer begin
        declare
        pre_call
        call
        post_call
        ! splicer end
      end {F_subprogram} {F_name_impl}

buf_arg
^^^^^^^

arg

    default.

shadow
size
capsule
context
len_trim
len

c_local_var
^^^^^^^^^^^

If true, generate a local variable using the C declaration for the argument.
This variable can be used by the pre_call and post_call statements.
A single declaration will be added even if with ``intent(inout)``.

call
^^^^

Code used to call the function.
Defaults to ``{F_result} = {F_C_call}({F_arg_c_call})``

declare
^^^^^^^

A list of declarations needed by *pre_call* or *post_call*.
Usually a *c_local_var* is sufficient.

f_helper
^^^^^^^^

Blank delimited list of helper function names to add to generated
Fortran code.
These functions are defined in whelper.py.
There is no current way to add additional functions.


f_module
^^^^^^^^

``USE`` statements to add to Fortran wrapper.
A dictionary of list of ``ONLY`` names:

.. code-block:: yaml

        f_module:
          iso_c_binding:
          - C_SIZE_T


post_call
^^^^^^^^^

Statement to execute after call.
Can be use to cleanup after *pre_call* or to coerce the return value.

pre_call
^^^^^^^^

Statement to execute before call, often to coerce types when *f_cast*
cannot be used.

need_wrapper
^^^^^^^^^^^^

If true, the Fortran wrapper will always be created.
This is used when an assignment is needed to do a type coercion;
for example, with logical types.


C
-

The *C_code* field has a default value of:

.. code-block:: text

    {C_return_type} {C_name}({C_prototype})
    {
        {pre_call}
        {call_code}
        {post_call_pattern}
        {post_call}
        {final}
        {ret}
    }


buf_args
^^^^^^^^^

*buf_args* lists the arguments which are used by the wrapper.
The default is to provide a one-for-one correspondance with the 
arguments of the function which is being wrapped.
However, often an additional function is created which will pass 
additional or different arguments to provide meta-data about the argument.

The Fortran wrapper will call the generated 'bufferified' function
and provide the meta-data to the C wrapper.

arg

    Use the library argument as the wrapper argument.
    This is the default when *buf_args* is not explicit.

capsule

    An argument of type *C_capsule_data_type*/*F_capsule_data_type*.
    It provides a pointer to the C++ memory as well as information
    to release the memory.

context

    An argument of *C_context_type*/*F_context_type*.
    For example, used with ``std::vector`` to hold
    address and size of data contained in the argument
    in a form which may be used directly by Fortran.

    *c_var_context*

len

    Result of Fortran intrinsic ``LEN`` for string arguments.
    Type ``int``.

len_trim

    Result of Fortran intrinsic ``LEN_TRIM`` for string arguments.
    Type ``int``.

size

    Result of Fortran intrinsic ``SIZE`` for array arguments.
    Type ``long``.

shadow

    Argument will be of type *C_capsule_data_type*.



c_header
^^^^^^^^

List of blank delimited header files which will be included by the generated header
for the C wrapper.  These headers must be C only.
For example, ``size_t`` requires stddef.h:

.. code-block:: yaml

    type: size_t
    fields:
        c_type: size_t 
        cxx_type: size_t
        c_header: <stddef.h>


c_helper
^^^^^^^^

A blank delimited list of helper functions which will be added to the wrapper file.
The list will be formatted to allow for additional flexibility::

    c_helper: capsule_data_helper vector_context vector_copy_{cxx_T}

These functions are defined in whelper.py.
There is no current way to add additional functions.

c_local_var
^^^^^^^^^^^

If a local C variable is created for the return value by post_call, *c_local_var*
indicates if the local variable is a **pointer** or **scalar**.
For example, when a structure is returned by a C++ function, the C wrapper creates
a local variable which contains a pointer to the C type of the struct.

The local variable can be passed in when buf_args is *shadow*.

call
^^^^

Code to call function.  This is usually generated.
An exception which require explicit call code are constructors
and destructors for shadow types.

cxx_header
^^^^^^^^^^

A blank delimited list of header files which will be added to the C
wrapper implementation.
These headers may include C++ code.

cxx_local_var
^^^^^^^^^^^^^

If a local C++ variable is created for an argument by pre_call,
*cxx_local_var*
indicates if the local variable is a **pointer** or **scalar**.
.. This sets *cxx_var* is set to ``SH_{c_var}``.
This in turns will set the format fields *cxx_member*.
For example, a ``std::string`` argument is created for the C++ function
from the ``char *`` argument passed into the C API wrapper.

destructor
^^^^^^^^^^

A list of lines of code used to delete memory. Usually allocated by a *pre_call*
statement.  The code is inserted into *C_memory_dtor_function* which will provide
the address of the memory to destroy in the variable ``void *ptr``.
For example:

.. code-block:: yaml

    destructor:
    -  std::vector<{cxx_T}> *cxx_ptr = reinterpret_cast<std::vector<{cxx_T}> *>(ptr);
    -  delete cxx_ptr;


destructor_name
^^^^^^^^^^^^^^^

A name for the destructor code in *destructor*.
Must be unique.  May include format strings:

.. code-block:: yaml

    destructor_name: std_vector_{cxx_T}

final
^^^^^

Inserted after *post_call* and before *ret*.
Can be used to release intermediate memory in the C wrapper.

.. evaluated in context of fmt_result

pre_call
^^^^^^^^

Code used with *intent(in)* arguments to convert from C to C++.

.. the typemap.c_to_cxx field will not be used.

.. * **C_call_code** code used to call the function.
   Constructor and destructor will use ``new`` and ``delete``.

.. * **C_post_call_pattern** code from the *C_error_pattern*.
   Can be used to deal with error values.

post_call
^^^^^^^^^

Code used with *intent(out)* arguments and function results.
Can be used to convert results from C++ to C.

ret
---

Code for return statement.
Usually generated but can be replaced.
For example, with constructors.

.. return is a reserved word so it's not possible to do dict(return=[])

return_type
-----------

Explicit return type when it is different than the
functions return type.
For example, with shadow types.

return_cptr
-----------

If *true*, the function will return a C pointer. This will be
used by the Fortran interface to declare the function as
``type(C_PTR)``.


How typemaps are found
----------------------

alias
^^^^^

Names another node which will be used for its contents.
