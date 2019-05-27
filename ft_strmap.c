/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:43:53 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/27 15:57:41 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_putchar(char const *s, char *c)
{
	size_t i;
	char *n;

	i = 0;
	while(s[i])
	{
		n[i] = s[i + 1];
		i++;
	}
	return (char *)n;
}
char *ft_strmap(char const *s, char (*f)(char))
{
	size_t i;
	char *n;
	size_t len;

	len = 0;
	i = 0;
	while(s[len])
		len++;
	n = malloc(sizeof(char) * len + 1);
	while(s[i])
	{
		n[i] = f(s[i]);
		i++;
	}
	return n;
}

int main()
{
	char *c ="Hello World";
	ft_strmap(c, ft_putchar);
}
