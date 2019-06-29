#include "get_next_line.h"

/*size_t checklinenum(char *lline)
{
	size_t i;
	char *current;
	i = 0;
	current = ft_strdup(lline);
	while(*current != '\0')
	{
		if(*current == '\n')
			i++;
		current++;
	}

	//printf("%lu\n", i);
	return (i);
}
char *changer(char *lline, size_t count, size_t i)
{
	char *rline;
	static char *cut = NULL;
	char  *cutbuf;
	size_t a;
	a = 0;
	cutbuf = NULL;
	if (checklinenum(lline) == 1 || count == 0)//This part is super important i.e. super important look closely
		cutbuf = ft_strchr(lline, '\n');
else if(a < checklinenum(lline))
			{
				lline = cut;
				cutbuf = ft_strchr(lline, '\n');
			}
	rline = ft_memalloc(ft_strlen(lline) - ft_strlen(cutbuf) + 1);
	while (lline[a] != '\n')
	{
		rline[a] = lline[a];
		a++;
	}
	if(cut != NULL)
		rline = ft_strjoin(cut, rline);
	cut = ft_strdup(cutbuf + 1);
	printf("cut = %s\n", rline);
	//find a way to use the cut part when buff 

 char reader(int fd, char *lline)
{
	size_t i;
	size_t loop;
	static size_t count = 0;
	char *line;
	int		ret;

	i = 0;
	ret = 1;
	loop = 0;
	lline = ft_memalloc(1);
	line = (char *)ft_memalloc(BUFF_SIZE + 1);
	while (loop == 0 && ret != 0)
	{
		if(count == 0)
			ret = read(fd, line, BUFF_SIZE);
		if (lline != NULL && count == 0)
			lline = ft_strjoin(lline, line);
		else if (count == 0)
			lline = ft_strdup(line);
		//printf("%lu, %lu\n", count, checklinenum(lline)); 
		while(lline[i] || count < checklinenum(lline))
		{
			if (lline[i] == '\n' || count != 0)
			{
				printf("\n%lu\n", checklinenum(lline));
					changer(lline, count, i);
				if (checklinenum(lline) > 1)
					count++;
				return 1;
				//LOOP = 1;
			}
			//printf("\n-\n");
			i++;
		}
		//printf("\n%s\n", lline);
	}
	return -1;
}*/
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
		//printf("%s\n", content);
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
	if (tmp->content_size == fd)
		content = tmp->content;
	else
	{
		ft_lstadd(&head, ft_lstnew(content, (BUFF_SIZE + 1)));
		tmp->content_size = fd;
	}
	if(tmp->content == NULL)
	{
		content = ft_strdup(st_linereader(fd, line, content, rline));
		rline = ft_memalloc(i + 1);
		while (content[i] != '\n')
			i++;
		rline = ft_memcpy(rline, content, i);
		printf("\n1\n%s\n", rline);
		tmp1 = ft_strdup(ft_strchr(content, '\n') + 1);
		free (content);
		if (tmp1)
			tmp->content = tmp1;
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
				rline = ft_memcpy(rline, content, i);
				printf("\n2\n%s\n", rline);
				free(tmp->content);
				tmp->content = NULL;
				tmp->content = ft_strdup(ft_strchr(content, '\n'));
				free(content);
				content = NULL;
				return (rline);
			}
			i++;
		}
		rline = ft_strjoin(content, st_linereader(fd, line, content, rline));
		tmp->content = NULL;
		//free(tmp->content);
		printf("\n3\n%s\n", rline);		
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
	while(i < 3)
	{
		get_next_line(fd, &a);
		i++;
	}
}
