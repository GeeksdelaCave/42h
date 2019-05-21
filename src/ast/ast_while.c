/**
 ** \file  ast_while.c
 */
#include "ast.h"
/**
 ** \brief initialization of whule node
 **
 ** \return a struct s_node_while
 */
struct s_node_while *init_while()
{
    struct s_node_while *node_while = malloc(sizeof(struct s_node_while));
    return node_while;
}
/**
 ** \brief find a while node
 ** \param p a type of struct parser_s
 ** \param node_until a type of struct s_node_while
 ** \return 0 or 1 if find while node
 */
int find_while(struct parser_s *p, struct s_node_while *node_while)
{
    struct list_node_s *cmp_node = ast_check_node(p, COUMPOUND);
    struct list_node_s *dogroup_node = ast_check_node(p, DOGROUP);
    if (!cmp_node || !dogroup_node)
    {
        return 0;
    }
    node_while->condition = cmp_node->node->compoundlist;
    node_while->dogroup = dogroup_node->node->dogroup->cpd;
    return 1;
}
