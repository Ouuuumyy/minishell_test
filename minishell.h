#ifndef MINISHELL_H
#define MINISHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_command
{
    char **args;
    char *input_file;
    char *out_file;
}   t_command;

typedef struct s_shell
{
    char **env_copy;
}   t_shell;

#endif
