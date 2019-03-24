/**
 ** \file test_ANDOR.C
 */
#include "test.h"
/**
 ** \brief test unit for and_or grammar
 */
void test_ANDOR()
{
  char *str[] =
    {
      "",
      "! JE FAIS DES TESTES | uhhvhbrb=15 15 < zrevjzrjvjerv a=15 | ! a=5"
      " JE jzrvnjzrnv jekznvjezn | 14 < kdvdjkv | a=5 b=15 c=16"
      " kvnskvnfskvnkfdsnvn | 15 < kfsjbkfsnvbenr | a=5 c=15",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_and_or(p1) == 1);
  //printf("%s \n", p1->input);
}