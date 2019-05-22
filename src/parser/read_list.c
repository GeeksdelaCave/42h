/**
 ** \file  read_list.c
 */
#include "grammar.h"
#include "../dot/generate_dot_file_ast.h"
/**
 ** \brief return true if if list's grammar is check and make
 ** an ast node
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_list(struct parser_s *p)
{
  int tmp = p->cursor;
  if (read_and_or(p) && ZeroOrMany(read_spaces(p)) &&
     (ZeroOrMany((read_virgule(p) || read_and(p)) &&
     ZeroOrMany(read_spaces(p)) && read_and_or(p))) &&
     ZeroOrMany(read_spaces(p)) &&
     (ZeroOrOne(read_virgule(p)) || ZeroOrOne(read_and(p))))
  {
    struct s_node_list *list = init_list(p);
    while(list_and_or(p, list));
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->list = list;
    p->nodes->node->list = list;
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
