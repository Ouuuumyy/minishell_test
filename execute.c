#include "minishell.h"

int is_buildin(char *command)
{
    int i;
    char *buildins[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL};

    i = 0;
    while(buildins[i])
    {
        if(strcmp(command, buildins[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}

int execute_command(t_shell *shell ,t_command *cmd)
{
    if(is_buildin(cmd->args[0]))
        return (execute_buildin(shell, cmd));
    else
        return (execute_external(shell, cmd));
}

int execute_external(t_shell *shell, t_command *cmd)
{

}

int execute_buildin(t_shell *shell, t_command *cmd)
{
    int i;
    char *name;
    int cmd_len;

    i = 0;
    name = cmd->args[0];
    len = strlen(name);
    while(shell->buildinds[i])
    {
        cmd_len = strlen(shell->buildinds[i]->name);
        if(strncmp(shell->buildinds[i]->name, name, len) == 0 && len == cmd_len)
        {
            return(shell->buildinds[i]->func(shell, cmd->args));
        }
        i++;
    }
    return 0;
}

char *get_command_path(t_command *cmd)
{

}