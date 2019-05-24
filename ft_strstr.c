#include <string.h>
#include <stdio.h>

char *ft_strstr(const char *haystack, const char *needle)
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
			while(strh[a + i] == strn[a] && strn[a])
			{
				a++;
			}
			if(strn[a] == '\0')
				return &strh[i];
			else
				a = 0;
		}
		i++;
	}
	return NULL;
}

int main()
{
	char *c = "Hello WORLD it is me ITHINK Code";
	printf("%p\n", ft_strstr(c, "isi"));
	printf("%p\n", strstr(c, "isi"));
	return 0;
}
