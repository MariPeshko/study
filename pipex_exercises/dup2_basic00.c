#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("dup2_basic00.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd != -1)
    {
        dup2(fd, STDOUT_FILENO);
        printf("This is dup2!\n");
        close(fd);
    }
    return (0);
}