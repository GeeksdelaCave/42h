#include "test.h"

void test_PIPELINE()
{
  char *str[] = 
    {
      "",
      "! a=15 b=569 12 < WORD 13 < ERJGNERJG 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 fdhvhkdvhfd=20 15 < zrevjzrjvjerv a=15 | JE=45 15 < fudhgufj",
      " 30 < wfvkfdkvndfkbv",
      "15 < fdjkbhdfbjekbej",
      "10< WORD"
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_pipeline(p1) == 1);
  printf("%s \n", p1->input);
}


