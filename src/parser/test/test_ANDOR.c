#include "test.h"

void test_ANDOR()
{
  char *str[] = 
    {
      "",
      "! JE FAIS DES TESTES | uhhvhbrb=15 a=15 | JE=45 | a=1 b=2 je teste mon code | a=5 && 15 < ABD JE FAIS DES TESTE",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_and_or(p1) == 1);
  printf("%s \n", p1->input);
  print_node(p1->nodes);
}