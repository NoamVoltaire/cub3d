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
#include <string.h>
//void draw_tile(int x, int y, int tilesize, t_vars *vars, int color)
//{
//    int bytes = vars->bits_per_pixel / 8;
//    char row_buffer[tilesize * bytes];
//    char *dst;
//    
//    // Fill the row buffer with the color repeated
//    for (int i = 0; i < tilesize; i++) {
//        // Copy the color bytes into each pixel position in the buffer
//        // Assuming 4 bytes per pixel (RGBA or BGRA)
//        // Cast color to bytes
//	if (i != 0 || i != tilesize - 1)
//		((unsigned int *)row_buffer)[i] = color;
//    }
//
//    // Draw the tile vertically by memcpy-ing the row buffer
//    for (int i = 0; i < tilesize ; i++) {
//        dst = vars->addr + ((y + i) * vars->line_length) + (x * tilesize * bytes);
//        memcpy(dst, row_buffer, tilesize * bytes);
//    }
//}

void	draw_tile(int x, int y, int tilesize, t_vars *vars)
{
	//int	bytes = vars->bits_per_pixel / 8;
	//char	*dst;
			//memset(vars->addr, ((x + 1)*bytes) * ((y + 1) * bytes), (tilesize - 1) 
				//* bytes);
	for (int i = 1; i < tilesize - 1; i++)
	//for (int i = 0 ; i < tilesize - 1; i++)
	{
		//dst = vars->addr + ((y + i) * vars->line_length) + (x * bytes); 
		//memset(dst, 0xFFFFFF, (tilesize -1) * bytes);
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
				draw_tile(x * map.tilesize, y* map.tilesize , map.tilesize, vars);
				// mlx_rectangle(
			}
			// my += map.tilesize;
		}
		// mx += map.tilesize;
	}
}
