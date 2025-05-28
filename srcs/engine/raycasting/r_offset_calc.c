/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_offset_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:49:33 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 10:49:36 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

double	safe_tan(double angle)
{
	double	t;

	t = tan(angle);
	if (fabs(t - 1.0) < 1e-6)
		return (1.0);
	if (fabs(t + 1.0) < 1e-6)
		return (-1.0);
	return (t);
}

void	calc_offset_up_down(t_ray *ray, t_map *map, t_player *player, double ra)
{
	double	_atan;

	_atan = -1 / tan(ra);
	if (ra > PI)
	{
		ray->ry = (((int)player->ypos / map->tilesize)
				* map->tilesize) - 0.0001;
		ray->rx = (player->ypos - ray->ry) * _atan + player->xpos;
		ray->yo = -map->tilesize;
		ray->xo = -ray->yo * _atan;
		ray->hit_dir = 0;
	}
	else if (ra < PI)
	{
		ray->ry = (((int)player->ypos / map->tilesize)
				* map->tilesize) + map->tilesize;
		ray->rx = (player->ypos - ray->ry) * _atan + player->xpos;
		ray->yo = map->tilesize;
		ray->xo = -ray->yo * _atan;
		ray->hit_dir = 2;
	}
}

void	r_offset_calc_x(t_ray *ray, t_map *map, t_player *player, double ra)
{
	ray->ra = ra;
	ray->hit_dir = 0;
	if (fabs(ra) < 0.0001 || fabs(PI - ra) < 0.0001)
	{
		ray->rx = player->xpos;
		ray->ry = player->ypos;
		ray->xo = player->xpos;
		ray->yo = player->ypos;
	}
	else
		calc_offset_up_down(ray, map, player, ra);
}

void	calc_offset_right_left(t_ray *ray, t_map *map,
				t_player *player, double ra)
{
	double	_ntan;

	_ntan = -tan(ra);
	if (ra > PII && ra < PIII)
	{
		ray->rx = (((int)player->xpos / map->tilesize)
				* map->tilesize) - 0.0001;
		ray->ry = (player->xpos - ray->rx) * _ntan + player->ypos;
		ray->xo = -map->tilesize;
		ray->yo = -ray->xo * _ntan;
		ray->hit_dir = 3;
	}
	else if (ra < PII || ra > PIII)
	{
		ray->rx = (((int)player->xpos / map->tilesize)
				* map->tilesize) + map->tilesize;
		ray->ry = (player->xpos - ray->rx) * _ntan + player->ypos;
		ray->xo = map->tilesize;
		ray->yo = -ray->xo * _ntan;
		ray->hit_dir = 1;
	}
}

void	r_offset_calc_y(t_ray *ray, t_map *map, t_player *player, double ra)
{
	ray->ra = ra;
	ray->hit_dir = 0;
	calc_offset_right_left(ray, map, player, ra);
}
