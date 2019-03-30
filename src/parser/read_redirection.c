#include "grammar.h" 

int read_redirection(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p)) &&
      parser_begin_capture(p, "num") && parser_readinteger(p) && parser_end_capture(p, "num")
      && ZeroOrMany(read_spaces(p)) &&
      parser_begin_capture(p, "chevron") && parser_readchar(p, '<') && parser_end_capture(p, "chevron")
      && ZeroOrMany(read_spaces(p)) && read_word(p) &&
      ZeroOrMany(read_spaces(p)))
    {
      char *num = parser_get_capture(p, "num");
      char *chevron = parser_get_capture(p, "chevron");
      char *word = parser_get_capture(p, "word");
      printf("READ_REDIRECTION %s %s  %s\n", num,chevron, word);
      
      // il faut réfléchir à le symbole redirection sinon le reste marche
      /*
      struct s_node_redirection *redirection = malloc(sizeof
      (struct s_node_redirection));
      redirection->number = num;
      redirection->redirection = chevron;
      redirection->word = word;

      union all_grammar *grammar = malloc(sizeof(union all_grammar));
      grammar->redirection = redirection;
      list_node_store(p->nodes, grammar, REDIRECTION);
      */
      return 1;
    }
  parser_get_capture(p, "num");
  parser_get_capture(p, "chevron");
  // déja fait dans word
  //parser_get_capture(p, "word");
  p->cursor = tmp;
  return 0;
}