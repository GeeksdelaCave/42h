#include "ast.h"

/*
** init commande node
*/
struct s_node_command *init_command_node()
{
    struct s_node_command *new_node = malloc(sizeof(struct s_node_command));
    if (new_node == NULL)
    {
        printf("fail init command\n");
      return NULL;
    }
    new_node->type = -1;
    new_node->struct_type = malloc(sizeof(union all_grammar));
    return new_node;
}

struct list_node_s *merge_command(struct parser_s *p)
{
    struct list_node_s *assign_node = ast_check_node(p, COMMAND);
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