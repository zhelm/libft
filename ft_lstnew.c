t_list *ft_lstnew(void const *content, size_t content size)
{
	t_list new;

	new = (t_list *)malloc(sizeof(t_list) * content);
	if(content == NULL)
	{
		new->content = NULL;
		new->content = 0;
	}
	else
	{
		new->content = malloc(content_size);
		if (new->content == NULL)
			return NULL:
		ft_memmove(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return(new);
}
