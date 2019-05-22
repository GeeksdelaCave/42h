/**
 ** \file  read_simple_command.c
 */
#include "grammar.h"
/**
 ** \brief return true if simple_command's grammar is check and make
 **  an ast node simple command
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_simple_command(struct parser_s *p)
{
  int tmp = p->cursor;
  if ((OneOrMany(read_prefix(p)) && ZeroOrMany(read_element(p)))
      || (ZeroOrMany(read_prefix(p)) && OneOrMany(read_element(p))))
  {
    struct s_simple_cmd *s_cmd = init_simple_command(p);
    struct list_node_s *node = p->nodes;
    for(; node; node = node->next)
    {
      if(node->type == ASSIGN)
      {
	find_assign(p, s_cmd);
      }else if(node->type == REDIRECTION)
      {
	find_redir(p, s_cmd);
      }else if(node->type == WORD1)
      {
	find_word(p, s_cmd);
      }
    }
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->simple_c = s_cmd;
    list_node_store(p->nodes, grammar, SIMPLECOMMAND);
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
