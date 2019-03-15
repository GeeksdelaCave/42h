#include "token_list.h"
struct parser_s *set_token_list(char *str[], int size)
{
  struct parser_s *parser = NULL;
  struct list_capt_s *capture = NULL;
  const char *text = copieInput(str);
  char *tag_condition = NULL;
  int i = 1;
  if (size > 1)
    {
      parser = parser_new_from_string(text);
      while (i < size)
	{
	  capture = init_list_capt(parser);
	  capture->capt.begin = parser->cursor;
	  capture->capt.end = (strlen(str[i]) + parser->cursor) - 1;
	  if (parser_readinteger(parser, capture->capt.end))
	    {
	      parser->capture = list_capt_store(parser->capture, "Number", &capture->capt);
	    }
	  else if ((tag_condition = set_condition_tag(parser, capture->capt.end))!= NULL)
	    {
	      parser->capture = list_capt_store(parser->capture, 
						tag_condition, &capture->capt);
	    }
	  else if ((tag_condition = set_condition_symbol(parser, capture->capt.end))!= NULL)
	    {
	      parser->capture = list_capt_store(parser->capture, 
						tag_condition, &capture->capt);
	    }
	  else if ((tag_condition = set_loop_tag(parser, capture->capt.end))!= NULL)
	    {
	      parser->capture = list_capt_store(parser->capture, 
						tag_condition, &capture->capt);
	    }
	  else if(parser_readidentifier(parser, capture->capt.end))
	    {
	      parser->capture = list_capt_store(parser->capture, 
						"readIndentifier", &capture->capt);
	    }
	  else
	    {
	      parser->capture = list_capt_store(parser->capture,"OTHER",
						&capture->capt);
	      parser->cursor = capture->capt.end + 1;
	    }
	  i++;
    	}
    }
  return parser;
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
int parser_begin_capture(struct parser_s *p, const char *tag)
  {
  struct capture_s capt = {p->cursor, 0};
  list_capt_store((p->capture), tag, &capt);
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
    //return strndup(p->input + pcapt->begin, pcapt->end - pcapt->begin);
    return NULL;
}
