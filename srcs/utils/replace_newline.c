#include <cub.h>

void	replace_newlines(t_list *lst)
{
	char	*ptr;

	while (lst)
	{
		ptr = ft_strchr((char *)lst->content, '\n');
		if (ptr)
			*ptr = '\0';
		lst = lst->next;
	}
}
