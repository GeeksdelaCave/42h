/**
 * @brief File relative to the execution switch for the AST
 */

#include <assert.h>

#include "ast.h"
#include "exec.h"



void exec_node(list_node_s *body)
{
    //assert(body);
    switch (node->type)
    {
        case IF: exec_if(&body->node.node_if);
            break;
        case WHILE: exec_while(&body->node.node_while);
            break;
        default:
            assert(0);
    }
}
