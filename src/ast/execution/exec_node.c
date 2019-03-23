# include "exec.h"

void exec_node(struct ast_node_compound_list *node)
{
    //assert(node);
    mymalloc(node, sizeof(struct ast_node_compound_list));
    switch (node->type)
    {
    case T_IF:
        printf("ok if");
        exec_if_node(&node->child.child_if);
        break;
    default:
        printf("error\n");
        break;
    }
}
