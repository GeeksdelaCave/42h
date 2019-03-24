/**
 ** \file  read_command.c
 */
#include "grammar.h" 
/**
 ** \brief Check if it  is a shell
 **  command
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_shell_command(struct parser_s *p)
{
    int tmp = p->cursor;
  if ((parser_readchar(p, '{') && ZeroOrMany(read_spaces(p)) && read_compound_list(p) && ZeroOrMany(read_spaces(p)) && parser_readchar(p, '}'))
      || (parser_readchar(p, '(') && ZeroOrMany(read_spaces(p)) && read_compound_list(p) && ZeroOrMany(read_spaces(p)) && parser_readchar(p, ')'))
      || read_for(p)
      || read_while(p)
      || read_until(p)
      || read_case(p)
      || read_if(p))
    {
      //printf("AST READ_SHELL_COMMAND Success \n");
      return  1;
    }
    //printf("AST READ SHELL COMMANDE FAIL \n" );    
    p->cursor = tmp;
  return 0;
}
