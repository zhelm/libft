/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:15:19 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/18 14:14:57 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "libft.h"

size_t ft_strlen(const char *c)
{
	size_t i;

	i = 0;
	while(c[i])
		i++;
	return i;
}
size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t a;
	size_t b;

	a = 0;
	i = 0;
	b = ft_strlen(src);
	while(dst[a] && a < dstsize)
		a++;
	if(a + 1 + i < dstsize)
	{
		while(a + 1 + i < dstsize && src[i])
		{
			dst[a + i] = src[i];
			i++;
		}
		dst[a + i] = '\0';
	}
	return (a + b);
}

int get_next_line(const int fd, char **line)
{
	static size_t l;
	size_t d;
	size_t i;
	static char *b1;
	static size_t a;

	i = 0;
	d = 0;
	line = (char**)malloc(sizeof(char *));
	*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 2));
	b1 = (char *)malloc(sizeof(char) * (BUFF_SIZE + 2));
	read(fd, line[0], BUFF_SIZE);
	while(i < BUFF_SIZE)
	{
		if(a == l)
		{
			printf("%c", line[0][i]);
			if(line[0][i] == '\n' || line[0][i] == EOF)
			{
				while(i < BUFF_SIZE)
				{
					*b1 = line[0][i] ;
					i++;
					b1++;
				}
				l++;
				a++;
				return 0;
			}
		}
		else if(line[0][i] == '\n' && a != l)
			a++;
			//problem lies with line[0] it includes the new line and lets say H so when it is \nH it sees '\n' and discards H. Need to find a way to detecct if the \n is inside the bufffer or at the end, try and get strlen of string an d then if '\n' is found before the end of the string then start the strsub at that point and len of that would be strlen - start;
		i++;
	}
	free(line[0]);
	get_next_line(fd, line);
	return 1;
}
int main()
{
	size_t i;

	i = 0;
	int fd;
	char **a;
	a = NULL;
	fd = open("text.txt", O_RDONLY);
	//	read(fd, c, BUFF_SIZE);
	//	c[18] = 127;
	//	printf("%s", c);
		get_next_line(fd, a);
		get_next_line(fd, a);
		get_next_line(fd, a);
//		get_next_line(fd, a);
	}
