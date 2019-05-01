#ifndef AST_ANDOR_H
# define AST_ANDOR_H
# include "ast.h"
int check_andor(struct parser_s *p);
struct s_node_and_or *init_andor(struct parser_s *p);
void andor_store(struct s_node_and_or *andor, 
struct s_node_pipeline *new_pipeline, int nb_child);
int find_pipeline(struct parser_s *p, struct s_node_and_or *s_andor);
#endif