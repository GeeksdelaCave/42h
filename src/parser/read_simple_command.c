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
    FILE *file = fopen("ast.txt", "w+");
    int simplecmd = SIMPLECOMMAND; 
    struct s_node_command *s_cmd = init_simple_command(p);
    if(s_cmd){
      fprintf(file, "AST {\n");
      fprintf(file, "    node [fontname=\"Arial\"];\n");
      while(check_word(p, s_cmd)|| check_redir(p, s_cmd) || check_assign(p, s_cmd));
    }
    for (; s_cmd; s_cmd = s_cmd->next)
    {
      fprintf(file,  "    %d -> %d;\n", simplecmd, s_cmd->type); 
    }
    fprintf(file, "}\n");
    printf("AST SIMPLE COMMAND SUCCESS\n");
    return 1;
  }
  printf("AST SIMPLE COMMAND FAIL !!!!!!!!!!!!!!!\n");
  p->cursor = tmp;
  return 0;
}
