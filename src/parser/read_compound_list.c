#include "grammar.h" 
/*
compound_list:
    ('\n')* and_or ((';'|'&'|'\n') ('\n')* and_or)* [('&'|';'|'\n') ('\n')*]
*/

int read_compound_list(struct parser_s *p)
{
    int tmp = p->cursor;
    if (ZeroOrMany(parser_readchar(p, '\n')) && ZeroOrMany(read_spaces(p)) 
    && read_and_or(p) && ZeroOrMany(read_spaces(p)) && 
    ZeroOrMany((read_virgule(p) || read_and(p) || parser_readchar(p, '\n')) && 
    ZeroOrMany(read_spaces(p)) && read_and_or(p) && ZeroOrMany(read_spaces(p)) 
    && ZeroOrMany(parser_readchar(p, '\n'))  && ZeroOrMany(read_spaces(p)) && 
    read_and_or(p)) &&  
    ((ZeroOrOne(read_virgule(p)) || ZeroOrOne(read_and(p)) || 
    ZeroOrOne(parser_readchar(p, '\n'))) && ZeroOrMany(read_spaces(p)) && 
    ZeroOrOne(ZeroOrMany(parser_readchar(p, '\n')))))
      {
        printf("AST read compound list : SUCCES\n");
        return 1;
      }
    printf("AST read compound list : FAIL\n");
    p->cursor = tmp;
    return 0;
}