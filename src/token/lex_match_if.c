#include "lex_match_if.h"
enum tag_condition match_if(struct parser_s *parser, int end)
{
  char *tmp = malloc(sizeof(char) * end - parser->cursor);
  tmp = strncpy(tmp,parser->input + parser->cursor, end - parser->cursor + 1);
  if (strcmp("else",tmp) == 0)
    {
      parser->cursor += 5;
      return ELSE;
    }
  if (strcmp("if",tmp) == 0)
    {
      parser->cursor += 3;
      return IF;
    }
  if (strcmp("fi", tmp) == 0)
    {
      parser->cursor += 3;
      return FI;
    }
  if (strcmp("then", tmp) == 0)
    {
      parser->cursor += 5;
      return THEN;
    }
  return 0;
}

char *set_condition_tag(struct parser_s *parser, int end)
{
  switch(match_if(parser, end))
    {
    case 1:
      return "IF";
      break;
    case 2:
      return "ELSE";
      break;
    case 3:
      return "THEN";
      break;
    case 4:
      return "FI";
      break;
    case 5:
      return "ELIF";
      break;
    }
  return NULL;
}
