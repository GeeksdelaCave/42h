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

int find_s_command(struct parser_s *p)
{
    int excla = ast_check_sym(p, EXCLA);
    int pipe = ast_check_sym(p, PIPE);
    struct list_node_s *command_node = ast_check_node(p, SIMPLECOMMAND);
    struct s_node_command *command;
    if(!command_node)
    {
        return 0;
    }
    command = init_command_node();
    command->type = SIMPLECOMMAND;
    command->struct_type->command = command_node->node->command;
    command->excla = excla;
    command->pipe = pipe;
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->command = command;
    list_node_store(p->nodes, grammar, COMMAND);
    return 1;
}

/*
int find_fundec(struct parser_s *p)
{
    struct list_node_s *command_node = ast_check_node(p, FUNDEC);
    struct s_node_funcdec_command *command;
    if(!command_node)
    {
        return 0;
    }
    command = init_command_node();
    command->type = FUNDEC;
    command->struct_type->funcdec = command_node->node->funcdec;
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->funcdec = command;
    list_node_store(p->nodes, grammar, COMMAND);
    return 1;
}*/

/*
ici il manque les shell commandes, if while for etc...
*/