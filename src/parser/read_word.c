#include "ast.h"

/*
  if true store the word in the list capture
  WORD:'
  'id'
*/
int read_word(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_begin_capture(p, "word") && parser_readidentifier(p) && 
      parser_end_capture(p, "word"))
    {
      printf("AST read WORD : SUCCES\n");
      return 1;
    }
  printf("AST read WORD : FAIL\n");
  p->cursor = tmp;
  return 0;
}

