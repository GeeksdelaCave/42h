#include "ast.h"

void ast_print_node(struct ast_node_compound_list *ast,
                    FILE *out,
                    unsigned int *node_id)
{
    switch (ast->type)
    {
        case T_IF:
            ast_if_print(ast, out, node_id);
        case T_CASE:
            ast_case_print(ast, out, node_id);
        case T_FOR:
            ast_for_print(ast, out, node_id);
        case T_WHILE:
            ast_while_print(ast, out, node_id);
        case T_RED:
            ast_red_print(ast, out, node_id);
        case T_CMD:
            ast_cmd_print(ast, out, node_id);
        default:
            printf("Fatal: unhandled type");
    }
}
