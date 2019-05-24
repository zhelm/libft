/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:44:06 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/24 10:13:41 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	i = 0;
	a = strlen(dst);
	b = strlen(src);
	if(dstsize - 1 < a + b || dstsize == 0)
		return 0;
	if(a + b >= dstsize - 1)
	{
		while(a + i < dstsize - 1 && src[i])
		{
			dst[a + i] = src[i];
			i++;
		}
		dst[a + i] = '\0';
	}
	return (a + b);

}
int main()
{
	char *a= "hello World";
	char *b = "hellohello";
	char *c = "Hello World";
	char *d = "HelloHello";
	printf("%zu\n", ft_strlcat(a, b, 50));
	printf("%s\n", a);
	printf("%zu\n", strlcat(c, d, 50));
	printf("%s\n", c);
	return 0;
}
