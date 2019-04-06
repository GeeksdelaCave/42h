/**
 ** \file  read_case.c
 */
#include "grammar.h" 
/**
 ** \brief return true if read case
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_case(struct parser_s *p)
{
    int tmp = p->cursor;
    if ((parser_readtext(p, "case") && read_word(p) && 
	 ZeroOrMany(parser_readchar(p, '\n')) && ZeroOrOne(read_case_clause(p)) && 
	 parser_readtext(p, "esac")))
    {
        //printf("AST read CASE : SUCCES\n");
        return 1;
    }
    //printf("AST read CASE : FAIL\n");
    p->cursor = tmp;
    return 0;
}