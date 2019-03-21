#ifndef AST_BIN_H
#define AST_BIN_H

struct s_ast_bin
{
    struct ast_node_compound_list *lhs;
    struct ast_node_compound_list *rhs;
}

#endif
