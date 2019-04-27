#ifndef AST_WHILE_H
#define AST_WHILE_H
struct s_node_while *init_while();
int find_while(struct parser_s *p, struct s_node_while *node_while);
#endif