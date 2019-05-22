/**
 ** \file  parser_init.c
 */
#include "grammar.h"
/**
 ** \brief 1 Initializing of parser with
 ** l'input text
 **
 ** \param input string text
 **
 ** \return struct p
 */
struct parser_s *parser_new_from_string(const char *text)
{
  struct parser_s *p = malloc(sizeof(struct parser_s));
  if (p == NULL)
  {
    return NULL;
  }
  p->cursor = 0;
  p->capture = init_list_capt();
  p->input = malloc(sizeof(char) * strlen(text));
  p->nodes = init_list_node();
  strcpy(p->input, text);
  return p;
}
/**
 ** \brief 1 Initialisation of catch list
 **
 ** \return captur
 */
struct list_capt_s *init_list_capt()
{
  struct list_capt_s *capture = malloc(sizeof(struct list_capt_s));
  capture->capt.begin = 0;
  capture->capt.end = 0;
  capture->next = NULL;
  capture->tag = NULL;
  return capture;
}
/**
 ** \brief Clean content of the catch list
 **
 ** \param th catch list
 **
 */
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
/**
 ** \brief Clean all the content in a parser
 **
 ** \param p struct parser
 **
 */
void parser_clean(struct parser_s *p)
{
  if (p)
  {
    free(p->input);
    free_list_capt_s(p->capture);
    free(p);
  }
}
/**
 ** \brief  return true if read space
 **
 ** \param catch list of capture
 **
 ** \return true or false
 */
int read_spaces(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_readinset(p, " \t"))
  {
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
