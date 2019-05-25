#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	unsigned char *str1 = (unsigned char *)s1;
	unsigned char *str2 = (unsigned char *)s2;

	i = 0;
	while(i < n && (str1[i] || str2[i]))
	{
		if(str1[i] != str2[i])
			return(str1[i] - str2[i]);
		i++;
	}
	return 0;
}

int main()
{
	char *c = "hello Wor";
	char *b = "hello World";
	printf("%d\n", ft_strncmp(c, b, 14));
	printf("%d\n", strncmp(c, b, 14));
	return 0;
}
