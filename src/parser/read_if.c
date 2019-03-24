/**
 ** \file  read_if.c
 */
#include "grammar.h" 
/**
 ** \brief return true if read a if
 **  condition
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_if(struct parser_s *p)
{
    int tmp = p->cursor;
    //printf("content dans l input -> '%s'\n", p->input);
    if (ZeroOrMany(read_spaces(p)) && 
        parser_readtext(p, "if") && read_compound_list(p) && 
        ZeroOrMany(read_spaces(p)) && parser_readtext(p, "then")  && 
        ZeroOrMany(read_spaces(p)) && read_compound_list(p) && 
        ZeroOrMany(read_spaces(p)) && ZeroOrOne(read_else(p)) && 
        ZeroOrMany(read_spaces(p)) && parser_readtext(p, "fi"))
    {
       //printf("AST read if : SUCCES\n");
    	return 1;
    }
    //printf("AST read if : FAIL\n");
    p->cursor = tmp;
    return 0;
}
