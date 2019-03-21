#ifndef AST_CASE_H
# define AST_CASE_H

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

#endif /* AST_CASE_H */
