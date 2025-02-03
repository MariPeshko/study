#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j;

	if(argc == 2)
	{
		while(argv[1][i])
		{
			if (argv[1][i] >= 97 && argv[1][i] <= 122)
				j = (argv[1][i]) - 96;
			else if (argv[1][i] >=65 && argv[1][i] <= 90)
				j = (argv[1][i]) - 64;
			else
				j = 1;
			{
				while(argv[1][i] && j > 0)
				{
					write(1, &argv[1][i], 1);
					j--;
				}
			}
			i++;
		}
	}
		write(1, "\n", 1);
	return (0);
}
