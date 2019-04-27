#include "ast.h"
struct s_node_for *init_for()
{
  struct s_node_for *node_for = malloc(sizeof(struct s_node_for));
  return node_for;
}
/*
int find_for(struct parser_s *p, struct s_node_for *node_for)
{
    struct list_node_s *condition = ast_check_node(p, COUMPOUND);
    struct list_node_s *for_body = ast_check_node(p, COUMPOUND);
    struct list_node_s *node_else = NULL;
    if(!condition || !for_body)
    {
        return 0;
    }
    node_for->condition = condition->node->compoundlist;
    node_for->for_body = for_body->node->compoundlist;
    node_for->node_else = node_else;
    return 1;
}*/