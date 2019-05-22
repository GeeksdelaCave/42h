/**
 ** \file  read_while.c
 */
#include "grammar.h"
#include "../dot/generate_dot_file_ast.h"
/**
 ** \brief return true if while's grammar is check and make
 **  an ast node while
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_while(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_readtext(p, "while") &&
      OneOrMany(read_spaces(p)) && read_compound_list(p) &&
      ZeroOrMany(read_spaces(p)) && read_do_group(p))
  {
    struct s_node_while *node_while = init_while();
    find_while(p, node_while);
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->node_while = node_while;
    list_node_store(p->nodes, grammar, WHILE);
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
