#include "ast.h"
int read_redirection(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p)) &&
      parser_begin_capture(p, "num") && parser_readinteger(p) && parser_end_capture(p, "num")
      && ZeroOrMany(read_spaces(p)) &&
      parser_begin_capture(p, "chevron") && parser_readchar(p, '<') && parser_end_capture(p, "chevron")
      && ZeroOrMany(read_spaces(p)) && read_word(p) &&
      ZeroOrMany(read_spaces(p)))
    {
      char *num = parser_get_capture(p, "num");
      char *chevron = parser_get_capture(p, "chevron");
      char *word = parser_get_capture(p, "word");
      printf("READ_REDIRECTION %s %s  %s\n", num,chevron, word);
      return 1;
    }
  p->cursor = tmp;
  return 0;
}
