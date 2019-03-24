/**
 ** \file  read_element.c
 */
#include "grammar.h" 
/**
 ** \brief return true if check a element
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int check_element(struct parser_s *p)
{
  //char* res = 
    parser_get_capture(p, "word");
  //printf("content element %s \n", res);
  if( !strcmp("for", res) || !strcmp("if", res) || !strcmp("while", res) 
  || !strcmp("do", res) || !strcmp("done", res) || !strcmp("fi", res) 
  || !strcmp("then", res) || !strcmp("else", res) || !strcmp("elif", res) 
  || !strcmp("until", res))
  {
	return 0;
  }
    //printf("word : %s\n", res);
    
    return 1;
}
/**
 ** \brief return true if read a element
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
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
  }
  p->cursor = tmp;
  printf("AST ELEMENT FAIL \n");
  return 0;
}
int read_for_word(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p)) && read_word(p) && ZeroOrMany(read_spaces(p)))
  {
    int res = check_element(p);
    if(res == 1)
    {
      //printf("AST FOR WORD \n");
      return 1;
    }
  }
  p->cursor = tmp;
  //printf("FAIL AST FOR WORD \n");
  return 0;
}