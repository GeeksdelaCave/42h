/**
 ** \file ast_andor.h
 ** \brief Declaration file ast_andor
 */
#ifndef AST_ANDOR_H
# define AST_ANDOR_H
# include "ast.h"
/**
 ** \fn int check_andor(struct parser_s *p)
 */  
int check_andor(struct parser_s *p);
/**
 ** \fn struct s_node_and_or *init_andor(struct parser_s *p) 
 */ 
struct s_node_and_or *init_andor(struct parser_s *p);
/**
 ** \fn void andor_store(struct s_node_and_or *andor, struct s_node_pipeline 
 ** new_pipeline, int nb_child)
 */ 
void andor_store(struct s_node_and_or *andor, struct s_node_pipeline 
*new_pipeline, int nb_child);
/**
 ** \fn int find_pipeline(struct parser_s *p, struct s_node_and_or *s_andor)
 */ 
int find_pipeline(struct parser_s *p, struct s_node_and_or *s_andor);
#endif