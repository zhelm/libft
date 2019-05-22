/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:09:46 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/22 14:39:01 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t n)
{
	char tmp[n];
	char *dst1;
	const char *src1;
	size_t i;

	i = 0;
	dst1 = (char *)dst;
	src1 = (const char *)src;

	while(i < n)
	{
		tmp[i] = src1[i];
		i++;
	}
	i = 0;
	while(i < n)
	{
		dst1[i] = tmp[i];
		i++;
		
	}
	return dst;
}

int main()
{
	char b[12] = "Hello World";
	char d[12] = "Hello World";
	char a[100];
	char c[100];
	//memmove(a+1, b, strlen(b) +1);
	ft_memmove(c+1, d, (strlen(d) + 1));
	//printf("%s\n", a);
	printf("%s\n", (c + 1));
	return 0;
}
