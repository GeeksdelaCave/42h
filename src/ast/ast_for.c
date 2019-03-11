# include "ast.h"

struct ast_node_compound_list *create_node_for(char *varname, char **values,
                                                 struct ast_node_compound_list
                                                 *exec)
{
    struct ast_node_compound_list *node;

    if (varname == NULL || values == NULL || exec == NULL)
        return NULL;

    node->type = T_FOR;
    node->child.child_for.varname = varname;
    node->child.child_for.values = values;
    node->child.child_for.exec = exec;
    return node;

}

void ast_for_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned *node_id)
{
    unsigned *current_node;

    if (node->type != T_FOR)
        return;
    fprintf(out, "%u [label = \"FOR\"];\n", current_node = *node_id);
    ++*node_id;

    if (node->child.child_for.varname)
    {
        fprintf(out, "%u -> %u\n", current_node, *node_id);
        ast_print_node(node->child.child_for.varname, out, node_id);
    }

    if (node->child.child_for.values)
    {
        fprintf(out, "%u -> %u\n", current_node, *node_id);
        ast_print_node(node->child.child_for.values, out, node_id);
    }

    if (node->child.child_for.exec)
    {
        fprintf(out, "%u -> %u\n", current_node, *node_id);
        ast_print_node(node->child.child_for.exec, out, node_id);
    }
}
