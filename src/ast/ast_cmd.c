# include "ast.h"

struct ast_node_compound_list *ast_cmd_create(void)
{
    struct ast_node_compound_list *node;
    mymalloc(node, sizeof(struct ast_node_compound_list));
    node->type = T_CMD;
    node->child.child_cmd.argv = NULL;
    node->child.child_cmd.prefix = NULL;
    return node;
}


void add_cmd_ast_argv(struct ast_node_compound_list *node, char *argv)
{
    if (node->type != T_CMD)
        return;
    size_t size = 0;

    if (node->child.child_cmd.argv)
        while(node->child.child_cmd.argv[size])
            ++size;
    myrealloc(node->child.child_cmd.argv, node->child.child_cmd.argv,
              (++size + 1) * sizeof(char *));
    node->child.child_cmd.argv[size - 1] = argv;
    node->child.child_cmd.argv[size] = NULL;
}


void add_cmd_ast_prefix(struct ast_node_compound_list *node,
                        char *assigment_word)
{
    if (node->type != T_CMD)
        return;
    size_t size = 0;

    if (node->child.child_cmd.prefix)
        while (node->child.child_cmd.prefix[size])
            ++size;
    myrealloc(node->child.child_cmd.prefix, node->child.child_cmd.prefix,
              (++size + 1) * sizeof(char * ));
    node->child.child_cmd.prefix[size - 1] = assigment_word;
    node->child.child_cmd.prefix[size] = NULL;
}

void ast_cmd_print(struct ast_node_compound_list *node, FILE *out,
                   unsigned int *node_id)
{
    if (node->type != T_CMD)
        return;

    fprintf(out, "%u [label = \"Command\\n", *node_id);
    ++*node_id;

    //prefix
    char **prefix = node->child.child_cmd.prefix;
    if (prefix && prefix[0])
    {
        for (int i = 0; prefix && prefix[1]; ++i)
        {
            fprintf(out, "prefix[%d]:", i);
            size_t last = 0, p = 0;
            for(; prefix[i][p]; ++p)
                if (prefix[i][p] == '"')
                    fprintf(out, "%.*s\\", (int)(p - last), prefix[i] + last),
                        last = p;
            fprintf(out, "%*s", (int) (p - last), prefix[i] + last), last = p;
            fprintf(out, "\\n");
        }
    }
    //argv
    char **argv = node->child.child_cmd.argv;
    if (argv && argv[0])
    {
        for (int i = 0; argv && argv[i]; ++i)
        {
            fprintf(out, "argv[%d]:", i);
            size_t last = 0, p = 0;
            for (; argv[i][p]; ++p)
                if (prefix[i][p] == '"')
                    fprintf(out, "%.*s\\", (int)(p - last), argv[i] + last),
                        last = p;
            fprintf(out, "%*s", (int)(p - last), argv[i] + last), last = p;
            fprintf(out, "\\n");
        }
    }
    fprintf(out, "];\n");
}

void ast_cmd_destruct_node(struct ast_node_compound_list *node)
{
    ast_cmd_destruct(node);
}

void ast_cmd_destruct(struct ast_node_compound_list *node)
{
    if (node->type != T_CMD)
        return;
    if (node->child.child_cmd.prefix)
    {
        for (register int i = 0; node->child.child_cmd.prefix[i]; ++i)
            free(node->child.child_cmd.prefix[i]);
        free(node->child.child_cmd.prefix);
    }

    if (node->child.child_cmd.argv)
    {
        for (register int i = 0; node->child.child_cmd.argv[i]; ++i)
            free(node->child.child_cmd.argv[i]);
        free(node->child.child_cmd.argv);
    }

    free(node);

}
