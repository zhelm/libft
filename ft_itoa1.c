#include "libft.h"

size_t  st_factor(size_t i)
{
	size_t a;

	a = 1;
	while (i > 1)
	{
		a = a *10;
		i--;
	}
	return a;
}
char *ft_itoa(int n)
{
	unsigned int a = (unsigned int)n;
	size_t i;
	char *b;
	size_t g;

	g = 0;
	i = 0;
	if(n < 0)
		a = n * -1;
	else
		a = n;
	while(a != 0)
	{
		a = a / 10;
		i++;
	}
	if(n < 0)
	{
		b = (char *)ft_strnew(i + 2);
		b[g] = '-';
		g++;
		n = n * -1;
	}
	else
		b = (char *)ft_strnew(i + 1);
	i = st_factor(i);
	while(i >= 1 && (unsigned int)n/i <= 9)
	{
		b[g] = (char)((unsigned int)n / i) + 48;
		n = (unsigned int)n % i;
		i = i / 10;
		g++;
	}
	b[g] = '\0';
	return b;
}
