#include "grammar.h" 
#include "../dot/generate_dot_file_ast.h" 
/*
  do_group:
  'do' compound_list 'done'
*/
int read_do_group(struct parser_s *p)
{
  int tmp = p->cursor;
  
  if (parser_readtext(p, "do") && read_compound_list(p) && 
       parser_readtext(p, "done"))
    {
        printf("AST read DOGROUP : SUCCES\n");
        struct s_do_group *dogroup = init_dogroup();
        find_coump(p, dogroup);
        union all_grammar *grammar = malloc(sizeof(union all_grammar));
        grammar->dogroup = dogroup;
        list_node_store(p->nodes, grammar, DOGROUP);
 print_compound_list(grammar->dogroup, fopen("ast.dot", "w+"));
        return 1;
    }
  printf("AST read DOGROUP : FAIL\n");
  p->cursor = tmp;
  return 0;
}
