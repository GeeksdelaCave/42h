#include "test.h"

void test_UNTIL()
{
    char *str[] = 
    {
      "",
      "until ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 < zrevjzrjvjerv do a=15 | JE=45 15 < WORDfadde 30 < wfvkfdkvndfkbv 15 < fdjkbhdfbjekbej 10< WORD && ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < dada ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < dada done",
    };
    struct parser_s *p1= parser_new_from_string(str[1]);
    read_until(p1);
    printf("%s \n", p1->input);
}