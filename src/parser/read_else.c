/**
 ** \file  read_else.c
 */
#include "grammar.h"
#include "../dot/generate_dot_file_ast.h"
/**
 ** \brief return true if else's grammar is check
 ** and make an ast node for else
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_else(struct parser_s *p)
{
  int tmp = p->cursor;
  if ((parser_readtext(p, "else") && read_compound_list(p))
     || (parser_readtext(p, "elif") && read_compound_list(p)
     && parser_readtext(p, "then") && read_compound_list(p)
     && ZeroOrOne(read_else(p))) )
  {
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
