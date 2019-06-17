#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFF_SIZE 2

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

typedef struct	a_list
{
//	static int	fd;
	int	line_num;
	char		*line;
	struct a_list	*next_line;
}		g_line;

int get_next_line(const int fd, char **line);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);












#endif
