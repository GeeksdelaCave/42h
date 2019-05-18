/**
 ** \file AST
 ** \brief Declaration file AST_H
 */
#ifndef AST_H
#define AST_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "error.h"
#include "../parser/grammar.h"
#include "ast_simple_command.h"
#include "ast_command.h"
#include "ast_pipeline.h"
#include "ast_andor.h"
#include "ast_compound_list.h"
#include "ast_dogroup.h"
#include "ast_while.h"
#include "ast_until.h"
#include "ast_if.h"
#include "ast_else.h"
#include "ast_list.h"
/**
 ** \def mymalloc(name, size) if (!(name = malloc(size))) exit(ERROR_MEM)
 */ 
# define mymalloc(name, size) if (!(name = malloc(size))) exit(ERROR_MEM)
/**
 ** \def myrealloc(ret, name, size) if (!(ret = realloc(name, size))) 
 */  
# define myrealloc(ret, name, size) if (!(ret = realloc(name, size)))   \
    exit(ERROR_MEM)							\
      /*-----------------------------------------------------------------------
-------------------------------------------------------------------------
----------------------- VERSION NEED TO DEV -----------------------------
-------------------------------------------------------------------------
-------------------------------------------------------------------------*/
/**
 ** \enum type_grammar
 ** \brief list of enumeration of type grammar
 */
enum type_grammar
{
  LIST,         //0
  ANDOR,        //1
  PIPELINE,     //2
  COMMAND,      //3
  SIMPLECOMMAND,//4
  FUNDEC,       //5
  ASSIGN,       //6
  REDIRECTION,  //7
  WORD1,        //8
  COUMPOUND,    //9
  FOR,      //10
  IF,       //11
  WHILE,    //12
  UNTIL,    //13
  CASE,     //14
  ELSECLAUSE,   //15
  DOGROUP,      //16
  CASECLAUSE,   //17
  CASEITEM,     //18
  PIPE,         //19
  EXCLA,        //20
  AND,          //21
  OR,           //22
  S_AND,        //23
  VIRGULE       //24
};
/**
 ** \enum all_grammar
 ** \brief list of all grammar with struct node
 */
union all_grammar
{
    struct s_node_list *list;
    struct s_node_and_or *andor;
    struct s_node_pipeline *pipeline;
    struct s_node_command *command;
    struct s_simple_cmd *simple_c;
    struct s_node_assign *assign;
    struct s_node_redirection *redirection;
    struct s_node_if *node_if;
	  struct s_node_else *node_else;
    struct s_node_for *node_for;
    struct s_node_while *node_while;
    struct s_node_case_item *case_item;
    struct s_node_compound_list *compoundlist;
    struct s_do_group *dogroup;
    struct s_node_until *node_until;
    struct s_node_word *word;
    struct s_symbole *symbole;
};
/**
 ** \struct s_symbole
 ** \brief declaration of a symbole 
 **  char *symbole
 */
struct s_symbole
{
    char *symbole;
};
/**
 ** \struct list_node_s
 ** \brief declaration a list of node 
 **  enum type_grammar type
 **  union all_grammar *node
 **  struct list_node_s *next
 **  struct list_node_s *prev
 */
struct list_node_s
{
  enum type_grammar type;
  union all_grammar *node;
  struct list_node_s *next;
  struct list_node_s *prev;
};
/**
 ** \struct s_node_list
 ** \brief declaration a node list 
 **  struct s_node_and_or *and_or
 **  int child
 */
struct s_node_list
{
  struct s_node_and_or *and_or;
  int child;
};
/**
 ** \struct s_node_and_or
 ** \brief declaration  s_node_and_or
 **  struct s_node_pipeline *pipelines
 **  int simple_and
 **  int virgule
 **  int child
 */
struct s_node_and_or
{
    struct s_node_pipeline *pipelines;
    int simple_and;
    int virgule;
    int type;
    int child;  
};
/**
 ** \struct node pipeline
 ** \brief declaration  node pipeline
 **  int b_and
 **  int b_or
 **  struct s_node_command *commands
 **  int child
 */
struct s_node_pipeline
{
    int b_and;
    int b_or;
    struct s_node_command *commands;
    int child;
};
/**
 ** \struct s_node_command
 ** \brief declaration s_node_command
 **  int excla
 **  enum type_grammar type
 **  union all_grammar *struct_type
 **  int pipe
 */
struct s_node_command
{
    int excla;
    enum type_grammar type;
    union all_grammar *struct_type;
    int pipe;
};
/**
 ** \struct s_simple_cmd
 ** \brief declaration s_simple_cmd
 **  enum type_grammar type
 **  struct s_node_command *child_node
 **  int child
 */
struct s_simple_cmd
{
  enum type_grammar type;
  struct s_node_command *child_node;
  int child;
};
/**
 ** \struct s_node_shell_command
 ** \brief declaration s_node_shell_command
 **  enum type_grammar type
 **   union all_grammar *struct_type
 */
struct s_node_shell_command
{
    enum type_grammar type;
    union all_grammar *struct_type;
};
/**
 ** \struct s_node_assign
 ** \brief declaration s_node_assign
 **  char *id
 **  char *num
 */
struct s_node_assign
{
  char *id;
  char *num;
};
/**
 ** \struct s_node_word
 ** \brief declaration s_node_word
 **  char *word
 */
