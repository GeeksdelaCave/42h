#include "grammar.h" 
/*
simple_command: 
    (prefix)+ | (prefix)* (element)+
*/
int read_simple_command(struct parser_s *p)
{
    int tmp = p->cursor;
    if (OneOrMany(read_prefix(p))  ||
	(ZeroOrMany(read_prefix(p)) && OneOrMany(read_element(p))))
      {
	printf("AST SIMPLE COMMAND SUCCESS\n");
	return 1;
    }
    printf("AST SIMPLE COMMAND FAIL !!!!!!!!!!!!!!!\n");
    p->cursor = tmp;  
    return 0;
}