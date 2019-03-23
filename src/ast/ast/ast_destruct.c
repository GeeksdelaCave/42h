#include "ast.h"


typedef void (*f_ast_destruct)(struct ast_node_compound_list *);

struct ast_print_switch
{
    enum shell_command_child_type type;
    f_ast_destruct fct;
};

struct ast_print_switch destruct_table[NODE_TYPE_COUNT] =
{
    {T_IF, ast_if_destruct}
};

void ast_destruct(struct ast_node_compound_list *ast)
{
    if (ast == NULL)
        return;
    for (register int i = 0; i < NODE_TYPE_COUNT; ++i)
    {
        if (destruct_table[i].type == ast->type)
            (destruct_table[i].fct)(ast);
    }
}
