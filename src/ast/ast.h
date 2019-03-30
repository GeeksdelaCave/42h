#ifndef AST_H
# define AST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "error.h"
#include "../parser/grammar.h"
# define mymalloc(name, size) if (!(name = malloc(size))) exit(ERROR_MEM)
# define myrealloc(ret, name, size) if (!(ret = realloc(name, size)))   \
        exit(ERROR_MEM)                                                 \
/*-----------------------------------------------------------------------
-------------------------------------------------------------------------
----------------------- VERSION NEED TO DEV -----------------------------
-------------------------------------------------------------------------
-------------------------------------------------------------------------
*/

/*
** node input
*/
struct s_node_input
{
   struct s_node_list *list;
};

/*
** Enum type for all grammar
*/
enum type_grammar
{
  LIST,
  ANDOR,
  PIPELINE,
  COMMAND,
  ASSIGN,
  REDIRECTION,
  WORD1,
  COUMPOUND,
  RULEFOR,
  RULEIF,
  RULEWHILE,
  RULEUNTIL,
  RULECASE,
  ELSECLAUSE,
  DOGROUP,
  CASECLAUSE,
  CASEITEM
};

union all_grammar
{
    struct s_node_list *list;
    struct s_node_and_or *andor;
    struct s_node_pipeline *pipeline;
    struct s_node_command *command;
    //struct s_node_simple_command *simple_c;
    //struct s_node_shell_command *shell_c;
    //struct s_node_funcdec_command *funcdec_c;
    //struct s_node_prefix *prefix;
    struct s_node_assign *assign;
    struct s_node_redirection *redirection;
    //struct s_node_element *element;
    struct s_node_if *node_if;
    struct s_node_for *node_for;
    struct s_node_while *node_while;
    struct s_node_case_item *case_item;
    struct s_node_compound_list *compoundlist;
    struct s_do_group *dogroup;
    struct s_node_until *until;
};

/*
** node list
*/
struct list_node_s
{
  enum type_grammar type;
  union all_grammar *node;
  struct list_node_s *next;
};
struct s_node_list
{
  struct s_node_and_or *and_or;
  char *mode_exec;
  struct s_node_list *next;
};

/*
** node andor
*/
struct s_node_and_or
{
  struct s_node_pipeline *pipeline;
  char *and_or;
  struct s_node_and_or *next;
};

/*
** node pipeline
*/
struct s_node_pipeline
{
  int exlamation;
  struct s_node_command *commands;
  char *pipes;
  struct s_node_pipeline *next;
};


/*
** node commands
*/
struct s_node_command
{
  enum type_grammar type;
  union all_grammar struct_type;
  struct s_node_command *next;
};

/*
** Assign Struct
*/
struct s_node_assign
{
  char *id;
  char *num;
};

/*
** WORD
*/

struct s_node_word
{
    char *word;
};

// Enumeration different type of redirection
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

/*
** Redirection
*/
struct s_node_redirection
{
  char *number;
  enum e_red_type redirection;
  char *word;
};

//if ast node
struct s_node_if
{
  struct s_node_compound_list *condition;
  struct s_node_compound_list *if_body;
  struct s_node_compound_list *else_body;
};

//for ast node
struct s_node_for
{
  char *varname;
  char **values;
  struct s_node_compound_list *dogroup;
};

//while ast node

struct s_node_while
{
  struct s_node_compound_list *condition;
  struct s_node_compound_list *dogroup;
};

/*
** until ast node
*/

struct s_node_until
{
  struct s_node_compound_list *condition;
  struct s_node_compound_list *dogroup;
};

//Case ast node

struct s_node_case_item
{
    char **pattern;
  struct s_node_compound_list *exec;
  struct s_node_case_item *next;
};

//Case ast node

struct s_node_case
{
  char *word;
  struct s_case_item *items;
};

struct s_node_compound_list
{
    struct s_node_and_or *and_or;
    char *mode_exec;
    struct s_node_compound_list *next;
};


struct s_do_group
{
    struct ast_node_compound_list *cpd;
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
struct list_node_s *init_list_node();
void free_list_node(struct list_node_s *lnodes);
void list_node_store(struct list_node_s *list_node, union all_grammar *s_node, 
enum type_grammar type);
struct list_node_s *list_node_lookup(struct list_node_s *list_node, enum 
type_grammar type);
void eat_list_node(struct parser_s *p);
struct list_node_s *ast_get_node(struct parser_s *p, enum type_grammar type);
void print_node(struct list_node_s *node);
#endif
