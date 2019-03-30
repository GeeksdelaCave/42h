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
      printf("EXCLAMATION : %s \n", parser_get_capture(p, "excla"));
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
        printf("%c\n", p->input[p->cursor]);
        if(p->input[p->cursor] != '&')
        {
            char *and = parser_get_capture(p, "and");
            printf("%s\n", and);  
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
        printf("%s\n", virgule);  
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
      //char *pipe = 
      
      if(p->input[p->cursor] != '|')
      {
	parser_get_capture(p, "pipe");
	  //printf("%s\n", pipe);  
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
////printf(" ASSIGN %d %c cursor \n", tmp, p->input[tmp]);
  if (ZeroOrMany(read_spaces(p)) && parser_begin_capture(p, "id") && parser_readidentifier(p) && 
      parser_end_capture(p, "id") && parser_readchar(p, '=')
      && parser_begin_capture(p, "num") && parser_readinteger(p) 
      && parser_end_capture(p, "num") && ZeroOrMany(read_spaces(p)))
    {
      char *id = parser_get_capture(p, "id");
      char *num = parser_get_capture(p, "num");
      printf("ID %s : %s \n", id, num);
      struct s_node_assign *assign = malloc(sizeof(struct s_node_assign));
      assign->id = id;
      assign->num = num;

      union all_grammar *grammar = malloc(sizeof(union all_grammar));
      grammar->assign = assign;
      printf("**ASSIGN -> ID : %s : %s\n", grammar->assign->id, grammar->assign->num);
      list_node_store(p->nodes, grammar, ASSIGN);
      //printf("DANS STORE -> %s : %s\n", s->assign->id, s->assign->num);
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
    char* res = parser_get_capture(p, "ANDOR");
    printf("READsymbole : %s\n", res);
      return 1;
    }
  p->cursor = tmp;
  parser_get_capture(p, "ANDOR");
  //printf("FAIL DANS READsymbole\n");
  return 0;
}
