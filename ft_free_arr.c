#include "libft.h"

void ft_free_arr(void **c)
{
    size_t i;

    i = 0;
    while(c[i])
    {
        free(c[i]);
        i++;
    }
    free(c);
}