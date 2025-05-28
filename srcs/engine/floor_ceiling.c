/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:09:18 by noam              #+#    #+#             */
/*   Updated: 2025/03/16 00:10:53 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	fill_with_color(t_vars *vars, char *row, int start, int end)
{
	char	*pixel_y_pos;
	int		j;
	int		bytes;

	j = start;
	bytes = vars->bits_per_pixel / 8;
	while (j < end)
	{
		pixel_y_pos = vars->addr + j * vars->line_length;
		ft_memcpy(pixel_y_pos, row, WIDTH * bytes);
		j++;
	}
}

void	draw_floor_ceiling(t_vars *vars, char *floor, char *ceiling)
{
	fill_with_color(vars, floor, 0, HEIGHT / 2);
	fill_with_color(vars, ceiling, HEIGHT / 2, HEIGHT);
}
