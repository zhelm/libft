#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strcmp(const char *s1, const char *s2)
{
	size_t i;
	unsigned char *str1 = (unsigned char *)s1;
	unsigned char *str2 = (unsigned char *)s2;

	i = 0;
	while(str1[i])
	{
		if(str1[i] != str2[i] || str2[i] == '\0')
			return(str1[i] - str2[i]);
		i++;
	}
	return 0;
}

int main()
{
	char *c = "Hello ";
	char *b = "Hello ";

	printf("%d", ft_strcmp(c, b));
	printf("%d", strcmp(c, b));
}
