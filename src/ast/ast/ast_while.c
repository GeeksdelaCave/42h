# include "ast.h"

struct ast_node_compound_list *create_node_while(struct ast_node_compound_list
                                                 *condition,
                                                 struct ast_node_compound_list
                                                 *exec)
{
    struct ast_node_compound_list *node;

    mymalloc(node, sizeof(struct ast_node_compound_list));
    node->type = T_WHILE;
    node->child.child_while.condition = condition;
    node->child.child_while.exec = exec;
    return node;
}

void ast_while_print(struct ast_node_compound_list *node, FILE *out,
                     unsigned int *node_id)
{
    unsigned lhs_id, rhs_id, current_node; //lhs_id = id du cote gauche
    fprintf(out, "%u [label = \"while\"];\n", current_node = *node_id);
    lhs_id = ++*node_id;
    ast_print_node(node->child.child_while.condition, out, node_id);
    fprintf(out, "%u -> %u\n", current_node, lhs_id);
    fprintf(out, "%u [label = \"while\"];\n", current_node = *node_id);
    rhs_id = ++*node_id;
    ast_print_node(node->child.child_while.exec, out, node_id);
    fprintf(out, "%u -> %u\n", current_node, rhs_id);
}

int ast_while_exec(struct ast_node_compound_list *node)
{
    // TODO EXECUTION
    return 0;
}

void ast_while_destruct_node(struct ast_node_compound_list *node)
{
    if (node->type != T_WHILE)
        return;

    free(node);
}


void ast_while_destruct(struct ast_node_compound_list *node)
{
    if (node->type != T_WHILE)
        return;
    ast_destruct(node->child.child_while.condition);
    ast_destruct(node->child.child_while.exec);
    free(node);
}
