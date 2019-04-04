# ifndef BUILTIN_H
# define BUILTIN_H


/*
**@author souleymane
**
** Func pointeur i use everywere
*/

typedef int (*fct_builtin)(char *arg[]);

struct shell
{
    int status;
};

/*!
** Builtin exit :)
**
** @param argv argument vector
**
** @retrun success status

*/

int exit_builtin(char *argv[]);

# endif
