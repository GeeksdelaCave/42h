#ifndef PARSER_INIT_H
#define PARSER_INIT_H
#define TRUE 1
#define FALSE 0
#define ZeroOrOne(R)   \
  __extension__({      \
      R;	       \
      TRUE;	       \
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
void free_list_capt_s(struct list_capt_s *capture);
void parser_clean(struct parser_s *p);
int read_spaces(struct parser_s *p);
#endif
