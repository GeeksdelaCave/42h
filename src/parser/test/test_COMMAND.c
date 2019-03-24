/**
 ** \file test_COMMAND.c
 */
#include "test.h"
/**
 ** \brief Test Unit for Command Grammar
 */
void test_COMMAND()
{
  char *str[] =
    {
      "a = 15 a = 15 b = 569 12 < WORD 13 < ERJGNERJG ",
      "12 < WORD 13 < JVFDHBVFSDBV 15 < frnklfdbfjvnf",
      "20 < word",
      " 30 < wfvkfdkvndfkbv",
      "15 < fdjkbhdfbjekbej",
      "10< WORD",
    };
  struct parser_s *p = NULL;
  p = parser_new_from_string(str[0]);
  assert(read_command(p) == 1);
}
