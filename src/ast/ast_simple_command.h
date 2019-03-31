#ifndef AST_SIMPLE_COMMAND_H
# define AST_SIMPLE_COMMAND_H
# include "ast.h"
struct s_simple_cmd *init_simple_command(struct parser_s *p);
void simple_command_store(struct s_simple_cmd *command, struct s_node_command *new_command);
int find_assign(struct parser_s *p, struct s_simple_cmd *s_command);
int find_redir(struct parser_s *p, struct s_simple_cmd *s_command);
int find_word(struct parser_s *p, struct s_simple_cmd *s_command);
#endif
