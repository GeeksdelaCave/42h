#include "parser.h"

struct parser_s *parser_new_from_string(const char *text)
{
    struct parser_s *p = malloc(sizeof(p));

    if (p == NULL)
    {
        return p;
    }
    p->cursor = 0;
    p->input = malloc(sizeof(char) * strlen(text));
    strcpy(p->input, text);
    return p;
}
void parser_clean(struct parser_s *p)
{
    free(p);
}
int parser_eof(struct parser_s *p)
{
    if(p->input[p->cursor] == '\0' || p->input[p->cursor] == 0)
    {
        return 1;
    }
    return 0;
}
char parser_getchar(struct parser_s *p)
{
    char c = p->input[p->cursor];
    p->cursor++;
    return c;
}

int parser_peekchar(struct parser_s *p, char c)
{
    if (p->input[p->cursor] == c)
    {
        return 1;
    }
    return 0;
}
int parser_readchar(struct parser_s *p, char c)
{
    if (p->input[p->cursor] == c)
    {
        p->cursor++;
        return 1;
    }
    return 0;
}

int parser_readtext(struct parser_s *p, char *text)
{
    while(p->input[p->cursor] != '\0')
    {
        if (p->input[p->cursor] != text[p->cursor])
        {
            return 0;
        }
        p->cursor++;
    }
    return 1;
}

int parser_readrange(struct parser_s *p, char begin, char end)
{
    if (p->input[p->cursor] >= begin && p->input[p->cursor] <= end)
    {
        p->cursor = p->cursor + 1;
        return 1;
    }
    return 0;
}

int parser_readinset(struct parser_s *p, char *set)
{
    for(int i = 0; set[i]; i++)
    {
        if (p->input[p->cursor] == set[i])
        {
            return 1;
        }
        p->cursor++;
    }
    return 0;
}
int parcer_readoutset(struct parser_s *p, char *set)
{
    for(int i = 0; set[i]; i++)
    {
        if (p->input[p->cursor] == set[i])
        {
            return 0;
        }
        p->cursor++;
    }
    return 1;
}
int parser_readeol(struct parser_s *p)
{
    if (p->input[p->cursor] == '\n')
    {
        return 1;
    }
    else
    {
        if (p->input[p->cursor] == '\r' && p->input[p->cursor++] == '\n')
        {
            return 1;
        }
    }
    return 0;
}
int parser_readidentifier(struct parser_s *p)
{
    if (parser_readrange(p, 'a', 'z') || parser_readrange(p, 'A', 'Z') || parser_readchar(p, '_'))
    {
        for(int i = p->cursor; p->input[i]; i++)
        {
            if (!parser_readrange(p, 'a', 'z') && ! parser_readrange(p, 'A', 'Z') && ! parser_readchar(p, '_') && !parser_readrange(p, '0', '9'))
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
int parser_readinteger(struct parser_s *p)
{
    if (parser_readrange(p, '0', '9'))
    {
        for (int i = p->cursor; p->input[i]; i++)
        {
            if (!parser_readrange(p, '0', '9'))
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
