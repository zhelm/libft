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

#include "libft.h"

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
