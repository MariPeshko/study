#include <stdio.h>

enum {
    SHEEP,  // Value is 0
    WHEAT,  // Value is 1
    WOOD,   // Value is 2
    BRICK,  // Value is 3
    ORE     // Value is 4
};

int	main(void)
{
	printf("%d %d\n", SHEEP, BRICK);  // 0 3
	return (0);
}
