# ifndef AST_CMD_H
# define AST_CMD_H

// Command ast node

struct s_cmd_node
{
    char **argv;
    char **prefix;
};

// create command

struct ast_node_compound_list *ast_cmd_create(void);

void add_cmd_ast_argv(struct ast_node_compound_list *node, char *argv);

void add_cmd_ast_prefix(struct ast_node_compound_list *node,
                        char *assignement_word);
void ast_cmd_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned int *node_id);
void ast_cmd_destruct_node(struct ast_node_compound_list *node);

void ast_cmd_destruct(struct ast_node_compound_list *node);


# endif
