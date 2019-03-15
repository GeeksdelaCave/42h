#ifndef AST_H
# define AST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "error.h"

# define mymalloc(name, size) if (!(name = malloc(size))) exit(ERROR_MEM)

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

//while ast node

struct ast_node_while
{
    struct ast_node_compound_list *condition;
    struct ast_node_compound_list *exec;
};

// for ast node

struct ast_ndoe_for
{
    char *varname;
    char **values;
    struct ast_node_compound_list *exec;
};

enum shell_command_child_type
{
    T_IF,
    T_FOR,
    T_WHILE

};


union shell_command_child
{
    struct ast_node_if child_if;
    struct ast_node_for child_for;
    struct ast_node_while child_while;
};


struct ast_node_compound_list //s_ast_node
{
    enum shell_command_child_type type;
    union shell_command_child child;//body
};

enum {NODE_TYPE_COUNT = 3};

void ast_print_node(struct ast_node_compound_list *ast, FILE *out,
                    unsigned int *node_id);

void ast_destruct(struct ast_node_compound_list *ast);

/*
** function an if
*/

struct ast_node_compound_list *create_node_if(struct ast_node_compound_list
                                              *condition,
                                              struct ast_node_compound_list
                                              *if_body,
                                              struct ast_node_compound_list
                                              *else_body);

void ast_if_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned int *node_id);

void ast_if_destruct(struct ast_node_compound_list *node);

/*
** function an while
*/

struct ast_node_compound_list *create_node_while(struct ast_node_compound_list
                                                 *condition,
                                                 struct ast_node_compound_list
                                                 *exec);

void ast_while_print(struct ast_node_compound_list *node, FILE *out,
                     unsigned int *node_id);

void ast_while_destruct_node(struct ast_node_compound_list *node);

void ast_while_destruct(struct ast_node_compound_list *node);

/*
** functions an for
*/

struct ast_node_compound_list *create_node_for(char *varname, char **values,
                                                 struct ast_node_compound_list
                                               *exec);

void ast_for_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned *node_id);

# endif
