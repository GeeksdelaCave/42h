#ifndef LEX_MATCH_SYMBOL
#define LEX_MATCH_SYMBOL
#include "lexer.h"
enum tag_symbol{
  LBRACK = 1,  //[
  RBRACK, //]
  LBRACE, // {
  RBRACE, // }
  BANG, // !
  PIPE,
  QUOTE,
  DQUOTE,
  EQUAL,
  DEQUAL,
  CHEVRON,
  DCHEVRON,
};
enum tag_symbol match_symbol(struct lexer *parser, int end);
char *set_condition_symbol(struct lexer *parser, int end);
#endif
