/**
 ** \file ast_command.h
 ** \brief Declaration file ast_command
 */
#ifndef AST_COMMAND_H
#define AST_COMMAND_H
#include "ast.h"
/**
 ** \fn struct s_node_command *init_command_node()
 */   
struct s_node_command *init_command_node();
/**
 ** \fn int find_s_command(struct parser_s *p)
 */ 
int find_s_command(struct parser_s *p);
/**
 ** \fn struct list_node_s *check_shell_cmd(struct parser_s *p)
 */
struct list_node_s *check_shell_cmd(struct parser_s *p);
#endif