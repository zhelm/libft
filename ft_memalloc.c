/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 07:48:05 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/27 15:22:24 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memalloc(size_t size)
{
	void *ptr;

	if(size <= 0)
		return NULL;
	ptr = (void*)malloc(size);
	ft_memset(ptr, 0, size);
	return ptr;
}
