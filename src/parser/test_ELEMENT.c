#include "test.h"

void test_ELEMENT()
{
  int size = 8;
  char *str[] =
    {
      "WORD",
      "12<10",
      "10< WORD",
      "1212123211fbdb",
      "a10",
      "rvfbvfsdkvf                <               fjvkfv",
      "545454545445445 < WORD",
      " sjvghskjvsdfvb  < Word",
    };
  for (int i = 0; i < size; i++)
    {
      if ((i % 2) == 0)
	{
	  struct parser_s *p = parser_new_from_string(str[i]);
	  assert(read_element(p) == 1);
	}
      else
	{
	  struct parser_s *p = parser_new_from_string(str[i]);
	  assert(read_element(p) == 0);
	}
    }
}
