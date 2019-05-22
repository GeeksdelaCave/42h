#include "test.h"
void test_UNTIL()
{
  char *str[] =
    {
      "",
      "until ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs 10 < dada done",
    };
  struct parser_s *p1= parser_new_from_string(str[1]);
  read_until(p1);
}
