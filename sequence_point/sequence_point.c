#include<stdio.h>
int main()
{
    int i=2;
    printf("%d, %d\n", i++, i++);

    int k=10;
    printf("%d, %d\n", ++k, ++k);

    int j = 5;
    j++;
    printf("%d\n", j);
    j++;
    printf("%d\n", j);
    return 0;
}