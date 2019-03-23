#include "grammar.h" 
/*
  do_group:
  'do' compound_list 'done'
*/
int read_do_group(struct parser_s *p)
{
  int tmp = p->cursor;
  
  if (parser_readtext(p, "do") && read_compound_list(p) && 
       parser_readtext(p, "done"))
    {
      printf("AST read DOGROUP : SUCCES\n");
      return 1;
    }
  printf("AST read DOGROUP : FAIL\n");
  p->cursor = tmp;
  return 0;
}