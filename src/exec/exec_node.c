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
<<<<<<< HEAD
    //assert(body);
    switch (node->type)
=======
    assert(body);
    switch (body->type)
>>>>>>> d05fc55a4ceebaa9f4f17618dd30e26f9ce65649
    {
        case IF: exec_if(&body->node.node_if);
            break;
        case WHILE: exec_while(&body->node.node_while);
            break;
        default:
            assert(0);
    }
}
