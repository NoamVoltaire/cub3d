/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:12:01 by noam              #+#    #+#             */
/*   Updated: 2025/04/22 16:32:34 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	init_window(t_vars *vars)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "that map test");
	vars->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, 
			&vars->line_length, &vars->endian);
	vars->mlx = mlx;
	vars->window = window;
}
