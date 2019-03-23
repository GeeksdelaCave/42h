# include "ast.h"


struct ast_node_compound_list *create_node_or(struct ast_node_compound_list
                                               *lhs,
                                               struct ast_node_compound_list
                                               *rhs)
{
    struct ast_node_compound_list *node;
    mymalloc(node, sizeof(struct ast_node_compound_list));
    node->child.child_or.lhs = lhs;
    node->child.child_or.rhs = rhs;
    return node;

}


void ast_or_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned int *node_id)
{
    unsigned int lhs_id;
    unsigned int rhs_id;
    unsigned int currend_id;

    if (node->type != T_OR)
        return;

    fprintf(out, "%u [label \"||\";\n]", currend_id = *node_id);
    lhs_id = ++*node_id;
    ast_print_node(node->child.child_or.lhs, out, node_id);
    fprintf(out, "%u -> %u", currend_id, lhs_id);
    rhs_id = ++*node_id;
    ast_print_node(node->child.child_or.rhs, out, node_id);
    fprintf(out, "%u -> %u", currend_id, rhs_id);
}

void ast_or_destruct_node(struct ast_node_compound_list *node)
{
    if (node->type != T_OR)
        return;
    free(node);
}

void ast_or_destruct(struct ast_node_compound_list *node)
{
    if (node->type != T_OR)
        return;
    ast_destruct(node->child.child_or.lhs);
    ast_destruct(node->child.child_or.rhs);
    free(node);
}

