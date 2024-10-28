#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// “hit CTRL-C twice to exit” code

/*
Automatic Argument Assignment:

When we set up the handler with signal
(SIGINT, sigint_handler);, we’re telling the operating system: "If SIGINT 
is triggered, call sigint_handler." The operating system takes care of 
calling sigint_handler and automatically passes in the signal number 
(in this case, SIGINT or the number 2) as the signum argument.

Using signum Without Explicit Assignment: 

Since we aren’t directly calling sigint_handler, we never assign a value 
to signum ourselves. Instead, the operating system assigns it the correct 
signal number whenever it calls the handler. This value corresponds to 
the specific signal that caused the handler to be triggered (in this case,
SIGINT).

Summary

    Setup: The line signal(SIGINT, sigint_handler); registers sigint_handler 
    to handle SIGINT.

    Automatic Calling: When SIGINT is raised (e.g., by pressing Ctrl+C), 
    the OS calls sigint_handler and passes SIGINT as signum without our 
    intervention.

*/

int count = 0;

void sigint_handler(int signum)
{
    // The compiler is allowed to run:
    //
    //   signal(signum, SIG_DFL)
    //
    // when the handler is called. So we reset the handler here:
    signal(SIGINT, sigint_handler);

    (void)signum;   // Get rid of unused variable warning

    count++;                       // Undefined behavior
    printf("Count: %d\n", count);  // Undefined behavior

    if (count == 2) {
        printf("Exiting!\n");      // Undefined behavior
        exit(0);
    }
}

int main(void)
{
    signal(SIGINT, sigint_handler);
    
    while(1)
    {
        printf("Try hitting ^C...\n");
        usleep(1000000);
    }
    for(;;);  // Wait here forever
}