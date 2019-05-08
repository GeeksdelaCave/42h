/**
 ** \file  read_until.c
 */
#include "grammar.h"
/**
 ** \brief return true if until's grammar is check and make
 **  an ast node until
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_until(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_readtext(p, "until") &&
      OneOrMany(read_spaces(p)) && read_compound_list(p)
      && ZeroOrMany(read_spaces(p)) && read_do_group(p))
  {
    struct s_node_until *node_until = init_until();
    find_until(p, node_until);
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->node_until = node_until;
    list_node_store(p->nodes, grammar, UNTIL);
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
