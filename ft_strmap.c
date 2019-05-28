/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:43:53 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/28 07:47:35 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	size_t i;
	char *n;

	i = 0;
	n = malloc(sizeof(char) * ft_strlen(s));
	while(s[i])
	{
		n[i] = f(s[i]);
		i++;
	}
	return n;
}
