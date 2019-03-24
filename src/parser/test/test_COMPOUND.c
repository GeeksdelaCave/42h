/**
 ** \file test_COMPOUND.c
 */
#include "test.h"
/**
 ** \brief test unit for compound grammar
 */
void test_COMPOUND()
{
  char *str[] =
    {
      "",
      "! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 < z",
      "vjzrjvjerv a=15 | JE=45 15 < WORDfadde 30 < wfvkfdkvndfkbv 15 < fdjkbh",
      "jekbej 10< WORD && ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < d",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_compound_list(p1) == 1);
  //assert(read_and_or(p1) == 1);
  //printf("%s \n", p1->input);
}
