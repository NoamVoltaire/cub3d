/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_newline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:58:03 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 13:58:06 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
