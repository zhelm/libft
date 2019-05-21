/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:23:39 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/21 12:57:43 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int main()
{
	char c[] = "hello";
	char *b;

	printf("%s",ft_strncpy(b, c, 4));
}
