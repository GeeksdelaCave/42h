#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "ast.h"

typedef void (*f_ast_print)(struct ast_node_compound_list *, FILE *,
                            unsigned int *);

struct ast_print_switch
{
    enum shell_command_child_type type;
    f_ast_print fct;
};

struct ast_print_switch print_table[NODE_TYPE_COUNT] =
{
    {T_IF, ast_if_print}
};

void ast_print_node(struct ast_node_compound_list *ast, FILE *out,
                    unsigned int *node_id)
{
    assert(ast);
    for (register int i = 0; i < NODE_TYPE_COUNT; ++i)
    {
        if (print_table[i].type == ast->type)
            (print_table[i].fct)(ast, out, node_id);
    }
}
