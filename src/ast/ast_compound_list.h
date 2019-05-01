#ifndef AST_COMPOUND_LIST_H
#define AST_COMPOUND_LIST_H
#include "ast.h"
struct s_node_compound_list *init_compound(struct parser_s *p);
int check_compound_list(struct parser_s *p);
void compound_list_store(struct s_node_compound_list *cpd,
struct s_node_and_or *new_and_or, int nb_child);
int find_and_or(struct parser_s *p, struct s_node_compound_list *s_cpd);
#endif