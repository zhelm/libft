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
    ft_strdel(econtent);
    *econtent = ft_strdup(tmp);
    ft_strdel(&tmp);
    return 1;
}

int ft_cutter(int rd, char **econtent, char **line, char **buff)
{
    ft_strdel(buff);
    if (ft_strchr(*econtent, '\n'))
        ft_checker(econtent, line);
    else if (rd == 0)
    {
        *line = ft_strdup(*econtent);
        ft_strdel(econtent);
    }
    return 1;
}

int ft_reader(int fd, char **econtent, char **line)
{
    char *buff;
    char *tmp;
    ssize_t rd;

    rd = 1;
    buff = malloc(BUFF_SIZE + 1);
    while (rd > 0)
    { 
        ft_bzero(buff, BUFF_SIZE);
        rd = read(fd, buff, BUFF_SIZE);
        buff[BUFF_SIZE] = '\0';
        if (*econtent == NULL)
            *econtent = ft_strdup(buff);
        else
        {
            tmp = ft_strjoin(*econtent, buff);
            ft_strdel(econtent);
            *econtent = ft_strdup(tmp);
            ft_strdel(&tmp);
        }
        if (**econtent != '\0' && (ft_strchr(*econtent, '\n') || rd == 0))
            return (ft_cutter(rd, &*econtent, line, &buff));
    }
    return 0;
}

int get_next_line(int fd, char **line)
{
    static t_list *head;
    t_list *ptr;

    if (!line || fd < 0 || read(fd, NULL, 0) == -1)
        return (-1);
    ptr = head;
    while (ptr)
    {
        if (ptr->content_size == (size_t)fd)
            break;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        ft_lstadd(&head, ft_lstnew(NULL, 0));
        ptr = head;
        ptr->content_size = (size_t)fd;
    } 
    if (ptr->content != NULL && ft_strchr(ptr->content, '\n') != NULL)
        return ft_checker((char **)&ptr->content, line);
    return (ft_reader(fd, (char **)&ptr->content, line));
}
// #include <time.h>
// int main()
// {
//     int fd1, fd2, fd3;
//     char *line;
//     int i = 0;
//     fd1 = open("libft/Test_texts/test.txt", O_RDONLY);
//     fd2 = open("libft/test2.txt", O_RDONLY);
//     fd3 = open("libft/bible.txt", O_RDONLY);
//     printf("This is one\n");
//     while ((get_next_line(fd1, &line)) == 1)
//     {
//         printf("%s\n", line);
//         ft_strdel(&line);
//     }
//     i = 0;
//     printf("This is two\n");
//     while ((get_next_line(fd2, &line)) == 1 && i < 2)
//     {
//         i++;
//         printf("%s\n", line);
//         ft_strdel(&line);
//     }
//     i = 0;
//     printf("This is one\n");
//     while ((get_next_line(fd1, &line)) == 1 && i < 2)
//     {
//         i++;
//         printf("%s\n", line);
//         ft_strdel(&line);
//     }
//     i = 0;
//     printf("This is 3\n");
//     while ((get_next_line(fd3, &line)) == 1 && i < 2)
//     {
//         i++;
//         printf("%s\n", line);
//         ft_strdel(&line);
//     }
//     ft_strdel(&line);
//     //sleep(30);
  //  return 0;
//}
