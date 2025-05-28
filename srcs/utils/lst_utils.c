/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:51:48 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 13:18:43 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

size_t	longest_row(t_list *lst)
{
	int	bigest_row_len;
	int	curr_row_len;

	bigest_row_len = 0;
	while (lst)
	{
		curr_row_len = ft_strlen(lst->content);
		if (curr_row_len > bigest_row_len)
			bigest_row_len = curr_row_len;
		lst = lst->next;
	}
	return (bigest_row_len);
}

t_list	*skip_to_map_lines(t_list *lst)
{
	while (lst && !is_map_line(lst->content))
		lst = lst->next;
	return (lst);
}

static void	init_row(int *row, size_t cols)
{
	size_t	i;

	i = 0;
	while (i < cols)
	{
		row[i] = ' ';
		++i;
	}
}

int	**allocate_map_array(size_t rows, size_t cols)
{
	int		**map;
	size_t	i;

	map = malloc(sizeof(int *) * rows);
	if (!map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map[i] = malloc(sizeof(int) * cols);
		if (!map[i])
			return (NULL);
		init_row(map[i], cols);
		i++;
	}
	return (map);
}
