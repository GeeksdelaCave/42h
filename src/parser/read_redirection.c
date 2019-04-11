#include "grammar.h" 
int return_chevron(char *chevron)
{
  if (strcmp(chevron, "<") == 0)
  {
    return R_LESS;
  }
  else if (strcmp(chevron, "<&") == 0)
  {
    return R_LESSAND;
  }
  else if (strcmp(chevron, ">") == 0)
  {
    return R_GREAT;
  }
  else if (strcmp(chevron, ">&") == 0)
  {
    return R_GREATAND;
  }
  else if (strcmp(chevron, ">>") == 0)
  {
    return R_DGREAT;
  }
  else if (strcmp(chevron, ">|") == 0)
  {
    return R_CLOBBER;
  }
  else if (strcmp(chevron, "<<") == 0)
  {
    return R_DLESS;
  }
  return R_DLESSDASH;
}
int parser_read_red(struct parser_s *p)
{
  if (parser_readtext(p, "<&"))
  {
    return 1;
  }
  else if (parser_readtext(p, ">&"))
  {
    return 1;
  }
  else if (parser_readtext(p, ">>"))
  {
    return 1;
  }
  else if (parser_readtext(p, ">|"))
  {
    return 1;
  }
  else if (parser_readtext(p, "<<"))
  {
    return 1;
  }
  else if (parser_readtext(p, "<"))
  {
    return 1;
  }
  else if (parser_readtext(p, ">"))
  {
    return 1;
  }
  return 0;
}
int read_redirection(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p)) &&
      parser_begin_capture(p, "num") && parser_readinteger(p) && parser_end_capture(p, "num")
      && ZeroOrMany(read_spaces(p)) &&
      parser_begin_capture(p, "chevron") && parser_read_red(p) && parser_end_capture(p, "chevron")
      && ZeroOrMany(read_spaces(p)) && read_word(p) &&
      ZeroOrMany(read_spaces(p)))
    {
      char *num = parser_get_capture(p, "num");
      char *chevron = parser_get_capture(p, "chevron");
      char *word = parser_get_capture(p, "word");
      //printf("READ_REDIRECTION %s %s  %s\n", num,chevron, word);
      
      // il faut réfléchir à le symbole redirection sinon le reste marche
      
      struct s_node_redirection *redirection = malloc(sizeof
						      (struct s_node_redirection));
      redirection->number = num;
      redirection->redirection = return_chevron(chevron);
      redirection->word = word;
      
      union all_grammar *grammar = malloc(sizeof(union all_grammar));
      grammar->redirection = redirection;
      list_node_store(p->nodes, grammar, REDIRECTION);
      return 1;
    }
  parser_get_capture(p, "num");
  parser_get_capture(p, "chevron");
  // déja fait dans word
  //parser_get_capture(p, "word");
  p->cursor = tmp;
  return 0;
}
