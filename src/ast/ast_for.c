/**
 ** \file  ast_for.c
 */
#include "ast.h"
/**
 ** \brief initialization of for node
 **
 ** \return a struct s_node_for
 */
struct s_node_for *init_for()
{
    struct s_node_for *node_for = malloc(sizeof(struct s_node_for));
    return node_for;
}
