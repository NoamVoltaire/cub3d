/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_hit_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:34:05 by noam              #+#    #+#             */
/*   Updated: 2025/05/26 18:01:54 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

float	r_hit_wall(t_ray *ray, t_map *map, t_vars *vars)
{
	int	mx;
	int	my;
	int	dof;

	dof = 0;
	mx = 0;
	my = 0;
	while (dof < map->mapx || dof < map->mapy)
	{
		mx = (int)ray->rx / map->tilesize;
		my = (int)ray->ry / map->tilesize;
		if (my >= 0 && my < map->mapy && mx >= 0 && mx < map->mapx
			&& map->grid[my][mx] == 1)
			dof = 10000000;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			dof++;
		}
	}
		return (sqrt(((ray->rx - vars->player.xpos)
				* (ray->rx - vars->player.xpos))
			+ ((ray->ry - vars->player.ypos)
				*(ray->ry - vars->player.ypos))));
}
