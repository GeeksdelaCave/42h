/**
 ** \file  parser_capture.c
 */
#include "grammar.h" 
/**
 ** \brief store the capt add in
 **  the list capt
 **
 ** \param p struct parser
 ** \param tag name of capture
 ** \param capt struct capture
 */
void list_capt_store(struct list_capt_s *capture, const char *tag, struct capture_s *capt)
{
  for(; capture->next; capture = capture->next);
  capture->next = init_list_capt();
  capture->tag = strdup(tag);
  capture->capt = *capt;
}
/**
 ** \brief look for the tag in the capt list
 **
 ** \param captur list of capture
 ** \param tag name of capture
 **
 ** \return struct capture
 */
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
/**
 ** \brief Function that retrieves the next
 **  capture
 **
 ** \param p structure of parser
 */
void eat_list_capt(struct parser_s *p)
{
  if (p->capture->next != NULL)
    {
      struct list_capt_s *list = p->capture->next;
      free(p->capture);
      p->capture = list;
    }
}
/**
 ** \brief Function that retrieves the tag
 **
 ** \param p structure of parser and char *tag
 **
 ** \return a tag
 */
char *parser_get_capture(struct parser_s *p, const char *tag)
{
  struct capture_s *pcapt = list_capt_lookup(p->capture, tag);
  if (!pcapt){
    return false;
  }
  eat_list_capt(p);
  return (strndup(&p->input[pcapt->begin], pcapt->end - pcapt->begin));
}

/**
 ** \brief Function Look the same tag in the list
 **
 ** \param p structure of parser and char* tag
 **
 ** \return true or false
 */
bool parser_end_capture(struct parser_s *p, const char *tag)
  {
    struct capture_s *pcapt = list_capt_lookup(p->capture, tag);
    if (!pcapt)
      return false;
    pcapt->end = p->cursor;
    return true;
}
/**
 ** \brief Function Set the begin of
 ** the capture and store and the list
 **
 ** \param p structure of parser and char* tag
 **
 ** \return true or false
 */ 
bool parser_begin_capture(struct parser_s *p, const char *tag)
{
  struct capture_s capt =  {p->cursor, 0 };
  list_capt_store(p->capture, tag, &capt);
  return true;
}
