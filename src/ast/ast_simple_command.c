#include "ast.h"
#include "ast_simple_command.h"
struct s_simple_cmd *init_simple_command(struct parser_s *p)
{
    struct s_simple_cmd *s_command = malloc(sizeof(struct s_simple_cmd));
    int nb_child = check_simple_command(p);
    s_command->child = nb_child;
    s_command->type = SIMPLECOMMAND;
    s_command->child_node = malloc(sizeof(struct s_node_command) * nb_child);
    return s_command;
}

int check_simple_command(struct parser_s *p)
{
    int nb_child = 0;
    struct list_node_s *pnode = p->nodes;
    for(;pnode->next; pnode = pnode->next)
    {
        nb_child++;
    }
    return nb_child;
}

void simple_command_store(struct s_simple_command *command, 
struct s_node_command *new_command)
{
    for(int i = 0; i < command->child; i++)
    {
        if(!command->child_node[i])
        {
            command->child_node[i] = new_command;   
        }
    }
}

int find_assign(struct parser_s *p, struct s_simple_cmd *s_command)
{
  struct list_node_s *assign_node = ast_check_node(p, ASSIGN);
  struct s_node_command *simple_command;
  if(!assign_node)
  {
      return 0;
  }
  simple_command = init_command_node();
  simple_command->type = ASSIGN;
  simple_command->struct_type->assign = assign_node->node->assign;
  simple_command_store(s_command, simple_command);
  return 1;
}

int find_redir(struct parser_s *p, struct s_simple_cmd *s_command)
{
    struct list_node_s *redirection_node = ast_check_node(p, REDIRECTION);
    struct s_node_command *simple_command;
    if(!redirection_node)
    {
        return 0;
    }
    simple_command = init_command_node();
    simple_command->type = REDIRECTION;
    simple_command->struct_type->redirection = redirection_node->
    node->redirection;
    simple_command_store(s_command, simple_command);
    return 1;
}

int find_word(struct parser_s *p, struct s_simple_cmd *s_command)
{
    struct list_node_s *word_node = ast_check_node(p, WORD1);
    struct s_node_command *simple_command;
    if(!word_node)
    {
        return 0;
    }
    simple_command = init_command_node();
    simple_command->type = WORD1;
    simple_command->struct_type->word = word_node->node->word;
    simple_command_store(s_command, simple_command);
    return 1;
}