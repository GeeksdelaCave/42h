# include "ast.h"

struct ast_node_compound_list *create_node_and(struct ast_node_compound_list
                                               *lhs,
                                               struct ast_node_compound_list
                                               *rhs)
{
    struct ast_node_compound_list *node;
    mymalloc(node, sizeof(struct ast_node_compound_list));
    node->type = T_AND;
    node->child.child_and.lhs = lhs;
    node->child.child_and.rhs = rhs;
    return node;
}

void ast_and_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned int *node_id)
{
    unsigned int currend_id;
    unsigned int lhs_id;
    unsigned int rhs_id;

    if (node->type != T_AND)
        return;

    fprintf(out, "%u [label \"&&\";\n]", currend_id = *node_id);
    lhs_id = ++*node_id;
    ast_print_node(node->child.child_and.lhs, out, node_id);
    fprintf(out, "%u -> %u", currend_id, lhs_id);
    rhs_id = ++*node_id;
    ast_print_node(node->child.child_and.rhs, out, node_id);
    fprintf(out, "%u -> %u", currend_id, rhs_id);
}

void ast_and_destruct_node(struct ast_node_compound_list *node)
{
    if (node->type != T_AND)
        return;
    free(node);
}

void ast_and_destruct(struct ast_node_compound_list *node)
{
    if (node->type != T_AND)
        return;
    ast_destruct(node->child.child_and.lhs);
    ast_destruct(node->child.child_and.rhs);
    free(node);
}
