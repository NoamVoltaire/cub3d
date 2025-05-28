/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:41:07 by lgrellie          #+#    #+#             */
/*   Updated: 2025/05/28 13:52:54 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static t_list	*get_lines(int fd)
{
	char	*line;
	t_list	*new_line;
	t_list	*lines;
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

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr("01 NSEW", line[i]))
			return (false);
		++i;
	}
	if (i == 0)
		return (false);
	return (true);
}

void	normalize_tab(int **tab, int width, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (tab[y][x] == '2')
				tab[y][x] = '0';
			if (tab[y][x] == '0' || tab[y][x] == '1')
				tab[y][x] -= '0';
			x++;
		}
		y++;
	}
}

int	parse_into_vars(int fd, t_vars *vars)
{
	t_parse	parse;

	ft_bzero(&parse, sizeof(t_parse));
	parse.lines = get_lines(fd);
	if (close(fd) == -1)
	{
		perror("close");
		return (1);
	}
	initialize_vars(parse.lines, &parse);
	parse.tab = lst_to_int_map(parse.lines, &parse);
	if (!flood_fill_map(&parse))
		handle_parse_error(&vars->parse, ERR_MAP_FORMAT);
	normalize_tab(parse.tab, parse.m_w, parse.m_h);
	vars->parse = parse;
	return (0);
}
