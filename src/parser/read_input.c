/**
 ** \file  read_input.c
 */
#include "grammar.h" 
/**
 ** \brief Check if the text is a input
 **  and init AST here
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_input(struct parser_s *p)
{
    int tmp = p->cursor;
   if ((read_list(p) && parser_readchar(p, '\n')) ||
      (read_list(p) && parser_eof(p)) ||
      (parser_readchar(p, '\n')) ||
      (parser_eof(p)))
      {
      //printf("AST INPUT Success\n");
      return 1;
    }
  //printf("AST INPUT Fail\n");

    p->cursor = tmp;
  return 0;
}