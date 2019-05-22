/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:49:08 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/22 16:31:28 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	size_t c;
	int h;
	int j;
	int *a = (int*)s1;
	int *b = (int*)s2;
	h = 0;
	j = 0;
	i = 0;
	c = 0;
	while(i < n)
	{
		j = j + a[i];
		h = h + b[c];
		i++;
		c++;
	}

	printf("%d\n", h);
	printf("%d\n", j);

	if(j == h)
		return 0;
	else if(j > h)
		return 1;
	else
		return -1;
}

int main()
{
	char a[12] = "Hello World";
	char b[12] = "Hello World";

	printf("%d\n",memcmp(a, b, 12));
	printf("%d\n", ft_memcmp(a, b, 12));
	return 0;
}
