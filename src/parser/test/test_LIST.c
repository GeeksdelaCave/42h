#include "test.h"

void test_LIST()
{
  char *str[] = 
    {
      "",
      "while ! a=1 b=2 10 < a 20 < b | c=3 30 < c d=4 | e=5 ; 40 < d 50 < e & 60 < f 70 < g && ! f=7 g=8 80 < JE 90 < TEST 100 < MON 110 < CODE || ! h=9 do 120 < toto 130 < t 140 < MON 150 < CODE && ! i=10 j=50 ; 160 < JE 170 < TESTE 180 < MON 190 < CODE && k=5 200 < dada 210 < je 220 < test done",
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

