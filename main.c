#include "minishell.h"

int main(int ac, char **av, char *envp)
{
    (void)ac;
    (void)av;
    char *input;

    while(1)
    {
        input = readline("minishell$");
        if(!input)
        {
            printf("exit\n");
            exit;
        }
        if(*input)
            add_history(input);
        free(input);
    }
    return 0;
}