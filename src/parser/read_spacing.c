#include "ast.h"

/* 
    Spaces <- '\t'* 
*/
int read_spaces(struct parser_s *p)
{
    int tmp = p->cursor;
    if (parser_readinset(p, " \t"))
    {
        return 1;
    }
    p->cursor = tmp;
    return 0;
}

/* 
    EndOfLine <- ['\r'] '\n' 
*/
int read_EndOfLine(struct parser_s *p)
{
    int tmp = p->cursor;
    if (ZeroOrOne(parser_readchar(p, '\r')) && parser_readchar(p, '\n'))
    {
        return 1; 
    } 
    p->cursor = tmp;
    return 0;
}

/* 
    Spacing <- Spaces EndOfLine / ';' (!\r\n)* EndOfLine 
*/
int read_spacing(struct parser_s *p)
{
    int tmp = p->cursor;

    if (read_spaces(p) && read_EndOfLine(p))
    {
        return 1;
    }
    p->cursor = tmp;
    if (parser_readchar(p, ';')
        && ZeroOrMany(parser_readoutset(p, "\r\n"))
        && read_EndOfLine(p))
    {
        return 1;
    }
    p->cursor = tmp;
    return 0;

}