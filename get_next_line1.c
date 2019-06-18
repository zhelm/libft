/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:04:46 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/18 14:14:11 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t st_linelen(int fd, char **line, size_t l, size_t count)
{
	size_t i;

	i = 0;
	line = (char **)malloc(sizeof(char **) * (BUFF_SIZE + 1));
	*line = (char *)malloc(sizeof(char *) * (BUFF_SIZE + 1));
	read(fd, line[l], BUFF_SIZE);
	while(line[l][i] != '\n' && i < BUFF_SIZE)
	{
		count++;
		i++;
	}
	if(line[l][i] == '\n')
	{
		printf("%lu", count);
		return count;
	}
	line = NULL;
	st_linelen(fd, line, l, count);
	return 123456;
}

int get_next_line(int fd, char **line)
{
	static size_t l;
	size_t i;
	size_t a;
	size_t count;
	struct a_list **test;
	char *b1;

	i = 0;
	a = 0;
	count = 0;
	b1 = (char *)malloc(sizeof(char *) * (BUFF_SIZE + 1));
	line = (char **)malloc(sizeof(char **));
	*line = (char *)malloc(sizeof(char *) * (BUFF_SIZE +1));
	a = st_linelen(fd, line, l, count);
	return 0;
}

int main()
{
	int fd;
	char **a;
	a = NULL;
	fd = open("text.txt", O_RDONLY);
//	get_next_line(fd, a);
//	get_next_line(fd, a);
	get_next_line(fd, a);
}
