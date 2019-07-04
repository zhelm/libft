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
void  ft_linecutter(char **content, char **line)
{
    char *cut;

    if (ft_strchr(*content, '\n'))
    {
        *line = ft_strcdup(*content, '\n');
    }

}

char *ft_linereader(int fd, char *buff)
{
    size_t i;
    char *rline;
    char *tmp;
    int ret;

    i = 0;
    rline = NULL;
    while((ret = read(fd, buff, BUFF_SIZE) > 0))
    {
        if (rline == NULL)
            rline = ft_strdup(buff);
        else
        {
            tmp = ft_strjoin(rline, buff);
            free(rline);
            rline = ft_strdup(tmp);
            free(tmp);
        }
        if (ft_strchr(rline, '\n') != NULL)
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
//mem leak
    content = NULL;
	if(head == NULL)
		head = ft_lstnew(content, (BUFF_SIZE + 1));
    ptr = head;
	while(ptr->next != NULL && ptr->content_size != fd)
		ptr = ptr->next;
	if (ptr->content_size == fd && ptr->content != NULL)
		content = ptr->content;
	else
	{
		ft_lstadd(&head, ft_lstnew(NULL, (BUFF_SIZE + 1)));
		ptr->content_size = fd;
	}
    buff = ft_memalloc(BUFF_SIZE + 1);
    if (ptr->content == NULL)
        content = ft_linereader(fd, buff);
    else
    {
        tmp = ft_linereader(fd, buff);
        tmp1 = ft_strdup(content);
        free(content);
        content = ft_strjoin(tmp1, tmp);
        free(tmp);
        free(tmp1);
    }
    ft_linecutter(&content, line);
   // if (!(ft_strchr(content, '\n') == content))//if the pointer of the first char of content = to a \n then do the action
        //*line = ft_strcdup(content, '\n');
    //else //----------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MAKE A CUTTING STATEMENT HERE
      //  *line = ft_strnew(1);
//    tmp1 = ft_strdup(ft_strchr(content, '\n') + 1);//still using pointers that point to the same addr
  //  free(ptr->content);
    //content = ft_strdup(tmp1);
    //free(tmp1);
   // printf("%s", ptr->content);
    //I think I need a cheacker to tell me if it is EOF <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-----------------------this one
    return 0;
}
/* The plan is :
    read until new line;
    if no new line is found when read == 0 return the line without new line
    else if a new line is found save excess and return line;
    if new line not found in excess read till it finds new line
 */

int     main()
{
    int fd;
    char *line;
    size_t i;

    i = 0;
    fd = open("test2.txt", O_RDONLY);
    while (i < 21)
    {
        i++;
        printf("\n%lu\n", i);
        get_next_line(fd, &line);
        printf("%s", line);
        free(line);
    }
    sleep (30);
}