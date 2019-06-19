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
static struct g_list	**list(char *llist, int fd)
{
	//determine how to assign different fd's to different lists and to remember them
}
char *assigner(size_t i, size_t count, char **line, size_t l)
{

}
char reader(int fd, size_t l, size_t count)
{
	size_t i;
	char *lline;
	i = 0;
	lline = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	read(fd, lline, BUFF_SIZE);

	count++;
	while(i < BUFF_SIZE)
	{
		if(lline[i] == '\n')
		{
			printf("%lu\n", count);
			return (0);
		}
		i++;
	}
	lline = NULL;
	reader(fd, l, count);
}
int get_next_line(int fd, char **line)
{
	size_t l;
	size_t count;

	count = 0;
	reader(fd, l, count);
	return 0;
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
