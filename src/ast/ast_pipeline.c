#include "ast.h"
int check_pipeline(struct parser_s *p)
{
    int nb_child = 0;
    struct list_node_s *pnode = p->nodes;
    for(;pnode; pnode = pnode->next)
    {
        if((pnode->type == COMMAND))
            nb_child++;
    }
    printf("NUMBER OF CHILD %d \n", nb_child);
    return nb_child;
}

struct s_node_pipeline *init_pipeline(struct parser_s *p)
{
    struct s_node_pipeline *s_pipline = malloc(sizeof(struct s_node_pipeline));
    s_pipline->commands = malloc(sizeof(struct s_node_command) * check_pipeline(p));
    s_pipline->child = 0;
    return s_pipline;
}

void pipeline_store(struct s_node_pipeline *pipeline, struct s_node_command *new_command, int nb_child)
{
    printf("NEW COMMAND TYPE %d \n", new_command->type);
    pipeline->commands[nb_child] = *new_command;   
    printf("NEW COMMAND TYPE %d ||| %d \n", pipeline->commands[nb_child].type, nb_child);
}

int find_command(struct parser_s *p, struct s_node_pipeline *s_pipeline)
{
  
  struct list_node_s *command_node = ast_check_node(p, COMMAND);
  struct s_node_pipeline *pipeline;
  if(!command_node)
  {
      return 0;
  }
  pipeline = init_pipeline(p);
  pipeline->commands[s_pipeline->child] = *command_node->node->command;
  pipeline_store(s_pipeline, command_node->node->command ,s_pipeline->child);
  s_pipeline->child++;
  return 1;
}

