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

void list_node_store(struct list_node_s *list_node, char *data, struct list_node_s *node, enum type_node type)
{
  for(; list_node->next; list_node = list_node->next);
  list_node->next = init_list_node();
  list_node->data = data;
  printf("%s\n", data);
  list_node->next= node;
  list_node->nb_child++;
  list_node->type = type;
}

struct list_node_s *list_node_lookup(struct list_node_s *list_node, enum type_node type)
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
struct list_node_s *ast_get_node(struct parser_s *p, enum type_node type)
{
  struct list_node_s *pnode = list_node_lookup(p->nodes, type);
  if (!pnode){
    return false;
  }
  eat_list_node(p);
  return pnode;
}
