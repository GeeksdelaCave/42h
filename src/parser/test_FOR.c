#include "test.h"

void test_FOR()
{
  char *str[] =
    {
      "for WORD ; in WORD WORD WORD WORD WORD do ",
    };
  /* struct parser_s *pre = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[0]);
  assert(read_for(p1) == 0);
  printf("%s \n", p1->input);
}
