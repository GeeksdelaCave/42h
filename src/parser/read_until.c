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
        struct s_node_until *node_until = init_until();
        find_until(p, node_until);
        union all_grammar *grammar = malloc(sizeof(union all_grammar));
        grammar->node_until = node_until;
        list_node_store(p->nodes, grammar, UNTIL);
        return 1;
    }
    printf("AST read while : FAIL\n");
    p->cursor = tmp;
    return 0;
}