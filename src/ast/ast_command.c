/**
 ** \file  ast_command.c
 */
#include "ast.h"
/**
 ** \brief initialization of command node
 **
 ** \return a struct s_node_command
 */
struct s_node_command *init_command_node()
{
    struct s_node_command *new_node = malloc(sizeof(struct s_node_command));
    if (new_node == NULL)
    {
        return NULL;
    }
    new_node->type = -1;
    new_node->struct_type = malloc(sizeof(union all_grammar));
    return new_node;
}
/**
 ** \brief check_type_cmd
 **
 ** \param  p of type struct parser_s
 **
 ** \return a enum type_grammar
 */
enum type_grammar check_type_cmd(struct parser_s *p)
{
    enum type_grammar pnode = list_type_lookup(p->nodes, FOR);
    if (!pnode)
    {
        pnode = list_type_lookup(p->nodes, WHILE);
    }
    if (!pnode)
    {
        pnode = list_type_lookup(p->nodes, UNTIL);
    }
    if (!pnode)
    {
        pnode = list_type_lookup(p->nodes, CASE);
    }
    if (!pnode)
    {
        pnode = list_type_lookup(p->nodes, IF);
    }
    return pnode;
}
/**
 ** \brief find_s_command
 **
 ** \param  p of type struct parser_s
 **
 ** \return a int
 */
int find_s_command(struct parser_s *p)
{
    enum type_grammar type = SIMPLECOMMAND ;
    int excla = ast_check_sym(p, EXCLA);
    int pipe = ast_check_sym(p, PIPE);
    struct list_node_s *command_node = ast_check_node(p, SIMPLECOMMAND);
    struct s_node_command *command;
    if (!command_node)
    {
        type = check_type_cmd(p);
        command_node = check_shell_cmd(p);
    }
    if (!command_node)
    {
        return 0;
    }
    command = init_command_node();
    command->type = type;
    command->struct_type->command = command_node->node->command;
    command->excla = excla;
    command->pipe = pipe;
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->command = command;
    list_node_store(p->nodes, grammar, COMMAND);
    return 1;
}
/**
 ** \brief check_shell_cmd
 **
 ** \param  p of type struct parser_s
 **
 ** \return a struct list_node_s
 */
struct list_node_s *check_shell_cmd(struct parser_s *p)
{
    struct list_node_s *pnode = ast_check_node(p, FOR);
    if (!pnode)
    {
        pnode = ast_check_node(p, WHILE);
    }
    if (!pnode)
    {
        pnode = ast_check_node(p, UNTIL);
    }
    if (!pnode)
    {
        pnode = ast_check_node(p, CASE);
    }
    if (!pnode)
    {
        pnode = ast_check_node(p, IF);
    }
    return pnode;
}
