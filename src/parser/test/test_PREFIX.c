#include "test.h"
void test_PREFIX()
{
  int size = 8;
  char *str[] =
    {
      "a=5",
      "b=a",
      "a = 10",
      "a =                  aveavz",
      "a                   =                       10",
      "            b =rvfbv,fsdkvf",
      " 545454545445445 < WORD",
      " sjvghskjvsdfvb  < Word",
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
      assert(read_prefix(p) == 0);
    }
  }
}
