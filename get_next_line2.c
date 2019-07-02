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

char *st_read(int fd, char **line)
{
    size_t i;
    size_t a;
    char *tmp;
    char *holder;
    char *buff;
    int loop;

    loop = 0;
    i = 0;
    a = 0;
    buff = ft_strnew(BUFF_SIZE + 1);
    while(loop == 0)
    {
        a++;
        printf("%lu", a);
        ft_memset(buff, '\0', (BUFF_SIZE + 1));
        read(fd, buff, BUFF_SIZE);
        printf("%s\n", buff);
        if (!holder)
            holder = ft_strdup(buff);
        else
        {
            tmp = ft_strjoin(holder, buff);
           // printf("HELLO%s", tmp);
            free(holder);
            holder = ft_strdup(tmp);
            free(tmp);
        }
        while (holder[i] != '\0')//checker
        {
            if (holder[i] == '\n')
                loop = 1;
            i++;
        }
    }
    printf("%s", holder);
    return (holder);
}

int     get_next_line(int fd, char **line)
{
    static t_list *head;
    t_list *tmp;
    char *content;
    char *tmp1;

    if (!head)
        head = ft_lstnew(NULL, 0);
    tmp = head;
    while (tmp->next != NULL && tmp->content_size != fd)
        tmp = tmp->next;
    if (tmp->content_size == fd)
        content = ft_strdup(tmp->content);
    else
    {
        ft_lstadd(&head, ft_lstnew(NULL, 0));
        tmp->content_size = fd;
    }
    printf("%s", st_read(fd, line));
    return 0;
}

int     main()
{
    int fd;
    char *line;

    fd = open("test2.txt", O_RDONLY);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
  //  printf("%s", line);
}