#ifndef AST_PIPELINE_H
# define AST_PIPELINE_H
# include "ast.h"
int check_pipeline(struct parser_s *p);
struct s_node_pipeline *init_pipeline(struct parser_s *p);
int find_command(struct parser_s *p, struct s_node_pipeline *s_pipeline);
void pipeline_store(struct s_node_pipeline *pipeline, struct s_node_pipeline 
    *new_command, int nb_child);
struct s_node_pipeline *init_pipeline(struct parser_s *p);
int check_pipeline(struct parser_s *p);
#endif