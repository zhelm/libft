#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *s, int c)
{
	size_t i;
	char *str = (char *)s;

	i = 0;
	while(str[i])
		i++;
	while(str[i] != c && i > 0)
		i--;
	if(str[i] == c)
		return &str[i];
	else
		return NULL;
}
