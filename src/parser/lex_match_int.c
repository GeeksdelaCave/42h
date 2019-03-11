#include "lex_match_int.h"
int parser_readinteger(struct lexer *p, int end)
{
  int cpt = p->cursor;
  if (parser_readrange(p, '0', '9'))
    {
      for (int i = p->cursor; i <= end; i++)
	{
	  if (!parser_readrange(p, '0', '9'))
	    {
	      p->cursor = cpt;
	      return 0;
	    }
	}
      p->cursor++;
      return 1;
    }
  p->cursor = cpt;
  return 0;
}
