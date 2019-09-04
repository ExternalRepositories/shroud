# Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
# other Shroud Project Developers.
# See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (BSD-3-Clause)
#
# #######################################################################
#
# test the tutorial module
#
from __future__ import print_function

import unittest
import tutorial

class NotTrue:
    """Test bool arguments errors"""
    def __bool__(self):
        raise NotImplementedError
 
class Tutorial(unittest.TestCase):
    """Test tutorial problem"""
     
    def XXsetUp(self):
        """ Setting up for the test """
        print("FooTest:setUp_:begin")
        ## do something...
        print("FooTest:setUp_:end")
     
    def XXtearDown(self):
        """Cleaning up after the test"""
        print("FooTest:tearDown_:begin")
        ## do something...
        print("FooTest:tearDown_:end")

    def test_enum_Color(self):
        self.assertEqual(0, tutorial.RED)
        self.assertEqual(1, tutorial.BLUE)
        self.assertEqual(2, tutorial.WHITE)

        # pass and return enumeration
        self.assertEqual(tutorial.RED, tutorial.colorfunc(tutorial.BLUE))

    def test_enum_Direction(self):
        # enum values
        self.assertEqual(2, tutorial.Class1.UP)
        self.assertEqual(3, tutorial.Class1.DOWN)
        self.assertEqual(100, tutorial.Class1.LEFT)
        self.assertEqual(101, tutorial.Class1.RIGHT)

        obj = tutorial.Class1()
        # class method with enums
        self.assertEqual(tutorial.Class1.LEFT, obj.directionFunc(tutorial.Class1.LEFT))

        # module method with enums
        self.assertEqual(tutorial.Class1.RIGHT, tutorial.directionFunc(tutorial.Class1.LEFT))
     
    def test_NoReturnNoArguments(self):
        tutorial.NoReturnNoArguments()

    def test_PassByValue(self):
        rv_double = tutorial.PassByValue(1.0, 4)
        self.assertEqual(rv_double, 5.0)#, "A is not equal to B")

    def test_ConcatenateStrings(self):
        rv_char = tutorial.ConcatenateStrings("dog", "cat")
        self.assertEqual(rv_char, "dogcat")

    def test_UseDefaultArguments(self):
        rv_double = tutorial.UseDefaultArguments()
        self.assertAlmostEqual(rv_double, 13.1415)
        rv_double = tutorial.UseDefaultArguments(1.0)
        self.assertAlmostEqual(rv_double, 11.0)

        rv_double = tutorial.UseDefaultArguments(1.0, False)
        self.assertAlmostEqual(rv_double, 1.0)

    def test_OverloadedFunction(self):
        tutorial.OverloadedFunction("name")
        self.assertEqual(tutorial.LastFunctionCalled(),
                         "OverloadedFunction(string)")

        tutorial.OverloadedFunction(1)
        self.assertEqual(tutorial.LastFunctionCalled(),
                         "OverloadedFunction(int)")

        self.assertRaises(TypeError, tutorial.OverloadedFunction, 1.0)

    def test_TemplateArgument_8(self):
        """Test cxx_template"""
        tutorial.TemplateArgument(1)
        self.assertEqual(tutorial.LastFunctionCalled(), "TemplateArgument<int>")
        tutorial.TemplateArgument(10.0)
        self.assertEqual(tutorial.LastFunctionCalled(), "TemplateArgument<double>")

        # return values set by calls to TemplateArgument
        #rv = tutorial.TemplateReturn_int()
        #self.assertEqual(rv, 1)
        #rv = tutorial.TemplateReturn_double()
        #self.assertEqual(rv, 10.0)

    def test_FortranGenericOverloaded(self):
        # overloaded (no default args)
        tutorial.FortranGenericOverloaded()
        tutorial.FortranGenericOverloaded("foo", 1.0)
        tutorial.FortranGenericOverloaded("bar", 1.0)

    def test_UseDefaultOverload(self):
        self.assertEqual(10, tutorial.UseDefaultOverload(10))
        self.assertEqual(10, tutorial.UseDefaultOverload(1., 10))

        self.assertEqual(142, tutorial.UseDefaultOverload(10,11,12))
        self.assertEqual(142, tutorial.UseDefaultOverload(1., 10,11,12))

        self.assertRaises(TypeError, tutorial.UseDefaultOverload, 1.0)
        self.assertRaises(TypeError, tutorial.UseDefaultOverload, "dog")
        
    def test_typefunc(self):
        self.assertEqual(2, tutorial.typefunc(2))

    def test_enumfunc(self):
        self.assertEqual(2, tutorial.enumfunc(1))

    def test_getMinMax(self):
        r = tutorial.getMinMax()
        self.assertEqual((-1,100), r)

#
#  end subroutine test_functions
#

    def test_class1_create1(self):
        obj = tutorial.Class1()
        self.assertIsInstance(obj, tutorial.Class1)
        self.assertEqual(0, obj.test)
        obj.test = 4
        self.assertEqual(4, obj.test)
        # test -1 since PyInt_AsLong returns -1 on error
        obj.test = -1
        self.assertEqual(-1, obj.test)
        with self.assertRaises(AttributeError) as context:
            obj.m_flag = 1
        self.assertTrue("is not writable" in str(context.exception))
        with self.assertRaises(TypeError) as context:
            obj.test = "dog"
        self.assertTrue("an integer is required" in str(context.exception))
        del obj

    def test_class1_create2(self):
        obj = tutorial.Class1(1)
        self.assertIsInstance(obj, tutorial.Class1)
        self.assertEqual(1, obj.m_flag)
        del obj

    def test_class1_method1(self):
        obj0 = tutorial.Class1()
        self.assertEqual(0, obj0.Method1())

        obj1 = tutorial.Class1(1)
        self.assertEqual(1, obj1.Method1())

    def test_class1_equivalent(self):
        obj0 = tutorial.Class1()
        obj1 = tutorial.Class1(1)
        self.assertTrue(obj0.equivalent(obj0))
        self.assertFalse(obj0.equivalent(obj1))

    def test_class1_PassClassByValue(self):
        # passClassByValue sets the global retrived by get_global_flag()
        tutorial.set_global_flag(0)
        obj0 = tutorial.Class1()
        obj0.test = 13
        tutorial.passClassByValue(obj0)
        self.assertEqual(13, tutorial.get_global_flag())

    def test_class1_useclass(self):
        obj0 = tutorial.Class1()
        self.assertEqual(0, tutorial.useclass(obj0))

        # getclass2 is const, not wrapped yet

        obj0a = tutorial.getclass3()
        self.assertIsInstance(obj0a, tutorial.Class1)

    def test_class1_useclass_error(self):
        """Pass illegal argument to useclass"""
        obj0 = tutorial.Class1()
        self.assertRaises(TypeError, tutorial.useclass(obj0))

    def test_singleton(self):
        # XXX - it'd be cool if obj0 is obj1
        obj0 = tutorial.Singleton.getReference()
        obj1 = tutorial.Singleton.getReference()

        obj2 = obj0.getReference()

# creating a new test suite
newSuite = unittest.TestSuite()
 
# adding a test case
newSuite.addTest(unittest.makeSuite(Tutorial))

if __name__ == "__main__":
    unittest.main()