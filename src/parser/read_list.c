#include "grammar.h" 
#include "../dot/generate_dot_file_ast.h"
/*
list: and_or ((';'|'&') and_or)* [';'|'&']
*/

int read_list(struct parser_s *p)
{
  int tmp = p->cursor;
  if (read_and_or(p) && ZeroOrMany(read_spaces(p)) && 
      (ZeroOrMany((read_virgule(p) || read_and(p)) && 
      ZeroOrMany(read_spaces(p)) && read_and_or(p))) &&
      ZeroOrMany(read_spaces(p)) && 
      (ZeroOrOne(read_virgule(p)) || ZeroOrOne(read_and(p))))
   {
        struct s_node_list *list = init_list(p);
        while(list_and_or(p, list));
        union all_grammar *grammar = malloc(sizeof(union all_grammar));
        grammar->list = list;
        list_node_store(p->nodes, grammar, LIST);
		my_print_ast(p);
        return 1;
   }
  p->cursor = tmp;
  printf("AST LIst FAil \n");
  return 0;
}
