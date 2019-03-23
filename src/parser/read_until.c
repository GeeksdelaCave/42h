#include "ast.h"

/*
rule_until:     
    'until' compound_list do_group
*/

int read_until(struct parser_s *p)
{
    int tmp = p->cursor;

    if ( (parser_readtext(p, "until") && read_compound_list(p) && 
    read_do_group(p)) )
    {
        printf("AST read UNTIL : SUCCES\n");
        return 1;
    }
    printf("AST read UNTIL : FAIL\n");
    p->cursor = tmp;
    return 0;
}

