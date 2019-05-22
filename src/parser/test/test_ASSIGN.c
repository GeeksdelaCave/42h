#include "test.h"

void test_ASSIGN()
{
  int size = 5;
  char *str[] =
    {
      "word",
      "          word",
      "\"word",
      " jdfhdsjfhds word",
      "gdfgf dffd gfdd sdvs",
    };
  for (int i = 0; i < size; i++)
  {
    struct parser_s *p = parser_new_from_string(str[i]);
    assert(read_word(p) == 1);
  }
}
