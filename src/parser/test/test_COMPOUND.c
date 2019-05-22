#include "test.h"

void test_COMPOUND()
{
  char *str[] =
    {
      "",
      "! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 <  ",
    };
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_compound_list(p1) == 1);
}
