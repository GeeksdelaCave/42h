/**
 ** \file  read_pipeline.c
 */
#include "grammar.h" 
/**
 ** \brief return true if read
 **  a pipeline
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_pipeline(struct parser_s *p)
{
  
  int tmp = p->cursor;
  if (ZeroOrOne(read_excla(p)) && ZeroOrMany(read_spaces(p)) &&
      read_command(p) && ZeroOrMany(read_spaces(p)) &&  
      ZeroOrMany(read_pipe(p) && ZeroOrMany(read_spaces(p)) && ZeroOrMany(parser_readchar(p, '\n')&& ZeroOrMany(read_spaces(p)))
		 && read_command(p)))
    {
      return 1;
    }
  p->cursor = tmp;
  //printf("AST PIPELINE FAIL \n");
  return 0;
}