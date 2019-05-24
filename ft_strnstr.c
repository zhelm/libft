#include <stdio.h>
#include <bsd/string.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t a;
	char *strh = (char *)haystack;
	char *strn = (char *)needle;

	i = 0;
	a = 0;

	if(strn == NULL)
		return strh;
	while(i != len && strh[i])
	{
		if(strh[i] == strn[a])
		{
			while((strh[i + a] == strn[a]) && strn[a])
				a++;
			if(strn[a] == '\0')
				return &strh[i];
			a = 0;
		}
		i++;
	}
	return NULL;
}

int main()
{
	char *c = "Hello world its me how are you doing?";

	printf("%p\n", ft_strnstr(c, "are", 40));
//	printf("%p\n", strnstr(c, "are", 20));
	return 0;
}
