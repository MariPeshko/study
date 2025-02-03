#include <stdio.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
    int     i = 0;
    int     j = 0;

    while (s[i] != '\0')
    {
		j = 0;
        while (reject[j] != '\0')
        {
            if(s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

int main(void)
{
    const char *s = "Maryna";
    const char *reject = "ny";

    size_t size = ft_strcspn(s, reject);

    printf("Unmatched characters before the first match: %zu\n", size);
    return (0);
}
