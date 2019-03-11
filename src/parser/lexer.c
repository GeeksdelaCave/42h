#include "lexer.h"

struct token_list *list = NULL;
struct lexer *parser_new_from_string(const char *text)
{
  struct lexer *p = malloc(sizeof(struct lexer));
  if (p == NULL)
    {
     return p;
    }
  p->cursor = 0;
  p->token_list = NULL;
  p->input = malloc(sizeof(char) * strlen(text));
  strcpy(p->input, text);

  return p;
}

struct token_list *init_list_capt(struct lexer *p)
{
  struct token_list *capture = malloc(sizeof(struct token_list));
  capture->token.begin = 0;
  capture->token.end = 0;
  capture->next = p->token_list;
  capture->tag = malloc(sizeof(char*));
  return capture;
}

void parser_clean(struct lexer *p)
{
  free(p);
}

int parser_eof(struct lexer *p)
{
  if(p->input[p->cursor] == '\0' || p->input[p->cursor] == 0)
    {
      return 1;
    }
  return 0;
}
char parser_getchar(struct lexer *p)
{
  char c = p->input[p->cursor];
  p->cursor++;
  return c;
}

int parser_peekchar(struct lexer *p, char c)
{
  if (p->input[p->cursor] == c)
    {
      return 1;
    }
  return 0;
}

int parser_readchar(struct lexer *p, char c)
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

int parser_readtext(struct lexer *p, char *text)
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

int parser_readinset(struct lexer *p, char *set)
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

int parser_readoutset(struct lexer *p, char *set)
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
int parser_readeol(struct lexer *p)
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

struct token_s *list_capt_lookup(struct token_list *capt, const char *tag)
{
  for (; capt; capt = capt->next)
    if (!strcmp(capt->tag, tag))
      return &(capt->token);
  return NULL;
}

int parser_readrange(struct lexer *p, char begin, char end)
{
  if (p->input[p->cursor] >= begin && p->input[p->cursor] <= end)
    {
      p->cursor += 1;
      return 1;
    }
  return 0;
}

int parser_readoperation(struct lexer *p)
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

