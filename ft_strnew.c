/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:51:58 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/28 10:26:42 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	char *a;
	a =	malloc(sizeof(char) * (size + 1));
	if(a == NULL)
		return NULL;
	return (ft_memset(a, '\0', size));
}
