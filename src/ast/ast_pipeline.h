/**
 ** \file ast_pipeline.h
 ** \brief Declaration file ast pipeline
 */
#ifndef AST_PIPELINE_H
# define AST_PIPELINE_H
# include "ast.h"
 /**
 ** \fn int check_pipeline(struct parser_s *p)
 */  
int check_pipeline(struct parser_s *p);
 /**
 ** \fn struct s_node_pipeline *init_pipeline(struct parser_s *p)
 */ 
struct s_node_pipeline *init_pipeline(struct parser_s *p);
 /**
 ** \fn int find_command(struct parser_s *p, struct s_node_pipeline *s_pipeline)
 */ 
int find_command(struct parser_s *p, struct s_node_pipeline *s_pipeline);
 /**
 ** \fn void pipeline_store(struct s_node_pipeline *pipeline, 
 **  struct s_node_pipeline *new_command, int nb_child)
 */ 
void pipeline_store(struct s_node_pipeline *pipeline, 
struct s_node_pipeline *new_command, int nb_child);
 /**
 ** \fn struct s_node_pipeline *init_pipeline(struct parser_s *p);
 **  int check_pipeline(struct parser_s *p)
 */ 
struct s_node_pipeline *init_pipeline(struct parser_s *p);
int check_pipeline(struct parser_s *p);
#endif