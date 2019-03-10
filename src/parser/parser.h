#ifndef PARSER_H
#define PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ZeroORMany(R)                                  \
    ({                                                 \
        while(R)                                       \
            ;                                          \
        true;                                          \
    })                                                 \
    
#define OneORMany(R)                            \
  ({ int res = FALSE;				\
    if (R)					\
      {						\
	while(R)				\
	  ;					\
	res = TRUE;				\
      }						\
    res;					\
    })                                          \
  
#define ZeroOrOne(R)					\
  ({  R;						\
    true;						\
  })							\

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
int parser_readidentifier(struct parser_s *p , int end);
int parser_readinteger(struct parser_s *p, int end);

// Assisgnement 4
struct list_capt_s *list_capt_store(struct list_capt_s *capt, const char *tag, 
    struct capture_s *capture);
struct capture_s *list_capt_lookup(struct list_capt_s *capt, const char *tag);
int parser_begin_capture(struct parser_s *p, const char *tag);
int parser_end_capture(struct parser_s *p, const char *tag);
char *parser_get_capture(struct parser_s *p, const char *tag);

#endif /* PARSER_H */

