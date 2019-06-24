/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:04:46 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/24 15:19:44 by zhelm            ###   ########.fr       */
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
	tmp = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while(lline[i] != '\n')
	{
		tmp[i] = lline[i];
		i++;
	}
	tmp[i] = '\0';
	//	printf(" ret = %s\n", cut);
	//	printf("cut = %s\n", cut);
	if (!cut && cut != NULL)
		ret = ft_strcpy(cut, tmp);
	else
		ret = tmp;
	if((((count - 1) * BUFF_SIZE + c) - i) > 0)
		cut = (char *)malloc(sizeof(char) * ((count - 1) * BUFF_SIZE + c));
	while(i < ((count - 1) * BUFF_SIZE + c))
	{
		cut[a] = lline[i];
		a++;
		i++;
	}
	// printf("cut = %s\n", cut);
	return ret;
}

char *st_strend(char *c)
{
	char *b;
	size_t i;

	i = 0;
	b = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while(i < BUFF_SIZE)
	{
		b[i] = c[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}

char reader(int fd, size_t l, size_t count, char **lline)
{
	size_t i;
	size_t loop;
	char *cut;
	char *line;//something is wrong here
	char *tmp;

	i = 0;
	loop = 0;
	lline = ft_memalloc(1);
	line = NULL;
	line = (char *)ft_memalloc(BUFF_SIZE);
	while(loop == 0)
	{
	//	read(fd, line, BUFF_SIZE);
	//	lline = ft_strjoin(lline, line);
	//	printf("%s", lline);
		i = 0;
		read(fd, line, BUFF_SIZE);
		tmp = ft_strjoin(*lline, line);
		free(*lline);
		*lline = ft_strdup(tmp);
		while(line[i] != '\n' && i < BUFF_SIZE)
		{
			if(line[i] == '\n')
				loop = 1;
			i++;
		}
		free(tmp);
	}
	//printf("%s", cut);
	//reader(fd, l, count, lline);// lline);
	return -1;
}
int get_next_line(int fd, char **line)
{
	size_t l;
	size_t count;
	char *lline;

	count = 0;
	reader(fd, l, count, &lline);
	return 0;
}

int main()
{
	int fd;
	char **line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, line);
	//	get_next_line(fd, line);
	//	get_next_line(fd, line);
}























