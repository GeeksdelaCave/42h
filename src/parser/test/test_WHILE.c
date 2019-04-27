#include "test.h"

void test_WHILE()
{
    char *str[] = 
    {
      "",
      "while ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 < zrevjzrjvjerv a=15 | JE=45 ; 15 < WORDfadde 30 < wfvkfdkvndfkbv & 15 < fdjkbhdfbjekbej 10< WORD && ! a=1 b=2 JE TEST MON CODE || ! a=5 do 15 < toto JE TESTE MON CODE && ! WORD=10 b=50 ; JE TESTE MON CODE && a=5 15 < dada je test done",
    };
    struct parser_s *p1= parser_new_from_string(str[1]);
    read_while(p1);
    printf("%s \n", p1->input);
    print_node(p1->nodes);
}