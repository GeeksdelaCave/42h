#include "grammar.h" 
int read_prefix(struct parser_s *p)
{
  int tmp = p->cursor;
  if (read_Assign(p) || read_redirection(p))
  {
    struct list_node_s *assign_node = ast_get_node(p, ASSIGN);
    struct list_node_s *redirection_node = ast_get_node(p, REDIRECTION);
    struct s_node_prefix *prefix = malloc(sizeof(struct s_node_prefix));
    if(assign_node != NULL){
      prefix->assign = assign_node->node->assign;
    }
    if(redirection_node != NULL)
    {
      prefix->redirection = redirection_node->node->redirection;
    }
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->prefix = prefix;
    list_node_store(p->nodes, grammar, PREFIX);
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
