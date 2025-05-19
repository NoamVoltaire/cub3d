/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrellie <lgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:15:50 by lgrellie          #+#    #+#             */
/*   Updated: 2025/05/19 12:27:50 by lgrellie         ###   ########.fr       */
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
		ft_lstclear(&lines, &free);
	return (lines);
}

int	check_input_syntax(t_list *input)
{
	if (input == NULL)
		return (1);
	return (0);
}

int	parse_into_vars(int fd, t_vars *vars)
{
	t_list	*lines;

	lines = get_lines(fd);
	if (close(fd) == -1)
	{
		perror("close");
		return (1);
	}
	(void)vars;
	t_list *ptr = lines;
	while (ptr)
	{
		printf("%s", (char *)ptr->content);
		ptr = ptr->next;
	}
	return (0);
	//
	//if (check_input_syntax(lines) == 1)
	//	return (1);
	//return (intialize_vars(lines, vars);
}
