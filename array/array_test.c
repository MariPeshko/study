#include <stdio.h>

int	pos[20];

int main(void)
{
    int n = 4;
    int i = 0;
    int row = 0;
    printf("pos[i]: %d, pos[i + 1]: %d\n\n", pos[i], pos[i + 1]);
    while (i < n)
    {
        if (i == 0 && row == 0)
        {
            pos[i] = i;
            printf("pos[i]: %d\n", pos[i]);
            row++;
        }
        else if (pos[i] == row)
            printf("This position is %d and this is equal to row which is %d\n", pos[i], row);
        else {
            printf("This position is %d and this is NOT equal to row which is %d\n", pos[i], row);
            pos[i] = i;
            printf("pos[i]: %d\n", pos[i]);
            row++;
        }
        i++;
    }
}