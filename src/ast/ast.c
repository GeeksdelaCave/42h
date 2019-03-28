#include "ast.h"

struct list_node_s *init_list_node()
{
    struct list_node_s *new_list = malloc(sizeof(struct list_node_s));
    if (new_list == NULL)
    {
      return NULL;
    }
    new_list->type = 0;
    new_list->node = NULL;
    new_list->next = NULL;
    return new_list;
}

void free_list_node(struct list_node_s *lnodes)
{
    struct list_node_s *prev_node = lnodes;
    while (lnodes)
    {
      prev_node = lnodes;
      lnodes = lnodes->next;
      free(prev_node);
    }
}

void list_node_store(struct list_node_s *list_node, union all_grammar *s_node, enum type_grammar type)
{
  for(; list_node->next; list_node = list_node->next);
  list_node->next = init_list_node();
  list_node = list_node->next;
  list_node->type = type;
  list_node->node = s_node;
}

/*
** find and get the node 
*/
struct list_node_s *list_node_lookup(struct list_node_s *list_node, enum type_grammar type)
{
    for (; list_node->next; list_node = list_node->next)
    {
        if (list_node->type == type)
        {

            return list_node; 
        }
    }
    return NULL;
}

void eat_list_node(struct parser_s *p)
{
  if (p->nodes != NULL)
    {
      struct list_node_s *list = p->nodes->next;
      free(p->nodes);
      p->nodes = list;
    }
}

/*
** get node and eat
*/
struct list_node_s *ast_get_node(struct parser_s *p, enum type_grammar type)
{
  struct list_node_s *pnode = list_node_lookup(p->nodes, type);
  if (!pnode){
    return false;
  }
  eat_list_node(p);
  return pnode;
}

void print_node(struct list_node_s *node)
{
    for(; node; node = node->next)
    {
        printf("TYPE : %d ", node->type);
    }
}


#include "repetition_tools.h"
#include "../ast/ast.h"

#ifndef REPETITION_TOOLS_H
#define REPETITION_TOOLS_H
void get_zero_or_many(struct parser_s *p);
#endif


#include "grammar.h" 
int read_prefix(struct parser_s *p)
{
    int tmp = p->cursor;
    if (read_Assign(p) || read_redirection(p))
    {
        struct list_node_s *assign_node = ast_get_node(p, ASSIGN);
        struct list_node_s *redirection_node = ast_get_node(p, REDIRECTION);
        struct s_node_prefix *prefix = malloc(sizeof(struct s_node_prefix));

        if(assign_node != NULL){
            prefix->assign = assign_node->node->assign;
            printf("REGARDE ICI ======== %s : %s\n", 
            assign_node->node->assign->id, assign_node->node->assign->num);
        }
        if(redirection_node != NULL)
        {
            prefix->redirection = redirection_node->node->redirection;    
        }
        union all_grammar *grammar = malloc(sizeof(union all_grammar));
        grammar->prefix = prefix;
        list_node_store(p->nodes, grammar, PREFIX);        
      return 1;
    }
    p->cursor = tmp;
    return 0;
}



#include "grammar.h" 
/*
simple_command: 
    (prefix)+ | (prefix)* (element)+
*/
int read_simple_command(struct parser_s *p)
{
    int tmp = p->cursor;
    if (OneOrMany(read_prefix(p))  ||
    (ZeroOrMany(read_prefix(p)) && OneOrMany(read_element(p))))
       {
        get_zero_or_many(p);    
        printf("AST SIMPLE COMMAND SUCCESS\n");
        return 1;
    }
    printf("AST SIMPLE COMMAND FAIL !!!!!!!!!!!!!!!\n");
    p->cursor = tmp;  
    return 0;
}
    
void get_zero_or_many(struct parser_s *p)
{
    struct list_node_s *prefix_node;
    struct list_node_s *element_node;
    struct s_node_simple_command *simple_command = malloc(
    sizeof(struct s_node_simple_command));

    prefix_node = ast_get_node(p, PREFIX);
    while(prefix_node)
    {
        simple_command->prefix = &prefix_node->node->prefix;
        prefix_node = ast_get_node(p, PREFIX);
        //printf("%s\n", simple_command->prefix->assign->id);
    }
    element_node = ast_get_node(p, ELEMENT);
    while(element_node)
    {
        simple_command->element = &element_node->node->element;
        element_node = ast_get_node(p, ELEMENT);
    }
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->simple_c = simple_command;
    list_node_store(p->nodes, grammar, ELEMENT);
}

