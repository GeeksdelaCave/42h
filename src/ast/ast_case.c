# include "ast.h"

struct ast_node_compound_list *create_node_case(char *word)
{
    struct ast_node_compound_list *node;
    mymalloc(node, sizeof(struct ast_node_compound_list));
    node->type = T_CASE;
    node->child.child_case.word = word;
    node->child.child_case.items = NULL;
    return node;
}

void ast_case_add_item(struct ast_node_compound_list *node,
                       char **pattern, struct ast_node_compound_list *exec)
{
    struct s_case_item *item;
    struct s_case_item **this;

    if (node->type != T_CASE)
        return;
    mymalloc(item, sizeof(struct s_case_item));
    item->pattern = pattern;
    item->exec = exec;
    item->next = NULL;

    for(this = &node->child.child_case.items; *this; this =  &(*this)->next)
        ;
    *this = item;
}

void ast_case_print(struct ast_node_compound_list *node, FILE *out,
                    unsigned *node_id)
{
    unsigned current_node;
    struct s_case_item *item;
    unsigned item_id;
    unsigned item_node;

    if (node->type != T_CASE)
        return;

    fprintf(out,"%u [Label = \"CASE\\nword:%s\"];\n", current_node = *node_id,
            node->child.child_case.word);
    ++*node_id;

    for (item = node->child.child_case.items, item_id = 0; item;
         item = item->next, ++item_id)
    {
        fprintf(out, "%u -> %u\n", current_node, *node_id);
        fprintf(out, "%u [label = \"Item %u\\n]", item_node = *node_id,
                item_id);
        ++*node_id;
        //print pattern
        if (item->pattern)
            for (int i = 0; item->pattern[i]; ++i)
                fprintf(out, "%s\\n", item->pattern[i]);
        fprintf(out, "\"];\n");

        //print exex
        if (item->exec)
        {
            fprintf(out, "%u -> %u\n", item_node, *node_id);
            ast_print_node(item->exec, out, node_id);
        }
    }
}

void ast_case_destruct_node(struct ast_node_compound_list *node)
{
    struct s_case_item *this;
    struct s_case_item *buff;
    if (node->type != T_CASE)
        return;
    free(node->child.child_case.word);
    for (this = node->child.child_case.items; this; this = buff)
    {
        for (register int i = 0; this->pattern[i]; ++i)
            free(this->pattern[i]);
        free(this->pattern);
        buff = this->next;
        free(this);
    }
    free(node);
}

void ast_case_destruct(struct ast_node_compound_list *node)
{
        struct s_case_item *this;
    struct s_case_item *buff;
    if (node->type != T_CASE)
        return;
    free(node->child.child_case.word);
    for (this = node->child.child_case.items; this; this = buff)
    {
        for (register int i = 0; this->pattern[i]; ++i)
            free(this->pattern[i]);
        free(this->pattern);
        ast_destruct(this->exec);
        buff = this->next;
        free(this);
    }
    free(node);
}
