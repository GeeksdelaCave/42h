/**
 ** \file  read_case_item.c
 */
#include "grammar.h"
/**
 ** \brief return true if read case item
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */

int read_case_item(struct parser_s *p)
{
  int tmp = p->cursor;
  if ((ZeroOrOne(parser_readchar(p, '(')) && read_word(p)
       && ZeroOrMany(parser_readchar(p,'|') && read_word(p))
       && parser_readchar(p, ')') && ZeroOrMany(parser_readchar(p, '\n'))
       && ZeroOrOne(read_compound_list(p)))
      )
  {
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
