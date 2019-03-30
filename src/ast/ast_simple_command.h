#ifndef AST_SIMPLE_COMMAND_H
# define AST_SIMPLE_COMMAND_H
# include "ast.h"
struct list_node_s *find_assign(struct parser_s *p);
struct list_node_s *find_redir(struct parser_s *p);
struct list_node_s *find_word(struct parser_s *p);
void simple_command_store(struct s_node_command *command, 
    struct s_node_command *new_command);
struct list_node_s *merge_command(struct parser_s *p);
struct s_node_command *init_simple_command(struct parser_s *p);
int check_redir(struct parser_s *p, struct s_node_command *command);
int check_word(struct parser_s *p, struct s_node_command *command);
int check_assign(struct parser_s *p, struct s_node_command *command);
#endif