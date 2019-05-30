/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:09:13 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/30 11:09:43 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	size_t i;
	char *str = (char *)s;

	i = 0;
	while(str[i])
		i++;
	while(str[i] != c && i > 0)
		i--;
	if(str[i] == c)
		return &str[i];
	else
		return NULL;
}
