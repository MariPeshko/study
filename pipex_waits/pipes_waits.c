#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main()
{
    int pipe1[2], pipe2[2];

    // Create pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t p1, p2, p3;

    // Fork the first child
    if ((p1 = fork()) == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (p1 == 0)
    {
        fprintf(stderr, "first\n");
        // First child process
        // Close unused read end of pipe1
        close(pipe1[0]);

        // Redirect STDIN to /dev/null
        int devnull = open("/dev/null", O_RDONLY);
        if (devnull == -1)
        {
            perror("open /dev/null");
            exit(EXIT_FAILURE);
        }
        dup2(devnull, STDIN_FILENO);
        close(devnull);

        // Write to pipe1
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[1]);

        // Execute some command, e.g., "ls"
        execlp("ls", "ls", NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Fork the second child
    if ((p2 = fork()) == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (p2 == 0)
    {
        fprintf(stderr, "second\n");
        // Second child process
        // Close unused write end of pipe1 and read end of pipe2
       // close(pipe1[1]);
        //close(pipe2[0]);

        // Read from pipe1 and write to pipe2
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);
       // close(pipe1[0]);
       // close(pipe2[1]);

        // Execute some command, e.g., "grep .c"
        execlp("grep", "grep", ".c", NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Fork the third child
    if ((p3 = fork()) == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (p3 == 0)
    {
        fprintf(stderr, "third\n");
        // Third child process
        // Close unused write end of pipe2
        close(pipe2[1]);

        // Read from pipe2
        dup2(pipe2[0], STDIN_FILENO);
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe2[0]);

        // Execute some command, e.g., "wc -l"
        execlp("wc", "wc", "-l", NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    dup2(STDOUT_FILENO, pipe2[1]);
    // Parent process
    // Close all pipe ends
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    // Wait for all children to finish
    fprintf(stderr, "parent %i\n", getpid());
    fprintf(stderr, "%i %i %i\n", p1, p2, p3);
    waitpid(p1, NULL, 0);
     printf("1 children finished\n");
    waitpid(p2, NULL, 0);
     printf("2 children finished\n");
    // waitpid(p3, NULL, 0);
    //  printf("All children finished\n");

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(pipe1[0], buffer, sizeof(buffer))) > 0) {
        if (write(STDERR_FILENO, buffer, bytes_read) == -1) {
            perror("write");
            close(pipe2[0]);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
