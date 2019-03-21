#ifndef AST_FOR_H
# define AST_FOR_H

struct ast_for
{
    char *varname;
    char **values;
    struct ast_node_compound_list *exec;
};

// Create
struct ast_node_compound_list *create_node_for(char *varname, char **values,
                                                 struct ast_node_compound_list
                                               *exec);

// Print
void ast_for_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned *node_id);

// Destruct
void ast_for_destruct_node(struct ast_node_compound_list *node);
void ast_for_destruct(struct ast_node_compound_list *node);


#endif /* AST_FOR_H */
