#include "get_next_line.h"

char *st_linereader(int fd, char *line, char *content, char *rline)
{
	size_t i;
	int loop;

	i = 0;
	loop = 0;
	line = (char *)ft_memalloc(BUFF_SIZE + 1);
	content = ft_memalloc(1);
	while (loop == 0)
	{
		read(fd, line, BUFF_SIZE);
		if(content == NULL)
			content = ft_strdup(line);
		else if(content != NULL)
			content = ft_strjoin(content, line);
		printf("%s\n", content);
		while(content[i] != '\0' && loop != 1)
		{
		 	if (content[i] == '\n')
				loop = 1;					
			i++;
		}
	}
	return (content);
}
			
char *st_cutter(int fd, char *line)
{
	static t_list *head;
	char *content;
	char *rline;
	char *tmp1;
	int loop;
	size_t i;
	t_list *tmp;

	content = NULL;
	if(head == NULL)
		head = ft_lstnew(content, (BUFF_SIZE + 1));
	tmp = head;
	//head->next;
	//ft_lstadd(head, ft_lstnew(line, b))
	loop = 0;
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
	//printf("%s|\n", content);
	if(tmp->content == NULL)
	{
		content = ft_strdup(st_linereader(fd, line, content, rline));
		while (content[i] != '\n')
			i++;
		rline = ft_memalloc(i + 1);
		rline = ft_memcpy(rline, content, i);
		//printf("\n1\n%s\n", rline);
		if (*(tmp1 = ft_strdup(ft_strchr(content, '\n') + 1)) == '\n')
				return 0;
		free (content);
		if (tmp1)
			tmp->content = ft_strdup(tmp1);
		printf("rline = %s|\n", rline);
		//printf("tmp = %s\n", tmp->content);
		return 0;
	}
	else if (tmp->content != NULL)
	{
		//printf("Between ifs = %s\n", content);
		i = 0;
		while (content[i])
		{
			//printf("Passes while\n");
			if (content[i] == '\n')
			{
				rline = ft_memalloc(i + 1);
				//printf("content = %s\n\n\n", content);
				rline = ft_memcpy(rline, content, i);	
		//		printf("\n2\n%s\n", rline);
				free(tmp->content);
				//tmp->content = NULL;
				//printf("%s", content);
				tmp->content = ft_strdup(ft_strchr(content, '\n'));
				//free(content);
				//content = NULL;
				printf("rline = %s|\n", rline);
			//	printf("tmp = %s\n", tmp->content);
				return (rline);
			}
			i++;
		}
		//printf("%s", content);
		//printf("%s", st_linereader(fd, line, content, rline));
		rline = ft_strjoin(content, st_linereader(fd, line, content, rline));
		tmp->content = NULL;
		printf("rline =%s|\n", rline);
		free(tmp->content);
	//	printf("\n3\n%s\n", rline);		
	}
	//else
	//{
	//	printf("%s", tmp->content);
	//}
	
	return 0;
}		
	/* char *content;
	size_t content_size;
	int loop;

	loop = 0;
	while(loop == 0)
	{
		loop = 1;		
	}

	head = ft_lstnew(content, fd);
}*/
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
