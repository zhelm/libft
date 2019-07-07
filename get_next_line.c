/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:20:10 by zhelm             #+#    #+#             */
/*   Updated: 2019/06/13 08:48:23 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_checker(char **econtent, char **line)
{
    char *tmp;

    *line = ft_strcdup(*econtent, '\n');
    tmp = ft_strdup(ft_strchr(*econtent, '\n') + 1);
    free(*econtent);
    *econtent = ft_strdup(tmp);
    free(tmp);
    return 1;
}

int     ft_cutter(int rd, char **econtent, char **line, char **buff)
{
  //  free(*buff);
    if(*econtent && ft_strchr(*econtent, '\n'))
    {
     ft_checker(econtent, line);
    }
    else if (rd == 0)
    {
        *line = ft_strdup(*econtent);
        free(*econtent);
    }
    return 1;
}

int ft_reader(int fd, char **econtent, char **line)
{
    char *buff;
    char *tmp;
    ssize_t rd;

    rd = 1;
    buff = ft_memalloc(BUFF_SIZE);
    while(rd > 0)//I think I need to put check in gnl
    {
        ft_bzero(buff, BUFF_SIZE);
        rd = read(fd, buff, BUFF_SIZE);
        if (*econtent == NULL && rd != 0)
            *econtent = ft_strdup(buff);
        else if (rd != 0)
        {
            tmp = ft_strjoin(*econtent, buff);
            free(*econtent);
            *econtent = ft_strdup(tmp);
            free(tmp);
        }
    if((ft_strlen(*econtent) != 0 && ft_strchr(*econtent, '\n')) || (ft_strlen(*econtent) != 0 && rd == 0))
        return(ft_cutter(rd, &*econtent, line, &buff));
    }
    return 0;
}

int get_next_line(int fd, char **line)
{
    static t_list *head;
    t_list *ptr;
    char *econtent;

    if (!line || fd < 0 || read(fd, NULL, 0) == -1)
        return (-1);
    econtent = NULL;
	if(head == NULL)
    {
		head = ft_lstnew(econtent, (BUFF_SIZE + 1));
		ft_lstadd(&head, ft_lstnew(NULL, (BUFF_SIZE + 1)));
    }
    ptr = head;
	while(ptr->next != NULL && ptr->content_size != fd)
		ptr = ptr->next;
	if (ptr->content_size == fd && ptr->content != NULL)
		econtent = ptr->content;        
	else
		ptr->content_size = fd;
    if(ft_strlen(econtent) != 0 && ft_strchr(econtent, '\n') != NULL)
        return ft_checker((char **)&ptr->content, line);
    return (ft_reader(fd, (char **)&ptr->content, line));
}
# include <time.h>
int     main()
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int fd;
    char *line;
    int ret;
    ret = 1;
    int i = 0;

    fd = open("bible.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        i++;
      //  printf("ret = %d\n", ret);
        printf("%s\n", line);
        free(line);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time = %f", cpu_time_used);
    
    return 0;
    //sleep (30);
}