#include "test.h"

void test_LIST()
{
  char *str[] = 
    {
      "",
      "! a=15 b=20 c=30 d=15 JE FAIS DES TESTES | uhhvhbrb=15 15 < zrevjzrjvjerv a=15 | JE=45 15 < WORDfadde 30 < wfvkfdkvndfkbv 15 < fdjkbhdfbjekbej 10< WORD && ! a=1 b=2 je teste mon code || ! a=5 15 < toto teste & JE TESTE MON CODE & TEST TEST TEST N;",

      "if a=5 b=6 ss=6 15 < qbddq then b=5 a=5 fi",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_list(p1) == 1);
  printf("%s \n", p1->input);
}

/*
while ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 < zrevjzrjvjerv do a=15 | JE=45 15 < WORDfadde 30 < wfvkfdkvndfkbv 15 < fdjkbhdfbjekbej 10< WORD && ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < dada ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < dada done 

*/

