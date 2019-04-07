#include "grammar.h" 

/* Check if the text is a input */
int read_input(struct parser_s *p)
{
    int tmp = p->cursor;
   if ((read_list(p) && parser_readchar(p, '\n')) ||
      (read_list(p) && parser_eof(p)) ||
      (parser_readchar(p, '\n')) ||
      (parser_eof(p)))
      {
        /* on initialise AST ICI*/

      //printf("AST INPUT Success\n");
      return 1;
    }
  //printf("AST INPUT Fail\n");

    p->cursor = tmp;
  return 0;
}
