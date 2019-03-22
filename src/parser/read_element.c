#include "ast.h"

int check_element(struct parser_s *p)
{
    char* res = parser_get_capture(p, "word");
    //printf("content element %s \n", res);
    if( !strcmp("for", res) || !strcmp("if", res) || !strcmp("while", res) )
      {
	return 0;
      }
    return 1;
}
int read_element(struct parser_s *p)
{
  int tmp = p->cursor;
    if ( read_word(p) || read_redirection(p))
      {
	int res = check_element(p);
	if(res == 1)
	  {
	    printf("WORD %s\n", parser_get_capture(p, "word"));
	    //printf("AST ELEMENT SUCCESS \n");
	    return 1;
	  }
      }
    p->cursor = tmp;
    printf("AST ELEMENT FAIL \n");    
    return 0;
}
