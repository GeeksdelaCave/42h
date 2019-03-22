#include "test.h"

void test_ANDOR()
{
  char *str[] = 
    {
      "",
      "! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 < zrevjzrjvjerv a=15 | JE=45 15 < WORDfadde 30 < wfvkfdkvndfkbv 15 < fdjkbhdfbjekbej 10< WORD && ! a=1 b=2 || ! a=5 15 < toto",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_and_or(p1) == 1);
  printf("%s \n", p1->input);
}


