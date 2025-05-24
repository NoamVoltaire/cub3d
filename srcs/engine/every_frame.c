/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   every_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:59:09 by noam              #+#    #+#             */
/*   Updated: 2025/04/22 03:14:46 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <unistd.h>

int	every_frame(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	memset(vars->addr, 0, (WIDTH * HEIGHT) 
		* (vars->bits_per_pixel / 8));
	//draw_map(vars->map, vars);
	update_pos(&vars->player, &vars->map);
	draw_floor_ceiling(vars, vars->textures.floor, vars->textures.ceiling);
	draw_rays(&vars->player, &vars->map, vars);
	
	// draw_cube_player(vars->player, vars);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img, 0, 0);
	usleep(16000);
	return (0);
}
