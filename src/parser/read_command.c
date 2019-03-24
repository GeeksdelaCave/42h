/**
 ** \file  read_command.c
 */
#include "grammar.h" 
/**
 ** \brief return true if read a command :
 ** simple command || shell command
 ** || funcdec
**
** \param p structure of parser
**
** \return true of false
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
    //printf("AST COMMAND FAIL !!!!!!!!!!!!!!\n");
    p->cursor = tmp; 
  return 0;
}
