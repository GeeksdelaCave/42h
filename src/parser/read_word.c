#include "ast.h"

/*
  if true store the word in the list capture
  WORD:'
  'id'
*/
int read_word(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(parser_readinset(p, " \t\r\n\"'`()|><;=&{}"))
      && parser_begin_capture(p, "word") &&
      parser_readidentifier(p) && 
      parser_end_capture(p, "word") &&
      ZeroOrMany(parser_readinset(p, " \t\r\n\"'`()|><;=&{}")))
    {
      char *str = parser_get_capture(p, "word");
      printf("AST read WORD %s : SUCCES\n", str);
      return 1;
    }
  //printf("AST read WORD : FAIL\n");
  p->cursor = tmp;
  return 0;
}

