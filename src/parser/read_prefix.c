#include "ast.h"

int read_prefix(struct parser_s *p)
{
    int tmp = p->cursor;
  if (read_Assign(p) || read_redirection(p))
    {
      printf("AST PREFIX SUCCESS \n");
      return 1;
    }
    p->cursor = tmp;
      printf("AST PREFIX FAIL!!!!!!!!!!!!!!!\n");
  return 0;
}
