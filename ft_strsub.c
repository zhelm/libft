/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:41:32 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/28 13:38:01 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *n;
	
	i = 0;
	n = (char *)malloc(sizeof(char) * (len + 1));
	if(n == NULL)
	   return NULL;	
	while(s[i] && i < len)
	{
		n[i] = s[i + start];
		i++;
	}
	n[i] = '\0';
	return n;
}

//int main()
//{
//	const char *c = "Hello World";
//	printf("%s", ft_strsub(c, 2, 9));
//}
