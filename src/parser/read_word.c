/**
 ** \file  read_word.c
 */
#include "grammar.h"
/**
 ** \brief returns true if word's grammar is check and make an ast
 ** node
 ** \param p structure of parser
 **
 ** \return true or false
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
