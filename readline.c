#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h> // flag -Ireadline
#include <readline/history.h>
#include <string.h>

int	main(void)
{
	int	i;
	int	j;
	char	*str;
	char 	*prompt;

	prompt = strdup("<");
	i = 1;
	j = 5;
	printf("%i line(s) till the end. Type something.\n", j--);
	while (i <= 5)
	{
		str = readline(prompt);
		printf("Line %i is %s\n%i line(s) till the end\n", i++, str, j--);
		free(str);
	}
	printf("Good night!\n");
	free(prompt);
	return (0);
}
