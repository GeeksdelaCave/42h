# include "ast.h"

struct ast_node_compound_list *create_node_pipe(struct ast_node_compound_list
                                                *lhs,
                                                struct ast_node_compound_list
                                                *rhs)
{
  struct ast_node_compound_list *node;
  mymalloc(node, sizeof(struct ast_node_compound_list));
  node->type = T_PIPE;
  node->child.child_pipe.lhs = lhs;
  node->child.child_pipe.rhs = rhs;
  return node;
}

void ast_pipe_print(struct ast_node_compound_list *node, FILE *out,
                    unsigned int *node_id)
{
    unsigned int lhs_id;
    unsigned int rhs_id;
    unsigned int currend_id;

    if (node->type != T_PIPE)
        return;
    fprintf(out, "%u [label \"|\";\n]",currend_id = *node_id);
    lhs_id = ++*node_id;
    ast_print_node(node->child.child_pipe.lhs, out, node_id);
    fprintf(out, "%u -> %u", currend_id, lhs_id);
    rhs_id = ++*node_id;
    ast_print_node(node->child.child_pipe.rhs, out, node_id);
    fprintf(out, "%u -> %u", currend_id, rhs_id);
}

void ast_pipe_destruct_node(struct ast_node_compound_list *node)
{
    if (node->type != T_PIPE)
        return;
    free(node);
}

void ast_pipe_destruct(struct ast_node_compound_list *node)
{
    if (node->type != T_PIPE)
        return;
    ast_destruct(node->child.child_pipe.lhs);
    ast_destruct(node->child.child_pipe.rhs);
    free(node);
}
