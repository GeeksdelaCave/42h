#include "grammar.h"
/**
 ** \brief return true if do_group and make an ast node for
 **  Do_group
 **
 ** \param p structure of parser
 **
 ** \return true of false
 */
int read_do_group(struct parser_s *p)
{
  int tmp = p->cursor;
  if (parser_readtext(p, "do") && read_compound_list(p)
      && parser_readtext(p, "done"))
  {
    struct s_do_group *dogroup = init_dogroup();
    find_coump(p, dogroup);
    union all_grammar *grammar = malloc(sizeof(union all_grammar));
    grammar->dogroup = dogroup;
    list_node_store(p->nodes, grammar, DOGROUP);
    return 1;
  }
  p->cursor = tmp;
  return 0;
}
