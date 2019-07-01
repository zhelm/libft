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
		content = ft_strdup(tmp->content);
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
		printf("%s", content);
		tmp->content = ft_strdup(ft_strchr(content, '\n') + 1);
		return 0;
	}
	else if (tmp->content != NULL)
	{
		i = 0;
		while (content[i])
		{
			if (content[i] == '\n')
			{
				rline = ft_memalloc(i + 1);
				rline = ft_strcdup(content, '\n');
				free(tmp->content);
				tmp->content = ft_strdup(ft_strchr(content, '\n'));
				printf("rline = %s|\n", rline);
				return (0);
			}
			i++;
		}
		tmp1 = st_linereader(fd, line, content, rline);
		while (tmp1[i])
			i++;
		rline = ft_strdup(ft_strjoin(content, ft_strsub(tmp1, 0, i)));
		free(tmp->content);
		//access current excess buffer and buffer after the read.
		printf("rline =%s|\n", rline);
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