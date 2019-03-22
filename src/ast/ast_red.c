# include "ast.h"

struct  ast_node_compound_list *create_node_red(void)
{
    struct ast_node_compound_list *node;
    mymalloc(node, sizeof(struct ast_node_compound_list));
    node->type = T_RED;
    node->child.child_red.size = 0;
    node->child.child_red.fd = NULL;
    node->child.child_red.words = NULL;
    node->child.child_red.mhs = NULL;
    return node;
}

void add_red_ast(struct ast_node_compound_list *node,
                 enum e_red_type type,
                 int fd, char *word)
{
    if (node->type != T_RED)
        return;
    struct s_red_node *reds = (struct s_red_node *) &node->child.child_red;
    ++reds->size;
    myrealloc(reds->type, reds->type, sizeof(enum e_red_type) *
              reds->size);
    reds->type[reds->size - 1] = type;
    myrealloc(reds->fd, reds->fd, sizeof(int) * reds->size);
    reds->fd[reds->size - 1] = fd;
    myrealloc(reds->words, reds->words, sizeof(char *) * reds->size);
    reds->words[reds->size - 1] = word;
}


void ast_red_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned int *node_id)
{
    unsigned current_node = *node_id;

    if (node->type != T_FOR)
        return;
    struct s_red_node *reds = (struct s_red_node *) &node->child.child_red;
    if (reds->size == 0)
        return;
    fprintf(out, "%u [label = \"Redirection\\n", *node_id);
    ++*node_id;
    for (register size_t i = 0; i < reds->size; ++i)
           fprintf(out, "id = %zu, fd = %d, type = %d, word = %s\\n",
                   i, reds->fd[i], reds->type[i], reds->words[i]);
    fprintf(out, "\"];\n");
    fprintf(out, "%u -> %u\n", current_node, *node_id);
    if(reds->mhs)
        ast_print_node(reds->mhs, out, node_id);
}

    void ast_red_destruct_node(struct ast_node_compound_list *node)
{
    struct s_red_node *reds;

    if (node->type != T_RED)
        return;
    reds = (struct s_red_node *) &node->child.child_red;
    if (reds->size){
        free(reds->type);
        free(reds->fd);
        for (register size_t i = 0; i < reds->size; ++i)
            free(reds->words[i]);
        free(node);
    }
}

void ast_red_destruct(struct ast_node_compound_list *node)
{
    if (node->type != T_RED)
        return;
    ast_destruct(node->child.child_red.mhs);
    ast_red_destruct_node(node);
}
