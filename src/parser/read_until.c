#include "grammar.h" 
/*
rule_until:     
    'until' compound_list do_group
*/

int read_until(struct parser_s *p)
{
    int tmp = p->cursor;
    
    if (parser_readtext(p, "until") &&
    OneOrMany(read_spaces(p)) && read_compound_list(p) &&
    ZeroOrMany(read_spaces(p)) && read_do_group(p))
    {
        printf("AST read while : SUCCES\n");
        return 1;
    }
    printf("AST read while : FAIL\n");
    p->cursor = tmp;
    return 0;
}