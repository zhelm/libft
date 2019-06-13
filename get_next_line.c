/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:15:19 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/13 10:31:08 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
//int get_next_line(const int fd, char **line)
//{}


int main()
{
	int fd, sz;
	char *c; 
	fd = open("test", O_RDONLY, 0);
	sz = read(fd, c, 10);
	printf("%d\n%d\n", fd, sz);
}
