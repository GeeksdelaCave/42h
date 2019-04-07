# include "exec.h"

void tree_traversal(struct ast_node_compound_list *node)
{
    //ast_print_node(node);

    for (size_t index = 0; index < NODE_TYPE_COUNT; index++)
        tree_traversal(node->child[index]);
}
