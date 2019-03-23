#include "grammar.h" 
/*
case_clause:
case_item (';;' ('\n')* case_item)* [;;] ('\n')*
*/

int read_case_clause(struct parser_s *p)
{
    int tmp = p->cursor;

    if (read_case_item(p)
	&& ((ZeroOrMany(parser_readtext(p, ";;"))) && (ZeroOrMany(ZeroOrMany(parser_readchar(p, '\n')))) && ZeroOrMany(read_case_item(p)))
	&& ZeroOrOne(parser_readtext(p, ";;")) && ZeroOrMany(parser_readchar(p, '\n')))
      {
	printf("AST read CASE CLAUSE : SUCCES\n");
	return 1;
      }
    printf("AST read CASE CLAUSE : FAIL\n");
    p->cursor = tmp;
    return 0;
}

