#ifndef AST_H
# define AST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "error.h"

# define mymalloc(name, size) if (!(name = malloc(size))) exit(ERROR_MEM)
# define myrealloc(ret, name, size) if (!(ret = realloc(name, size)))   \
        exit(ERROR_MEM)                                                 \

//void ast_print_node(struct ast_node_compound_list *ast, FILE *out,
                  //  unsigned int *node_id);

//void ast_destruct(struct ast_node_compound_list *ast);


/*
 * ================ IF RELATED FUNCTIONS ================
 *

struct ast_node_compound_list *create_node_if(struct ast_node_compound_list
                                              *condition,
                                              struct ast_node_compound_list
                                              *if_body,
                                              struct ast_node_compound_list
                                              *else_body);
void ast_if_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned int *node_id);
void ast_if_destruct(struct ast_node_compound_list *node);


*/
/*
 * ================ CASE RELATED FUNCTIONS ================
 *
struct ast_node_compound_list *create_node_case(char *word);
void ast_case_add_item(struct ast_node_compound_list *node,
                       char **pattern, struct ast_node_compound_list *exec);
void ast_case_print(struct ast_node_compound_list *node, FILE *out,
                    unsigned *node_id);
void ast_case_destruct_node(struct ast_node_compound_list *node);
void ast_case_destruct(struct ast_node_compound_list *node);

*/
/*
 * ================ WHILE RELATED FUNCTIONS ================

struct ast_node_compound_list *create_node_while(struct ast_node_compound_list
                                                 *condition,
                                                 struct ast_node_compound_list
                                                 *exec);
void ast_while_print(struct ast_node_compound_list *node, FILE *out,
                     unsigned int *node_id);
void ast_while_destruct_node(struct ast_node_compound_list *node);
void ast_while_destruct(struct ast_node_compound_list *node);

*/

/*
 * ================ FOR RELATED FUNCTIONS ================

struct ast_node_compound_list *create_node_for(char *varname, char **values,
                                               struct ast_node_compound_list
                                               *exec);
void ast_for_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned *node_id);
void ast_for_destruct_node(struct ast_node_compound_list *node);
void ast_for_destruct(struct ast_node_compound_list *node);


*/
/*
 * ================ FOR RELATED FUNCTIONS ================
 *
struct ast_node_compound_list *create_node_red(void);
void add_red_ast(struct ast_node_compound_list *node,
                 enum e_red_type type,
                 int fd, char *word);
void ast_red_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned int *node_id);
void ast_red_destruct_node(struct ast_node_compound_list *node);
void ast_red_destruct(struct ast_node_compound_list *node);


*/
/*
 * ================ CMD RELATED FUNCTIONS ================

struct ast_node_compound_list *create_node_cmd(void);
void add_cmd_ast_argv(struct ast_node_compound_list *node, char *argv);
void add_cmd_ast_prefix(struct ast_node_compound_list *node,
                        char *assignement_word);
void ast_cmd_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned int *node_id);
void ast_cmd_destruct_node(struct ast_node_compound_list *node);
void ast_cmd_destruct(struct ast_node_compound_list *node);


*/
/*
 * ================ AND RELATED FUNCTIONS ================
 *
struct ast_node_compound_list *create_node_and(struct ast_node_compound_list
                                               *lhs,
                                               struct ast_node_compound_list
                                               *rhs);
void ast_and_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned int *node_id);
void ast_and_destruct_node(struct ast_node_compound_list *node);
void ast_and_destruct(struct ast_node_compound_list *node);


*/
/*
 * ================ OR RELATED FUNCTIONS ================
 *
struct ast_node_compound_list *create_node_or(struct ast_node_compound_list
                                               *lhs,
                                               struct ast_node_compound_list
                                               *rhs);
void ast_or_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned int *node_id);
void ast_or_destruct_node(struct ast_node_compound_list *node);
void ast_or_destruct(struct ast_node_compound_list *node);

*/
//*
 //* ================ OR RELATED FUNCTIONS ================
 /*
struct ast_node_compound_list *create_node_pipe(struct ast_node_compound_list
                                               *lhs,
                                               struct ast_node_compound_list
                                               *rhs);
void ast_pipe_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned int *node_id);
void ast_pipe_destruct_node(struct ast_node_compound_list *node);
void ast_pipe_destruct(struct ast_node_compound_list *node);
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
  int child;
};
/*
** node andor
*/
struct s_node_and_or
{
    struct s_node_pipeline *pipelines;
    int simple_and;
    int virgule;
    int type;
    int child;
};

/*
** node pipeline
*/
struct s_node_pipeline
{
    int b_and;
    int b_or;
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
** node shell commands
*/

struct s_node_shell_command
{
    enum type_grammar type;
    union all_grammar *struct_type;
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
  struct s_node_else *else_body;
};

//else ast node
struct s_node_else
{
  struct s_node_compound_list *else_body;
  struct s_node_compound_list *elif_body;
  struct s_node_compound_list *then_body;
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
    struct s_node_compound_list *cpd;
};

# endif
