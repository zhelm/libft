/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:30:09 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/22 15:48:23 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <string.h>
void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	const char *str = (const char*)s;
	unsigned char a = (unsigned char)c;

	i = 0;
	while(i < n)
	{
		if(str[i] == a)
		{
			return ((char *)s + i);
		}
		else
		{
			i++;
		}
	}
	return NULL;
}

int main()
{
	char c[12] = "Hello World";
	char b[12] = "Hello World";

	printf("%s\n", memchr(c,'o',1));
	printf("%s\n", c);
	printf("%s\n", ft_memchr(b, 'o',1));
	printf("%s\n", b);
	return 0;
}
