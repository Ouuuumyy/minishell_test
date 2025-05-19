#include "minishell.h"

char **copy_env(char **env)
{
    int i;
    char **env_copy;

    i = 0;
    while(env[i])
        i++;
    env_copy = malloc(sizeof(char *) * (i + 1));
    if(!env_copy)
    {
        fprintf(stderr, "enviroment allocation failed\n");
        return NULL;
    }
    i = 0;
    while(env[i])
    {
        env_copy[i] = strdup(env[i]);
        if(!env_copy[i])
        {
            while(i > 0)
                free(env_copy[--i]);
            free(env_copy);
            return NULL;
        }
        i++;
    }
    env_copy[i] = NULL;
    return env_copy;
}

char *get_env_var(t_shell *shell, char *name)
{
    int len;
    int i;

    len = strlen(name);
    while(shell->env_copy[i])
    {
        if(strncmp(shell->env_copy[i], name, len) && shell->env_copy[i][len] == '=')
            return (&shell->env_copy[i][len + 1]);
        i++;
    }
    return NULL;
}