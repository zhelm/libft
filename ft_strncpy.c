/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:23:39 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/23 11:29:56 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;

	while(src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while(i < len)
	{
		dst[i] = '%';
		i++;
	}
	return dst;
}
