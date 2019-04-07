/**
 ** \file  read_and_or.c
 */
#include "grammar.h"
#include "../dot/generate_dot_file_ast.h"
/**
 ** \brief return true if read and
 **  or
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */

void print_andor(struct s_node_and_or *andor)
{
    for(int i = 0; i < andor->child; i++)
    {
        //printf("%d -- AND : %d\n", i+1,andor->pipelines[i].b_and);
        //printf("%d -- OR : %d\n", i+1,andor->pipelines[i].b_or);
    }
}

int read_and_or(struct parser_s *p)
{
    int tmp = p->cursor;
    if (ZeroOrMany(read_spaces(p)) && read_pipeline(p) && ZeroOrMany(read_spaces(p)) && (ZeroOrMany((read_symbole(p, "ANDOR", "&&") || read_symbole(p, "ANDOR", "||")) && ZeroOrMany(read_spaces(p)) && ZeroOrMany(parser_readchar(p, '\n')) && ZeroOrMany(read_spaces(p)) && read_pipeline(p))))
    {
        struct s_node_and_or *andor = init_andor(p);
        //print_node(p->nodes);
        //printf("enfant %d\n", andor->child);
        while(find_pipeline(p, andor));
        //print_andor(andor);
        union all_grammar *grammar = malloc(sizeof(union all_grammar));
        grammar->andor = andor;
        list_node_store(p->nodes, grammar, ANDOR);
        //printf("*****REUSSI ANDOR *******\n");
	print_and_or_to_pipeline(andor, fopen("ast.dot", "w+"));
	return 1;
    }
    p->cursor = tmp;
    return 0;
}
