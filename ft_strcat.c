/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:46:46 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/22 12:32:06 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t b;

	i = 0;
	b = 0;
	while(s1[i])
	{
		i++;
	}
	while(s2[b])
	{
		s1[i] = s2[b];
		b++;
		i++;
	}
	s1[i] = '\0';
	return s1;
}

int main()
{
	char c[] = "Hello";
	char b[] = "World";

	printf("%s", ft_strcat(c,b));
	return 0;
}
