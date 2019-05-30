/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:28:09 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/30 09:19:11 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char st_modi(int n, size_t c)
{
	while(c > 0)
	{
		n = n / 10;
		c--;
	}
	if(n < 0)
		n *= -1;
	return ((char)(n % 10) + 48);
}
static size_t st_numlen(int n)
{
	int a;
	size_t i;

	i = 0;
	a = n;
	if (n == 0)
		return 1;
	while(a != 0)
	{
		a = a / 10;
		i++;
	}
	if (n < 0)
		i++;
	return i;
}
char *ft_itoa(int n)
{
	size_t c;
	char *b;
	size_t i;

	i = 0;
	c = st_numlen(n) - 1;
	if(n < 0)
	{
		b = ft_strnew(st_numlen(n) + 2);
		b[i] = '-';
		i++;
		c = st_numlen(n) - 2;
	}
	else
		b = ft_strnew(st_numlen(n) + 1);
	while(i < st_numlen(n))
	{
		b[i] = st_modi(n, c);
		c--;
		i++;
	}
	b[i] = '\0';
	return b;
}
