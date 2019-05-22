/**
 ** \file  read_option.c
 */
#include "grammar.h"
#include "../dot/generate_dot_file_ast.h"
#include <string.h>
/**
 ** \brief return true if option's grammar is check
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int strlenarray(char **string, int number)
{
  int len = 0;
  for (int i = 1; i < number; i++)
  {
    len += strlen(string[i]);
  }
  return (len + number);
}
char *my_strcat(char *dest, char *strings[], int number)
{
  dest[0] = '\0';
  for (int i = 1; i < number; i++)
  {
    strcat(dest, strings[i]);
    if (i < number - 1 )
    {
      strcat(dest, " ");
    }
  }
  dest[strlenarray(strings, number)] = '\0';
  return dest;
}
int read_option(int argc, char **argv)
{
  char *text = my_strcat(malloc(sizeof(char) * (strlenarray(argv, argc))),
			 argv, argc);
  struct parser_s *p= parser_new_from_string(text);
  p->cursor = 0;
  if (parser_readtext(p, "-c") && OneOrMany(read_spaces(p)) &&
      parser_readtext(p, "\"") && read_list(p) && parser_readtext(p, "\""))
  {
    fprintf(stdout, "Version 0.3\n");
  }
  p->cursor = 0;
  if (parser_readtext(p, "--version") &&
      parser_eof(p))
  {
    fprintf(stdout, "Version 0.3\n");
  }
  p->cursor = 0;
  if (parser_readtext(p, "--ast-print") && OneOrMany(read_spaces(p))
      && parser_readtext(p, "\"") && read_list(p)
      && parser_readtext(p, "\""))
  {
    my_print_ast(p);
  }
  return 0;
}
