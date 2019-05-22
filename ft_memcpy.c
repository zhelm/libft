/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:56:38 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/22 13:33:43 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<string.h>
#include <stdio.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char *a = (char *)dst;
	const char *b = (const char *)src;
	size_t i;

	i = 0;
	while(i < n)
	{
		a[i] = b[i];
		i++;
	}
	return dst;
}

//int main()
//{
//	char a[12] = "Hello World";
//	char b[12] = "Hello World";
//	char c[13];
//	char d[13];
//	
//	printf("%s|\n", a);
//	printf("%s|\n", memcpy(c, a, 5));
//	printf("\n%s|\n", b);
//	printf("%s|\n", ft_memcpy(d, b, 4));
//	return 0;
//}
int main()
{
   char csrc[100] = "Geeksfor";
   char crsc1[100] = "Geeksfor";
   ft_memcpy(crsc1+5, crsc1, strlen(crsc1)+1);
   memcpy(csrc+5, csrc, strlen(csrc)+1);
   printf("%s\n", csrc);
   printf("%s\n", crsc1);
   return 0;
}
