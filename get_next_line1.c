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
//static struct g_list	**list(char *llist, int fd)
//{
//determine how to assign different fd's to different lists and to remember them
//}
char *changer(char *lline, size_t count, size_t c)
{
	size_t i;
	size_t a;
	char *tmp;
	char *ret;
	static char *cut;

	i = 0;
	a = 0;
	tmp = NULL;
	ret = NULL;
	while(lline[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * i);
	i = 0;
	while(lline[i] != '\n')
	{
		tmp[i] = lline[i];
		i++;
	}
	ret = ft_strjoin(cut, tmp);
	if((((count - 1) * BUFF_SIZE + c) - i) > 0)
		cut = (char *)malloc(sizeof(char) * ((count - 1) * BUFF_SIZE + c));
	if (cut == NULL)
		return 0;
	while(i < ((count - 1) * BUFF_SIZE + c))
	{
		cut[a] = lline[i];
		a++;
		i++;
	} 
}
char reader(int fd, size_t l, size_t count) //char *lline)
{
	static char *lline;
	size_t i;
	size_t a;
	char *line;//something is wrong here
	char *b1;
	i = 0;
	a = 0;
	line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	read(fd, line, BUFF_SIZE);
	lline = ft_strjoin(lline, line);
	count++;
	while(i < BUFF_SIZE)
	{
		if(line[i] == '\n')
		{
			printf("%s", changer(lline, count, i));
			//printf("%s\n\n", b1);
			//printf("%lu\n", count);
	//		printf("%s\n", lline);
			return (0);
		}
		i++;
	}
	free(line);
	free(lline);
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
	get_next_line(fd1, a);
	get_next_line(fd1, a);
	//get_next_line(fd1, a);
	//get_next_line(fd1, a);
	//get_next_line(fd1, a);
}

