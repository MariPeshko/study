//I wanna test if unlink closed the fd
// Checking it with valgrind [flags for checking fd]

//to use open & read
# include <fcntl.h>
// scanf
#include <stdio.h>
// access
#include <unistd.h>
// printf
#include <stdio.h>
// errno
# include <errno.h>
// exit
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	error_handling(int err)
{
	if (err == 4)
		ft_putstr_fd("PATH not readable from ENVP", 1);
	else if (err == 2)
	{
		errno = 12;
		ft_putstr_fd("Problems with malloc", 1);
		exit (1);
	}
	else if (err == 3)
	{
		ft_putstr_fd("zsh: ", 2);
		exit(127);
	}
	perror("Error");
	exit(EXIT_FAILURE);
}

static int	ft_get_fd(char *filename)
{
	int	fd_out;

	fd_out = 0;
	if (!access(filename, W_OK))
	{
		fd_out = open(filename, O_WRONLY | O_TRUNC);
		if (fd_out == -1)
			error_handling(1);
	}
	else
	{
		printf("%s: Permission denied\n", filename);
		return (-1);
	}
	return (fd_out);
}

int main ()
{
    int		fd_out;
    char input[100];  // Buffer to store the input
    
    fd_out = 0;
    printf("Enter a name of the file you want to create: ");
    scanf("%99s", input); 
	if (access(input, F_OK))
	{
		fd_out = open(input, O_WRONLY | O_CREAT, 0644);
		if (fd_out == -1)
			error_handling(1);
        printf("File %s is created\n", input);
	}
    else
        fd_out = ft_get_fd(input);
	unlink(input);
	close(fd_out);
    return (0);
}