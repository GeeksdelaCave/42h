#include "test.h"
void test_IF()
{
  char *str[] =
    {
      "",
      "if ! 1 < b 2 < c && ! d=4 e=5 || ! f=6 7 < g ; ! i=10 then ! j=11 fi",
    };
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_if(p1) == 1);
}
