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

int ft_reader(int fd, char **econtent, char **line)
{
    char *buff;
    char *tmp;
    ssize_t rd;

    rd = 1;
    while(rd > 0)
    {
        buff = ft_memalloc(BUFF_SIZE);
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
        ft_bzero(buff, BUFF_SIZE);
        free(buff);
    if((ft_strlen(*econtent) != 0 && ft_strchr(*econtent, '\n')) || (ft_strlen(*econtent) != 0 && rd == 0))
        return(ft_cutter(rd, &*econtent, line));
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
		head = ft_lstnew(econtent, (BUFF_SIZE + 1));
    ptr = head;
	while(ptr->next != NULL && ptr->content_size != fd)
		ptr = ptr->next;
	if (ptr->content_size == fd && ptr->content != NULL)
		econtent = ptr->content;
	else
	{
		ft_lstadd(&head, ft_lstnew(NULL, (BUFF_SIZE + 1)));
		ptr->content_size = fd;
	}
   
    return (ft_reader(fd, (char **)&ptr->content, line));
}

int     main()
{
    int fd;
    char *line;
    int ret;
    ret = 1;
 
    fd = open("test2.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        printf("ret = %d\n", ret);
        printf("%s\n", line);
        free(line);
    }
    return 0;
    //sleep (30);
}