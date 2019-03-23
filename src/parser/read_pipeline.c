#include "ast.h"
/*
pipeline: ['!'] command ('|' ('\n')* command)*
*/

int read_pipeline(struct parser_s *p)
{

    int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p)) && ZeroOrOne(parser_readchar(p, '!')) && ZeroOrMany(read_spaces(p)) &&
      read_command(p) && 
      ZeroOrMany(parser_readchar(p, '|') && ZeroOrMany(parser_readchar(p, '\n')
    ) && read_command(p)))
    {
      printf("AST PIPELINE SUCCESS \n");
      return 1;
    }
    
    p->cursor = tmp;
  printf("AST PIPELINE FAIL \n");
  return 0;
}
