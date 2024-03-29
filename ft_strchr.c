/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:45:02 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/12 07:45:49 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	char	*str;

	str = (char *)s1;
	while (*str != c && *str)
		str++;
	if (*str == c)
		return (str);
	return (NULL);
}
