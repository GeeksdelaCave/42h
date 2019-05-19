/**
 ** \file  ast_compound_list.c
 */
#include "ast.h"
/**
 ** \brief initialization of compound node 
 ** 
 ** \return a struct s_node_compound_list
 */ 
struct s_node_compound_list *init_compound(struct parser_s *p)
{
    struct s_node_compound_list *s_compound = malloc(
    sizeof(struct s_node_compound_list));
    s_compound->and_or = malloc(sizeof(struct s_node_and_or) *
    check_compound_list(p));
    s_compound->child = 0;
    return s_compound;
}
/**
 ** \brief check a list of compound
 ** \param p a type of struct parser_s
 ** \return a number of child
 */ 
int check_compound_list(struct parser_s *p)
{
    int nb_child = 0;
    struct list_node_s *pnode = p->nodes;
    for (;pnode; pnode = pnode->next)
    {
        if ((pnode->type == ANDOR))
        nb_child++;
    }
    return nb_child;
}
/**
 ** \brief store a list of compound
 ** \param cpd a type of struct s_node_compound_list
 */
void compound_list_store(struct s_node_compound_list *cpd,
struct s_node_and_or *new_and_or, int nb_child)
{
    cpd->and_or[nb_child] = *new_and_or;
}
/**
 ** \brief find andor
 ** 
 ** \param p a type of struct parser_s
 **
 ** \param s_cpd a type of struct s_node_compound_list
 ** 
 ** \return 1 or 0 if find the and or node
 */
int find_and_or(struct parser_s *p, struct s_node_compound_list *s_cpd)
{
    struct list_node_s *and_or = ast_check_node(p, ANDOR);
    int simple_and = ast_check_sym(p, S_AND);
    int virgule = ast_check_sym(p, VIRGULE);
    struct s_node_compound_list *cpd;
    if(!and_or)
    {
        return 0;
    }
    cpd = malloc(sizeof(struct s_node_compound_list));
    cpd->and_or = and_or->node->andor;
    cpd->and_or->simple_and = simple_and;
    cpd->and_or->virgule = virgule;
    compound_list_store(s_cpd, cpd->and_or, s_cpd->child);
    s_cpd->child++;
    return 1;
}