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














#endif
