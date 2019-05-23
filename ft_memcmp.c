/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:49:08 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/23 13:34:59 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *str1 = (unsigned char *)s1;
	unsigned char *str2 = (unsigned char *)s2;
	i = 0;
	if(n == 0)
		return 0;
		while(i < n)
		{
			if(str1[i] != str2[i])
				return (str1[i] - str2[i]);
			i++;
		}
		return 0;
}

int main()
{
	char *a = "Hello World1";
	char *b = "Hello World2";

	printf("%d\n",memcmp(a, b, 12));
	printf("%d\n", ft_memcmp(a, b, 12));
	return 0;
}
