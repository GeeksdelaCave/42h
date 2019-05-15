#ifndef EXEC_H
#define EXEC_H

#include "ast.h"

void exec_node(struct list_node_s *body);
void exec_if_node(struct s_node_if *node);
void exec_while_node(struct  *s_node_while node);
void redirection (int argc, char* argv[]);
void exec_redirection_node(struct list_node_s *n, struct list_node_s *prev, struct list_node_s *next, struct s_node_redirection *node);
#endif /* EXEC_H */
