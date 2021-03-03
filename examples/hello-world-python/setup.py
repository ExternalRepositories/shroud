# setup.py
# This file is generated by Shroud 0.12.2. Do not edit.
from setuptools import setup, Extension

module = Extension(
    'helloworld',
    sources=[
         'helloworld/pyhelloworld_Persontype.cpp',
         'helloworld/pyhelloworld_helloworldmodule.cpp',
         'helloworld/pyhelloworldmodule.cpp',
         'helloworld/pyhelloworldutil.cpp',
         'helloworld.cpp'
    ],
    language='c++',
    include_dirs = None,
#    libraries = ['tcl83'],
#    library_dirs = ['/usr/local/lib'],      
#    extra_compile_args = [ '-O0', '-g' ],
#    extra_link_args =
)

setup(
    name='helloworld',
    ext_modules = [module],
)
