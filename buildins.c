#include "minishell.h"

void init_buildin(t_shell *shell)
{
    shell->buildinds[0] = {"echo", &ft_echo};
    shell->buildinds[1] = {"cd", &ft_cd};
    shell->buildinds[2] = {"pwd", &ft_pwd};
    shell->buildinds[3] = {"export", &ft_export};
    shell->buildinds[4] = {"unset", &ft_unset};
    shell->buildinds[5] = {"env", &ft_env};
    shell->buildinds[6] = {"exit", &ft_exit};
    shell->buildinds[7] = {NULL, NULL};
}

int ft_echo(t_shell *shell, char **args)
{
    int i;
    int new_line;
    (void*)shell;

    i = 1;
    new_line = 1;
    if(args[1] && strcmp(args[1], "-n") == 0)
    {
        new_line = 0;
        i++;
    }
    while(args[i])
    {
        printf("%s", args[i]);
        if(args[i + 1])
            printf(" ");
        i++;
    }

    if(new_line)
        printf("\n");
    return 0;
}

