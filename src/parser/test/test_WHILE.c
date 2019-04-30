#include "test.h"
//POINT VIRGULE
void test_WHILE()
{
    char *str[] = 
    {
		"",
      "while ! a=1 b=2 10 < a 20 < b | c=3 30 < c d=4 | e=5 ; 40 < d 50 < e & 60 < f 70 < g && ! f=7 g=8 80 < JE 90 < TEST 100 < MON 110 < CODE || ! h=9 do 120 < toto 130 < t 140 < MON 150 < CODE && ! i=10 j=50 ; 160 < JE 170 < TESTE 180 < MON 190 < CODE && k=5 200 < dada 210 < je 220 < test done",
      "while ! l=15 n=569 15 < a 16 < jsd m=15 15 < zrev o=35 | p=45 q=5 do r=5 15 < dada 450 < pnl done",
    };
    struct parser_s *p1= parser_new_from_string(str[1]);
    read_while(p1);
    printf("%s \n", p1->input);
    print_node(p1->nodes);
}
