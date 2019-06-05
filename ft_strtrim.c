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
	char *b = (char *)s;

	start = 0;
	end = 0;
	len = 0;
	while(s[start] == ' ' && s[start] == '\n' && s[start] == '\t')
		start++;
	while(s[len + start] != ' ' && s[len + start] != '\n' && s[len + start] != '\t')
		len++;
	while(s[start + len + end] == ' ' && s[start + len + end] == '\n' && s[start + len + end] == '\t')
		end++;
	if(end != 0 && start != 0)
	{
		end = 0;
		while(start < len)
		{
			b[end] = s[start];
			start++;
			end++;
		}
		*b = '\0';
		return b;
	}
	else
        {
                while(*s)
                {
                        b = (char *)s;
                        b++;
                        s++;
                }
                *b = '\0';
                return b;
        }
}
