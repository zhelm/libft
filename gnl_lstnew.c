#include "get_next_line.h"

h_list	*gnl_lstnew(int lst_num, void const *content, size_t fd)
{
	h_list *new;

	if (!(new = (h_list *)malloc(sizeof(h_list))))
		return (NULL);
	if (content == NULL)
	{
        new->lst_num = 0;
		new->content = NULL;
		new->fd = 0;
	}
	else
	{
		if (!(new->content = malloc(ft_strlen(content))))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, ft_strlen(content));
		new->fd = fd;
        new->lst_num = 0;
	}
	new->next = NULL;
	return (new);
}