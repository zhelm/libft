/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 07:47:45 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/28 08:01:04 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t i;
	char *n;

	i = 0;
	n = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while(s[i])
	{
		n[i] = f(i, s[i]);
		i++;
	}
	return n;
}
