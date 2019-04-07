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

//if ast node

struct ast_node_if
{
    struct ast_node_compound_list *condition;
    struct ast_node_compound_list *if_body;
    struct ast_node_compound_list *else_body;

};

//for ast node

struct ast_node_for
{
    char *varname;
    char **values;
    struct ast_node_compound_list *exec;
};

//Case ast node

struct s_case_item
{
    char **pattern;
    struct ast_node_compound_list *exec;
    struct s_case_item *next;
};

struct ast_node_case
{
    char *word;
    struct s_case_item *items;
};

//while ast node

struct ast_node_while
{
    struct ast_node_compound_list *condition;
    struct ast_node_compound_list *exec;
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

//Redirection ast node
struct s_red_node
{
    size_t size;
    enum e_red_type *type;
    int *fd;
    char **words;
    struct ast_node_compound_list *mhs;
};

//type shell command
enum shell_command_child_type
{
    T_IF,
    T_CASE,
    T_FOR,
    T_WHILE,
    T_RED,
    T_CMD,
    T_AND,
    T_OR,
    T_PIPE
};

/*
**Command ast node
*/

struct s_cmd_node
{
    char **argv;
    char **prefix;
};

/*
** struct for ast ant pip ...
*/

struct s_ast_bin
{
    struct ast_node_compound_list *lhs;
    struct ast_node_compound_list *rhs;
};

union shell_command_child
{
    struct ast_node_if child_if;
    struct ast_node_case child_case;
    struct ast_node_for child_for;
    struct ast_node_while child_while;
    struct s_red_node child_red;
    struct s_cmd_node child_cmd;
    struct s_ast_bin child_and;
    struct s_ast_bin child_or;
    struct s_ast_bin child_pipe;
};


struct ast_node_compound_list //s_ast_node
{
    enum shell_command_child_type type;
    union shell_command_child child;//body
};

enum {NODE_TYPE_COUNT = 9};

void ast_print_node(struct ast_node_compound_list *ast, FILE *out,
                    unsigned int *node_id);

void ast_destruct(struct ast_node_compound_list *ast);


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
# endif
