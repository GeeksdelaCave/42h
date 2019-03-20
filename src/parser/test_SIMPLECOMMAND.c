#include "test.h"
void test_SIMPLECOMMAND()
{
  int size = 1;
  char *str[] =
    {
      "a = 15 a = 15 b = 569 12 < WORD 13 < ERJGNERJG ",
      "       15    <               word",
      "20 < word",
      " 30 < wfvkfdkvndfkbv",
      "15 < fdjkbhdfbjekbej",
      "10< WORD",
    };
  struct parser_s *p = NULL;
  for (int i = 0; i < size; i++)
    {
      p = parser_new_from_string(str[i]);
      assert(read_simple_command(p) == 1);
    }
  struct list_capt_s *list = p->capture;
  for(; list; list = list->next)
    {
      printf("TAG : %s\n", list->tag); 
    }
}
