/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:04:46 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/19 13:50:27 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *assigner(char *, char **line, size_t l)
{

}
char reader(int fd, char **line, size_t l)
{

	read(fd, line[l], BUFF_SIZE);
}
int get_next_line(int fd, char **line)
{
	static size_t l;

	line = 
}
int main()
{
	int fd;
	char **a;
	a = NULL;
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, a);
	get_next_line(fd, a);
	get_next_line(fd, a);
	get_next_line(fd, a);
	get_next_line(fd, a);
	get_next_line(fd, a);
	get_next_line(fd, a);
}
