#ifndef MINISHELL_H
#define MINISHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_shell t_shell;

typedef int (*func)(struct s_shell *, char **);

typedef struct s_command
{
    char **args;
}       t_command;

typedef struct s_buildin
{
    char *name;
    func cmd_func;
}   t_buildin;


struct s_shell
{
    char **env_copy;
    t_buildin buildinds[8];

};

char **copy_env(char **env);
void init_buildin(t_shell *shell);
int execute_command(t_shell *shell ,t_command *cmd);

#endif
