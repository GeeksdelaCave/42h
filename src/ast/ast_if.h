#ifndef AST_IF_H
# define AST_IF_H

struct ast_node_if
{
    struct ast_node_compound_list *condition;
    struct ast_node_compound_list *if_body;
    struct ast_node_compound_list *else_body;

};

// Create
struct ast_node_compound_list *create_node_if(struct ast_node_compound_list
                                              *condition,
                                              struct ast_node_compound_list
                                              *if_body,
                                              struct ast_node_compound_list
                                              *else_body);

// Print
void ast_if_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned int *node_id);

// Destruct
void ast_if_destruct(struct ast_node_compound_list *node);


#endif /* AST_IF_H */
