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
    {T_IF, ast_if_print}, {T_WHILE, ast_for_print}, {T_FOR, ast_for_print},
    {T_RED, ast_red_print}, {T_CMD, ast_cmd_print}
};
/*
static char *newastfilename(void)
{
    static char buf[PATH_MAX];
    time_t st;
    struct tm *t;
    struct stat buf2;
    int more = 0;
    st = time(NULL);
    t = localtime(&st);
    do
        snprintf(buf, "../src/ast-%d-%d-%")
}
*/
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
