/**
 ** \file ast_if.h
 ** \brief Declaration file ast if
 */
#ifndef AST_IF_H
#define AST_IF_H
/**
 ** \fn struct s_node_if *init_if()
 */
struct s_node_if *init_if();
/**
 ** \fn int find_if(struct parser_s *p, struct s_node_if *node_if)
 */
int find_if(struct parser_s *p, struct s_node_if *node_if);
#endif
