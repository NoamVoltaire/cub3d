/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:04:16 by noam              #+#    #+#             */
/*   Updated: 2025/05/26 17:21:00 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	rgb_to_hex(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	init_vars(t_vars *vars)
{
	init_map(&vars->map, &vars->parse);
	init_player(&vars->player, &vars->parse);
	init_window(vars);
	init_textures(vars, rgb_to_hex(vars->parse.f_color_input),
		rgb_to_hex(vars->parse.c_color_input));
	//free_tab(vars->parse.t_paths);
}
