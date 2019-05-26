/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:44:06 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/24 10:16:01 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	i = 0;
	a = ft_strlen(dst);
	b = ft_strlen(src);
	if(dstsize - 1 < a + b || dstsize == 0)
		return 0;
	if(a + b <= dstsize - 1)
	{
		while(a + i < dstsize - 1 && src[i])
		{
			dst[a + i] = src[i];
			i++;
		}
		dst[a + i] = '\0';
	}
	return (a + b);

}
