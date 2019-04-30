#include "grammar.h" 
#include "../dot/generate_dot_file_ast.h"
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
        struct s_node_while *node_while = init_while();
        find_while(p, node_while);
        union all_grammar *grammar = malloc(sizeof(union all_grammar));
        grammar->node_while = node_while;
        print_while_command(node_while, fopen("ast.dot", "w+"));
        list_node_store(p->nodes, grammar, WHILE);
        return 1;
    }
    printf("AST read while : FAIL\n");
    p->cursor = tmp;
    return 0;
}