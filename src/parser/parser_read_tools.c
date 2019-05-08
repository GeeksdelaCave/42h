/**
 ** \file  parser_read_tools.c
 */
#include "grammar.h"
/**
 ** \brief retrieve a char
 **
 ** \param p struct parser
 **
 ** \return the current char
 */
char parser_getchar(struct parser_s *p)
{
  char c = p->input[p->cursor];
  p->cursor++;
  return c;
}
/**
 ** \brief function is true
 **  if the current char == c
 **
 ** \param p struct parser
 ** \param c caracter, we search
 **
 ** \return true or false
 */
int parser_peekchar(struct parser_s *p, char c)
{
  if (p->input[p->cursor] == c)
  {
    return 1;
  }
  return 0;
}
/**
 ** \brief retrieve a caract exclamation
 **
 ** \param p struct parser
 **
 ** \return true or false
 */
int read_excla(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_begin_capture(p, "excla") && parser_readchar(p, '!')
      && parser_end_capture(p, "excla"))
  {
    char *excla = parser_get_capture(p, "excla");
    struct s_symbole *node_sym = malloc(sizeof(struct s_symbole));
    node_sym->symbole = excla;
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->symbole = node_sym;
    list_node_store(p->nodes, grammar, EXCLA);
    return 1;
  }
  parser_get_capture(p,"excla");
  p->cursor = tmp;
  return 0;
}
/**
 ** \brief return true
 **  if it read and
 **
 ** \param p struct parser
 **
 ** \return true or false
 */
int read_and(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_begin_capture(p, "and") && parser_readchar(p, '&')
      && parser_end_capture(p, "and"))
  {
    if (p->input[p->cursor] != '&')
    {
      char *and = parser_get_capture(p, "and");
      struct s_symbole *node_sym = malloc(sizeof(struct s_symbole));
      node_sym->symbole = and;
      union all_grammar *grammar = malloc(sizeof(union all_grammar));
      grammar->symbole = node_sym;
      list_node_store(p->nodes, grammar, S_AND);
      return 1;
    }
  }
  parser_get_capture(p, "and");
  p->cursor = tmp;
  return 0;
}
/**
 ** \brief return true if it read "virgule"
 **
 ** \param p struct parser
 **
 ** \return true or false
 */
int read_virgule(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_begin_capture(p, "virgule") && parser_readchar(p, ';')
      && parser_end_capture(p, "virgule"))
  {
    char *virgule = parser_get_capture(p, "virgule");
    struct s_symbole *node_sym = malloc(sizeof(struct s_symbole));
    node_sym->symbole = virgule;
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->symbole = node_sym;
    list_node_store(p->nodes, grammar, VIRGULE);
    return 1;
  }
  parser_get_capture(p, "virgule");
  p->cursor = tmp;
  return 0;
}
/**
 ** \brief return true if read PIPE
 **
 ** \param p struct parser
 **
 ** \return true or false
 */
int read_pipe(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_begin_capture(p, "pipe") && parser_readchar(p, '|')
      && parser_end_capture(p, "pipe"))
  {
    if(p->input[p->cursor] != '|')
    {
      char *pipe = parser_get_capture(p, "pipe");
      struct s_symbole *node_sym = malloc(sizeof(struct s_symbole));
      node_sym->symbole = pipe;
      union all_grammar *grammar = malloc(sizeof(union all_grammar));
      grammar->symbole = node_sym;
      list_node_store(p->nodes, grammar, PIPE);
      return 1;
    }
  }
  parser_get_capture(p, "pipe");
  p->cursor = tmp;
  return 0;
}

/**
 ** \brief Check EOF
 **
 ** \param p struct parser
 **
 ** \return 0 or 1
 */
int parser_eof(struct parser_s *p)
{
  if(p->input[p->cursor] == '\0' || p->input[p->cursor] == 0)
  {
    return 1;
  }
  return 0;
}

/**
 ** \brief parser for assign
 **
 ** \param p struct parser
 **
 ** \return true or false
 */
int read_Assign(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p)) && parser_begin_capture(p, "id")
      && parser_readidentifier(p)
      && parser_end_capture(p, "id") && parser_readchar(p, '=')
      && parser_begin_capture(p, "num") && parser_readinteger(p)
      && parser_end_capture(p, "num") && ZeroOrMany(read_spaces(p)))
  {
    char *id = parser_get_capture(p, "id");
    char *num = parser_get_capture(p, "num");
    struct s_node_assign *assign = malloc(sizeof(struct s_node_assign));
    assign->id = id;
    assign->num = num;
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->assign = assign;
    list_node_store(p->nodes, grammar, ASSIGN);
    return 1;
  }
  parser_get_capture(p, "id");
  parser_get_capture(p, "num");
  p->cursor = tmp;
  return 0;
}

/**
 ** \brief return true if it read a symbol
 **
 ** \param p structure parser
 ** \param tag the name of capture
 ** \param type the type of capture
 **
 ** \return true or false
 */
int read_symbole(struct parser_s *p, char* tag, char* type)
{
  int tmp = p->cursor;
  if (parser_begin_capture(p, tag) && parser_readtext(p, type)
      && parser_end_capture(p, tag))
  {
    char* andor = parser_get_capture(p, "ANDOR");
    struct s_symbole *node_sym = malloc(sizeof(struct s_symbole));
    node_sym->symbole = andor;
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->symbole = node_sym;
    if(strcmp(andor, "||") == 0)
    {
      list_node_store(p->nodes, grammar, OR);
    }
    else
    {
      list_node_store(p->nodes, grammar, AND);
    }
    return 1;
  }
  p->cursor = tmp;
  parser_get_capture(p, "ANDOR");
  return 0;
}
