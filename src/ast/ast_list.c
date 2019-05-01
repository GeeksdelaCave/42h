#include "ast.h"
struct s_node_list *init_list(struct parser_s *p)
{
    struct s_node_list *s_list = malloc(sizeof(struct s_node_list));
    s_list->and_or = malloc(sizeof(struct s_node_and_or) * check_list(p));
    s_list->child = 0;
    return s_list;
}

int check_list(struct parser_s *p)
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

void list_store(struct s_node_list *list, struct s_node_and_or *new_and_or,
int nb_child)
{
    list->and_or[nb_child] = *new_and_or;
}

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