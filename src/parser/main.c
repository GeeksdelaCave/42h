#include "lexer.h"
#include "lex_match_if.h"
#include "lex_match_id.h"
#include "lex_match_int.h"
#include "token_list.h"

void print_content_listToken(struct lexer *parser)
{
  int cpt = 1;
  struct token_list *p = parser->token_list;
  while(p)
    {
      printf("Token num : %d \n", cpt);
      printf("TAG : %s\n", p->tag);
      for(int i = p->token.begin; i < p->token.end+1; i++)
	     printf("%c", parser->input[i]);
      printf("\n");
      printf("BEGIN %d\n", p->token.begin);
      printf("END %d\n", p->token.end);
      printf("\n");
      cpt++;
      p = p->next;
    }
}

void print_content_Token(struct lexer *parser)
{
  struct token_list *p = parser->token_list;
  printf("TAG : %s\n", p->tag);
  for(int i = p->token.begin; i <= p->token.end; i++)
    printf("%c", parser->input[i]);
  printf("\n");
  printf("BEGIN %d\n", p->token.begin);
  printf("END %d\n", p->token.end);
  printf("\n");
}

int main(int argc, char *argv[])
{
  struct lexer *parser = set_token_list(argv, argc);
  print_content_listToken(parser);
  return 0; 
}
