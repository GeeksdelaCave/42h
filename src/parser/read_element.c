#include "ast.h"

int check_element(struct parser_s *p)
{
    char* res = parser_get_capture(p, "word");
    //printf("content element %s \n", res);
    if( !strcmp("for", res) || !strcmp("if", res) || !strcmp("while", res) || !strcmp("do", res) || !strcmp("done", res) || !strcmp("fi", res) || !strcmp("then", res) )
      {
	return 0;
      }
    printf("%s\n", res);
    
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
	    //printf("AST ELEMENT SUCCESS \n");
	    return 1;
	  }
      else{
        return 0;
      }
      }
      parser_get_capture(p, "word");
    p->cursor = tmp;
    printf("AST ELEMENT FAIL \n");    
    return 0;
}
