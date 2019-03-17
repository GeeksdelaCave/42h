# include "ast.h"

struct ast_node_compound_list *create_node_case(char *word)
{
    struct ast_node_compound_list *node;
    mymalloc(node, sizeof(struct ast_node_compound_list));
    node->type = T_CASE;
}

void ast_case_add_item(struct ast_node_compound_list *node,
                       char **pattern, struct ast_node_compound_list *exec);

void ast_case_print(struct ast_node_compound_list *node, FILE *out,
                    unsigned *node_id);

void ast_case_destruct_node(struct ast_node_compound_list *node);

void ast_case_destruct(struct ast_node_compound_list *node);
