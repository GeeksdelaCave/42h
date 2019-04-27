#include "test.h"

void test_DOGROUP()
{
  char *str[] = 
    {
      "",
      "do ! a=15 b=569 15 < ker 16 < jsd | u=15 15 < zre a=15 | JE=45 15 < W 30 < w 15 < f 10< W && ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < dada done",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  read_do_group(p1);
  //assert(read_and_or(p1) == 1);
  //printf("%s \n", p1->input);
}


