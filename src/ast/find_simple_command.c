#include "ast.h"

struct s_node_command *init_simple_command(struct parser_s *p)
{
    struct s_node_command *simple_command = find_assign(p);
    if(simple_command){
        return simple_command;
    }
    simple_command = find_redir(p);
    if(simple_command){
        return simple_command;
    }
    simple_command = find_word(p);
    if(simple_command){
        return simple_command;
    }
    return NULL;
}

int check_assign(struct parser_s *p, struct s_node_command *command)
{
    struct s_node_command *new_node = find_assign(p);
    if(!new_node)
        return 0;
    simple_command_store(command, new_node);
    return 1;
}
int check_word(struct parser_s *p, struct s_node_command *command)
{
    struct s_node_command *new_node = find_word(p);
    if(!new_node)
        return 0;
    simple_command_store(command, new_node);
    return 1;    
}
int check_redir(struct parser_s *p, struct s_node_command *command)
{
    struct s_node_command *new_node = find_redir(p);
    if(!new_node)
        return 0;
    simple_command_store(command, new_node);
    return 1;    
}

void simple_command_store(struct s_node_command *command, 
struct s_node_command *new_command)
{
    for(; command->next; command = command->next);
    command->next = new_command;
}

struct s_node_command *find_assign(struct parser_s *p)
{
    struct list_node_s *assign_node = ast_check_node(p, ASSIGN);
    struct s_node_command *simple_command;
    if(!assign_node)
    {
        return NULL;
    }
    simple_command = init_command_node();
    simple_command->type = ASSIGN;
    simple_command->struct_type->assign = assign_node->node->assign;
    return simple_command;
}

struct s_node_command *find_redir(struct parser_s *p)
{
    struct list_node_s *redirection_node = ast_check_node(p, REDIRECTION);
    struct s_node_command *simple_command;
    if(!redirection_node)
    {
        return NULL;
    }
    simple_command = init_command_node();
    simple_command->type = REDIRECTION;
    simple_command->struct_type->redirection = redirection_node->
    node->redirection;
    return simple_command;
}

struct s_node_command *find_word(struct parser_s *p)
{
    struct list_node_s *word_node = ast_check_node(p, WORD1);
    struct s_node_command *simple_command;
    if(!word_node)
    {
        return NULL;
    }
    simple_command = init_command_node();
    simple_command->type = WORD1;
    simple_command->struct_type->word = word_node->node->word;
    return simple_command;
}