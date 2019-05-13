#include "ast.h"

struct list_node_s *init_list_node()
{
    struct list_node_s *new_list = malloc(sizeof(struct list_node_s));
    if (new_list == NULL)
    {
      return NULL;
    }
    new_list->type = -1;
    new_list->node = malloc(sizeof(union all_grammar));
    new_list->next = NULL;
    new_list->prev = NULL;
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
  list_node->type = type;
	//printf("----------------------------------------TEST IN LIST_NODE_STORE-------------------------------%d\n", list_node->type);  
list_node->node = s_node;
  list_node->next->prev = list_node;
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

enum type_grammar list_type_lookup(struct list_node_s *list_node, enum type_grammar type)
{
    for (; list_node->next; list_node = list_node->next)
    {
        if (list_node->type == type)
        {
            return type; 
        }
    }
    return -1;
}

/*
** find and get the last node of the type : type 
*/
struct list_node_s *lookup_last(struct list_node_s *list_node, enum type_grammar type)
{
    struct list_node_s *last = NULL; 
    for (; list_node->next; list_node = list_node->next)
    {
        if (list_node->type == type)
        {
            last = list_node; 
        }
    }
    return last;
}

void eat_list_node(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = list_node_lookup(p->nodes, type);
    if (pnode->next != NULL && pnode->prev != NULL)
    {
        pnode->prev->next = pnode->next;
        pnode->next->prev = pnode->prev;
        free(pnode);
    }
    else if(pnode->next != NULL)
    {
        p->nodes = pnode->next;
		//p->nodes->prev = NULL;
        pnode->next->prev = NULL;
        free(pnode);
    }
    else if(pnode->prev != NULL)
    {
        pnode->prev->next = NULL;
        free(pnode);
    }
    else
    {
        free(pnode);
    }   
}

void eat_list_last(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = lookup_last(p->nodes, type);
    if (pnode->next != NULL && pnode->prev != NULL)
    {
        pnode->prev->next = pnode->next;
        pnode->next->prev = pnode->prev;
        free(pnode);
    }
    else if(pnode->next != NULL)
    {
        p->nodes = pnode->next;
        //p->nodes->prev = NULL;
        pnode->next->prev = NULL;
        free(pnode);
    }
    else if(pnode->prev != NULL)
    {
        pnode->prev->next = NULL;
        free(pnode);
    }
    else
    {
        free(pnode);
    }   
}

/*
** check node and get if true
*/
struct list_node_s *ast_check_node(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = list_node_lookup(p->nodes, type);
    if (!pnode){
      return NULL;
    }
    eat_list_node(p, type);
    return pnode;
}

struct list_node_s *ast_check_last(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = lookup_last(p->nodes, type);
    if (!pnode){
      return NULL;
    }
    eat_list_last(p, type);
    return pnode;
}

/*
** check sym and get if true
*/
int ast_check_sym(struct parser_s *p, enum type_grammar type)
{
    struct list_node_s *pnode = list_node_lookup(p->nodes, type);
    if (!pnode){
      return 0;
    }
    eat_list_node(p, type);
    return 1;
}

void print_node(struct list_node_s *node)
{
    for(; node; node = node->next)
    {
        printf("TYPE : %d ", node->type);
        if(node->prev)
            printf("LE PREV : %d\n", node->prev->type);
        else
            printf("\n");    
    }
    printf("\n");
}
