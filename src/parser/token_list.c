#include "token_list.h"

struct lexer *set_token_list(char *str[], int size)
{
  struct lexer *parser = NULL;
  struct token_list *capture = NULL;
  const char *text = copieInput(str);
  enum token_type tag_condition;
  int i = 1;
  if (size > 1)
    {
      parser = parser_new_from_string(text);
      while (i < size)
	{
	  capture = init_list_capt(parser);
	  capture->token.begin = parser->cursor;
	  capture->token.end = (strlen(str[i]) + parser->cursor) - 1;
	  if (parser_readinteger(parser, capture->token.end))
	    {
	      parser->token_list = list_capt_store(parser->token_list, Number, &capture->token);
	    }
	  else if ((tag_condition = match_if(parser, capture->token.end))!= 0)
	    {
	      parser->token_list = list_capt_store(parser->token_list, 
						tag_condition, &capture->token);
	    }
	  else if(parser_readidentifier(parser, capture->token.end))
	    {
	      parser->token_list = list_capt_store(parser->token_list, 
						Identifiant, &capture->token);
	    }
	  else
	    {
	      parser->token_list = list_capt_store(parser->token_list, Other,
						&capture->token);
	      parser->cursor = capture->token.end + 1;
	    }
	  i++;
    	}
    }
  return parser;
}

struct token_list *list_capt_store(struct token_list *capt, enum token_type type, struct token_s *capture)
{
  struct token_list *pc = (struct token_list*) malloc(sizeof(struct token_list));
  //pc->tag = malloc(strlen(tag));
  //strcpy(pc->tag,tag);
  pc->type = type;
  pc->next = capt;
  pc->token.begin = capture->begin;
  pc->token.end = capture->end;
  return pc;
}

int parser_begin_capture(struct lexer *p, enum token_type type)
{
  struct token_s capt = {p->cursor, 0};
  list_capt_store((p->token_list), type, &capt);
  return 1;
}

int parser_end_capture(struct lexer *p, enum token_type type)
{
  struct token_s *pcapt = list_capt_lookup(p->token_list, type);
  if (!pcapt)
  return 0;
  pcapt->end = p->cursor;
  return 1;
}

char *parser_get_capture(struct lexer *p, enum token_type type)
{
  struct token_s *pcapt = list_capt_lookup(p->token_list, type);
    if (!pcapt)
      return 0;
    //return strndup(p->input + pcapt->begin, pcapt->end - pcapt->begin);
    return NULL;
}

/*
enum token_type peek (struct lexer *lexer)
{ 
  if (lexer->token_list == NULL)
    lexer->token_list = get_tokens();//readline, then split token
  return lexer->token_list->type;
}

struct token_list *pop (struct lexer * lexer)
{
  if (lexer->token_list == NULL)
    lexer->token_list = get_tokens();//readline, then split token
  struct token_list *first_token = lexer->token_list;
  lexer->token_list = lexer->token_list->next;
  return first_token;
}

int grammar_rule_if (struct lexer *lexer)
{
  if (peek(lexer) != TOKEN_IF)
    return FALSE;
  free(pop(lexer));
//parse recursively...
}
*/