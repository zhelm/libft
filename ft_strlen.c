/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:44:02 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/20 14:11:26 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while(s[len])
		len++;
	return len;
}

int main()
{
	char c = ft_strlen("Hello World");
	printf("%d", c);
	return 0;
}
