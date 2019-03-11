#include "parser.h"

struct list_capt_s *list = NULL;
struct parser_s *parser_new_from_string(const char *text)
{
  struct parser_s *p = malloc(sizeof(struct parser_s*));
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

struct list_capt_s *init_list_capt(struct parser_s *p)
{
  struct list_capt_s *capture = malloc(sizeof(struct list_capt_s));
  capture->capt.begin = 0;
  capture->capt.end = 0;
  capture->next = p->capture;
  capture->tag = malloc(sizeof(char*));
  return capture;
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

int parser_readoutset(struct parser_s *p, char *set)
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

struct capture_s *list_capt_lookup(struct list_capt_s *capt, const char *tag)
{
  for (; capt; capt = capt->next)
    if (!strcmp(capt->tag, tag))
      return &(capt->capt);
  return NULL;
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

int parser_readoperation(struct parser_s *p)
{
  return (parser_readchar(p, '+') || parser_readchar(p, '/') ||
	  parser_readchar(p, '*') || parser_readchar(p, '-'));
}

int count_caracter(char *str[])
{
  int count = 0;
  for (int i = 1; str[i] != NULL; i++)
    {
      count = count + strlen(str[i]);
    }	  return count;
}

//function qui copie le contenu d'argv en char*
char *copieInput(char *str[])
{
  int size_tab = count_caracter(str);
  char *res = malloc(sizeof(char) * size_tab);
  for(int i = 1; str[i]; i++)
    {
      strcat(res, str[i]);
      strcat(res, " ");
    }
  return res;
}

