#include "exec.h"


/**
 * @brief Execute a if node, using child structure.
 * @param node The node to execute
 * @return The return code of the executed body
 */
 struct shell
 {
     int status;
 };

void exec_if_node(struct list_node_s *node)
{
    //assert(node);
    exec_node(node->condition);
    if (!shell->status)
      exec_node(node->if_body);
    else
      exec_node(node->else_body);
}
