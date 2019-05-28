/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:20:10 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/28 13:50:50 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s)
{
	size_t len;
	size_t start;

	start = 0;
	len = 0;
	while(s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while(s[len])
		len++;
	len--;
	while(s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len--;
	return (ft_strsub(s, start, len));
}

int main()
{
	char const *s = "  Hello it is me ";
	printf("%s", ft_strtrim(s));
}
