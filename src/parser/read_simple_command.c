#include "grammar.h" 

struct list_node_s *find_type(struct parser_s *p)
{
    struct s_node_command *simple_command = init_command_node();
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    struct list_node_s *simple_node = ast_get_node(p, ASSIGN);
    if(simple_node == NULL)
    {/*
        simple_node = ast_get_node(p, WORD1);
        if(simple_node == NULL)
        {
            simple_node = ast_get_node(p, REDIRECTION);
            simple_command->type = REDIRECTION;
            simple_command->struct_type->redirection = simple_node->node->redirection;
            grammar->command = simple_command;
            list_node_store(p->nodes, grammar, COMMAND);
            return simple_node;
        }
        simple_command->type = WORD1;
        simple_command->struct_type->word = simple_node->node->word;
        grammar->command = simple_command;
        list_node_store(p->nodes, grammar, COMMAND);
        return simple_node;*/
    }
    simple_command->type = ASSIGN;
    simple_command->struct_type->assign = simple_node->node->assign;
    grammar->command = simple_command;
    list_node_store(p->nodes, grammar, COMMAND); 
    return simple_node;
}

void get_zero_or_many(struct parser_s *p)
{
    struct list_node_s *simple_node;

    simple_node = find_type(p);
    while(simple_node)
    {       
        simple_node = find_type(p);
    }
}

/*
simple_command: 
    (prefix)+ | (prefix)* (element)+
*/
int read_simple_command(struct parser_s *p)
{
  int tmp = p->cursor;
  if ((OneOrMany(read_prefix(p)) && ZeroOrMany(read_element(p))) || (ZeroOrMany(read_prefix(p)) && OneOrMany(read_element(p))))
  {
    printf("TROUVER 1 \n");
    get_zero_or_many(p);
    printf("AST SIMPLE COMMAND SUCCESS\n");
    return 1;
  }
  printf("AST SIMPLE COMMAND FAIL !!!!!!!!!!!!!!!\n");
  p->cursor = tmp;
  return 0;
}