/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cube_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:08:42 by noam              #+#    #+#             */
/*   Updated: 2025/03/16 00:08:55 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int draw_cube_player(t_player player, t_vars *vars)
{
    // t_vars		*vars = (t_vars *)param;
	// static int	x = WIDTH/2;
	// static int	y= HEIGHT/2;
	// update_position(img);
	// clear_image(img, 0x000000); // Black background

	int	i = (int)player.xpos - 2;
	int	j = (int)player.ypos - 2;

	int rx = (int)player.xpos;
	int ry = (int)player.ypos;
	int l = 0;
	int steps = 10;
	// int pixel_color;
	
	// printf("player xpos : %f, ypos : %f\n", player.xpos, player.ypos);
	// pixel_color = 0x00FF0000;
	while (i < player.xpos + 2)
	{
		j = player.ypos - 2;
		while (j < player.ypos + 2)
		{
			// printf("i = %d, j = %d\n", i, j);
			// return 0 ;
			my_mlx_pixel_put(vars, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	// mlx_clear_window(img->mlx, img->mlx_window);
	// mlx_put_image_to_window(vars->mlx, vars->window, vars->img, 0, 0);
	// usleep(100000)
	while (l < steps)
	{
		my_mlx_pixel_put(vars, rx, ry, 0x00FF0000);
		l++;
		rx += (int)player.xdelt /2;
		ry += (int)player.ydelt /2;
	}
	return (0);
}