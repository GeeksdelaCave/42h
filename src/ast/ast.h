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
** node list
*/

struct s_node_list
{
    struct s_node_and_or **and_or;
    char **mode_exec;
};

/*
** node andor
*/
struct s_node_and_or
{
    struct s_node_pipeline **pipeline;
    char **and_or;
};

/*
** node pipeline
*/

struct s_node_pipeline
{
    int exlamation;
    struct s_node_command **commands;
    char **pipes;
};

/*
** command type
*/
enum command_type
{
    SIMPLE_COMMAND,
    SHELL_COMMAND,
    FUNCDEC,
};

/*
** struct command
*/
union struct_command
{
    struct s_node_simple_command *simple_c;
    struct s_node_shell_command *shell_c;
    struct s_node_funcdec_command *funcdec_c;
};

/*
** node commands
*/
struct s_node_command
{
    enum command_type type;
    union struct_command struct_type; 
    struct s_node_redirection **redirection;
};

/*
**Simple command ast node
*/
struct s_node_simple_command
{
    struct s_node_prefix **prefix;
    struct s_node_element **element;
};

/*
** type shell command
*/
enum shell_command_child_type
{
    T_CPD,
    T_FOR,
    T_WHILE,
    T_UNTIL,
    T_CASE,
    T_IF
};

/*
** type shell command
*/
union shell_command_child
{
    struct s_node_cpd *child_cpd;
    struct s_node_for *child_for;
    struct s_node_while *child_while;
    struct s_node_until *child_until;
    struct s_node_case *child_case;
    struct s_node_if *child_if;
};

/*
** Shell command
*/
struct s_node_shell_command
{
    enum shell_command_child_type type_command;
    union shell_command_child struct_shell_commands;
};
struct s_node_funcdec
{
    struct s_node_word *word;
    struct s_node_shell_command *shell_command;
};

/*
** Element
*/
struct s_node_element
{
    char *word;
    struct s_node_redirection *redirection;
};

/*
** Prefix
*/
struct s_node_prefix
{
    char *assign_word;
    struct s_node_redirection *redirection;
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
    int ionumber;
    enum e_red_type redirection;
    char* word;
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
    struct s_node_compound_list *exec;
};

//while ast node

struct s_node_while
{
    struct s_node_compound_list *condition;
    struct s_node_compound_list *exec;
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
    struct s_node_and_or **and_or;
    char **mode_exec;
};


struct s_do_group
{
    struct ast_node_compound_list *cpd;
};

/*
**list nodes
*/
struct list_node_s
{
    int nb_child;
    enum shell_command_child_type type;
    char* data;
    struct list_node_s *next;
};

/*-----------------------------------------------------------------------
-------------------------------------------------------------------------
----------------------- VERSION BEFORE ----------------------------------
-------------------------------------------------------------------------
-------------------------------------------------------------------------
*/

//Redirection ast node
struct s_red_node
{
    size_t size;
    enum e_red_type *type;
    int *fd;
    char **words;
    struct ast_node_compound_list *mhs;
};

struct ast_node_compound_list //s_node_node
{
    enum shell_command_child_type type;
    union shell_command_child child;//body
};

/*
** struct for ast pipe ...
*/
struct s_node_bin
{
    struct ast_node_compound_list *lhs;
    struct ast_node_compound_list *rhs;
};

/*
**------------------------------------------------------------------
**------------------------------------------------------------------
**                     FUNCTION CREATE NODES
**------------------------------------------------------------------
**------------------------------------------------------------------
*/

#endif

