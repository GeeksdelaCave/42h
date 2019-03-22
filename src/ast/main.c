# include "ast.h"

int main()
{
    //struct ast_node_compound_list *condition = malloc(100);
    //struct ast_node_compound_list *if_body = malloc(100);
    //struct ast_node_compound_list *else_body = malloc(100);
    //struct ast_node_compound_list *cond = malloc(100);
    unsigned *res = malloc(10);
    char *cmdargv = "echo";
    char *cmdprefix = "if";
    //int i = 0;
    //create_node_if(condition, if_body, else_body);
    //ast_if_print(condition, stdout, res);
    /*create_node_while(condition, if_body);
    ast_while_print(cond, stdout, res);
    ast_if_destruct(condition);*/
    ast_cmd_create();
    add_cmd_ast_argv(condition, cmdargv);
    add_cmd_ast_prefix(condition, cmdprefix);
    return 0;

}
