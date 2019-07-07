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
<<<<<<< HEAD

int     ft_cutter(int rd, char **econtent, char **line)
{
    char *tmp;
    if(*econtent && ft_strchr(*econtent, '\n'))
    {
        //join is not proper
        *line = ft_strcdup(*econtent, '\n');
        tmp = ft_strdup(ft_strchr(*econtent, '\n') + 1);
        free(*econtent);
        *econtent = ft_strdup(tmp);
        free(tmp);
    }
   // printf("between");
    else if (rd == 0)
    {
     //   printf("Hello I get here\n");
        *line = ft_strdup(*econtent);
        free(*econtent);
    }
    return 1;
}
=======
>>>>>>> edac758106a1885c9d6fb7a488d94f2c1bcbbcfa

int ft_reader(int fd, char **econtent, char **line)
{
    char *buff;
    char *tmp;
<<<<<<< HEAD
    ssize_t rd;

    rd = 1;
    while(rd > 0)
    {
        buff = ft_memalloc(BUFF_SIZE);
        rd = read(fd, buff, BUFF_SIZE);
        if (*econtent == NULL && rd != 0)
            *econtent = ft_strdup(buff);
        else if (rd != 0)
=======
    ssize_t ret;

    i = 0;
    ret = 1;
    rline = NULL;
    while(ret > 0)
    {
        ft_bzero(buff, BUFF_SIZE);
        ret = read(fd, buff, BUFF_SIZE);
        if (rline == NULL && ret != 0)
            rline = ft_strdup(buff);
        else if (ret != 0)
>>>>>>> edac758106a1885c9d6fb7a488d94f2c1bcbbcfa
        {
          
            tmp = ft_strjoin(*econtent, buff);
            free(*econtent);
            *econtent = ft_strdup(tmp);
            free(tmp);
        }
<<<<<<< HEAD
        ft_bzero(buff, BUFF_SIZE);
        free(buff);
    if((ft_strlen(*econtent) != 0 && ft_strchr(*econtent, '\n')) || (ft_strlen(*econtent) != 0 && rd == 0))
        return(ft_cutter(rd, &*econtent, line));
    return 0;
=======
        if (ft_strchr(buff, '\n') != NULL)
            return rline;
>>>>>>> edac758106a1885c9d6fb7a488d94f2c1bcbbcfa
    }
    return -1;
}

int get_next_line(int fd, char **line)
{
    static t_list *head;
    t_list *ptr;
    char *econtent;

    if (!line || fd < 0 || read(fd, NULL, 0) == -1)
        return (-1);
<<<<<<< HEAD
    econtent = NULL;
=======
    content = NULL;
>>>>>>> edac758106a1885c9d6fb7a488d94f2c1bcbbcfa
	if(head == NULL)
		head = ft_lstnew(econtent, (BUFF_SIZE + 1));
    ptr = head;
	while(ptr->next != NULL && ptr->content_size != (unsigned)fd)
		ptr = ptr->next;
<<<<<<< HEAD
	if (ptr->content_size == fd && ptr->content != NULL)
		econtent = ptr->content;
=======
	if (ptr->content_size == (unsigned)fd && ptr->content != NULL)
		content = ptr->content;
>>>>>>> edac758106a1885c9d6fb7a488d94f2c1bcbbcfa
	else
	{
		ft_lstadd(&head, ft_lstnew(NULL, (BUFF_SIZE + 1)));
		ptr->content_size = fd;
	}
<<<<<<< HEAD
    return (ft_reader(fd, (char **)&ptr->content, line));
}

=======
    if (ptr->content && read(fd, NULL, 0) == 0)
    {
        if (ft_strchr(ptr->content, '\n'))
        {
            *line = ft_strcdup(ptr->content, '\n');
            tmp = ft_strdup(ft_strchr(ptr->content, '\n'));
            free(ptr->content);
            ptr->content = ft_strdup(tmp);
            free(tmp);
        }
        else
        {
            *line = ft_strdup(ptr->content);
            free(ptr->content);
            return 0;
        }
        return 1;
    }
    if(ptr->content == NULL && read(fd, NULL, 0) > 0)
    {
        ptr->content = ft_linereader(fd, buff);
        if (ft_strchr(ptr->content, '\n'))
        {
            *line = ft_strcdup(ptr->content, '\n');
            tmp = ft_strdup(ft_strchr(ptr->content, '\n'));
            free(ptr->content);
            ptr->content = ft_strdup(tmp);
        }
        return 1;
    }
    if (ptr->content == NULL && read(fd, NULL, 0) == 0)
    {
        return 0;
    }
}
>>>>>>> edac758106a1885c9d6fb7a488d94f2c1bcbbcfa
int     main()
{
    int fd;
    char *line;
<<<<<<< HEAD
    int ret;
    ret = 1;
    fd = open("bible.txt", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("ret = %d\n", ret);
        printf("%s\n", line);
       free(line);
    }
    return 0;
    sleep (30);
=======
    size_t i;
    int ret = 1;
    i = 0;
    fd = open("test2.txt", O_RDONLY);
    while (ret > 0)
    {
        i++;
        printf("%lu\n", i);
        ret = get_next_line(fd, &line);
        printf("%s\n", line);
        free(line);
    }
  //  sleep(30);
>>>>>>> edac758106a1885c9d6fb7a488d94f2c1bcbbcfa
}