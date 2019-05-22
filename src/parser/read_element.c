/**
 ** \file  read_element.c
 */
#include "grammar.h"
/**
 ** \brief return true if the word doesn't match with shell_word (for, if ...)
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int check_element(struct parser_s *p)
{
  char* word = parser_get_capture(p, "word");
  if (!strcmp("for", word) || !strcmp("if", word) || !strcmp("while", word)
      || !strcmp("do", word) || !strcmp("done", word) || !strcmp("fi", word)
      || !strcmp("then", word) || !strcmp("else", word) ||
      !strcmp("elif", word) || !strcmp("until", word))
  {
    return 0;
  }
  struct s_node_word *node_word = malloc(sizeof(struct s_node_word));
  node_word->word = word;
  union all_grammar *grammar = malloc(sizeof(union all_grammar));
  grammar->word = node_word;
  list_node_store(p->nodes, grammar, WORD1);
  return 1;
}
/**
 ** \brief return true if element
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_element(struct parser_s *p)
{
  int tmp = p->cursor;
  if ( read_word(p) || read_redirection(p))
  {
    int word = check_element(p);
    if(word == 1)
    {
      return 1;
    }
  }
  parser_get_capture(p, "word");
  p->cursor = tmp;
  return 0;
}
/**
 ** \brief return true if word
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_for_word(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p)) && read_word(p) && ZeroOrMany(read_spaces(p)))
  {
    int word = check_element(p);
    if(word == 1)
    {
      return 1;
    }
  }
  p->cursor = tmp;
  return 0;
}
