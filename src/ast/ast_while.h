/**
 ** \file ast_while.h
 ** \brief Declaration file ast while
 */
#ifndef AST_WHILE_H
#define AST_WHILE_H
/**
 ** \fn struct s_node_while *init_while()
 */
struct s_node_while *init_while();
/**
 ** \fn int find_while(struct parser_s *p, struct s_node_while *node_while)
 */
int find_while(struct parser_s *p, struct s_node_while *node_while);
#endif
