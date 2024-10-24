#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
// to be able to work with function readline
// we also have to include -lreadline
#include <readline/history.h>
#include <readline/readline.h>

int main(void)
{
    char *prompt;
    prompt = strdup("mon_bijou>");
    char *input;
    input = NULL;

    // signal(SIGINT, SIG_IGN);
    signal(SIGINT, SIG_DFL);

    signal(SIGQUIT, SIG_IGN);

    while (1)
    {
        input = readline(prompt);
        if (*input)
			{
				add_history(input);
            }
    }
    free(input);
    free(prompt);
    return (0);
}

// beej book
// int main(void)
// {
//     char s[1024];

//     signal(SIGINT, SIG_IGN);
//     //signal(SIGINT, SIG_DFL);

//     printf("Try hitting ^C... (hit RETURN to exit)\n");

//     //Wait for a line of input so the program doesn't just exit
//     fgets(s, sizeof s, stdin);
//     return (0);
// }