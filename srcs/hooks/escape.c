/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:10:22 by noam              #+#    #+#             */
/*   Updated: 2025/05/28 10:58:01 by nvoltair         ###   ########.fr       */
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
	mlx_destroy_image(vars->mlx, texture->no.img);
	mlx_destroy_image(vars->mlx, texture->so.img);
	mlx_destroy_image(vars->mlx, texture->we.img);
	mlx_destroy_image(vars->mlx, texture->ea.img);
	free(texture->floor);
	free(texture->ceiling);
}

int	quit_everything(void *data)
{
	t_vars	*vars;

	vars = (t_vars *)data;
	del_textures(vars, &vars->textures);
	mlx_clear_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_display(vars->mlx);
	free_parse(&vars->parse);
	free(vars->mlx);
	exit(0);
	return (1);
}

int	escape(int keycode, t_vars *vars)
{
	printf("key is %d\n", keycode);
	if (keycode == XK_Escape)
	{
		printf("01\n");
		quit_everything(vars);
	}
	return (0);
}
