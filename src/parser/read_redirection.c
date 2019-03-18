#include "ast.h"
int read_redirection(struct parser_s *p)
{
  int tmp = p->cursor;
    if (ZeroOrMany(read_spaces(p)) &&
	parser_begin_capture(p, "num") && parser_readinteger(p) && parser_end_capture(p, "num")
	&& ZeroOrMany(read_spaces(p)) &&
	parser_begin_capture(p, "chevron") && parser_readchar(p, '<') && parser_end_capture(p, "chevron") && read_word(p)
	&& ZeroOrMany(read_spaces(p)))
      {
	printf("NUM : %s WORD : %s \n", parser_get_capture(p, "num"), parser_get_capture(p, "word"));
	//	printf("AST REDIRECTION SUCCESS\n");
	return 1;
      }
    p->cursor = tmp;
    // printf("AST REDIRECTION FAIL!!!!!!!!!\n");
    return 0;
}
