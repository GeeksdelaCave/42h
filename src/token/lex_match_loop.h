#ifndef LEX_MATCH_LOOP
#define LEX_MATCH_LOOP
#include "token_list.h"

enum tag_loop{
  FOR = 1,
  WHILE,
  DO,
  DONE,
};

enum tag_loop match_loop(struct parser_s *parser, int end);
char *set_loop_tag(struct parser_s *parser, int end);
#endif
