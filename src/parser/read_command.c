#include "grammar.h" 
/*
command: 
    simple_command
    | shell_command (redirection)*
    | funcdec (redirection)*
*/

int read_command(struct parser_s *p)
{
  int tmp = p->cursor;
  if (read_simple_command(p)  ||
      (read_shell_command(p) && ZeroOrMany(read_redirection(p))) ||
      (read_funcdec(p) && ZeroOrMany(read_redirection(p))))
    {
      return 1;
    }
    printf("AST COMMAND FAIL !!!!!!!!!!!!!!\n");
    
    p->cursor = tmp; 
  return 0;
}
