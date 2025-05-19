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

int execute_command(t_command *cmd)
{
    if(is_buildin(cmd->args[0]))
        return (execute_buildin(cmd));
    else
        return (execute_external(cmd));
}

int execute_external(t_command *cmd)
{

}

int execute_buildin(t_command *cmd)
{

}

char *get_command_path(t_command *cmd)
{

}