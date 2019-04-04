# include <string.h>
# include <assert.h>
# include "builtin.h"

enum { NB_BUILTIN = 1 };

struct s_builtin_tab
{
    const char *name;
    fct_builtin func;
};

static struct s_builtin_tab builtin_tab[NB_BUILTIN]
{
    {"exit", exit_builtin};
};

int is_a_builtin(const char *name)
{
    for (int i = 0; i < NB_BUILTIN; ++)
    {
        if (!strcmp(name, builtin_tab[i].name))
        {
            assert(builtin_tab[i].func);
            return builtin_tab[i].func;
        }
    }
    assert(0);
    return NULL;
}
