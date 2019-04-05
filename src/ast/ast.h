#ifndef AST_H
#define AST_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "error.h"
#include "../parser/grammar.h"
#include "ast_simple_command.h"
#include "ast_command.h"
#include "ast_pipeline.h"
#include "ast_compound_list.h"
# define mymalloc(name, size) if (!(name = malloc(size))) exit(ERROR_MEM)
# define myrealloc(ret, name, size) if (!(ret = realloc(name, size)))   \
    exit(ERROR_MEM)							\
      /*-----------------------------------------------------------------------
-------------------------------------------------------------------------
----------------------- VERSION NEED TO DEV -----------------------------
-------------------------------------------------------------------------
-------------------------------------------------------------------------*/

/*
** Enum type for all grammar
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
  RULEFOR,      //10
  RULEIF,       //11
  RULEWHILE,    //12
  RULEUNTIL,    //13
  RULECASE,     //14
  ELSECLAUSE,   //15
  DOGROUP,      //16
  CASECLAUSE,   //17
  CASEITEM,     //18
  PIPE,         //19
  EXCLA,        //20
  AND,          //21
  OR,           //22
  S_AND,        //23
  VIRGULE,       //24
};

union all_grammar
{
    struct s_node_list *list;
    struct s_node_and_or *andor;
    struct s_node_pipeline *pipeline;
    struct s_node_command *command;
    struct s_simple_cmd *simple_c;
    //struct s_node_funcdec_command *funcdec;
    struct s_node_assign *assign;
    struct s_node_redirection *redirection;
    struct s_node_if *node_if;
    struct s_node_for *node_for;
    struct s_node_while *node_while;
    struct s_node_case_item *case_item;
    struct s_node_compound_list *compoundlist;
    struct s_do_group *dogroup;
    struct s_node_until *until;
    struct s_node_word *word;
    struct s_symbole *symbole;
};


struct s_symbole
{
    char *symbole;
};

/*
** node list
*/
struct list_node_s
{
  enum type_grammar type;
  union all_grammar *node;
  struct list_node_s *next;
  struct list_node_s *prev;
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
  //char *and_or;
  //struct s_node_and_or *next;
  int simple_and;
  int virgule;
};

/*
** node pipeline
*/
struct s_node_pipeline
{
  struct s_node_command *commands;
  int child;
};


/*
** node commands
*/
struct s_node_command
{
    int excla;
    enum type_grammar type;
    union all_grammar *struct_type;
    int pipe;
};


/*
** node simple commands
*/
struct s_simple_cmd
{
  enum type_grammar type;
  struct s_node_command *child_node;
  int child;
};

/*
**
*/
/*
struct s_node_funcdec_command
{

}*/


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
  R_DLESSDASH,             /* <<-*/
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
  int child;
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
void eat_list_node(struct parser_s *p, enum type_grammar type);
struct list_node_s *ast_get_node(struct parser_s *p, enum type_grammar type);
void print_node(struct list_node_s *node);
struct list_node_s *ast_check_node(struct parser_s *p, enum type_grammar type);

int check_pipeline(struct parser_s *p);
struct s_node_pipeline *init_pipeline(struct parser_s *p);
int find_command(struct parser_s *p, struct s_node_pipeline *s_pipeline);
void pipeline_store(struct s_node_pipeline *pipeline, struct s_node_command 
    *new_command, int nb_child);
struct s_node_pipeline *init_pipeline(struct parser_s *p);
int check_pipeline(struct parser_s *p);
int ast_check_sym(struct parser_s *p, enum type_grammar type);

struct s_node_compound_list *init_compound(struct parser_s *p);
int check_compound_list(struct parser_s *p);
void compound_list_store(struct s_node_compound_list *cpd, struct s_node_and_or *new_and_or, int nb_child);
int find_and_or(struct parser_s *p, struct s_node_compound_list *s_cpd);
#endif
