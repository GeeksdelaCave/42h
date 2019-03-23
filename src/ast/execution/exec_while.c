#include "exec.h"

int exec_while_node(struct ast_node_compound_list *node)
{
    // If node isn't what we expected
    if (!node || (node->type != T_WHILE))
        return ERROR_TYPE_NOT_SUPPORTED;

    int retour = 0;

    // Checking condition before calling
    if (node->child.child_while.condition)
    {
        // Execute it, maybe we can have side-effects in it
        while (exec_node(node->child.child_while.condition))
        {
            // Checking and executing body
            if (node->child.child_while.exec)
                retour = exec_node(node->child.child_while.exec);
        }
    }

    return retour;
}
