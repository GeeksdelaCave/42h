#include "test.h"

void test_PIPELINE()
{
  char *str[] =
    {
      "",
      "! a=15 b=569 toto titi | uhhvhbrb=15 fdhvhkdvhfd=20 a=15 | JE=45 toto t",
      " 30 < wfvkfdkvndfkbv",
      "15 < fdjkbhdfbjekbej",
      "10< WORD"
    };
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_pipeline(p1) == 1);
}
