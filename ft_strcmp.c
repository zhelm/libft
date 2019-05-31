/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 09:26:16 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/31 09:28:17 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
	size_t i;
	unsigned char *str1 = (unsigned char *)s1;
	unsigned char *str2 = (unsigned char *)s2;

	i = 0;
	while(str1[i])
	{
		if(str1[i] != str2[i] || str2[i] == '\0')
			return(str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
