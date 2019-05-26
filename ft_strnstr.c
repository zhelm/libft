
#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t a;
	char *strh = (char *)haystack;
	char *strn = (char *)needle;

	i = 0;
	a = 0;
	while(strh[i])
	{
		if(strh[i] == strn[a])
		{
			while(strh[a + i] == strn[a] && strn[a] && a + i < len)
			{
				a++;
			}
			if(strn[a] == '\0')
				return &strh[i];
		}
		else
			a = 0;
		i++;
	}
	return NULL;
}

