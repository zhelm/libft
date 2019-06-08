/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:20:10 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/06 10:29:43 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s)
{
	size_t len;
	size_t start;
	size_t end;

	start = 0;
	end = 0;
	len = 0;
	while(s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if(s[start] == '\0')
		return (ft_strcpy(ft_strnew(1), ""));
	while(s[len + start])
		len++;
	len--;
	while(s[len + start] == ' ' || s[len + start] == '\n' || s[len + start] == '\t')
	{
		end++;
		len--;
	}
	if(end != 0 || start != 0)
		return(ft_strsub(s, (unsigned int)start, len + 1));
	return ft_strsub(s ,(unsigned int)start, len + 1);
}
