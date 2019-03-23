#include "grammar.h" 
/*
case_item:
      ['('] WORD ('|' WORD)* ')' ('\n')*  [ compound_list ]
*/

int read_case_item(struct parser_s *p)
{
  int tmp = p->cursor;

  if ((ZeroOrOne(parser_readchar(p, '(')) && read_word(p) && 
       ZeroOrMany(parser_readchar(p,'|') && read_word(p)) 
       && parser_readchar(p, ')') && ZeroOrMany(parser_readchar(p, '\n')) 
       && ZeroOrOne(read_compound_list(p))) 
      )
    {
      printf("AST read CASE ITEM : SUCCES\n");
      return 1;
    }
    printf("AST read CASE ITEM : FAIL\n");
    p->cursor = tmp;
    return 0;
}

