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

//void	fill_block(char *dst, int line_length, int bpp, int x, int y, int w, int h, int color)
//{
//	int		i;
//	int		j;
//	char	row[w * (bpp / 8)];
//	int		bytes = bpp / 8;
//
//	// Fill one row with the desired color
//	for (i = 0; i < w; i++)
//		memcpy(row + i * bytes, &color, bytes);
//
//	// Copy that row into each image row
//	for (j = 0; j < h; j++)
//	{
//		char *pixel = dst + (y + j) * line_length + x * bytes;
//		memcpy(pixel, row, w * bytes);
//	}
//}
static void	fill_with_color(t_vars *vars, char *row, int start, int end)
{

	//int		i;
	int		j;
	//char	row[WIDTH * (vars->bits_per_pixel / 8)];
	int		bytes = vars->bits_per_pixel / 8;

//	for (i = 0; i < WIDTH; i++)
//		memcpy(row + i * bytes, &color, bytes);

	for (j = start; j < end; j++)
	{
		char *pixel = vars->addr + j * vars->line_length;
		//memcpy(pixel, row, WIDTH * bytes);
		memcpy(pixel, row, WIDTH * bytes);
	}
}


void	draw_floor_ceiling(t_vars *vars, char *floor, char *ceiling)
{

	fill_with_color(vars, floor, 0, HEIGHT / 2);
	fill_with_color(vars, ceiling, HEIGHT / 2, HEIGHT);
}
