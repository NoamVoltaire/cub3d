/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:03:38 by noam              #+#    #+#             */
/*   Updated: 2025/03/16 00:12:05 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	draw_tile(int x, int y, int tilesize, t_vars *vars)
{
	for (int i = 1; i < tilesize - 1; i++)
	{
		for (int j = 1; j < tilesize -1; j++)
		{
			my_mlx_pixel_put(vars, x + i, y + j, 0xFFFFFF);
		}
	}
}

void	draw_map(t_map map, t_vars *vars)
{
	// if (!map.grid)
	// return;
	// int mx, my = 0;
	for (int y = 0; y < map.mapy; y++)
	{
		for (int x = 0; x < map.mapx; x++)
		{
			if (map.grid[y][x] == 1)
			{
				// Draw a tile at (x, y)
				draw_tile(x * map.tilesize, y * map.tilesize, map.tilesize, vars);
				// mlx_rectangle(
			}
			// my += map.tilesize;
		}
		// mx += map.tilesize;
	}
}
