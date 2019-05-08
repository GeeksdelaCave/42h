#include "test.h"
void test_ELSE()
{
  char *str[] = 
    {
      "",
		"else ! 1 < b 2 < c && ! d=4 e=5 || ! f=6 7 < g ; ! i=10 then ! j=11 k=12 || ! l=13 14 < n",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  read_else(p1);
  //assert(read_and_or(p1) == 1);
  printf("%s \n", p1->input);
}
