#include <unistd.h>
#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;	

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	
	
	while (1)
	{
		printf("%d, ", n);
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

int main(void)
{
    unsigned int a = 5;
    unsigned int b = 15;
    unsigned int c = lcm(a, b);

    printf("The LCM of %d and %d is: %d\n", a, b, c);
    return (0);
}