#include "test.h"

void test_INPUT()
{
  char *str[] = 
    {
      "",
      "for WORD in WORD space A B C D E F G E F H ; do b=6 15 < ABC JE TESTE MON CODE  done",
      "if ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 < zrevjzrjvjerv a=15 then a=5 || b=10 5 < abcad && a=5 JE TESTE MON TRUC fi",
      "while ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 < zrevjzrjvjerv a=15 | JE=45 ; 15 < WORDfadde 30 < wfvkfdkvndfkbv & 15 < fdjkbhdfbjekbej 10< WORD && ! a=1 b=2 JE TEST MON CODE || ! a=5 do 15 < toto JE TESTE MON CODE && ! WORD=10 b=50 ; JE TESTE MON CODE && a=5 15 < dada je test done",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_input(p1) == 1);
  printf("%s \n", p1->input);
  print_node(p1->nodes);
}