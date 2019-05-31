/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:55:35 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/31 11:52:53 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_numstr(char const *s, char c)// determines amount of strings
{
	size_t i;
	size_t b;
	size_t num;

	num = 0;
	i = 0;
	while(s[i])
	{
		if(s[i] == c)
		{
			while(s[i] == c)
				i++;
			b = 0;
		}
		else if(s[i] != c && b == 0)
		{
			num++;
			b = 1;
			while(s[i] != c)
				i++;
		}
	}
	return num;
}
static size_t ft_strnumlen(char const *s, char c, size_t word)//returns length of chosen string
{
	size_t len;
	size_t i;

	len = 0;
	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			i++;
		else if(s[i] != c && s[i])
		{
			word--;
			if(word == 0)
				while(s[i] != c && s[i])
				{
					i++;
					len++;
				}
			while(s[i] != c && s[i])
				i++;
		}
	}
	return  len;
}
static size_t ft_strstart(char const *s, char c, size_t word)
{
	size_t i;

	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			while(s[i] == c)
				i++;
		else if (s[i] != c)
		{
			word--;
			if(word == 0)
			{
				return i;
			}
			while(s[i] != c)
				i++;
		}
	}
	return 0;
}
char **ft_strsplit(char const *s, char c)
{
	size_t len;
	size_t i;
	size_t a;
	size_t g;
	char **n;

	i = 0;
	a = 0;
	len = sizeof(char *) + sizeof(char *) * (ft_numstr(s, c) + 1);
	n = (char **)malloc(sizeof(char) *(len + 1));
	while(a <= ft_numstr(s, c))
	{
		g = 0;
		n[a] = (char *)malloc(sizeof(char) * ft_strnumlen(s, c, a) + 1);
		while(g < ft_strnumlen(s, c, a))
		{
			n[a][g] = s[ft_strstart(s, c, a) + g];
			g++;
		}
		n[a][g] = '\0';
		a++;
	}
	n[a] = (char *)malloc(sizeof(char) * 1);
	n[a][0] = '\0';
	return n;
}
