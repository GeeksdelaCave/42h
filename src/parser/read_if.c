#include "grammar.h" 
/*
rule_if:    
    'if' compound_list 'then' compound_list [else_clause] 'fi'
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
        printf("AST read if : SUCCES\n");
        struct s_node_if *node_if = init_if();
        find_if(p, node_if);
        union all_grammar *grammar = malloc(sizeof(union all_grammar));
        grammar->node_if = node_if;
        list_node_store(p->nodes, grammar, IF);
    	return 1;
    }
    printf("AST read if : FAIL\n");
    p->cursor = tmp;
    return 0;
}