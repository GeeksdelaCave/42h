#include "test.h"
void test_LIST()
{
  char *str[] =
    {
      "",
      "while ! a=1 b=2 10 < a 20 < b | c=3 30 < c d=4 | e=5 ; 40 < d  done",
      "if a=5 b=6 ss=6 15 < qbddq then b=5 a=5 fi",
    };
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_list(p1) == 1);
  printf("%s \n", p1->input);
}
