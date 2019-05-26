/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:09:46 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/23 11:28:55 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
