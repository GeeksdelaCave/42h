#include "exec.h"

void exec_while_node(struct s_node_while *node)
{
    assert(node);
  for(exec_node(node->compoundlist); !shell->status; exec_node(node->condition))
    exec_node(node->);
}
