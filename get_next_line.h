#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFF_SIZE 1

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct	h_list
{
    int             lst_num;
	void			*content;
	size_t			fd;
	struct s_list	*next;
}				h_list;


int     get_next_line(const int fd, char **line);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);












#endif
