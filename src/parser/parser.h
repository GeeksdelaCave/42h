#ifndef PARSER_H
#define PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

enum tag{
  Spaces,
  Id,
  Number,
  Operator,
  Logic,
  Eof,
  Quote,
  Pipe,
};

struct parser_s
{
  int cursor;
  char *input;
  struct list_capt_s *capture;
};
struct capture_s
{
  int begin;
  int end;
}; 
struct list_capt_s
{
  char *tag;
  struct capture_s capt;
  struct list_capt_s *next;
};
struct parser_s *parser_new_from_string(const char *text);
int parser_readtext(struct parser_s *p, char *text);
void parser_clean(struct parser_s *p);
int parser_eof(struct parser_s *p);
int parser_peekchar(struct parser_s *p, char c);
int parser_readchar(struct parser_s *p, char c);
int parser_readtext(struct parser_s *p, char *text);
int parser_readrange(struct parser_s *p, char begin, char end);
int read_Alpha(struct parser_s *p);
int parser_readinset(struct parser_s *p, char *set);
int read_Spacing(struct parser_s *p);
int parser_readoutset(struct parser_s *p, char *set);
int parser_readeol(struct parser_s *p);
struct capture_s *list_capt_lookup(struct list_capt_s *capt, const char *tag);
char *parser_get_capture(struct parser_s *p, const char *tag);
char *copieInput(char *str[]);
int count_caracter(char *str[]);
struct list_capt_s *init_list_capt(struct parser_s *p);
#endif

