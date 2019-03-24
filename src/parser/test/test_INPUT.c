/**
 ** \file test_INPUT.c
 */
#include "test.h"
/**
 ** \brief Test for input Grammar
 */
void test_INPUT()
{
  char *str[] =
    {
      "",
      "until ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_input(p1) == 1);
  printf("%s \n", p1->input);
}
