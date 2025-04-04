/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:13:33 by noam              #+#    #+#             */
/*   Updated: 2025/03/21 17:18:27 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	main(void)
{
	t_vars	vars;

	init_vars(&vars);
	the_hooks(&vars);
	//if (!vars.textures.t_addr)  // Exit function early to prevent crash
		 //printf("ITSNULLLLLLLLLL");
		// printf("vars.player.xpos = %f\n", vars.player.xpos);
	mlx_loop_hook(vars.mlx, every_frame, &vars);
	mlx_loop(vars.mlx);
}
