/**
 ** \file test_IF.c
 */
#include "test.h"
/**
 ** \brief test for IF Grammar
 */
void test_IF()
{
  char *str[] =
    {
      "",
	"",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  read_if(p1);
  //assert(read_and_or(p1) == 1);
  printf("%s \n", p1->input);
}
