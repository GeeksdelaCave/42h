#ifndef LEX_MATCH_IF
#define LEX_MATCH_IF
#include "token_list.h"
enum tag_condition{
  IF = 1,
  ELSE,
  THEN,
  FI,
  ELIF,
};

enum tag_condition match_if(struct parser_s *p, int end);
char *set_condition_tag(struct parser_s *p, int end);
#endif
