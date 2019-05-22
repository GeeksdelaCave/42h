/**
 ** \file LEX_MATCH_LOOP_H
 ** \brief Declaration file LEX_MATCH_LOOP
 */
#ifndef LEX_MATCH_LOOP
#define LEX_MATCH_LOOP
#include "token_list.h"
/**
 ** \enum tag_condition
 ** \brief description of tag loop
 ** for , while, do, done
 */ 
enum tag_loop{
  FOR = 1,
  WHILE,
  DO,
  DONE,
};

/**
 ** \fn enum tag_loop match_loop(struct parser_s *parser, int end);
 */ 
enum tag_loop match_loop(struct parser_s *parser, int end);
/**
 ** \fn char *set_loop_tag(struct parser_s *parser, int end);
 */ 
char *set_loop_tag(struct parser_s *parser, int end);
#endif
