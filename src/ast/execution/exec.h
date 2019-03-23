# ifndef EXEC_H
# define EXEC_H

# include "../ast/ast.h"

struct s_exec
{
    int status;
};

struct s_exec *exec;
void exec_node(struct ast_node_compound_list *node);

void exec_if_node(struct ast_node_if *node);

# endif
