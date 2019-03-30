#include "ast.h"

struct list_node_s *find_assign(struct parser_s *p)
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
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->command = simple_command;
    list_node_store(p->nodes, grammar, COMMAND); 
    return assign_node;
}

struct list_node_s *find_redir(struct parser_s *p)
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
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->command = simple_command;
    list_node_store(p->nodes, grammar, COMMAND);
    return redirection_node;
}

struct list_node_s *find_word(struct parser_s *p)
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
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->command = simple_command;
    list_node_store(p->nodes, grammar, COMMAND); 
    return word_node;
}