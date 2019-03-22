#include "ast.h"

/*
list: and_or ((';'|'&') and_or)* [';'|'&']
*/

int read_list(struct parser_s *p)
{
  int tmp = p->cursor;
  if (read_and_or(p) && ZeroOrMany(read_spaces(p)) && 
      (ZeroOrMany((read_virgule(p) || read_and(p)) && 
      ZeroOrMany(read_spaces(p)) && read_and_or(p))) &&
      ZeroOrMany(read_spaces(p)) && 
      (ZeroOrOne(read_virgule(p))  || ZeroOrOne(read_and(p))))
   {
     printf("AST LIST Success \n");
     return 1;
   }
  p->cursor = tmp;
  printf("AST LIst FAil \n");
  return 0;
}
