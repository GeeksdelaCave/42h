#ifndef AST_ELSE_H
#define AST_ELSE_H
struct s_node_else *init_else();
int find_else(struct parser_s *p, struct s_node_else *node_if);
#endif
