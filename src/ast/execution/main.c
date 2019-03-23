# include "exec.h"


int main(void)
{
    struct ast_node_compound_list *res = malloc(sizeof(struct
                                                       ast_node_compound_list *)
                                                * 20);
    struct ast_node_if *node_if = malloc(sizeof(struct ast_node_if) * 20);
    res->type = 1;
    exec_if_node(node_if);
    exec_node(res);
    printf("ok\n");
    return 0;
}
