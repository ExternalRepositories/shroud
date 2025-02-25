/*
 * Copyright (c) 2017-2021, Lawrence Livermore National Security, LLC and
 * other Shroud Project Developers.
 * See the top-level COPYRIGHT file for details.
 *
 * SPDX-License-Identifier: (BSD-3-Clause)
 *
 * Test C API generated from classes.yaml.
 */

#include <wrapclasses.h>
#include <wrapClass1.h>

#include <assert.h>

void test_class(void)
{
  int flag;
  CLA_Class1 c1;

  CLA_Class1_ctor_default(&c1);

  flag = CLA_Class1_method1(&c1);
  assert(flag == 0 && "CLA_class1_method1");

  // passClassByValue sets global_flag
  CLA_set_global_flag(-1);
  CLA_pass_class_by_value(&c1);
  flag = CLA_get_global_flag();
  assert(flag == 0 && "CLA_pass_class_by_value");

}

int main(int argc, char *argv[])
{
  test_class();

  return 0;
}

