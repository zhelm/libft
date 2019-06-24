#include "get_next_line.h"

char *zero_count
char *changer(char *lline, size_t count, size_t i)
{
	char *rline;
	static char *cut;
	char  *cutbuf;
	size_t a;
	if(count != 0)
	{
		a = 0;
		cutbuf = NULL;
		cutbuf = ft_strchr(lline, '\n');

		rline = ft_memalloc(ft_strlen(lline) - ft_strlen(cutbuf) + 1);
		while (a < ft_strlen(lline) - ft_strlen(cutbuf))
		{
			rline[a] = lline[a];
			a++;
		}
		if(cut != NULL)
			rline = ft_strjoin(cut, rline);
		cut = ft_strdup(cutbuf + 1);
		printf("cut = %s\n", rline);
	}
	else
		return zero_count(lline, i);
}

char reader(int fd, size_t l, size_t count, char *lline)
{
	size_t i;
	size_t loop;
	char *line;//something is wrong here
	char *tmp;

	i = 0;
	loop = 0;
	lline = ft_memalloc(1);
	line = (char *)ft_memalloc(BUFF_SIZE + 1);
	while(loop == 0)
	{
		read(fd, line, BUFF_SIZE);
		if (tmp != NULL)
			lline = ft_strjoin(lline, line);
		else
		{
			tmp = line;
			lline = ft_strdup(line);
		}
		while(lline[i])
		{
			if (lline[i] == '\n')
			{
				changer(lline, count, i);
				loop = 1;
			}
			i++;
		}
		count++;
	}
	return -1;
}
int get_next_line(int fd, char **line)
{
	size_t l;
	size_t count;
	char *lline;

	count = 0;
	reader(fd, l, count, lline);
	return 0;
}

int main()
{
	char *a;
	int fd;
	size_t i;

	i = 0;

	fd = open("text.txt", O_RDONLY);
	while(i < 14)
	{
		get_next_line(fd, &a);
		i++;
	}
}
