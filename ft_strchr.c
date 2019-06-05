
#include "libft.h"

char *ft_strchr(const char *s1, int c)
{
	size_t i;
	char *str = (char *)s1;

	i = 0;
	while(str[i] != c && str[i])
		i++;
	if(str[i] == c)
		return(&str[i]);
	return NULL;
}