struct s_node_word
{
    char *word;
};
/**
 ** \enum e_red_type
 ** \brief enumeration of list of type of redirection
 */
enum e_red_type
{
  R_LESS,                 /* <  */
  R_LESSAND,              /* <& */
  R_GREAT,                /* >  */
  R_GREATAND,             /* >& */
  R_DGREAT,               /* >> */
  R_LESSGREAT,            /* <> */
  R_CLOBBER,              /* >| */
  R_DLESS,                /* << */
  R_DLESSDASH             /* <<-*/
};
/**
 ** \struct s_node_redirection
 ** \brief declaration node redirection
 **  char *number
 **  enum e_red_type redirection
 **  char *word
 */
struct s_node_redirection
{
  char *number;
  enum e_red_type redirection;
  char *word;
};
/**
 ** \struct s_node_if
 ** \brief declaration if ast node
 **  struct s_node_compound_list *condition
 **  struct s_node_compound_list *if_body
 **  struct s_node_else *else_body
 */
struct s_node_if
{
  struct s_node_compound_list *condition;
  struct s_node_compound_list *if_body;
  struct s_node_else *else_body;
};
/**
 ** \struct s_node_else
 ** \brief declaration else ast node
 **  struct s_node_compound_list *else_body
 **  struct s_node_compound_list *elif_body
 **  struct s_node_compound_list *then_body
 */
struct s_node_else
{
  struct s_node_compound_list *else_body;
  struct s_node_compound_list *elif_body;
  struct s_node_compound_list *then_body;
};
/**
 ** \struct s_node_for
 ** \brief declaration for ast node
 **  char *varname
 **  char **values
 **  struct s_node_compound_list *dogroup
 */
struct s_node_for
{
  char *varname;
  char **values;
  struct s_node_compound_list *dogroup;
};
/**
 ** \struct s_node_while
 ** \brief declaration while ast node
 **  struct s_node_compound_list *condition
 **  struct s_node_compound_list *dogroup
 */
struct s_node_while
{
  struct s_node_compound_list *condition;
  struct s_node_compound_list *dogroup;
};
/**
 ** \struct s_node_until
 ** \brief declaration until ast node
 **  struct s_node_compound_list *condition
 **  struct s_node_compound_list *dogroup
 */
struct s_node_until
{
  struct s_node_compound_list *condition;
  struct s_node_compound_list *dogroup;
};
/**
 ** \struct s_node_case_item
 ** \brief declaration Case ast node item
 **  char **pattern
 **  struct s_node_compound_list *exec
 **  struct s_node_case_item *next
 */
struct s_node_case_item
{
  char **pattern;
  struct s_node_compound_list *exec;
  struct s_node_case_item *next;
};
/**
 ** \struct s_node_case
 ** \brief declaration Case ast node
 **  char *word
 **   struct s_case_item *items
 */
struct s_node_case
{
  char *word;
  struct s_case_item *items;
};
/**
 ** \struct s_node_compound_list
 ** \brief declaration compound_list ast node
 **  struct s_node_and_or *and_or
 **  int child
 */
struct s_node_compound_list
{
    struct s_node_and_or *and_or;
    int child;
};
/**
 ** \struct s_do_group
 ** \brief declaration do group ast node
 **  struct s_node_compound_list *cpd
 */
struct s_do_group
{
    struct s_node_compound_list *cpd;
};

/*
**------------------------------------------------------------------
**------------------------------------------------------------------
**                     FUNCTION CREATE NODES
**------------------------------------------------------------------
**------------------------------------------------------------------
*/

/*
**
** init and free list_node
**
*/
/**
 ** \fn struct list_node_s *init_list_node()
 */
struct list_node_s *init_list_node();
/**
 ** \fn void free_list_node(struct list_node_s *lnodes)
 */
void free_list_node(struct list_node_s *lnodes);
/**
 ** \fn void list_node_store(struct list_node_s *list_node, union all_grammar *s_node, 
 **   enum type_grammar type)
 */
void list_node_store(struct list_node_s *list_node, union all_grammar *s_node, 
enum type_grammar type);
/**
 ** \fn struct list_node_s *list_node_lookup(struct list_node_s *list_node,
 **  enum type_grammar type)
 */
struct list_node_s *list_node_lookup(struct list_node_s *list_node,
enum type_grammar type);
/**
 ** \fn struct list_node_s *ast_get_node(struct parser_s *p, enum type_grammar type);
 **   void print_node(struct list_node_s *node)
 */
struct list_node_s *ast_get_node(struct parser_s *p, enum type_grammar type);
void print_node(struct list_node_s *node);
/**
 ** \fn struct list_node_s *ast_check_node(struct parser_s *p, enum type_grammar type)
 */
struct list_node_s *ast_check_node(struct parser_s *p, enum type_grammar type);
/**
 ** \fn int ast_check_sym(struct parser_s *p, enum type_grammar type)
 */
int ast_check_sym(struct parser_s *p, enum type_grammar type);
/**
 ** \fn enum type_grammar list_type_lookup(struct list_node_s *list_node,
 **   enum type_grammar type)
 */
enum type_grammar list_type_lookup(struct list_node_s *list_node,
enum type_grammar type);
/**
 ** \fn struct list_node_s *ast_check_last(struct parser_s *p, enum type_grammar type)
 */
struct list_node_s *ast_check_last(struct parser_s *p, enum type_grammar type);
#endif