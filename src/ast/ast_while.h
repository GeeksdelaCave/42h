#ifndef AST_WHILE_H
# define AST_WHILE_H

struct ast_node_while
{
    struct ast_node_compound_list *condition;
    struct ast_node_compound_list *exec;
};

// Create
struct ast_node_compound_list *create_node_while(struct ast_node_compound_list
                                                 *condition,
                                                 struct ast_node_compound_list
                                                 *exec);

// Print
void ast_while_print(struct ast_node_compound_list *node, FILE *out,
                     unsigned int *node_id);

// Destruct
void ast_while_destruct_node(struct ast_node_compound_list *node);
void ast_while_destruct(struct ast_node_compound_list *node);


#endif /* AST_WHILE_H */
