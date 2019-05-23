/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:17:54 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/23 11:27:31 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char *ft_strncat(char  *restrict s1, const char *restrict s2, size_t len)
{
	int d;
//	int c;
	d = (*s1/sizeof(char));
	printf("%d", d);

	int a;
	a = 0;
	while(s1[a])
	{
		a++;	
	}
	while(s1[a] == '\0')
	{
		a++;
	}
//	printf("%d", a);
	size_t i;
	size_t b;

	i = 0;
	b = 0;
	//printf("%lu",sizeof(*s1));
	while(s1[i])
		i++;
	while(s2[b] && b < len)
	{
		s1[i] = s2[b];
		b++;
		i++;
	}
	s1[i] = '\0';
//	printf("%lu", sizeof(s1));
	return s1;
}

int main()
{
	char a[40] = "Hello";
	char b[] = " World";
//	printf("%lu", sizeof(a));
	printf("%s", ft_strncat(a,b, 3));
	return 0;
}
