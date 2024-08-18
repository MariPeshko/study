#include <unistd.h>
#include <stdio.h>

int main (void)
{
	int i;

	i = 0;
	
	printf("int i++: %d\n", i++);

	i = 0;
	printf("int ++i: %d\n", ++i);

	i = 10;
	printf("int i--: %d\n", i--);
	i = 10;
	printf("int --i: %d\n", --i);

	return (0);
}
