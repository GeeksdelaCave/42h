#ifndef PARSER_TP_H
#define PARSER_TP_H
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0

#define ZeroOrOne(R)   \
  __extension__({      \
      R;       \
      TRUE;       \
    })
#define ZeroOrMany(R)  \
  __extension__({      \
      while(R)       \
	;       \
      TRUE;       \
    })
#define OneOrMany(R)    \
  __extension__ ({    \
      int res = FALSE;      \
      if(R)      \
	{      \
	  while(R)      \
	    ;                 \
	  res = TRUE;      \
	}                 \
      res;  \
    })
struct parser_s
{
  int cursor;
  char *input;
  struct list_capt_s *capture;
  struct list_node_s *nodes;
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
struct list_capt_s *init_list_capt();
int read_pipe(struct parser_s *p);
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
struct capture_s *list_capt_lookup(struct list_capt_s *captur, const char *tag);
void parser_eat_capture(struct parser_s *p);
int read_excla(struct parser_s *p);
int read_symbole(struct parser_s *p, char* tag, char* type);
int read_virgule(struct parser_s *p);
int read_and(struct parser_s *p);
int read_for_word(struct parser_s *p);
//bool parser_begin_capture(struct parser_s *p, const char *tag);
//bool parser_end_capture(struct parser_s *p, const char *tag);
//char *parser_get_capture(struct parser_s *p, const char *tag);
bool parser_begin_capture(struct parser_s *p, const char *tag);
/*
{

  struct capture_s capt = { p->cursor, 0 };

  list_capt_store(p->capture, tag, &capt);

  return true;

}

*/

char *parser_get_capture(struct parser_s *p, const char *tag);
/*
{
  struct capture_s *pcapt = list_capt_lookup(p->capture, tag);
  if (!pcapt)
    return false;
  return (strndup(&p->input[pcapt->begin], pcapt->end - pcapt->begin));

}
  */
bool parser_end_capture(struct parser_s *p, const char *tag);
/*
{

  struct capture_s *pcapt = list_capt_lookup(p->capture, tag);

  if (!pcapt)

    return false;

  pcapt->end = p->cursor;

  return true;

}
*/

struct capture_s *list_capt_lookup(struct list_capt_s *capt, const char *tag);
void print_node(struct list_node_s *node);
#endif
