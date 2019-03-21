#ifndef AST_REDIRECTION_H
# define AST_REDIRECTION_H

// Enumeration different type of redirection
enum red_type
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

// Redirection ast node
struct ast_red
{
    size_t size;
    enum e_red_type *type;
    int *fd;
    char **words;
    struct ast_node_compound_list *mhs;
};

// Create
struct ast_node_compound_list *create_red_ast(void);

// Add
void add_red_ast(struct ast_node_compound_list *node,
                 enum e_red_type type,
                 int fd, char *word);

// Print
void ast_red_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned int *node_id);

// Destruct
void ast_red_destruct_node(struct ast_node_compound_list *node);
void ast_red_destruct(struct ast_node_compound_list *node);

#endif /* AST_REDIRECTION_H */
