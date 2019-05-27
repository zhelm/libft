/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:51:58 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/27 13:50:41 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	char *a;
	a = NULL;
	if(size <= 0)
		return NULL;
	a =	malloc(sizeof(char) * (size + 1));
	if(a == NULL)
		return NULL;
	return (ft_memset(a, '\0', size));
}
