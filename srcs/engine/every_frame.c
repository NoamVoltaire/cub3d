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

int	every_frame(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	memset(vars->addr, 0, (WIDTH * HEIGHT) 
		* (vars->bits_per_pixel / 8));
	draw_map(vars->map, vars);
	update_pos(&vars->player, &vars->map);
	draw_rays(&vars->player, &vars->map, vars);
	// set_keyb(&vars->player.keybind);
	// printf("forward = %d, backward = %d, left = %d, right = %d\n", vars->player.keybind.forwards, vars->player.keybind.backwards, vars->player.keybind.left, vars->player.keybind.right);
	//printf("vars.player.xpos = %f\n", vars->player.xpos);
	//printf("vars.player.ypos = %f\n", vars->player.ypos);
	//printf("vars.player.angle = %f\n", vars->player.angle);
	
	// draw_cube_player(vars->player, vars);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img, 0, 0);
	return (0);
}
