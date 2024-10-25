#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
// to be able to work with function readline
// we also have to include -lreadline
#include <readline/history.h>
#include <readline/readline.h>
// pid_t
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void error_handling(int err)
{
    if (err == 4)
        printf("PATH not readable from ENVP\n");
    else if (err == 1)
    {
        printf("INPUT_ERROR\n");
    }
    else if (err == 2)
    {
        printf("Problems with malloc\n");
        exit(1);
    }
    exit(EXIT_FAILURE);
}

// TASK - to fix it.
int main(int argc, char **argv)
{
    char *input;
    char *prompt;

    if (argc != 1)
        error_handling(1);
    else if (argc == 1)
    {
        prompt = strdup("exercise>");
        input = NULL;
        while (1)
        {
            input = readline(prompt);
            if (!input)
            {
                free(prompt);
                exit(EXIT_FAILURE);
            }
            else if (!*input)
                free(input);
            else if (*input)
            {
                pid_t pid;

                // signal(SIGINT, SIG_IGN);
                signal(SIGINT, SIG_DFL);
                // >ctrl-\ /
                // signal(SIGQUIT, SIG_IGN);
                pid = fork();
                if (pid == 0)
                {
                    while (1)
                    {
                        char *ch_prompt;
                        ch_prompt = strdup("mon_bijou>");
                        char *ch_input;
                        ch_input = NULL;
                        while (1)
                        {
                            ch_input = readline(ch_prompt);
                            if (!strncmp(ch_input, "exit", strlen(ch_input)))
                            {
                                free(ch_input);
                                free(ch_prompt);
                                exit(EXIT_SUCCESS);
                            }
                            if (*input)
                            {
                                add_history(ch_input);
                                free(ch_input);
                            }
                        }
                    }
                }
                else
                {
                    waitpid(pid, NULL, 0);
                    free(input);
                    input = NULL;
                    printf("Parent's last action\n");
                }
            }
        }
        free(prompt);
		prompt = NULL;
    }
    return (0);
}
