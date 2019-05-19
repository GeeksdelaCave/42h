/**
 ** \file  ast_andor.c
 */
#include "ast.h"
/**
 ** \brief check a and or
 **
 ** \param p of type struct parser_s
 ** 
 ** \return a nb_child
 */
int check_andor(struct parser_s *p)
{
    int nb_child = 0;
    struct list_node_s *pnode = p->nodes;
    for (;pnode; pnode = pnode->next)
    {
        if ((pnode->type == PIPELINE))
            nb_child++;
    }
    return nb_child;
}
/**
 ** \brief Initialization of and or 
 **
 ** \param p of type struct parser_s
 ** 
 ** \return a struct s_node_and_or
 */
struct s_node_and_or *init_andor(struct parser_s *p)
{
    struct s_node_and_or *s_andor = malloc(sizeof(struct s_node_and_or));
    s_andor->pipelines = malloc(sizeof(struct s_node_pipeline) * 
    check_andor(p));
    s_andor->child = 0;
    return s_andor;
}

void andor_store(struct s_node_and_or *andor, struct s_node_pipeline 
*new_pipeline, int nb_child)
{
    andor->pipelines[nb_child] = *new_pipeline;
}
/**
 ** \brief find pipeline
 **
 ** \param p of type struct parser_s
 **
 ** \param s_andor struct s_node_and_or
 ** 
 ** \return a int 
 */
int find_pipeline(struct parser_s *p, struct s_node_and_or *s_andor)
{
    struct list_node_s *pipeline_node = ast_check_node(p, PIPELINE);
    struct s_node_and_or *andor;
    if (!pipeline_node)
    {
        return 0;
    }
    andor = malloc(sizeof(struct s_node_and_or));
    andor->pipelines = pipeline_node->node->pipeline;
    andor_store(s_andor, andor->pipelines, s_andor->child);
    s_andor->child++;
    return 1;
}