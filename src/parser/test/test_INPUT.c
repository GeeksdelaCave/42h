#include "test.h"

void test_INPUT()
{
  char *str[] = 
    {
      "",
      "a=15 b=569 a=5 b=50",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_input(p1) == 1);
  printf("%s \n", p1->input);
  print_node(p1->nodes);
}