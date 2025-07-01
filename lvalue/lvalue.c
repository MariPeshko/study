/*
https://www.geeksforgeeks.org/c/lvalue-and-rvalue-in-c-language/
*/

#include <unistd.h>

int	main(void)
{
	int a = 1, b;

	//a + 1 = b;  // Error, left expression is
				// is not variable(a + 1)

	int *p, *q; // *p, *q are lvalue
	p = &b;     // initialization

	*p = 1; 	// valid l-value assignment

	// below is invalid - "p + 2" is not an l-value 
 	//p + 2 = 18; 

	q = p + 5; // valid - "p + 5" is an r-value

	// Below is valid - dereferencing pointer
 	// expression gives an l-value
 	*(p + 2) = 18;

	p = &b;

	int arr[20];	// arr[12] is an lvalue; equivalent
					// to *(arr+12)
					// Note: arr itself is also an lvalue

	struct S { int m; };

 	struct S obj; // obj and obj.m are lvalues

	// ptr-> is an lvalue; equivalent to (*ptr).m
 	// Note: ptr and *ptr are also lvalues
 	struct S* ptr = &obj;

	return 0;
}