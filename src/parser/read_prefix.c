#include "grammar.h" 

int read_prefix(struct parser_s *p)
{
  int tmp = p->cursor;
  if (read_Assign(p) || read_redirection(p))
  {
    /*struct list_node_s *assign = list_node_lookup(p->nodes, ASSIGN);
    printf("11111111111111111111111111 ID %s NUM %s TYPE %d \n", assign->node->assign->id, assign->node->assign->num, assign->type);
    struct list_node_s *assign_node = ast_get_node(p, ASSIGN);
    struct list_node_s *assign2 = list_node_lookup(p->nodes, ASSIGN);
    if (assign2 != NULL)
        printf("22222222222222222222222222 ID %s NUM %s TYPE %d\n", assign2->node->assign->id, assign2->node->assign->num, assign2->type);
    struct list_node_s *redirection_node = ast_get_node(p, REDIRECTION);
    struct s_node_prefix *prefix = malloc(sizeof(struct s_node_prefix));
    if(assign_node != NULL){
      prefix->assign = assign_node->node->assign;
      //printf("TROUVER id %s : %s\n", prefix->assign->id, prefix->assign->num);
    }
    
    if(redirection_node != NULL)
    {
      prefix->redirection = redirection_node->node->redirection;
    }
    
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->prefix = prefix;
    */
    //printf("++TROUVER id %s : %s\n", grammar->prefix->assign->id, grammar->prefix->assign->num);
    //list_node_store(p->nodes, grammar, PREFIX);
    // print_node(p->nodes);
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
