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

// TASK - to fix it.
int main(void)
{

    pid_t pid;

    // C-c
    //signal(SIGINT, SIG_IGN);
    signal(SIGINT, SIG_DFL);

    // >ctrl-\ /
    // signal(SIGQUIT, SIG_IGN);

    pid = fork();
    if (pid == 0)
    {
        while (1)
        {
            char *prompt;
            prompt = strdup("mon_bijou>");
            char *input;
            input = NULL;
            while (1)
            {
                input = readline(prompt);
                if (!strncmp(input, "exit", strlen(input)))
                {
                    free(input);
                    free(prompt);
                    exit(EXIT_SUCCESS);
                }
                if (*input)
                {
                    add_history(input);
                    free(input);
                }
            }
        }
    }
    else
    {
        sleep(2);
        kill(pid, SIGKILL);
        waitpid(pid, NULL, 0);
        
        // while (1)
        // {
        //     sleep(2);
        //     printf("\nChild is killed\n");
        // }
        
        printf("\nChild is killed\n");
        printf("Parent's last action\n");
    }
    return (0);
}


