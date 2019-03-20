#include "ast.h"

/*
rule_for:'
    for' WORD ([';']|[('\n')* 'in' (WORD)* (';'|'\n')]) ('\n')* do_group
*/
int read_for(struct parser_s *p)
{
    int tmp = p->cursor;

    if (parser_readtext(p, "for")
	&& read_word(p)
	&& ((ZeroOrOne(parser_readchar(p, ';'))) ||
	    ((ZeroOrOne(ZeroOrMany(parser_readchar(p, '\n')))) && (ZeroOrOne(parser_readtext(p, "in"))) && (ZeroOrOne(ZeroOrMany(read_word(p)))) && ((ZeroOrOne(parser_readchar(p, ';'))) ||
																		     ZeroOrOne(parser_readchar(p, '\n')))))
	&& ZeroOrMany(parser_readchar(p, '\n'))
	&& read_do_group(p))
      {
	printf("AST read FOR : SUCCES\n");
	return 1;
      }
    printf("AST read FOR : FAIL\n");
    p->cursor = tmp;
    return 0;
}

								   
