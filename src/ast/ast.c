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
  if (p->nodes->next != NULL)
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
