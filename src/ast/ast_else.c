/**
 ** \file  ast_else.c
 */
#include "ast.h"
/**
 ** \brief initialization of else node 
 ** 
 ** \return a struct s_node_else
 */  
struct s_node_else *init_else()
{
    struct s_node_else *node_else = malloc(sizeof(struct s_node_else));
    return node_else;
}
/**
 ** \brief find a else node 
 ** 
 ** \return 1 or 0 if find the else node
 */ 
int find_else(struct parser_s *p, struct s_node_else *node_else)
{
    struct list_node_s *else_body = ast_check_node(p, COUMPOUND);
    struct list_node_s *elif_body = ast_check_node(p, COUMPOUND);
    //struct list_node_s *then_body = ast_check_node(p, COUMPOUND);
	if (!else_body)
    {
	    return 0;
    } 
    if (elif_body != NULL)
	{
	    node_else->else_body = NULL;
        node_else->elif_body = else_body->node->compoundlist;
        node_else->then_body = elif_body->node->compoundlist;
    }
    else
	{
	  node_else->else_body = else_body->node->compoundlist;  
      node_else->elif_body = NULL;
      node_else->then_body = NULL; 
    }
	return 1;
}