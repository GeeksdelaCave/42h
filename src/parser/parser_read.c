/**
 ** \file  parser_read.c
 */
#include "grammar.h" 
/**
 ** \brief return true if the current
 **  char = c and move cursor
 **
 ** \param p struct parser
 ** \param caracter that we want to search
 **
 ** \return true or false
 */
int parser_readchar(struct parser_s *p, char c)
{
  if (p->input[p->cursor] == c)
    {
      p->cursor++;
      return 1;
    }
  return 0;
}
/**
 ** \brief return true if the string
 ** text = the current cursor string
 **
 ** \param p structure parser
 ** \param input string text
 **
 ** \return true or false
 */
int parser_readtext(struct parser_s *p, char *text)
{
  char *cmp = p->input + p->cursor;
  int tmp = p->cursor;
  for(int i = 0; text[i]; i++)
    {
        ////printf("x = %c y = %c \n",cmp[i], text[i] );
    if(cmp[i] != text[i])
      {
        p->cursor = tmp;
        return 0;
      }
      p->cursor++;
    }
    return 1;
}
/**
 ** \brief True if the char
 **at the current cursor is respectevely
 **inside the range of the char and move
 **
 ** \param p struct parser
 ** \param begin of capture
 ** \param end of capture
 **
 ** \return true or false
 */
int parser_readrange(struct parser_s *p, char begin, char end)
{
  int tmp = p->cursor;
    if (p->input[p->cursor] >= begin && p->input[p->cursor] <= end)
      {
    p->cursor += 1;
        return 1;
      }
    p->cursor = tmp;
    return 0;
}
/**
 ** \brief true if the char at the
 **  current cursor is inside the
 **   set of char and move
 **
 ** \param p struct parser
 ** \param set string of symbole
 **
 ** \return true or false
 */
int parser_readinset(struct parser_s *p, char *set)
{
  int tmp = p->cursor;
    for(int i = 0; set[i]; i++)
    {
        if (p->input[p->cursor] == set[i])
        {
      ////printf("SUCCES Check Space de '%c' à '%c' \n", p->input[p->cursor],
      p->cursor++;
      return 1;
    }
    }
    p->cursor = tmp;
    return 0;
}
/**
 ** \brief true if the char at the
 **  current cursor is not inside the
 **   set of char and move
 **
 ** \param p struct parser
 ** \param set string of symbole
 **
 ** \return true or false
 */
int parser_readoutset(struct parser_s *p, char *set)
{
  int tmp = p->cursor;
  for(int i = 0; set[i]; i++)
    {
      if (p->input[p->cursor] == set[i])
    {
        p->cursor = tmp;
       return 0;
       }
    }
  p->cursor = tmp;
  return 1;
}
/**
 ** \brief true if the char at the
 **  current cursor is a char
 **
 ** \param p struct parser
 **
 ** \return true or false
 */
int parser_readalpha(struct parser_s *p)
{
  int tmp = p->cursor;
  if(parser_readrange(p, 'a', 'z') || parser_readrange(p, 'A', 'Z'))
    {
      return 1;
    }
  p->cursor = tmp;
  return 0;
} 
/**
 ** \brief true if the current char
 **  is a number
 **
 ** \param p struct parser
 **
 ** \return true or false
*/
int parser_readnum(struct parser_s *p)
{
  int tmp = p->cursor;
  if(parser_readrange(p, '0', '9'))
    {
        return 1;
    }
  p->cursor = tmp;
  return 0;
}
/**
 ** \brief true if the char is a variable
 **
 ** \param p struct parser
 **
 ** \return true or false
 */
int parser_var(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_readnum(p) || parser_readalpha(p) || parser_readchar(p, '_'))
    {
      return 1;
    }
  p->cursor = tmp;
  return 0;
}
/**
 ** \brief true if the current char is a Id
 **
 ** \param p struct parser
 **
 ** \return true or false
 */
int parser_readidentifier(struct parser_s *p)
{
  int tmp = p->cursor;
  if ((parser_readalpha(p) || parser_readchar(p, '_')) && ZeroOrMany(parser_var(p)))
    {
      return 1;
    }
  p->cursor = tmp;
  return 0;
}
/**
 ** \brief true if the curent char is a Number
 **
 ** \param p struct parser
 **
 ** \return true or false
 */
int parser_readinteger(struct parser_s *p)
{
  int tmp = p->cursor;
  if (OneOrMany(parser_readnum(p)))
    {
      return 1;
    }
    p->cursor = tmp;
    return 0;
}