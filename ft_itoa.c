/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:50:22 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/07 09:51:34 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *st_tolong(char *b)
{
	b = (char *)malloc(sizeof(char) * 12);
	b = "-2147483648";
	return b;
}
char *st_itoamalloc(int n, char *b, size_t a)
{
	if(n < 0)
	{
		b = (char *)malloc(sizeof(char) * (a + 2));
		b[0] = '-';
		n = n * -1;
		a++;
	}
	else
		b = (char *)malloc(sizeof(char) * (a + 1));
	if(b == NULL)
		return NULL;
	b[a] = '\0';
	while(n != 0)
	{
		a--;
		b[a] = (unsigned char)(n % 10 + 48);
		n = n / 10;
	}
	return b;
}
char *ft_itoa(int n)
{
	int a;
	size_t i;
	char *b;

	a = n;
	b = NULL;
	i = 0;
	if (n == -2147483648)
		return st_tolong(b);
	while(a != 0)
	{
		a = a / 10;
		i++;
	}
	if(n == 0)
	{
		b = (char *)malloc(sizeof(char) * 2);
		b[0] = n + 48;
		b[1] = '\0';
		return b;
	}
	return(st_itoamalloc(n, b, i));
}
