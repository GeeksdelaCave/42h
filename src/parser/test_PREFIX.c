#include "test.h"

void test_PREFIX()
{
  int size = 7;
  char *str[] =
    {
      "a=5",
      "b=10",
      "a = 10",
      "a =                  15",
      "a                   =                       10",
      "            b = 10",
      "a = vnskvskvnnv",
    };
  for (int i = 0; i < size; i++)
    {
      if ((i % 2) == 0)
	{
	  struct parser_s *p = parser_new_from_string(str[i]);
	  assert(read_prefix(p) == 1);
	}
      else
	{
	  struct parser_s *p = parser_new_from_string(str[i]);
	  assert(read_prefix(p) == 1);
	}
    }
}
