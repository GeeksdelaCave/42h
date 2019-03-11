#ifndef LEX_MATCH_SYMBOL
#define LEX_MATCH_SYMBOL
enum tag_symbol{
  LBRACK = 1,  //[
  RBRACK, //]
  LBRACE, // {
  RBRACE, // }
  BANG, // !
  PIPE,
  QUOTE,
  DQUOTE,
};
enum tag_symbol match_symbol(struct parser_s *parser, int end);
char *set_condition_symbol(struct parser_s *parser, int end);
#endif
