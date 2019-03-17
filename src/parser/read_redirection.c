#include "ast.h"
int read_redirection(struct parser_s *p)
{
    int tmp = p->cursor;
  if (parser_begin_capture(p, "num") && parser_readinteger(p) && parser_end_capture(p, "num")
      && parser_begin_capture(p, "chevron") && parser_readchar(p, '<') && parser_end_capture(p, "chevron") && parser_begin_capture(p,  "word") && read_word(p) && parser_end_capture(p, "word"))
    {
      printf("AST REDIRECTION SUCCESS\n");
      return 1;
    }
    p->cursor = tmp;
      printf("AST REDIRECTION FAIL!!!!!!!!!\n");
  return 0;
}
