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

void exec_if_node(struct s_node_if *body)
{
    //assert(node)s;
    struct s_node_compound_list *res = malloc(sizeof(struct s_node_compound_list));
    exec_node(res->body.condition);
    if (!shell->status)
      exec_node(res->body.if_body);
    else
      exec_node(body->else_body);
}
