#include "ast.h"

/*
  if true store the word in the list capture
  WORD:'
  'id'
*/
int read_word(struct parser_s *p)
{
  int tmp = p->cursor;
  printf("IIIIIIIII %d\n", p->cursor);
  if (ZeroOrMany(read_spaces(p))
      && parser_begin_capture(p, "word") &&
      parser_readidentifier(p) && 
      parser_end_capture(p, "word") &&
      ZeroOrMany(read_spaces(p)))
    {
      printf("READ WORD : %s\n", parser_get_capture(p, "word"));
      return 1;
    }
  p->capture->tag = " ";
  p->cursor = tmp;
  return 0;
}

