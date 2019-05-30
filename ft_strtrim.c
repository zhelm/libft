/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:20:10 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/30 15:00:42 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s)
{
	size_t len;
	size_t start;
	size_t end;

	start = 0;
	len = 0;
	end = 0;
	while(s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if(start == 0)
		return (ft_strcpy(s));
	while(s[len])
		len++;
	len--;
	while(s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
	{
		len--;
		end++;
	}
	if(end == 0)
		return((ft_strcpy(s));
	return (ft_strsub(s, start, len));
}
