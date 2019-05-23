/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 07:03:30 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/23 11:30:25 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
void *ft_memset(void *b, int c, size_t len)
{
	size_t i;
	char *s = (char *)b;
	unsigned char f = (unsigned char)c;
	i = 0;
	while (i < len)
	{	
		s[i] = f;
		i++;
	}
	return b;
}

int main()
{
	char b[12] = "Hello World";
	printf("%s\n", ft_memset(b + 3, '*', 4));
	printf("%s", b);
	return 0;
}
