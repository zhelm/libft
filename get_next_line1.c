/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:04:46 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/21 09:54:31 by zhelm            ###   ########.fr       */
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
	printf(" ret = %s\n", cut);
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
   printf("cut = %s\n", cut);
	return ret;
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
	if(lline != NULL)
        lline = ft_strjoin(lline, line);
    else
    {
      //  line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
        lline = line;
    }
	count++;// count only stops after 104019 times. count Does not stop for some reason
	printf("%sHello", lline);
	while(i < BUFF_SIZE && count != 3)
	{
		if(line[i] == '\n')
		{
		//	printf("%s\n\n\n", lline);
			printf("new %s\n", changer(lline, count, i));
			lline = NULL;
			//printf("%s\n\n", b1);
			//printf("%lu\n", count);
//			printf("%s\n", lline);
			return (0);
		}
		i++;
	}
	if (count == 3)
        return 0;
	free(line);
//	free(lline);
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


