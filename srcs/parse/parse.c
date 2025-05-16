/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrellie <lgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:15:50 by lgrellie          #+#    #+#             */
/*   Updated: 2025/05/16 17:07:05 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_list   *get_lines(int fd)
{
	char	*line;
	t_list	*new_line;
	t_list  *lines;
	int		ret;

	if (fd < 0)
		return (NULL);
	ret = next_gnl(&line, fd);
	lines = NULL;
	while (ret == 0)
	{
		new_line = ft_lstnew(line);
		if (new_line == NULL)
		{
			free(line);
			ft_lstclear(&lines, &free);
			return (NULL);
		}
		ft_lstadd_back(&lines, new_line);
		ret = next_gnl(&line, fd);
	}
	if (ret != 1)
	{
		
	}
	return (lines);
}

int	parse_into_vars(int fd, t_vars *vars)
{
	char	**lines;

	lines = get_lines(fd);
	close(fd);
	if (lines == NULL)
		return (1);
	return (0);
}
