#include "ast.h"
struct s_do_group *init_dogroup()
{
  struct s_do_group *dogroup = malloc(sizeof(struct s_do_group));
  return dogroup;
}
int find_coump(struct parser_s *p, struct s_do_group *dogroup)
{
  struct list_node_s *cmp_node = ast_check_node(p, COUMPOUND);
  if (!cmp_node)
  {
    return 0;
  };
  dogroup->cpd = cmp_node->node->compoundlist;
  return 1;
}
