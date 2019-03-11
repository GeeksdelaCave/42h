#include "parser.h"
#include "lex_match_if.h"
#include "lex_match_id.h"
#include "lex_match_int.h"
#include "token_list.h"

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

int main(int argc, char *argv[])
{
  struct parser_s *parser = set_token_list(argv, argc);
  print_content_listToken(parser);
  return 0; 
}
