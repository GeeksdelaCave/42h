#include "ast.h"
struct s_node_until *init_until()
{
    struct s_node_until *node_until = malloc(sizeof(struct s_node_until));
    return node_until;
}
int find_until(struct parser_s *p, struct s_node_until *node_until)
{
    struct list_node_s *cmp_node = ast_check_node(p, COUMPOUND);
    struct list_node_s *dogroup_node = ast_check_node(p, DOGROUP);
    if (!cmp_node || !dogroup_node)
    {
        return 0;
    }
    node_until->condition = cmp_node->node->compoundlist;
    node_until->dogroup = dogroup_node->node->dogroup->cpd;
    return 1;
}