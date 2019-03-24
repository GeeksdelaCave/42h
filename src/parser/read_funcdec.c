/**
 ** \file  read_funcdec.c
 */
#include "grammar.h" 
/**
 ** \brief return true if read a funcdec
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_funcdec(struct parser_s *p)
{
    int tmp = p->cursor;
  if ((parser_begin_capture(p, "FUNCTION") && ZeroOrMany(read_spaces(p)) && ZeroOrOne(parser_readtext(p, "function")) && parser_end_capture(p, "FUNCTION")) 
    && read_word(p) && parser_readchar(p, '(') && parser_readchar(p, ')')
      && ZeroOrMany(read_spaces(p) || parser_readchar(p, '\n')) && read_shell_command(p))
    {
      //printf("AST FUNCDEC SUCCESS \n");
      return 1;
    }
    
    p->cursor = tmp;
  return 0;
}
