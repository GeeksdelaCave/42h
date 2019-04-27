# include <stdio.h>
# include "builtin.h"

int builtin_cmd(char *argv[])
{
    long i;
    char *endpointeur;

    assert(argv && argv[0])
    if (!argv[2])
    {
        fprintf(stderr, "42sh : exit : too many arguments\n");
        return 1;
    }
}
