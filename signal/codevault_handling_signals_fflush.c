#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=jF-1eFhyz1U

void handle_sigcont(int sig)
{
    printf("Input number: \n");
    fflush(stdout);
}

{
    struct sigaction sa;

    sigaction(SIGCONT, &sa, NULL)
    (...)

    int x;
    printf("Input number: \n");
    scanf("%d", &x);
}