/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:52:08 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 10:52:10 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	flood_cell(t_parse *parse, int x, int y)
{
	int	a;
	int	b;
	int	c;
	int	d;

	if (x < 0 || y < 0 || x >= parse->m_w || y >= parse->m_h)
		return (0);
	if (parse->tab[x][y] == ' ')
		return (0);
	if (parse->tab[y][x] != '0')
		return (1);
	parse->tab[y][x] = '2';
	a = flood_cell(parse, x + 1, y);
	b = flood_cell(parse, x - 1, y);
	c = flood_cell(parse, x, y + 1);
	d = flood_cell(parse, x, y - 1);
	return (a && b && c && d);
}

static int	find_first_zero(t_parse *parse, int *x, int *y)
{
	int	a;
	int	b;

	a = 0;
	while (a < parse->m_h)
	{
		b = 0;
		while (b < parse->m_w)
		{
			if (parse->tab[a][b] == '0')
			{
				*x = b;
				*y = a;
				return (1);
			}
			++b;
		}
		++a;
	}
	return (0);
}

int	flood_fill_map(t_parse *parse)
{
	int	x;
	int	y;

	while (find_first_zero(parse, &x, &y))
	{
		if (!flood_cell(parse, x, y))
			return (0);	
	}
	return (1);
}
