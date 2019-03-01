#include "parser.h"
/*
struct parser_s *parser_new_from_string(const char *text)
{
    struct parser_s *p = malloc(sizeof(p));

    if (p == NULL)
    {
        return p;
    }
    p->cursor = 0;
    p->capture = NULL;
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
void list_capt_store(struct list_capt_s *list, const char *tag, struct capture_s *capture)
{
  struct list_capt_s *new = malloc(sizeof(struct list_capt_s));
  new->tag = malloc(strlen(tag));
  new->tag = strcpy(new->tag, tag);
  new->capt = *capture;
  new->next = list;
}
struct capture_s *list_capt_lookup(struct list_capt_s *list, const char *tag)
{
  for(; list; list = list->next)
    {
      if (strcmp(list->tag, tag))
	{
	  struct capture_s capture = list->capt;
	  return &capture;
	}
    }
}
*/
struct list_capt_s *list = NULL;
#include "parser.h"
#include <string.h>

int myfunc1()
{
  return 42;
}

int myfunc2(int a, int b)
{
  return (42 + b) / a;
}

struct parser_s *parser_new_from_string(const char *text)
{
  struct parser_s *p = malloc(sizeof(p));

    if (p == NULL)
    {
      return p;
    }
    p->cursor = 0;
    p->capture = NULL;
    p->input = malloc(sizeof(char) * strlen(text));
    //strcpy(p->input, text);
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

/*
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
*/

int parser_readtext(struct parser_s *p, char *text)
{
  int tmp = p->cursor;
  int i = 0;

  for(; parser_readchar(p,text[i]); ++i)
    ;

  if (!text[i])
    return 1;

  p->cursor = tmp;
  return 0;
}

int parser_readrange(struct parser_s *p, char begin, char end)
{
  if (p->input[p->cursor] >= begin && p->input[p->cursor] <= end)
    {
      p->cursor += 1;
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
  if (parser_readrange(p, 'a', 'z') || parser_readrange(p, 'A', 'Z') ||
      parser_readchar(p, '_'))
    {
      while (parser_readrange(p, 'a', 'z') || parser_readrange(p, 'A', 'Z') ||
	     parser_readchar(p, '_') || parser_readrange(p, '0', '9'))
	;
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

int read_number(struct parser_s *p)
{
  if (parser_readrange(p, '0', '9'))
    {
      while(parser_readrange(p, '0', '9'))
	return 1;
    }
  return 0;
}

  void list_capt_store(struct list_capt_s **capt, const char *tag, struct capture_s *capture)
{
  struct list_capt_s *pc = (struct list_capt_s*) malloc(sizeof(struct list_capt_s));
  pc->tag = malloc(strlen(tag));
  strcpy(pc->tag,tag);
  pc->next = *capt;
  pc->capt.begin = capture->begin;
  pc->capt.end = capture->end;
  *capt = pc;
}

struct capture_s *list_capt_lookup(struct list_capt_s *capt, const char *tag)
{
  for (; capt; capt = capt->next)
    if (!strcmp(capt->tag, tag))
      return &(capt->capt);
  return NULL;
}

int parser_begin_capture(struct parser_s *p, const char *tag)
{
  struct capture_s capt = {p->cursor, 0};
  list_capt_store(&(p->capture), tag, &capt);
  return 1;
}

int parser_end_capture(struct parser_s *p, const char *tag)
{
  struct capture_s *pcapt = list_capt_lookup(p->capture, tag);
  if (!pcapt)
    return 0;
  pcapt->end = p->cursor;
  return 1;
}
char *parser_get_capture(struct parser_s *p, const char *tag)
{
  struct capture_s *pcapt = list_capt_lookup(p->capture, tag);
  if (!pcapt)
    return 0;
  return strndup(&p->input[pcapt->begin], pcapt->end - pcapt->begin);
}
struct parser_s *set_token_list(char *str[], int size)
{
  enum tag my_tag;
  struct parser_s *parser = NULL;
  int i = 1;
  struct capture_s capt = {0, 0};
  if (size > 1 )
    {
      parser = parser_new_from_string(str[i]);
      while (i < size)
	{
	  parser->input = strcpy(parser->input,str[i]);
	  i++;
	  capt.begin = parser->cursor;
	  if (parser_readinteger(parser))
	    {
	      printf("%s\n", parser->input);
	      capt.end = parser->cursor;
	      list_capt_store(&parser->capture, "Number", &capt);
	    }
	  if (parser_readchar(parser, ' '))
	    {
	      printf("Space\n");
	      capt.end = parser->cursor;
	      list_capt_store(&parser->capture, "Space", &capt);  
	    }
	}
    }
  return parser;
}
int main(int argc, char *argv[])
{
  set_token_list(argv, argc);
  //printf("%s\n", argv[2]);
}

