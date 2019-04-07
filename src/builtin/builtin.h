# ifndef BUILTIN_H
# define BUILTIN_H


/*
**@author souleymane
**
** Func pointeur i use everywere
*/

typedef int (*func_builtin)(char *arg[]);

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

int builtin_exit(char *argv[]);

/*!
** Builtin cd :)
**
** @param argv argument vector
**
** @retrun success status

*/

int builtin_cd(char *argv[]);
# endif
