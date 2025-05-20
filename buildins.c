#include "minishell.h"


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

int ft_cd(t_shell *shell, char **args)
{

}

int ft_pwd(t_shell *shell, char **args)
{
    
}int ft_unset(t_shell *shell, char **args)
{
    
}int ft_export(t_shell *shell, char **args)
{
    
}int ft_env(t_shell *shell, char **args)
{
    
}int ft_exit(t_shell *shell, char **args)
{
    
}


void init_buildin(t_shell *shell)
{
    shell->buildinds[0] = (t_buildin){"echo", &ft_echo};
    shell->buildinds[1] = (t_buildin){"cd", &ft_cd};
    shell->buildinds[2] = (t_buildin){"pwd", &ft_pwd};
    shell->buildinds[3] = (t_buildin){"export", &ft_export};
    shell->buildinds[4] = (t_buildin){"unset", &ft_unset};
    shell->buildinds[5] = (t_buildin){"env", &ft_env};
    shell->buildinds[6] = (t_buildin){"exit", &ft_exit};
    shell->buildinds[7] = (t_buildin){NULL, NULL};
}