/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:44:06 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/23 14:29:06 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t n;
	char *dest = (char *)dst;
	const char *source = (const char *)src;

	n = 0;
	i = 0;
	while(dest[i])
		i++;
	while(source[n] && i < dstsize -1)
	{
		dest[i] = source[n];
		n++;
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int main()
{
	char c[18] = "hello World";
	char b[] = "hello          hello";
	printf("%ld", ft_strlcat(c, b, 18));
//	printf("%ld", strlcat(c, b, 30));
	printf("%s", c);
	return 0;
}
