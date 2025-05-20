#ifndef MINISHELL_H
#define MINISHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef int (*t_command_func)(struct s_shell *, char **);

typedef struct s_command
{
    char **args;
    char *input_file;
    char *out_file;
}   t_command;

typedef struct s_buildin
{
    char *name;
    t_command_func func;
}   t_buildin;


typedef struct s_shell
{
    char **env_copy;
    t_buildin buildinds[7];

}   t_shell;

#endif
