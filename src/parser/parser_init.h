/**
 ** \file PARSER_INIT
 ** \brief Declaration file PARSER_INIT_H
*/
#ifndef PARSER_INIT_H
#define PARSER_INIT_H
/**
 ** \def TRUE 1
 */
#define TRUE 1
/**
 ** \def FALSE 0
 */
#define FALSE 0
/**
 ** \def ZeroOrOne(R)
 */
#define ZeroOrOne(R)   \
  __extension__({      \
      R;	       \
      TRUE;	       \
    })
/**
 ** \def ZeroOrMany(R)
 */
#define ZeroOrMany(R)  \
  __extension__({      \
      while(R)	       \
	;	       \
      TRUE;	       \
    })
/**
 ** \def OneOrMany(R)
 */
#define OneOrMany(R)	      \
  __extension__ ({	      \
      int res = FALSE;	      \
      if(R)		      \
      {			      \
	while(R)	      \
	  ;		      \
	res = TRUE;	      \
      }			      \
      res;		      \
    })
/**
 ** \struct parser_s
 ** \brief struct of the parser
 **  the string input
 **  a int cursor
 **  structure of catch list
 **  structure of node list
 */
struct parser_s
{
  int cursor;
  char *input;
  struct list_capt_s *capture;
  struct list_node_s *nodes;
};
/**
 ** \struct capture_s
 ** \brief the position at
 ** begin and end of cursor
 */
struct capture_s
{
  int begin;
  int end;
};
/**
 ** \struct list_capt_s
 ** \brief description of capture
 ** the tag  name of  capture
 ** struct capture to give the lenght of capture
 ** the next capture
 */
struct list_capt_s
{
  char *tag;
  struct capture_s capt;
  struct list_capt_s *next;
};
/**
 ** \fn struct parser_s *parser_new_from_string(const char *text)
 */
struct parser_s *parser_new_from_string(const char *text);
/**
 ** \fn struct list_capt_s *init_list_capt()
 */
struct list_capt_s *init_list_capt();
/**
 ** \fn void free_list_capt_s(struct list_capt_s *capture);
 */
void free_list_capt_s(struct list_capt_s *capture);
/**
 ** \fn void parser_clean(struct parser_s *p);
 */
void parser_clean(struct parser_s *p);
/**
 ** \fn int read_spaces(struct parser_s *p);
 */
int read_spaces(struct parser_s *p);
#endif
