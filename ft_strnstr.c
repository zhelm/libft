#include <string.h>
#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t a;
	size_t b;
	size_t c;
	char *strh = (char *)haystack;
	unsigned char *strn = (unsigned char *)needle;

	i = 0;
	a = 0;
	b = 0;
	c = 0;
	if(strlen(strn) != 0)
	{
		while(*(strh + i) && i  + a < len)
		{
			if(*(strh + i) == *(strn + a))
			{
				a = 0;
				while(*(strh + a + i) == *(strn + a))
					a++;
			}
			else if(*(strn + a) == '\0')
				return &strh[i];
			i++;
		}
		return NULL;
	}
	printf("Problem is here at NULL strn");
	return strh;
}

int main()
{
	char *c = "Hello WORLD it is me ITHINK Code";
	printf("%s\n", ft_strnstr(c, "its", 20));
	//	printf("%p\n", strstr(c, "isi"));
	return 0;
}

