#ifndef EXEC_H
#define EXEC_H

#include "../ast/ast.h"

int exec_node(struct ast_node_compound_list *ast);

int exec_if_node(struct ast_node_compound_list *node);
int exec_while_node(struct ast_node_compound_list *node);
int exec_for_node(struct ast_node_compound_list *node);
int exec_cmd_node(struct ast_node_compound_list *node);

#endif /* EXEC_H */
