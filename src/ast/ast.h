#ifndef AST_H
# define AST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

#include "ast_case.h"
#include "ast_for.h"
#include "ast_if.h"
#include "ast_redirection.h"
#include "ast_while.h"

# include "error.h"

# define mymalloc(name, size) if (!(name = malloc(size))) exit(ERROR_MEM)
# define myrealloc(ret, name, size) if (!(ret = realloc(name, size)))   \
        exit(ERROR_MEM)                                                 \



//type shell command
enum shell_command_child_type
{
    T_IF,
    T_CASE,
    T_FOR,
    T_WHILE,
    T_RED,
    T_CMD
};

// Command ast node

struct s_cmd_node
{
    char **argv;
    char **prefix;
};

union shell_command_child
{
    struct ast_node_if child_if;
    struct ast_case child_case;
    struct ast_for child_for;
    struct ast_node_while child_while;
    struct ast_red child_red;
    struct s_cmd_node child_cmd;
};


struct ast_node_compound_list //s_ast_node
{
    enum shell_command_child_type type;
    union shell_command_child child;//body
};

enum {NODE_TYPE_COUNT = 6};

void ast_print_node(struct ast_node_compound_list *ast, FILE *out,
                    unsigned int *node_id);

void ast_destruct(struct ast_node_compound_list *ast);



/*
**function an case
*/
struct ast_node_compound_list *create_node_case(char *word);

void ast_case_add_item(struct ast_node_compound_list *node,
                       char **pattern, struct ast_node_compound_list *exec);

void ast_case_print(struct ast_node_compound_list *node, FILE *out,
                    unsigned *node_id);

void ast_case_destruct_node(struct ast_node_compound_list *node);

void ast_case_destruct(struct ast_node_compound_list *node);



// create command

struct ast_node_compound_list *ast_cmd_create(void);

void add_cmd_ast_argv(struct ast_node_compound_list *node, char *argv);

void add_cmd_ast_prefix(struct ast_node_compound_list *node,
                        char *assignement_word);
void ast_cmd_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned int *node_id);
void ast_cmd_destruct_node(struct ast_node_compound_list *node);

void ast_cmd_destruct(struct ast_node_compound_list *node);


# endif /* AST_H */

