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
	size_t	i;
	char	*str;

	str = (char *)s1;
	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}
