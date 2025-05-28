/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_int_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:53:02 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 10:53:05 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static char	normalize_map_char(char c)
{
	if (c == '\0')
		return ('1');
	//if (c == ' ' )
	//	return ('0');
	return (c);
}

static void	handle_player_char(char dir, int x, int y, t_parse *parse)
{
	parse->playerxpos = (x * TILE_SIZE) + (TILE_SIZE / 2);
	parse->playerypos = (y * TILE_SIZE) + (TILE_SIZE / 2);
	parse->p_first_xposm = x;
	parse->p_first_yposm = y;
	if (dir == 'N')
		parse->p_angle = PIII;
	else if (dir == 'S')
		parse->p_angle = PII;
	else if (dir == 'E')
		parse->p_angle = 0;
	else if (dir == 'W')
		parse->p_angle = PI;
}

int	process_map_line(char *line, int *row, int row_idx, t_parse *parse)
{
	char	c;
	int		j;
	int		line_has_player;
	int		line_len;

	j = 0;
	line_has_player = 0;
	line_len = ft_strlen(line);
	if (line == NULL)
		return (0);
	while (j < parse->m_w && j < line_len)
	{
		c = normalize_map_char(line[j]);
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			line_has_player++;
			handle_player_char(c, j, row_idx, parse);
			c = '0';
		}
		row[j] = c - '0';
		j++;
	}
	return (line_has_player);
}

void	fill_map_array(t_list *lst, int **map_tab_array, t_parse *parse)
{
	size_t	i;

	i = 0;
	while (lst && is_map_line(lst->content))
	{
		parse->m_has_player += process_map_line((char *)lst->content,
				map_tab_array[i], i, parse);
		lst = lst->next;
		i++;
	}
	if (!parse->m_has_player || parse->m_has_player > 1)
	{
		parse->tab = NULL;
		handle_parse_error(parse, ERR_MISSING_PLAYER);
	}
}

int	**lst_to_int_map(t_list *lst, t_parse *parse)
{
	int		**map_tab_array;
	size_t	rows;
	size_t	cols;

	lst = skip_to_map_lines(lst);
	rows = ft_lstsize(lst);
	cols = longest_row(lst);
	parse->m_w = cols;
	parse->m_h = rows;
	map_tab_array = allocate_map_array(rows, cols);
	if (!map_tab_array)
		return (NULL);
	fill_map_array(lst, map_tab_array, parse);
	return (map_tab_array);
}
