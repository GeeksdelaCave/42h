# include "ast.h"

struct ast_node_compound_list *create_node_pipe(struct ast_node_compound_list *lhs, struct ast_node_compound_list *rhs)
{
  struct ast_node_compound_list *node;
  mymalloc(node, sizeof(struct ast_node_compound_list));
  node->type = T_PIPE;
  node->child.child_pipe.lhs = lhs;
  node->child.child_pipe.rhs = rhs;
  return node;
}
