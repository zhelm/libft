/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:19:18 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/23 11:26:29 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
	size_t i;
	char *str = (char *)s;
	
	i = 0;
	if(n > 0)
	{
	while(i < n)
	{
		str[i] = 0;
		i++;
	}
	}
//	return s;
}

int main()
{
	char c[12] = "Hello World";

	ft_bzero(c, 3);
	printf("%c is here\n", c[2]);
	printf("%c is here\n", c[3]);
}
