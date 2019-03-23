#include "ast.h"

/*
command: 
    simple_command
    | shell_command (redirection)*
    | funcdec (redirection)*
*/

int read_command(struct parser_s *p)
{
    int tmp = p->cursor;
    printf("ce que j'ai command %c\n", p->input[p->cursor]);
  if (read_simple_command(p)  ||
      (read_shell_command(p) && ZeroOrMany(read_redirection(p))) ||
      (read_funcdec(p) && ZeroOrMany(read_redirection(p))))
    {
      printf("AST COMMAND Success %s \n", p->input);
      return 1;
    }
    printf("AST COMMAND FAIL !!!!!!!!!!!!!! %s \n", p->input);
     
    p->cursor = tmp; 
  return 0;
}
