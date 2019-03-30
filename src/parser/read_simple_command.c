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
    struct s_node_command *s_cmd = init_simple_command(p);
    if(s_cmd){
        while(check_word(p, s_cmd)|| check_redir(p, s_cmd) || check_assign(p, s_cmd));    
    }
    printf("AST SIMPLE COMMAND SUCCESS\n");
    return 1;
  }
  printf("AST SIMPLE COMMAND FAIL !!!!!!!!!!!!!!!\n");
  p->cursor = tmp;
  return 0;
}