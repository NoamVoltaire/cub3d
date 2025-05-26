/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:13:33 by noam              #+#    #+#             */
/*   Updated: 2025/05/26 09:17:31 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	main_loop(t_vars *vars)
{
	init_vars(vars);
	the_hooks(vars);
	//if (!vars.textures.t_addr)  // Exit function early to prevent crash
		 //printf("ITSNULLLLLLLLLL");
		// printf("vars.player.xpos = %f\n", vars.player.xpos);
	mlx_loop_hook(vars->mlx, every_frame, vars);
	mlx_loop(vars->mlx);
	return (0);
}
