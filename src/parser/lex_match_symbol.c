#include "lex_match_symbol.h"
enum tag_symbol match_symbol(struct parser_s *parser, int end)
{
  char *tmp = malloc(sizeof(char) * end - parser->cursor);
  tmp = strncpy(tmp,parser->input + parser->cursor, end - parser->cursor + 1);
  if (strcmp("[",tmp) == 0)
    {
      parser->cursor += 2;
      return LBRACK;
    }
  if (strcmp("]",tmp) == 0)
    {
      parser->cursor += 2;
      return RBRACK;
    }
  if (strcmp("{", tmp) == 0)
    {
      parser->cursor += 2;
      return LBRACE;
    }
  if (strcmp("}", tmp) == 0)
    {
      parser->cursor += 2;
      return RBRACE;
    }
  if(strcmp("!", tmp) == 0)
    {
      parser->cursor += 2;
      return BANG;
    }
  return 0;
}
char *set_condition_symbol(struct parser_s *parser, int end)
{
  switch(match_symbol(parser, end))
    {
    case 1:
      return "LBRACK";
      break;
    case 2:
      return "RBRACK";
      break;
    case 3:
      return "LBRACE";
      break;
    case 4:
      return "RBRACE";
      break;
    case 5:
      return "BANG";
      break;
      /*case 6:
	return "PIPE";
	break;
      case 7:
    return "QUOTE";
    break;
      case 8:
      return "DQUOTE";
      break;*/
    }
  return NULL;
}
