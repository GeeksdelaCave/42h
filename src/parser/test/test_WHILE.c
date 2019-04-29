#include "test.h"
//POINT VIRGULE
void test_WHILE()
{
    char *str[] = 
    {
		"",
      "while ! a=5484 b=569 15 < k 16 < j | ugf=15 15 < z a=15 | JE=45 ; 15 < WORD 30 < wfv & 15 < fd 10 < WORD && ! a=1 b=2 60 < JE 80 < TEST 75 < MON 90 < CODE || ! a=5 do 15 < toto 45 < t 50 < MON 50 < CODE && ! WORD=10 b=50 ; 100 < JE 120 < TESTE 130 < MON 14 < CODE && a=5 15 < dada 15 < je 25 < test done",
      "while ! a=15 b=569 15 < a 16 < jsd uhh=15 15 < zrev a=35 | JE=45 a=5 do a=5 15 < dada 450 < pnl done",
    };
    struct parser_s *p1= parser_new_from_string(str[1]);
    read_while(p1);
    printf("%s \n", p1->input);
    print_node(p1->nodes);
}
