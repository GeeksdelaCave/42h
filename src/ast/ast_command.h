#ifndef AST_COMMAND_H
# define AST_COMMAND_H
# include "ast.h"
struct s_node_command *init_command_node();
int find_s_command(struct parser_s *p);
struct list_node_s *check_shell_cmd(struct parser_s *p);
#endif