#include <stdio.h>

#include "../utils/string.h"

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        if (!my_strcmp(argv[i], "--version"))
            printf("Version 0.3\n");
    }
    return 0;
}
