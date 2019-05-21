/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:38:54 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/21 10:11:03 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
size_t ft_strlen(const char *c)
{
	size_t i;
	
	i = 0;
	while(c[i])
		i++;
	return i;
}
char *ft_strdup(const char *s1)
{
	char *str;
	size_t a;
	
	a = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if(str == NULL)
		return NULL;
	while(s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

int main()
{
	char c[] = "Good Day";
	printf("%s", ft_strdup(c));
	return 0;
}
