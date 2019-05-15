# include <string.h>
# include <assert.h>
# include "builtin.h"
/*
**@author BA Souleymane
**
**builtin the function c
*/

enum { NB_BUILTIN = 3 };

struct s_builtin_tab
{
    const char *name;
    func_builtin func;
};

static struct s_builtin_tab s_builtin_tab[NB_BUILTIN] =
{
    {"exit", builtin_exit},
    {"while", builtin_while}
    //{"cd", builtin_cd}

};

func_builtin is_a_builtin(const char *name)
{
    for (int i = 0; i < NB_BUILTIN; ++i)
    {
        if (!strcmp(name, s_builtin_tab[i].name))
        {
            assert(s_builtin_tab[i].func);
            return s_builtin_tab[i].func;
        }
    }
    assert(0);
    return NULL;
}
