#include "grammar.h" 
/*
  if true store the word in the list capture
  WORD:'
  'id'
*/
int read_word(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p))
      && parser_begin_capture(p, "word") &&
      parser_readidentifier(p) && 
      parser_end_capture(p, "word") &&
      ZeroOrMany(read_spaces(p)))
    {
      return 1;
    }
    parser_get_capture(p, "word");
    p->cursor = tmp;
    return 0;
}