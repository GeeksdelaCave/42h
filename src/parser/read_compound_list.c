/**
 ** \file  read_compound_list.c
 */
#include "grammar.h"
/**
 ** \brief return true if compound list and make an ast node for
 **  Compound list
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_compound_list(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(parser_readchar(p, '\n')) && ZeroOrMany(read_spaces(p))
      && read_and_or(p) && ZeroOrMany(read_spaces(p))
      && ZeroOrMany((read_virgule(p) || read_and(p)
      || parser_readchar(p, '\n')) && ZeroOrMany(read_spaces(p))
      && ZeroOrMany(parser_readchar(p, '\n'))  && ZeroOrMany(read_spaces(p))
      && read_and_or(p)) && ((ZeroOrOne(read_virgule(p))
      || ZeroOrOne(read_and(p)) || ZeroOrOne(parser_readchar(p, '\n')))
      && ZeroOrMany(read_spaces(p))
      && ZeroOrOne(ZeroOrMany(parser_readchar(p, '\n')))))
  {
    struct s_node_compound_list *cpd = init_compound(p);
    while(find_and_or(p, cpd));
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->compoundlist = cpd;
    list_node_store(p->nodes, grammar, COUMPOUND);
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
