/**
 ** \file  read_input.c
 */
#include "grammar.h"
/**
 ** \brief return true if if the text is a input and make
 **  an ast node
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_input(struct parser_s *p)
{
  int tmp = p->cursor;
  if ((read_list(p) && parser_readchar(p, '\n')) ||
      (read_list(p) && parser_eof(p)) ||
      (parser_readchar(p, '\n')) ||
      (parser_eof(p)))
  {
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
