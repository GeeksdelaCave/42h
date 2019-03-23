#include "ast.h"


/*
rule_while: 
    'while' compound_list do_group
*/

int read_while(struct parser_s *p)
{
    int tmp = p->cursor;
    
    if (parser_readtext(p, "while") &&
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