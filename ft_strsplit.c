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

char **ft_strsplit(char const *s, char c)
{
	size_t i;
	size_t j;
	size_t amount;
	char **a;

	i = 0;
	j = 0;
	amount = 0;
	s = 0;
	while(s[i])
	{
		if(s[i] == c)
			i++;
		else if(s[i] != c && s[i])
		{
			amount++;
			i++;
		}
		else
			i++;
	}
	printf("%zu", amount);
	return a;
}

int main()
{
	char *s = "****HELO**IT*IS*FOUR**";
	ft_strsplit(s, '*');
}
