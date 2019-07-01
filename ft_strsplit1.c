/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 07:53:13 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/31 14:06:37 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char st_strstart(char const *s, char c, size_t n)
{
	while(*s)
	{
		while(*s == c)
			s++;
		if(*s != c)
			n--;
		if(n == 0)
			return (char)*s;
		while(*s != c)
			s++;
	}
	return 0;
}
size_t st_countstrlen(char const *s, char c, size_t n)
{
	size_t i;
	if(n == 0)
		return 0;
	i = 0;
	while(*s)
	{
		while(*s == c)
			s++;
		n--;
		if (n == 0)
		{
			while(*s != c)
			{
				s++;
				i++;
			}
			return i;
		}
		else
			s++;
	}
	return 0;
}
size_t st_countstr(char const *s, char c)
{
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	while(*s)
	{
		if(*s == c)
		{
			if(i == 1)
				i = 0;
		}
		else if(*s != c)
		{
			if(i == 0)
			{
				i = 1;
				count++;
			}
		}
		s++;
	}
	return count;
}
char **ft_strsplit(char const *s, char c)
{
	char **array;
	size_t len;
	size_t i;
	size_t a;
	size_t b;

	a = 0;
	i = 0;
	b = 0;
	//len = sizeof(char) + sizeof(char) * (st_countstr(s, c));
	array = (char **)malloc(sizeof(char *) * (st_countstr(s,c) + 1));
	while(a <= st_countstr(s, c))
	{
		b = 0;
		array[a] = ft_strnew(st_countstrlen(s, c, a));
		while(b < st_countstrlen(s, c, a))
		{
			array[a][b] =  s[st_strstart(s, c, a) + b];
			b++;
		}
		array[a][b] = '\0';
		a++;
	}
//	array[a] = '\0';
	printf("%s", array[1]);
	return array;
}
int main()
{
	const char *a = "****Hello*its**World*";
	printf("%s", ft_strsplit(a, '*')[1]);
}
