#include "test.h"
void test_REDIRECTION()
{
  int size = 6;
  char *str[] =
    {
      "12<WORD",
      "       15    <               word",
      "20 < word",
      " 30 < wfvkfdkvndfkbv",
      "15 < fdjkbhdfbjekbej",
      "10< WORD",
    };
  for (int i = 0; i < size; i++)
  {
    struct parser_s *p = parser_new_from_string(str[i]);
    assert(read_redirection(p) == 1);
  }
}
