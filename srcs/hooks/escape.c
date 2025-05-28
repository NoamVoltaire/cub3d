/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:10:22 by noam              #+#    #+#             */
/*   Updated: 2025/05/26 17:22:59 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	delete_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->mapy)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	del_textures(t_vars *vars, t_texture *texture)
{
	mlx_destroy_image(vars->mlx, texture->no.addr);
	mlx_destroy_image(vars->mlx, texture->so.addr);
	mlx_destroy_image(vars->mlx, texture->we.addr);
	mlx_destroy_image(vars->mlx, texture->ea.addr);
	free(texture->no.img);
	free(texture->so.img);
	free(texture->we.img);
	free(texture->ea.img);
	free(texture->floor);
	free(texture->ceiling);
}

void	quit_everything(t_vars *vars)
{
	del_textures(vars, &vars->textures);
	mlx_clear_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->window);
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_display(vars->mlx);
	delete_map(&vars->map);
	free(vars);
	exit(0);
}

int	escape(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		quit_everything(vars);
	}
	return (0);
}
