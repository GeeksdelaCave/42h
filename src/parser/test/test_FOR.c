/**
 ** \file test_FOR.c
 */
#include "test.h"
/**
 ** \brief test unit for For Grammar
 */
void test_FOR()
{
  char *str[] =
    {
      "for WORD in WORD ; do b=6 done \n",
      "for word in word word word word ; do b=7 done \n",
    };
  /* struct parser_s *pre = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[0]);
  assert(read_for(p1) == 1);
  printf("%s \n", p1->input);
}
