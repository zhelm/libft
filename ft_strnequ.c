/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:31:39 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/28 08:38:09 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
	return(ft_strncmp(s1, s2, n) ? 0 : 1);
}

int main()
{
	const char *s = "Hello World";
	const char *a = "Hello World";
	printf("%d", ft_strnequ(s, a, 15));
}
