#include "lex_match_symbol.h"
enum tag_symbol match_symbol(struct parser_s *parser, int end)
{
  char *tmp = malloc(sizeof(char) * end - parser->cursor);
  tmp = strncpy(tmp,parser->input + parser->cursor, end - parser->cursor + 1);
  if (strcmp("[",tmp) == 0)
    {
      parser->cursor += 1;
      return LBRACK;
    }
  if (strcmp("]",tmp) == 0)
    {
      parser->cursor += 1;
      return RBRACK;
    }
  if (strcmp ("{", tmp) == 0)
    {
      parser->cursor += 1;
      return LBRACE;
    }
  if (strcmp ("}", tmp) == 0)
    {
      parser->cursor += 1;
      return RBRACE;
    }
  if(strcmp ("!", tmp) == 0)
    {
      parser->cursor += 1;
      return BRANG;
    }
  if (strcmp ("|", tmp) == 0)
  {
      parser->cursor += 1;
      return PIPE;
  }
  if (strcmp ("'", tmp) == 0)
  {
      parser->cursor += 1;
      return QUOTE;
  }
  if (strcmp ("\"", tmp) == 0)
  {
      parser->cursor += 1;
      return DQUOTE;
  }
  if (strcmp ("=", tmp) == 0)
  {
      parser->cursor += 1;
      return EQUAL;
  }
  if (strcmp ("==", tmp) == 0)
  {
      parser->cursor += 1;
      return DEQUAL;
  }
  if (strcmp ("<", tmp) == 0)
  {
      parser->cursor += 1;
      return CHEVRON;
  }
  if (strcmp ("<<", tmp) == 0)
  {
      parser->cursor += 1;
      return DCHEVRON;
  }
  return 0;
}
char *set_condition_tag_symbol(struct parser_s *parser, int end)
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
    case 6:
      return "PIPE";
      break;
    case 7:
      return "QUOTE";
      break;
    case 8:
      return "DQUOTE";
      break;
    case 9:
      return "EQUAL";
      break;
    case 10:
      return "DEQUAL";
      break;
    case 11:
      return "CHEVRON";
      break;
    case 12:
      return "DCHEVRON";
      break;
    }
  return NULL;
}
