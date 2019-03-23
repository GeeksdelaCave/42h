# include "exec.h"
# 
void exec_if_node(struct ast_node_if *node)
{
    exec_node(node->condition);
    if (!exec->status)
        exec_node(node->if_body);
    else
        exec_node(node->else_body);
}
