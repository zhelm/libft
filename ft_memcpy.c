/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:56:38 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/22 13:33:43 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char *a = (char *)dst;
	const char *b = (const char *)src;
	size_t i;

	i = 0;
	while(i < n)
	{
		a[i] = b[i];
		i++;
	}
	return dst;
}
