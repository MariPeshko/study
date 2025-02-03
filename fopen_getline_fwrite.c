#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// From Beej

int	main(void)
{
	FILE *fp;

	fp = fopen("fopen.txt", "r"); // Open file for reading
	if (fp == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	char	*lineptr;
	size_t n = 0;
	ssize_t	nread;

	// In the call to fwrite, the arguments are:
	//
	// * lineptr - pointer to data to write
	// * nread   - size of each "piece" of data
	// * 1       - count of each "piece" of data
	// * FILE*
	while ((nread = getline(&lineptr, &n, fp)) != -1) {
		printf("Retrieved line of length %zd:\n", nread);
		fwrite(lineptr, nread, 1, stdout);
	//	free(lineptr);
	}
	free(lineptr);
	fclose(fp);
	return (0);
}
