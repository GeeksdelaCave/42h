#include "test.h"

void test_DOGROUP()
{
  char *str[] =
    {
      "",
      "do ! a=15 b=569 15 < ker 16 < jsd | u=15 15 < zre  | JE=45 15 < W done"
    };
  struct parser_s *p1= parser_new_from_string(str[1]);
  read_do_group(p1);
}
