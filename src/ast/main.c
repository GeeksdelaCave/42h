# include "ast.h"

int main()
{
    struct ast_node_compound_list *condition = malloc(100);
    struct ast_node_compound_list *if_body = malloc(100);
    struct ast_node_compound_list *else_body = malloc(100);
    unsigned *res = malloc(10);
    //int i = 0;
    create_node_if(condition, if_body, else_body);
    ast_if_print(condition, stdout, res);
    ast_if_print(if_body, stdout, res);
    ast_if_print(else_body, stdout, res);
/*if (argc > 2)
        while (i < argc)
        {
            ast_if_print(argv[i], stdout, res);
            argv[i]++;
            i++;
            }*/
    ast_if_destruct(condition);
    ast_if_destruct(if_body);
    ast_if_destruct(else_body);
    return 0;

}
