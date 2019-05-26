
#include "libft.h"

char *ft_strchr(const char *s1, int c)
{
	size_t i;
	char *str = (char *)s1;

	i = 0;
	while(str[i] != c)
		i++;
	if(str[i] == c)
		return(&str[i]);
	else
		return NULL;
}
