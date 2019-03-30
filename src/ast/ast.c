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

/*
** check node and get if true
*/
struct list_node_s *ast_check_node(struct parser_s *p, enum type_grammar type)
{
  struct list_node_s *pnode = p->nodes;
  if (!(pnode->type == type))
  {
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
    printf("\n");
}

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
    new_node->next = NULL;
    return new_node;
}