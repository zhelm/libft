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

#include <string.h>
#include <stdio.h>

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	char *dest = (char *)dst;
	const char *source = (const char *)src;

	i = 0;
	while(dest[i])
		i++;
	while(i < n)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return ((sizeof(source)-;
}

int main()
{
	char c[20] = "hello World";
	char b[] = "Hello World  ";

	printf("%lu", strlcpy(c, b, 30));
}
