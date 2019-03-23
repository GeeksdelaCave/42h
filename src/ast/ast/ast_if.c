# include "ast.h"


struct ast_node_compound_list *create_node_if(struct ast_node_compound_list
                                              *condition,
                                              struct ast_node_compound_list
                                              *if_body,
                                              struct ast_node_compound_list
                                              *else_body)
{
    struct  ast_node_compound_list *node;
    mymalloc(node,sizeof(struct ast_node_compound_list*));

    if ( condition == NULL || if_body == NULL || else_body == NULL ||
         node == NULL)
        return NULL;
    node->type = T_IF;
    node->child.child_if.condition = condition;
    node->child.child_if.if_body = if_body;
    node->child.child_if.else_body = else_body;
    return node;
}

void ast_if_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned *node_id)
{
    unsigned current_node;

    if (node->type != T_IF)
        return;
    fprintf(out, "%u [label = \"IF\"];\n", current_node = *node_id);
    ++*node_id;

    if (node->child.child_if.condition)
    {
        fprintf(out, "%u -> %u\n",current_node, *node_id);
        ast_print_node(node->child.child_if.condition, out, node_id);
    }

    if (node->child.child_if.if_body)
    {
        fprintf(out, "%u->%u\n",current_node, *node_id);
        ast_print_node(node->child.child_if.if_body, out, node_id);
    }

    if (node->child.child_if.else_body)
    {
        fprintf(out, "%u->%u\n",current_node, *node_id);
        ast_print_node(node->child.child_if.else_body, out, node_id);
    }
}

int ast_if_exec(struct ast_node_compound_list *node)
{
    if (!node || (node->type != T_IF))
        return ERROR_TYPE_NOT_SUPPORTED;
    if (ast_exec_node(node->child.child_if.condition) == 0)
        return ast_exec_node(node->child.child_if.if_body);
    else if (node->child.child_if.else_body)
        return ast_exec_node(node->child.child_if.else_body);
    else
        return 0;
}

void ast_if_destruct_node(struct ast_node_compound_list *node)
{
    if(node->type != T_IF)
        return;
    free(node);
}

void ast_if_destruct(struct ast_node_compound_list *node)
{
    if (node->type != T_IF)
        return;
    ast_destruct(node->child.child_if.condition);
    ast_destruct(node->child.child_if.if_body);
    ast_destruct(node->child.child_if.else_body);
    free(node);
}
