/**
 ** \file  read_word.c
 */
 #include "grammar.h" 
/**
 ** \brief Check if the text is word
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_word(struct parser_s *p)
{
  int tmp = p->cursor;
  if (ZeroOrMany(read_spaces(p))
      && parser_begin_capture(p, "word") &&
      parser_readidentifier(p) && 
      parser_end_capture(p, "word") &&
      ZeroOrMany(read_spaces(p)))
    {
      return 1;
    }
  p->cursor = tmp;
  return 0;
}
