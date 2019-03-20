#include "ast.h"

/*
    and_or: 
        pipeline (('&&'|'||') ('\n')* pipeline)*
*/
int read_and_or(struct parser_s *p)
{
    // utilisation d un || dans un zero or many
    int tmp = p->cursor;

  if (read_pipeline(p) && (ZeroOrMany((parser_readtext(p, "&&") || parser_readtext(p, "||")) &&  ZeroOrMany(parser_readchar(p, '\n')) && read_pipeline(p))))
    {
      printf("AST READANDOR Success \n");
      return 1;
    }t 
    p->cursor = tmp;
  printf("READ ANDOR FAil !!!!!!!!!!!!!!!!!!!!\n");
  return 0;
}
