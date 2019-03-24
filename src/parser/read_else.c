/**
 ** \file  read_else.c
*/
#include "grammar.h" 
/**
 ** \brief return true if read a else
**  condition
**
** \param p structure of parser
**
** \return true of false
*/
int read_else(struct parser_s *p)
{
    int tmp = p->cursor;

    if ( (parser_readtext(p, "else") && read_compound_list(p)) || (parser_readtext(p, "elif") && read_compound_list(p) && parser_readtext(p, "then") && read_compound_list(p) && ZeroOrOne(read_else(p))) )
      {
        //printf("AST read ELSE : SUCCES\n");
        return 1;
    }
    //printf("AST read ELSE : FAIL\n");
    p->cursor = tmp;
    return 0;
}
