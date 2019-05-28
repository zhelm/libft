/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:55:35 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/28 14:30:28 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int ft_numstr(char const *s, char c)
{
	size_t i;
	size_t b;
	size_t num;

	num = 0;
	b = 1;
	i = 0;
	while(s[i])
	{
		while(s[i] == c && s[i])
		{
			if(b = 1)
			{
				b = 0;
			}
			i++;
		} 
		while(s[i] != c && s[i])
		{
			if(b = 0)
			{
				b = 1;
				num++;
			}
			i++;
		}
		i++;
	}
	return num;
}
char **ft_strsplit(char const *s, char c)
{
	printf("%d", ft_numstr(s,c));
	return 0;
}

int main()
{
	char *s = "****HELO**IT*IS*FOUR**";
	printf("%d", ft_numstr(s, '*'));
}
