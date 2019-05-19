/**
 ** \file  ast_list.c
 */
#include "ast.h"
/**
 ** \brief initialization of list node 
 ** 
 ** \return a struct s_node_list
 */  
struct s_node_list *init_list(struct parser_s *p)
{
    struct s_node_list *s_list = malloc(sizeof(struct s_node_list));
    s_list->and_or = malloc(sizeof(struct s_node_and_or) * check_list(p));
    s_list->child = 0;
    return s_list;
}
/**
 ** \brief check a list node 
 ** \param p a type of struct parser_s
 ** \return a number of child
 */ 
int check_list(struct parser_s *p)
{
    int nb_child = 0;
    struct list_node_s *pnode = p->nodes;
    for(;pnode; pnode = pnode->next)
    {
      if((pnode->type == ANDOR))
        nb_child++;
    }
    return nb_child;
}
/**
 ** \brief a liste store
 ** 
 ** \param list type of struct s_node_list
 ** 
 ** \param new_and_or type of struct s_node_and_or
 ** 
 ** \param a number of child
 */ 
void list_store(struct s_node_list *list, struct s_node_and_or *new_and_or,
int nb_child)
{
    list->and_or[nb_child] = *new_and_or;
}
/**
 ** \brief check a list and or node 
 ** \param p a type of struct parser_s
 ** \param s_list a type of struct s_node_list
 ** \return 1 or 0 if find the list and or node
 */ 
int list_and_or(struct parser_s *p, struct s_node_list *s_list)
{
    struct list_node_s *and_or = ast_check_node(p, ANDOR);
    int simple_and = ast_check_sym(p, S_AND);
    int virgule = ast_check_sym(p, VIRGULE);
    struct s_node_list *list;
    if (!and_or)
    {
        return 0;
    }
    list = malloc(sizeof(struct s_node_list));
    list->and_or = and_or->node->andor;
    list->and_or->simple_and = simple_and;
    list->and_or->virgule = virgule;
    list_store(s_list, list->and_or, s_list->child);
    s_list->child++;
    return 1;
}