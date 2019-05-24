#include <string.h>
#include <stdio.h>

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

int main()
{
	char *c = "hello Gabby";
	printf("%p\n", ft_strchr(c, '\0'));
	printf("%p\n", strchr(c, '\0'));
	return 0;
}
