#include "test.h"
void test_COMMAND()
{
  
  char *str[] =
    {
      "a=5 b=10 c=15 d=20 e=25 f=30 toto",
      "12 < WORD 13 < JVFDHBVFSDBV 15 < frnklfdbfjvnf",
      "20 < word",
      " 30 < wfvkfdkvndfkbv",
      "15 < fdjkbhdfbjekbej",
      "10< WORD",
    };
  struct parser_s *p = NULL;
  p = parser_new_from_string(str[0]);
  assert(read_command(p) == 1);
  print_node(p->nodes);
  //struct pa
  //assert(read_simple_command(p) == 1);
}
