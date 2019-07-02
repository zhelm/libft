#include "get_next_line.h"

char *st_linereader(int fd, char *line, char *content, char *rline)
{
	size_t i;
	int loop;
	char *tmp;

	i = 0;
	loop = 0;
	tmp = NULL;
	line = (char *)ft_memalloc(BUFF_SIZE + 1);
	if (content == NULL)
		content = ft_memalloc(1);
	while (loop == 0)
	{
		read(fd, line, BUFF_SIZE);
		if(content == NULL)
			content = ft_strdup(line);
		else if(content != NULL)
			content = ft_strjoin(content, line);
		while(content[i] != '\0' && loop != 1)
		{
		 	if (content[i] == '\n')
				loop = 1;
			else					
				i++;
		}
	}
	printf("content = %s\n", content);
return content;
}
			
char *st_cutter(int fd, char *line)
{
	static t_list *head;
	char *content;
	char *rline;
	char *tmp1;
	size_t i;
	t_list *tmp;

	content = NULL;
	if(head == NULL)
		head = ft_lstnew(content, (BUFF_SIZE + 1));
	tmp = head;
	i = 0;
	while(tmp->next != NULL && tmp->content_size != fd)//goes through the loop to find fd
		tmp = tmp->next;
	if (tmp->content_size == fd && tmp->content != NULL)
	{
		content = ft_strdup(tmp->content);
	//	printf("%s",content);
	}
	else
	{
		ft_lstadd(&head, ft_lstnew(content, (BUFF_SIZE + 1)));
		tmp->content_size = fd;
	}
	if(tmp->content == NULL)
	{
		content = ft_strdup(st_linereader(fd, line, content, rline));
		while (content[i] != '\n')
			i++;
		rline = ft_memalloc(i + 1);
		rline = ft_memcpy(rline, content, i);
		//printf("%s", content);
		tmp->content = ft_strdup(ft_strchr(content, '\n') + 1);
		return 0;
	}
	else if (tmp->content != NULL)
	{
		i = 0;
		content = ft_strdup(tmp->content);
		//printf("%s", content);
		while (content[i])
		{
			if (content[i] == '\n')
			{
				rline = ft_strcdup(content, '\n');
				free(tmp->content);
				tmp->content = ft_strdup(ft_strchr(content, '\n') + 1);
				//printf("rline = %s|", rline);
				return (0);
			}
			i++;
		}
		rline = ft_strdup(content);
		free(content);
		tmp1 = st_linereader(fd, line, content, rline);
		rline = ft_strdup(ft_strjoin(rline, ft_strcdup(tmp1, '\n')));
		content = ft_strdup(ft_strchr(tmp1, '\n') + 1);
		printf("r line = %s", rline);

		//for some wierd reason I am losing 4 characters when I join them
		//if (!(tmp->content = ft_strchr(tmp1, '\n') + 1))
			//free(tmp->content);
		//access current excess buffer and buffer after the read.
		//printf("\n3rline =%s|\n", rline);
	}
	return 0;
}		
int get_next_line(int fd, char **line)
{
	size_t l;
	size_t count;
	char *lline;
	st_cutter(fd, lline);
	count = 0;
	return 0;
}
int main()
{
	char *a;
	int fd;
	size_t i;

	i = 0;

	fd = open("text.txt", O_RDONLY);
	while(i < 20)
	{
		printf ("i = %lu\n", i);
		get_next_line(fd, &a);
		i++;
	}
}