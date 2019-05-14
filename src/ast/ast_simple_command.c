#include "ast.h"

int check_simple_command(struct parser_s *p)
{
    int nb_child = 0;
    struct list_node_s *pnode = p->nodes;
    for(;pnode; pnode = pnode->next)
    {
        if((pnode->type == ASSIGN) || (pnode->type == WORD1) || 
        (pnode->type == REDIRECTION))
        {
            nb_child++;
        }
    }
    return nb_child;
}

struct s_simple_cmd *init_simple_command(struct parser_s *p)
{
    struct s_simple_cmd *s_command = malloc(sizeof(struct s_simple_cmd));
    s_command->child = 0;
    s_command->type = SIMPLECOMMAND;
    s_command->child_node = malloc(
    sizeof(struct s_node_command) * check_simple_command(p));
    return s_command;
}

void simple_command_store(struct s_simple_cmd *command, struct s_node_command *new_command, int nb_child)
{
    command->child_node[nb_child] = *new_command;
}

int find_assign(struct parser_s *p, struct s_simple_cmd *s_command)
{
    struct list_node_s *assign_node = ast_check_node(p, ASSIGN);
    struct s_node_command *simple_command;
    if (!assign_node)
    {
        return 0;
    }
    simple_command = init_command_node();
    simple_command->type = ASSIGN;
    simple_command->struct_type->assign = assign_node->node->assign;
    simple_command_store(s_command, simple_command,s_command->child);
    s_command->child++;
    return 1;
}

int find_redir(struct parser_s *p, struct s_simple_cmd *s_command)
{
    struct list_node_s *redirection_node = ast_check_node(p, REDIRECTION);
    struct s_node_command *simple_command;
    if (!redirection_node)
    {
        return 0;
    }
    simple_command = init_command_node();
    simple_command->type = REDIRECTION;
    simple_command->struct_type->redirection = redirection_node->
    node->redirection;
    simple_command_store(s_command, simple_command,s_command->child);
    s_command->child++;
    return 1;
}

int find_word(struct parser_s *p, struct s_simple_cmd *s_command)
{
    struct list_node_s *word_node = ast_check_node(p, WORD1);
    struct s_node_command *simple_command;
    if (!word_node)
    {
        return 0;
    }
    simple_command = init_command_node();
    simple_command->type = WORD1;
    simple_command->struct_type->word = word_node->node->word;
    simple_command_store(s_command, simple_command,s_command->child);
    s_command->child++;
    return 1;
}