/**
 ** \file ast_else.h
 ** \brief Declaration file ast else
 */
#ifndef AST_ELSE_H
#define AST_ELSE_H
/**
 ** \fn struct s_node_else *init_else()
 */
struct s_node_else *init_else();
/**
 ** \fn int find_else(struct parser_s *p, struct s_node_else *node_if)
 */
int find_else(struct parser_s *p, struct s_node_else *node_if);
#endif
