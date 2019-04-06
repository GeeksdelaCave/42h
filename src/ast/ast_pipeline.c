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
    //printf("NUMBER OF CHILD ---- %d \n", nb_child);
    return nb_child;
}

struct s_node_pipeline *init_pipeline(struct parser_s *p)
{
    struct s_node_pipeline *s_pipline = malloc(sizeof(struct s_node_pipeline));
    s_pipline->commands = malloc(sizeof(struct s_node_command) * check_pipeline(p));
    s_pipline->child = 0;
    return s_pipline;
}

void pipeline_store(struct s_node_pipeline *pipeline, struct s_node_pipeline *new_command, int nb_child)
{
    pipeline->commands[nb_child] = *new_command->commands;
    pipeline->b_and = new_command->b_and;
    pipeline->b_or = new_command->b_or;
}

int find_command(struct parser_s *p, struct s_node_pipeline *s_pipeline)
{
    struct list_node_s *command_node = ast_check_node(p, COMMAND);
    int b_and = ast_check_sym(p, AND);
    int b_or = ast_check_sym(p, OR);
    struct s_node_pipeline *pipeline;
    if(!command_node)
    {
        return 0;
    }
    pipeline = malloc(sizeof(struct s_node_pipeline));
    pipeline->commands= command_node->node->command;
    pipeline->b_and = b_and;
    pipeline->b_or = b_or;
    pipeline_store(s_pipeline, pipeline, s_pipeline->child);
    s_pipeline->child++;
    return 1;
}
