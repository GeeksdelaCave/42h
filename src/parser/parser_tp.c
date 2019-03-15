#include "parser_tp.h"
/* Iniitialisation du parser avec l'input text */

struct parser_s *parser_new_from_string(const char *text)
{
  struct parser_s *p = malloc(sizeof(struct parser_s*));
  if (p == NULL)
    {
      return NULL;
    }
  p->cursor = 0;
  p->capture = init_list_capt();
  p->input = malloc(sizeof(char) * strlen(text));
  strcpy(p->input, text);
  return p;
}
struct list_capt_s *init_list_capt()
{
  struct list_capt_s *capture = malloc(sizeof(struct list_capt_s));
  capture->capt.begin = 0;
  capture->capt.end = 0;
  capture->next = NULL;
  capture->tag = NULL;
  return capture;
}
/*Clean content of the list Capt */
void free_list_capt_s(struct list_capt_s *capture)
{
  struct list_capt_s *prev_catpure = capture;
  while (capture)
      {
        if (capture->next)
	  {
            free(capture->tag);
	  }
        prev_catpure = capture;
        capture = capture->next;
        free(prev_catpure);
      }
}
/* Clean all the content in a parser */
void parser_clean(struct parser_s *p)
{
  if (p)
    {
      free(p->input);
      free_list_capt_s(p->capture);
      free(p);
    }
}
/* Check EOF */
int parser_eof(struct parser_s *p)
{
    if(p->input[p->cursor] == '\0' || p->input[p->cursor] == 0)
      {
	return 1;
      }
    return 0;
}
/* return the current char */
char parser_getchar(struct parser_s *p)
{
  char c = p->input[p->cursor];
  p->cursor++;
  return c;
}
/* true if the current char = c */
int parser_peekchar(struct parser_s *p, char c)
{
    if (p->input[p->cursor] == c)
      {
	return 1;
      }
    return 0;
}
/* true if the current char = c and move cursor */
int parser_readchar(struct parser_s *p, char c)
{
  if (p->input[p->cursor] == c)
    {
      p->cursor++;
      return 1;
    }
  return 0;
}
/* true if the string text = the current cursor string */
int parser_readtext(struct parser_s *p, char *text)
{
  char *cmp = p->input + p->cursor;
  int cpt = p->cursor;
    
  for(int i = 0; text[i]; i++)
    {
      if(cmp[cpt] != text[i])
	return 0;
      cpt++;
    }
  return 1;
}
/* True if the char at the current cursor is respectevely inside the range of the char and move */
int parser_readrange(struct parser_s *p, char begin, char end)
{
    if (p->input[p->cursor] >= begin && p->input[p->cursor] <= end)
      {
        p->cursor += 1;
        return 1;
      }
    return 0;
}
/* true if the char at the current cursor is inside the set of char and move */
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
/* true if the char at the current cursor is not inside the set of char and move */
int parser_readoutset(struct parser_s *p, char *set)
{
  for(int i = 0; set[i]; i++)
    {
      if (p->input[p->cursor] == set[i])
	return 0;
      p->cursor++;
    }
  return 1;
}
/* True if the char at the current cursor is a char */
int parser_readalpha(struct parser_s *p)
{
  if(parser_readrange(p, 'a', 'z') || parser_readrange(p, 'A', 'Z'))
    {
      return 1;
    }
  return 0;
}
/* True if the current char is a number */
int parser_readnum(struct parser_s *p)
{
  if(parser_readrange(p, '0', '9'))
    {
      return 1;
    }
  return 0;
}
/* True if the char is a variable*/
int parser_var(struct parser_s *p)
{
  if (parser_readnum(p) || parser_readalpha(p) || parser_readchar(p, '_'))
    {
      return 1;
    }
  return 0;
}
/*True if the current char is a Id */
int parser_readidentifier(struct parser_s *p)
{
  if ((parser_readalpha(p) || parser_readchar(p, '_')) && ZeroOrMany(parser_var(p)))
    {
      printf("j'arrête identifier à ->    %c\n", p->input[p->cursor]);
      return 1;
    }
  return 0;
}
/* True if the current char is a number */
int parser_readinteger(struct parser_s *p)
{
  if (OneOrMany(parser_readnum(p)))
    {
      return 1;
    }
  return 0;
}
/* Store the capt add in the list capt*/
void list_capt_store(struct list_capt_s *capture, const char *tag, struct capture_s *capt)
{
  for(; capture->next; capture = capture->next);
  capture->next = init_list_capt();
  capture->tag = strdup(tag);
  capture->capt = *capt;
}
/*Parser for assign */
int read_Assign(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_begin_capture(p, "id") && parser_readidentifier(p) && 
  parser_end_capture(p, "id") && parser_readchar(p, '=') &&
  parser_begin_capture(p, "num") && parser_readinteger(p) && parser_end_capture
  (p, "num"))
    {
      char *id = parser_get_capture(p, "id");
      char *num = parser_get_capture(p, "num");
      printf("Dans Assignement %s %s\n", id, num);
      return 1;
    }
  p->cursor = tmp;
  return 0;
}
/*Set the begin of the capture and store and the list */
static inline bool parser_begin_capture(struct parser_s *p, const char *tag)
{
  struct capture_s capt = { p->cursor, 0 };
  list_capt_store(p->capture, tag, &capt);
  return true;
}
/*Look the same tag in the list and return true */
static inline bool parser_end_capture(struct parser_s *p, const char *tag)
{
  struct capture_s *pcapt = list_capt_lookup(p->capture, tag);
  if (!pcapt)
    return false;
  pcapt->end = p->cursor;
  return true;
}
/*look for the tag in the capt list */
struct capture_s *list_capt_lookup(struct list_capt_s *captur, const char *tag)
{
  for (; captur->next; captur = captur->next)
    {
    if (strcmp(captur->tag, tag) == 0)
	{
        return &(captur->capt); 
	}
    }
  return NULL;
}
/*return string if they are the same tag */
static inline char *parser_get_capture(struct parser_s *p, const char *tag)
{
  struct capture_s *pcapt = list_capt_lookup(p->capture, tag);
  if (!pcapt){
    return false;
  }
  return (strndup(&p->input[pcapt->begin], pcapt->end - pcapt->begin));
}
int main()
{
  struct parser_s *parser = parser_new_from_string("A142535=1154554");
  //printf("%d\n", parser_readidentifier(parser))
  read_Assign(parser);
  // printf("%s\n", parser->input);
}
