#include <stddef.h>

#include "string.h"

int my_strcmp(char *s1, char *s2)
{
    for (size_t i = 0; s1[i] != '\0' && s2[i] != '\0'; ++i)
        if (s1[i] != s2[i])
            return s1[i] < s2[i] ? -1 : 1;
    return 0;
}
