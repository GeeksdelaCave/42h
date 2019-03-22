#include "ast.h"

int read_and_or(struct parser_s *p)
{
    int tmp = p->cursor;
    if (ZeroOrMany(read_spaces(p)) && read_pipeline(p)
        && ZeroOrMany(read_spaces(p))
        && (ZeroOrMany((read_symbole(p, "ANDOR", "&&") ||
                        read_symbole(p, "ANDOR", "||")) &&
                       ZeroOrMany(read_spaces(p)) &&
                       ZeroOrMany(parser_readchar(p, '\n')) &&
                       ZeroOrMany(read_spaces(p)) && read_pipeline(p))))
    {
        return 1;
    }
    p->cursor = tmp;
    printf("READ ANDOR FAil !!!!!!!!!!!!!!!!!!!!\n");
    return 0;
}
