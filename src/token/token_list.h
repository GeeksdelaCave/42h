#ifndef TOKEN_LIST
#define TOKEN_LIST
#include "parser.h"
#include "lex_match_if.h"
#include "lex_match_id.h"
#include "lex_match_int.h"
#include "lex_match_symbol.h"
#include "lex_match_loop.h"
struct list_capt_s *list_capt_store(struct list_capt_s *capt, const char *tag, 
				    struct capture_s *capture);
int parser_begin_capture(struct parser_s *p, const char *tag);
int parser_end_capture(struct parser_s *p, const char *tag);
struct parser_s *set_token_list(char *str[], int size);
char *parser_get_capture(struct parser_s *p, const char *tag);
#endif
