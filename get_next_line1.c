/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:04:46 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/20 13:30:10 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*static struct g_list	**list(char *llist, int fd)
{
	//determine how to assign different fd's to different lists and to remember them
}
char *assigner(size_t i, size_t count, char **line, size_t l)
{

}*/
char reader(int fd, size_t l, size_t count) //char *lline)
{
	static char *lline;
	size_t i;
	char *line;//something is wrong here
	i = 0;
	line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	read(fd, line, BUFF_SIZE);
	lline = ft_strjoin(lline, line);
	count++;
	while(i < BUFF_SIZE)
	{
		if(line[i] == '\n')
		{
			printf("%lu\n", count);
			printf("%s\n", lline);
			return (0);
		}
		i++;
	}
	free(line);
	reader(fd, l, count);// lline);
	return -1;
}
int get_next_line(int fd, char **line)
{
	size_t l;
	size_t count;
	char *lline;

	lline = NULL;
	count = 0;
	reader(fd, l, count);// lline);
	return 0;
}
int main()
{
	int fd1, fd2;
	char **a;
	a = NULL;
	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text1.txt", O_RDONLY);
	get_next_line(fd1, a);
	get_next_line(fd2, a);
	get_next_line(fd1, a);
	get_next_line(fd2, a);
}
