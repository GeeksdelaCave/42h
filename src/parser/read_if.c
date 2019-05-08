/**
 ** \file  read_if.c
 */
#include "grammar.h"
#include "../dot/generate_dot_file_ast.h"
/**
 ** \brief return true if if's grammar is check and make an ast
 **  node for the grammar of if
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_if(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p)) &&
      parser_readtext(p, "if") && read_compound_list(p) &&
      ZeroOrMany(read_spaces(p)) && parser_readtext(p, "then")  &&
      ZeroOrMany(read_spaces(p)) && read_compound_list(p) &&
      ZeroOrMany(read_spaces(p)) && ZeroOrOne(read_else(p)) &&
      ZeroOrMany(read_spaces(p)) && parser_readtext(p, "fi"))
  {
    struct s_node_if *node_if = init_if();
    find_if(p, node_if);
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->node_if = node_if;
    print_if_command(node_if, fopen("ast.dot", "w+"));
    list_node_store(p->nodes, grammar, IF);
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
