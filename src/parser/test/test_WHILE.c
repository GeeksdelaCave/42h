#include "test.h"
void test_WHILE()
{
  char *str[] =
    {
      "",
      "while ! a=1 b=2 1060 < f 70 < g && ! f=7 g=8 80 < JE do 120 < toto done",
      "while ! l=15 n=569 15 < a 16 < jsd m=15 15 < zrev o=35 do q=4 done",
    };
  struct parser_s *p1= parser_new_from_string(str[1]);
  read_while(p1);
}
