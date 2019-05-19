/**
 ** \file ast_until.h
 ** \brief Declaration file ast until
 */
#ifndef AST_UNTIL_H
#define AST_UNTIL_H
/**
 ** \fn struct s_node_until *init_until()
 */  
struct s_node_until *init_until();
/**
 ** \fn int find_until(struct parser_s *p, struct s_node_until *node_until)
 */
int find_until(struct parser_s *p, struct s_node_until *node_until);
#endif