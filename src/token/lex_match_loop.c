#include "lex_match_loop.h"
enum tag_loop match_loop(struct parser_s *parser, int end)
{
  char *tmp = malloc(sizeof(char) * end);
  tmp = strncpy(tmp,parser->input + parser->cursor, end - parser->cursor + 1);
  if (strcmp("for", tmp) == 0)
    {
      parser->cursor += 4;
      return FOR;
    }
  if (strcmp("while", tmp ) ==0)
    {
      parser->cursor += 6;
      return WHILE;
    }
  if (strcmp("do", tmp) == 0)
    {
      parser->cursor += 3;
      return DO;
    }
  if (strcmp("done", tmp) == 0)
    {
      parser->cursor += 5;
      return DONE;
    }
  return 0;
}
char *set_loop_tag(struct parser_s *parser, int end)
{
  switch(match_loop(parser, end))
    {
    case 1:
      return "FOR";
      break;
    case 2:
      return "WHILE";
    case 3:
      return "DO";
    case 4:
      return "DONE";
    }
  return NULL;
}
