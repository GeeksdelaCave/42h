#ifndef AST_SIMPLE_COMMAND_H
# define AST_SIMPLE_COMMAND_H
# include "ast.h"
struct list_node_s *find_assign(struct parser_s *p);
struct list_node_s *find_redir(struct parser_s *p);
struct list_node_s *find_word(struct parser_s *p);
#endif