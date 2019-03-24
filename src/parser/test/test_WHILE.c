/**
 ** \file test_WHILE.c
 */
#include "test.h"
/**
 ** \brief test unit for while grammmar
 */
void test_WHILE()
{
  char *str[] =
    {
      "",	
	  "",
    };
  struct parser_s *p1= parser_new_from_string(str[1]);
  read_while(p1);
  printf("%s \n", p1->input);
}
