/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:13:33 by noam              #+#    #+#             */
/*   Updated: 2025/03/15 23:49:05 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	main(void)
{
	t_vars	vars;

	init_vars(&vars);
	the_hooks(&vars);
	// printf("vars.player.xpos = %f\n", vars.player.xpos);
	mlx_loop_hook(vars.mlx, every_frame, &vars);
	mlx_loop(vars.mlx);
}
