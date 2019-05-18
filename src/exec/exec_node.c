/**
 * @brief File relative to the execution switch for the AST
 */

#include <assert.h>

#include "ast.h"
#include "exec.h"


/**
 * @brief Execute a node, using list of nodestructure.
 * @param body The list node to execute
 */
void exec_node(list_node_s *body)
{
    //assert(body)n;
    assert(body);
    switch (body->type)
    {
        case IF: exec_if(&body->node.node_if);
            break;
        case WHILE: exec_while(&body->node.node_while);
            break;
        default:
            assert(0);
    }
}
