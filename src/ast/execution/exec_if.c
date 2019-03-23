#include "exec.h"

/**
 * @brief Execute a if node, using child structure.
 * @param node The node to execute
 * @return The return code of the executed body
 */
int exec_if_node(struct ast_node_compound_list *node)
{
    // If node isn't what we expected
    if (!node || (node->type != T_IF))
        return ERROR_TYPE_NOT_SUPPORTED;

    // If the condition value is ok, then execute the body
    if (node->child.child_if.condition &&
        node->child.child_if.if_body &&
        exec_node(node->child.child_if.condition) == 0)
        return exec_node(node->child.child_if.if_body);

    // Else, if there is a else body, execute it
    else if (node->child.child_if.else_body)
        return exec_node(node->child.child_if.else_body);

    // If nothing
    else
        return 0;
}
