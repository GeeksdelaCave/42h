#include "lex_match_id.h"
int parser_readidentifier(struct parser_s *p, int end)
{
  int cpt = p->cursor;
  if (parser_readrange(p, 'a', 'z') || parser_readrange(p, 'A', 'Z') ||
      parser_readchar(p, '_'))
    {
      for (int i = p->cursor; i <= end; i++)
	{
	  if (!(parser_readrange(p, 'a', 'z') || parser_readrange(p, 'A', 'Z') || parser_readchar(p, '_') || parser_readrange(p, '0', '9')))
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
