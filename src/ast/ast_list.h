#ifndef AST_LIST_H
# define AST_LIST_H
# include "ast.h"
struct s_node_list *init_list(struct parser_s *p);
int check_list(struct parser_s *p);
void list_store(struct s_node_list *list, struct s_node_and_or *new_and_or, int nb_child);
int list_and_or(struct parser_s *p, struct s_node_list *s_list);
#endif