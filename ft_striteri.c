/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:53:39 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/27 15:37:28 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void oneup(unsigned int g, char *s)
{
	*s = *s + g;
}

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int a;

	a = 0;
	while(s[a])
	{
		f(a, &s[a]);
		a++;
	}
}

int main()
{
	char c[12] = "Hello World";

	ft_striteri(c, oneup);
	printf("%s", c);
}
