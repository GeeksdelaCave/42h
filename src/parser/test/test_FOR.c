#include "test.h"

void test_FOR()
{
  char *str[] =
    {
      "for WORD in WORD ; do b=6 done \n",
    };
  struct parser_s *p1= parser_new_from_string(str[0]);
  assert(read_for(p1) == 1);
}
