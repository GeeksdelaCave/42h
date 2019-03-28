#include "grammar.h" 
/*
  pipeline: ['!'] command ('|' ('\n')* command)*
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
  printf("AST PIPELINE FAIL \n");
  return 0;
}