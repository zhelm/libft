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
    *econtent = NULL;
    free(*econtent);
    *econtent = ft_strdup(tmp);
    free(tmp);
    return 1;
}

int     ft_cutter(int rd, char **econtent, char **line, char **buff)
{
    free(*buff);
    if(*econtent && ft_strchr(*econtent, '\n'))
        ft_checker(econtent, line);
    else if (rd == 0)
    {
      //  printf("it gets here\n\n\n\n\n\n\n\n\n\n\n\n\n");
        *line = ft_strdup(*econtent);
        *econtent = NULL;
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
    buff = ft_memalloc(BUFF_SIZE + 1);
    ft_bzero(buff, BUFF_SIZE);

    while(rd > 0)
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
    *line = NULL;
    return 0;
}

int get_next_line(int fd, char **line)
{
    static char *head;
   // t_list *ptr;
    char *econtent;

    if (!line || fd < 0 || read(fd, NULL, 0) == -1)
        return (-1);
    econtent = NULL;
    if(head != NULL)
        econtent = ft_strdup(head);
	// if(head == NULL)
    // {
	// 	head = ft_lstnew(econtent, (BUFF_SIZE + 1));
    //     head->content_size = (size_t)fd;
    // }
    // ptr = head;
	// while(ptr->next != NULL && ptr->content_size != (size_t)fd)
	// 	ptr = ptr->next;
	// if (ptr->content_size == (size_t)fd && ptr->content != NULL)
	// 	econtent = ptr->content;        
    // // else
    //     // ptr->content_size = fd;
    if(ft_strlen(econtent) != 0 && ft_strchr(econtent, '\n') != NULL)
        return ft_checker(&head, line);
    if (ft_reader(fd, &head, line) == 0)
    {
        free(head);
        return 0;
    }
    return 1;
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
    fd = open("libft/test.txt", O_RDONLY);
    while ((get_next_line(fd, &line)) == 1)
    {
        i++;
    //    printf("ret = %d\n", ret);
       printf("%s\n", line);
       line = NULL;
       free(line);
       if(ret == 0)
       break;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("time = %f", cpu_time_used);
    
  
    sleep (30);
      return 0;
}