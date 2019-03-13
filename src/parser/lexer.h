#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

enum token_type{
  Spaces,
  Id,
  Identifiant,
  Command,
  Option,
  Number,
  Operator,
  Logic,
  Separator,
  Eof,
  Quote,
  Pipe,
};

struct token_s
{
  int begin;
  int end;
};

struct token_list
{
    enum token_type type;
    struct token_s token;
    struct token_list *next;
};

struct lexer
{
  int cursor;
  char *input;
  struct token_list *token_list;
};


struct lexer *parser_new_from_string(const char *text);
int parser_readtext(struct lexer *p, char *text);
void parser_clean(struct lexer *p);
int parser_eof(struct lexer *p);
int parser_peekchar(struct lexer *p, char c);
int parser_readchar(struct lexer *p, char c);
int parser_readtext(struct lexer *p, char *text);
int parser_readrange(struct lexer *p, char begin, char end);
int read_Alpha(struct lexer *p);
int parser_readinset(struct lexer *p, char *set);
int read_Spacing(struct lexer *p);
int parser_readoutset(struct lexer *p, char *set);
int parser_readeol(struct lexer *p);
struct token_s *list_capt_lookup(struct token_list *capt, const char *tag);
char *parser_get_capture(struct lexer *p, const char *tag);
char *copieInput(char *str[]);
int count_caracter(char *str[]);
struct token_list *init_list_capt(struct lexer *p);
#endif

