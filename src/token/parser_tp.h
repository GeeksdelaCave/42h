#ifndef PARSER_TP_H
#define PARSER_TP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0
/*
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
*/
#define OPTIONAL(R)
{
  R;
  TRUE;
}
#define ZeroOrMany(R)
{
  while(R)
    ;
  TRUE;
}
#define OneOrMany(R)
{ int res = FALSE;
  if(R)
    {
      while(R)
	;
      res = TRUE;
    }
  res;
}

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
struct list_capt_s *init_list_capt(struct parser_s *p);
void free_list_capt_s(struct list_capt_s *capture);
void parser_clean(struct parser_s *p);
int parser_eof(struct parser_s *p);
char parser_getchar(struct parser_s *p);
int parser_peekchar(struct parser_s *p, char c);
int parser_readchar(struct parser_s *p, char c);
int parser_readtext(struct parser_s *p, char *text);
int parser_readrange(struct parser_s *p, char begin, char end);
int parser_readinset(struct parser_s *p, char *set);
int parser_readoutset(struct parser_s *p, char *set);
int parser_readalpha(struct parser_s *p);
int parser_readnum(struct parser_s *p);
int parser_var(struct parser_s *p);
int parser_readidentifier(struct parser_s *p);
int parser_readinteger(struct parser_s *p);
void list_capt_store(struct list_capt_s *capture, const char *tag, struct capture_s *capt);
int read_Assign(struct parser_s *p);
static inline bool parser_end_capture(struct parser_s *p, const char *tag);
struct capture_s *list_capt_loopup(struct list_capt_s *capt, const char *tag);
#endif

