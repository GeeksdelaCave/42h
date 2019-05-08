/**
 ** \file  read_prefix.c
 */
#include "grammar.h"
/**
 ** \brief return true if prefix's grammar is check
 ** and make an ast node for Prefix
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_prefix(struct parser_s *p)
{
  int tmp = p->cursor;
  if (read_Assign(p) || read_redirection(p))
  {
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
