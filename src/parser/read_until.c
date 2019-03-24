/**
 ** \file  read_until.c
 */
#include "grammar.h" 
/**
 ** \brief Check if the text is until
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_until(struct parser_s *p)
{
    int tmp = p->cursor;
    
    if (parser_readtext(p, "until") &&
    OneOrMany(read_spaces(p)) && read_compound_list(p) &&
    ZeroOrMany(read_spaces(p)) && read_do_group(p))
    {
        //printf("AST read while : SUCCES\n");
        return 1;
    }
    //printf("AST read while : FAIL\n");
    p->cursor = tmp;
    return 0;
}
