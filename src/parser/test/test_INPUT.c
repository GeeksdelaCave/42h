#include "test.h"

void test_INPUT()
{
  char *str[] =
    {
      "",
      "a=5 b=15 c=20 d=15",
      "for WORD in WORD space A B C D E F G E F H ; do b=6 15 < ABC JE done",
    };
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_input(p1) == 1);
}
