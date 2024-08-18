#include <stdio.h>

// Named enum, type is "enum resource"

enum resource {
    SHEEP,
    WHEAT,
    WOOD,
    BRICK,
    ORE
};

// Declare a variable "r" of type "enum resource"

int	main(void)
{
	enum resource r = BRICK;
	if (r == BRICK) {
		printf("I'll trade you a brick for two sheep.\n");
	}
	return (0);
}
