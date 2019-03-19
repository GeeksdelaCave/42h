#include "test.h"
void test_SIMPLECOMMAND()
{
  int size = 1;
  char *str[] =
    {
      "a = 15 a = 15 b = 569 12 < WORD 13 < ERJGNERJG WORD WORD ",
      "       15    <               word",
      "20 < word",
      " 30 < wfvkfdkvndfkbv",
      "15 < fdjkbhdfbjekbej",
      "10< WORD",
    };
  for (int i = 0; i < size; i++)
    {
      struct parser_s *p = parser_new_from_string(str[i]);
      assert(read_simplecommand(p) == 1);
    }  

}
