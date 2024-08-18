#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("dup2_basic01", O_RDONLY);
    if (fd != -1)
    {
        dup2(fd, STDIN_FILENO);
        close(fd);
        // Buffer to store read content
        char buffer[1024];
        // Read from stdin and print to stdout
        ssize_t bytesRead;
        while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1)) > 0)
        {
            buffer[bytesRead] = '\0';  // Null-terminate the buffer
            printf("%s", buffer);      // Print the buffer content to stdout
        }
    }
    return (0);
}