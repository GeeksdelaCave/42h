#ifndef AST_CASE_H
# define AST_CASE_H

struct ast_case_item
{
    char **pattern;
    struct ast_node_compound_list *exec;
    struct ast_case_item *next;
};

struct ast_case
{
    char *word;
    struct ast_case_item *items;
};

#endif /* AST_CASE_H */
