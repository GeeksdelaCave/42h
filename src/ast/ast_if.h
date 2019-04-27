#ifndef AST_IF_H
#define AST_IF_H
struct s_node_if *init_if();
int find_if(struct parser_s *p, struct s_node_if *node_if);
#endif