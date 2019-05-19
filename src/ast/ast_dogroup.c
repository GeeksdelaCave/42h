/**
 ** \file  ast_dogroup.c
 */
#include "ast.h"
/**
 ** \brief initialization of dogroup node 
 ** 
 ** \return a struct s_do_group
 */ 
struct s_do_group *init_dogroup()
{
    struct s_do_group *dogroup = malloc(sizeof(struct s_do_group));
    return dogroup;
}
/**
 ** \brief find a coump node
 ** \param p type of struct parser_s 
 ** \param dogroup struct s_do_group
 ** \return 1 or 0 if find dogroup node 
 */ 
int find_coump(struct parser_s *p, struct s_do_group *dogroup)
{
    struct list_node_s *cmp_node = ast_check_last(p, COUMPOUND);
    if (!cmp_node)
    {
        return 0;
    };
    dogroup->cpd = cmp_node->node->compoundlist;
    return 1;
}