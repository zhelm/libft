/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:30:09 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/06 14:41:25 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	const char *str = (const char*)s;
	unsigned char a = (unsigned char)c;

	i = 0;
	while(i < n)
	{
		if((unsigned char)str[i] == a)
			return ((char *)s + i);
		else
			i++;
	}
	return NULL;
}
