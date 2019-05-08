#include "ast.h"
struct s_node_if *init_if()
{
  struct s_node_if *node_if = malloc(sizeof(struct s_node_if));
  return node_if;
}

int find_if(struct parser_s *p, struct s_node_if *node_if)
{
    struct list_node_s *condition = ast_check_node(p, COUMPOUND);
    struct list_node_s *if_body = ast_check_node(p, COUMPOUND);
	struct s_node_else *node_else = init_else();
	find_else(p, node_else);
    if(!condition || !if_body)
    {
        return 0;
    }
    node_if->condition = condition->node->compoundlist;
    node_if->if_body = if_body->node->compoundlist;
    node_if->else_body = NULL;
	if (node_else != NULL)
	{    
	    node_if->else_body = node_else;
	}    
return 1;
}
