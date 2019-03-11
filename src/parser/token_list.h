#ifndef TOKEN_LIST
#define TOKEN_LIST
#include "lexer.h"
#include "lex_match_if.h"
#include "lex_match_id.h"
#include "lex_match_int.h"
#include "token_list.h"
struct token_list *list_capt_store(struct token_list *capt, const char *tag, 
				    struct token_s *capture);
int parser_begin_capture(struct lexer *p, const char *tag);
int parser_end_capture(struct lexer *p, const char *tag);
struct lexer *set_token_list(char *str[], int size);
char *parser_get_capture(struct lexer *p, const char *tag);
#endif
