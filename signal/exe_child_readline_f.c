#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
// to be able to work with function readline
// we also have to include a flag -lreadline to compile
#include <readline/history.h>
#include <readline/readline.h>
// pid_t
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// On WSL - Faulty Terminal after execution.
/* The readline library in C can interfere with terminal state because 
it modifies terminal settings, like disabling canonical mode and 
echoing, to handle input more interactively. When a process using 
eadline is terminated abruptly (e.g., with SIGKILL), the terminal 
is not restored to its original state, which can leave the terminal 
behaving unexpectedly.

To handle signals like SIGINT (Ctrl+C) or SIGTERM properly with 
readline, you need to ensure that the terminal settings are restored 
when the process exits. Using SIGKILL should be avoided for this 
reason because it cannot be caught or handled, which prevents the 
process from cleaning up. */
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
        
        while (1)
        {
            sleep(2);
            printf("\nChild is killed\n");
        }
        
        printf("\nChild is killed\n");
        printf("Parent's last action\n");
    }
    return (0);
}


