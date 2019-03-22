#include "test.h"

void test_ELEMENT()
{
  int size = 2;
  char *str[] =
    {
      "WORD",
      "12        <      WORD",
    };
  for (int i = 0; i < size; i++)
    {
      if (i % 2)
	{
      struct parser_s *p = parser_new_from_string(str[i]);
      assert(read_element(p) == 1);
	}
      else
	{
	  struct parser_s *p = parser_new_from_string(str[i]);
	  assert(read_element(p) == 1);
	}
    }
}
