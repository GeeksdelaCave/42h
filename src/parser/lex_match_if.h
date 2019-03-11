#ifndef LEX_MATCH_IF
#define LEX_MATCH_IF
#include "lexer.h"

enum tag_condition{
  IF = 1,
  ELSE,
  THEN,
  FI,
  ELIF,
};

enum tag_condition match_if(struct lexer *p, int end);
char *set_condition_tag(struct lexer *p, int end);
#endif
