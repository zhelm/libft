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

char *ft_linereader(int fd, char *buff)
{
    size_t i;
    char *rline;
    char *tmp;
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
        {
            tmp = ft_strjoin(rline, buff);
            free(rline);
            rline = ft_strdup(tmp);
            free(tmp);
        }
        if (ft_strchr(buff, '\n') != NULL)
            return rline;
    }
    return rline;
}

int get_next_line(int fd, char **line)
{
    static t_list *head;
    t_list *ptr;
    char *buff;
    char *content;
    char *tmp;
    char *tmp1;

    if (!line || fd < 0 || read(fd, NULL, 0) == -1)
        return (-1);
    content = NULL;
	if(head == NULL)
		head = ft_lstnew(content, (BUFF_SIZE + 1));
    ptr = head;
	while(ptr->next != NULL && ptr->content_size != (unsigned)fd)
		ptr = ptr->next;
	if (ptr->content_size == (unsigned)fd && ptr->content != NULL)
		content = ptr->content;
	else
	{
		ft_lstadd(&head, ft_lstnew(NULL, (BUFF_SIZE + 1)));
		ptr->content_size = fd;
	}
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
int     main()
{
    int fd;
    char *line;
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
}