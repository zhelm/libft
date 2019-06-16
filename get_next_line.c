/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:15:19 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/14 08:54:58 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "libft.h"

int get_next_line(const int fd, char **line)
{
	static int l;
	size_t i;
	char *b1;
	static int a;

	i = 0;
	line = (char**)malloc(sizeof(char *));
	*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	read(fd, line[0], BUFF_SIZE);
	b1 = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_strlcat(b1, line[0], BUFF_SIZE);
	while(i < BUFF_SIZE)
	{
		if(a == l)
		{
			printf("%c", line[0][i]);
			if(line[0][i] == '\n' || line[0][i] == EOF)
			{
				l = l + 1;
				return 0;
			}
		}
		else if(line[0][i] == '\n')
			a++;
		i++;
	}
	line = NULL;
	get_next_line(fd, line);
}
int main()
{
	size_t i;

	i = 0;
	int fd, sz;
	char **a;
	fd = open("text.txt", O_RDONLY);
	//	read(fd, c, 50);
	//	c[18] = 127;
	//	printf("%s", c);
	while(i < 4)
	{
		get_next_line(fd, a);
		i++;
	}
}
