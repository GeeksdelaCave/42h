#include "grammar.h" 
/*
simple_command: 
    (prefix)+ | (prefix)* (element)+
*/
int read_simple_command(struct parser_s *p)
{
  int tmp = p->cursor;
  if ((OneOrMany(read_prefix(p)) && ZeroOrMany(read_element(p))) || (ZeroOrMany(read_prefix(p)) && OneOrMany(read_element(p))))
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
