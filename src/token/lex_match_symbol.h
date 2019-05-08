/**
 ** \file LEX_MATCH_SYMBOL_H
 ** \brief Declaration file LEX_MATCH_SYMBOL
 */
#ifndef LEX_MATCH_SYMBOL
#define LEX_MATCH_SYMBOL

#include "token_list.h"
/**
 ** \enum tag_symbol
 ** \brief description of tag loop
 ** lbrack, rbrack, lbrace, rbrace
 */  
enum tag_symbol{
  LBRACK = 1,  //[
  RBRACK, //]
  LBRACE, // {
  RBRACE, // }
  BANG, // !
  //PIPE,
  // QUOTE,
  //DQUOTE,
};
/**
 ** \fn enum tag_symbol match_symbol(struct parser_s *parser, int end);
 */
enum tag_symbol match_symbol(struct parser_s *parser, int end);
/**
 ** \fn char *set_condition_symbol(struct parser_s *parser, int end);
 */
char *set_condition_symbol(struct parser_s *parser, int end);
#endif
