/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:03:27 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/22 13:58:40 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *a = (char *)dst;
	const char *b = (const char *)src;
	unsigned char d = (unsigned char)c;
	size_t i;

	i = 0;
	while(i < n)
	{
		a[i] = b[i];
		if(a[i] == d)
		{
			a[i] = d;
			return (dst + i + 1);
		}
		i++;
	}
	return NULL;
}

int main()
{
	char d[12] = "Hello World";
	char b[12] = "Hello Wolrd";
	char c[12];
	char a[12];

	 memccpy(c, d, 'e', 12);
	ft_memccpy(a, b, 'e', 12);
	printf("%s|\n", c);
	printf("%s|\n", a);
}
