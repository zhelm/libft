/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:56:24 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/27 15:26:52 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striter(char *s, void(*f)(char *))
{
	size_t i;
	i = 0;
	
	while(s[i])
	{
		f(&s[i]);
		i++;
	}
}

int main(void)
{
	char c[12] = "Hello World";
	ft_striter(c, ft_strclr);
	printf("%s", c);
