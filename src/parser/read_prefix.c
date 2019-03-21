#include "ast.h"

int read_prefix(struct parser_s *p)
{
  int tmp = p->cursor;
  if (read_Assign(p) || read_redirection(p))
    {
      return 1;
    }
    p->cursor = tmp;
  return 0;
}
