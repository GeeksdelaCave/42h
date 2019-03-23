/**
 * @brief File relative to the execution switch for the AST
 */

#include <assert.h>

#include "../ast/ast.h"
#include "exec.h"



typedef int (*ast_exec)(struct ast_node_compound_list *);

struct ast_exec_switch
{
    enum shell_command_child_type type;
    ast_exec fct;
};

struct ast_exec_switch exec_table[] =
    {
        {T_IF,      exec_if_node}
        //{T_CASE,    ast_case_exec},
        //{T_WHILE,   ast_while_exec},
        //{T_FOR,     ast_for_exec},
        //{T_RED,     ast_red_exec},
        //{T_CMD,     ast_cmd_exec},
        //{T_AND,     ast_and_exec},
        //{T_OR,      ast_or_exec},
        //{T_PIPE,    ast_pipe_exec}
    };

int exec_node(struct ast_node_compound_list *ast)
{
    assert(ast);
    for (register int i = 0; i < NODE_TYPE_COUNT; ++i)
    {
        if (exec_table[i].type == ast->type)
            return (exec_table[i].fct)(ast);
    }
    return ERROR_TYPE_NOT_FOUND;
}
