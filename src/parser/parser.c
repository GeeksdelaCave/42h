#include "parser.h"
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

struct capture_s *list_capt_lookup(struct list_capt_s *capt, const char *tag)
{
  for (; capt; capt = capt->next)
    if (!strcmp(capt->tag, tag))
      return &(capt->capt);
  return NULL;
}

/*
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
*/



// print content of the list of tokens
void print_content_listToken(struct parser_s *parser)
{
    int cpt = 1;
    struct list_capt_s *p = parser->capture;
    while(p)
    {
        printf("Token num : %d \n", cpt);
        printf("TAG : %s\n", p->tag);
        for(int i = p->capt.begin; i < p->capt.end+1; i++)
            printf("%c", parser->input[i]);
        printf("\n");
        printf("BEGIN %d\n", p->capt.begin);
        printf("END %d\n", p->capt.end);
        printf("\n");
        cpt++;
        p = p->next;
    }
}


void print_content_Token(struct parser_s *parser)
{
    struct list_capt_s *p = parser->capture;
        printf("TAG : %s\n", p->tag);
        for(int i = p->capt.begin; i <= p->capt.end; i++)
            printf("%c", parser->input[i]);
        printf("\n");
        printf("BEGIN %d\n", p->capt.begin);
        printf("END %d\n", p->capt.end);
        printf("\n");
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

int parser_readinteger(struct parser_s *p, int end)
{
    printf("d-> %d le char à tester %c \n", p->cursor,p->input[p->cursor]);
    int cpt = p->cursor;
    if (parser_readrange(p, '0', '9'))
    {
        for (int i = p->cursor; i <= end; i++)
        {
            printf("le char à tester %c \n", p->input[p->cursor]);
            if (!parser_readrange(p, '0', '9'))
            {
                p->cursor = cpt;
                return 0;
            }
        }
        p->cursor++;
        return 1;
    }
    p->cursor = cpt;
    return 0;
}

int parser_readidentifier(struct parser_s *p, int end)
{
    printf("d-> %d le char à tester %c \n", p->cursor,p->input[p->cursor]);
    int cpt = p->cursor;
    if (parser_readrange(p, 'a', 'z') || parser_readrange(p, 'A', 'Z') ||
    parser_readchar(p, '_'))
    {
        printf("p2 -> %d, et end -> %d", p->cursor ,end);
        for (int i = p->cursor; i <= end; i++)
        {
            printf("le char à tester %c \n", p->input[p->cursor]);
            if (!(parser_readrange(p, 'a', 'z') || parser_readrange(p, 'A', 'Z') || parser_readchar(p, '_') || parser_readrange(p, '0', '9')))
            {
                p->cursor = cpt;
                return 0;
            }
        }
        p->cursor++;
        return 1;
    }
    p->cursor = cpt;
    return 0;
}

int parser_readoperation(struct parser_s *p)
{
  return (parser_readchar(p, '+') || parser_readchar(p, '/') ||
	  parser_readchar(p, '*') || parser_readchar(p, '-'));
}

struct list_capt_s *list_capt_store(struct list_capt_s *capt, const char *tag, struct capture_s *capture)
{
  struct list_capt_s *pc = (struct list_capt_s*) malloc(sizeof(struct list_capt_s));
  pc->tag = malloc(strlen(tag));
  strcpy(pc->tag,tag);
  pc->next = capt;
  pc->capt.begin = capture->begin;
  pc->capt.end = capture->end;
  return pc;
}

int count_caracter(char *str[])
{
  int count = 0;
  for (int i = 1; str[i] != NULL; i++)
    {
      count = count + strlen(str[i]);
    }
  return count;
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

struct parser_s *set_token_list(char *str[], int size)
{
    struct parser_s *parser = NULL;
    struct list_capt_s *capture = NULL;
    const char *text = copieInput(str);
    int i = 1;

    if (size > 1)
    {
        parser = parser_new_from_string(text);
        printf("À l'entrer : %s\n", parser->input);
        while (i < size)
    	{
            capture = init_list_capt(parser);
    	    capture->capt.begin = parser->cursor;
            printf("LA DEBUT DE DU CURSOR de input numero %d est %d \n",i, capture->capt.begin);
            capture->capt.end = (strlen(str[i]) + parser->cursor) - 1;
            printf("LA FIN DE DU CURSOR de input numero %d est %d \n",i, capture->capt.end);
            printf("LE CURSOR EST A %d\n", parser->cursor);
    	    if (parser_readinteger(parser, capture->capt.end))
    	    {
                parser->capture = list_capt_store(parser->capture, "Number", &capture->capt);
            }
            else if(parser_readidentifier(parser, capture->capt.end))
            {
                parser->capture = list_capt_store(parser->capture, 
                "readIndentifier", &capture->capt);
            }
	    else if (parser_readoutset(parser, "+-*/"))
	      {
		parser->capture = list_capt_store(parser->capture, "Operation", &capture->capt);
	      }
            else
            {
                parser->capture = list_capt_store(parser->capture,"OTHER",
                &capture->capt);
                parser->cursor = capture->capt.end + 2;
            }
            i++;
    	}
    }
    print_content_listToken(parser);
    return parser;
}
/*
int main(int argc, char *argv[])
{
  set_token_list(argv, argc);
  return 0;
}
*/
