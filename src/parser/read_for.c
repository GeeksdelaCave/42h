/**
 ** \file  read_for.c
 */
#include "grammar.h" 
/**
 ** \brief return true if read a for
 **  boucle
 **
 ** \param p structure of parser
 **
** \return true of false
*/
int read_for(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p)) && parser_readtext(p, "for")
      && read_for_word(p)
      && ZeroOrOne(read_word_in_for(p))
      && ZeroOrMany(read_spaces(p)) && ZeroOrMany(parser_readchar(p, '\n'))
      && ZeroOrMany(read_spaces(p)) && read_do_group(p))
  {
    //printf("AST read FOR : SUCCES\n");
    return 1;
  }
  //printf("AST read FOR : FAIL\n");
  p->cursor = tmp;
  return 0;
}

int read_word_in_for(struct parser_s *p)
{
    if(read_virgule(p))
    {
        //printf("IL Y A UN VIRGULE===================");
        return 1;
    }
    else if(ZeroOrMany(parser_readchar(p, '\n')) && 
    ZeroOrMany(read_spaces(p)) &&
    parser_readtext(p, "in") && ZeroOrMany(read_spaces(p)) && 
    ZeroOrMany(read_for_word(p)) && ZeroOrMany(read_spaces(p)) && 
    ((parser_readchar(p, ';') && ZeroOrMany(read_spaces(p))) || (parser_readchar(p, '\n') && ZeroOrMany(read_spaces(p)) )))
    {
        //printf("SUCCES ===========================================");
        return 1;
    }
    //printf("FAIL IN WORD IN FOR\n");
    return 0;
}
