#include <stdio.h>

enum {
  A,    // 0, default starting value
  B,    // 1
  C=4,  // 4, manually set
  D,    // 5
  E,    // 6
  F=3,   // 3, manually set
  G,    // 4
  H,     // 5
};

int	main(void)
{
	printf("%d %d %d %d\n", C, D, F, G); 
	return (0);
}
