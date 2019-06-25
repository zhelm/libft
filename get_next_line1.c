#include "get_next_line.h"

size_t checklinenum(char *lline)
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
	else
		if(a < checklinenum(lline))
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
	//find a way to use the cut part when buff is big
	return 0;
}

char reader(int fd, char *lline)
{
	size_t i;
	size_t loop;
	static size_t count = 0;
	char *line;//something is wrong here
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
		while(lline[i])
		{
			if (lline[i] == '\n')
			{
				printf("\n%lu\n", checklinenum(lline));
				if(loop == 0)
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
}
int get_next_line(int fd, char **line)
{
	size_t l;
	size_t count;
	char *lline;

	count = 0;
	reader(fd, *line);
	return 0;
}

int main()
{
	char *a;
	int fd;
	size_t i;

	i = 0;

	fd = open("text.txt", O_RDONLY);
	while(i < 10)
	{
		get_next_line(fd, &a);
		i++;
	}
}
