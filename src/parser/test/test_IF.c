#include "test.h"
// WORD Ca marche pas 
void test_IF()
{
  char *str[] = 
    {
      "",
  "if ! 1 < b 2 < c && ! d=4 e=5 || ! f=6 7 < g ; ! i=10 then ! j=11 k=12 || ! l=13 else ! 1 < z 2 < zz && ! zzz=4 zzzz=5 fi",
  "if ! 1 < b 2 < c && ! d=4 e=5 || ! f=6 7 < g ; ! i=10 then ! j=11 k=12 || ! l=13 elif ! 1 < z 2 < zz && ! zzz=4 zzzz=5 then 1 < za 2 < zza && ! zzza=4 zzzzza=5 fi",
		"if ! 1 < b 2 < c && ! d=4 e=5 || ! f=6 7 < g ; ! i=10 then ! j=11 k=12 || ! l=13 14 < n ; ! WORD=10 b=50 15 < dada else ! 1 < b 2 < c && ! d=4 e=5 || ! f=6 7 < g ; ! i=10 j=11 k=12 || ! l=13 14 < n  fi",
      "if ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 < zrevjzrjvjerv a=15 | JE=45 15 < WORDfadde 30 < wfvkfdkvndfkbv 15 < fdjkbhdfbjekbej 10< WORD && ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < dada then ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < dada fi",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[2]);
  assert(read_if(p1) == 1);
  printf("%s \n", p1->input);
}
