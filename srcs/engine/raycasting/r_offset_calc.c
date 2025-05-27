/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_offset_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:33:39 by noam              #+#    #+#             */
/*   Updated: 2025/05/26 17:47:00y noam             ###   ########.fr       */
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
	double	aTan; 

	//ray->ra = ra;
	aTan = -1 / safe_tan(ra);
	if (ra > PI)
	{
		ray->ry = (((int)player->ypos / map->tilesize)
				* map->tilesize) - 0.0001;
		ray->rx = (player->ypos - ray->ry) * aTan + player->xpos;
		ray->yo = -map->tilesize;
		ray->xo = -ray->yo * aTan;
		ray->hit_dir = 0;
	}
	else if (ra < PI)
	{
	//printf("INFF == \n");
		ray->ry = (((int)player->ypos / map->tilesize)
				* map->tilesize) + map->tilesize;
		ray->rx = (player->ypos - ray->ry) * aTan + player->xpos;
		ray->yo = map->tilesize;
		ray->xo = -ray->yo * aTan;
		ray->hit_dir = 2;
	}
}

void	r_offset_calc_x(t_ray *ray, t_map *map, t_player *player, double ra)
{
	ray->ra = ra;
	ray->hit_dir = 0;
	if (fabs(ra) < 0.0001 || fabs(PI - ra) < 0.0001)
	{
		////printf("WEGETTHERE*****\n");
		ray->rx = player->xpos;
		ray->ry = player->ypos;
		ray->xo = player->xpos;
		ray->yo = player->ypos;
	}
	else
		calc_offset_up_down(ray, map, player, ra);
}
void	calc_offset_right_left(t_ray *ray, t_map *map, t_player *player, double ra)
{
double	nTan; 
		nTan = -tan(ra);
	if (ra > PII && ra < PIII)
	{
	//printf("LEFT== \n");
		ray->rx = (((int)player->xpos / map->tilesize) * map->tilesize) - 0.0001;
		ray->ry = (player->xpos - ray->rx) * nTan + player->ypos;
		ray->xo = -map->tilesize;
		ray->yo = -ray->xo * nTan;
		ray->hit_dir = 3;
	}
	else if (ra < PII || ra > PIII)
	{
	//printf("RIGHT == \n");
		ray->rx = (((int)player->xpos / map->tilesize) * map->tilesize) + map->tilesize;
		ray->ry = (player->xpos - ray->rx) * nTan + player->ypos;
		ray->xo = map->tilesize;
		ray->yo = -ray->xo * nTan;
		ray->hit_dir = 1;
	}
}

void	r_offset_calc_y(t_ray *ray, t_map *map, t_player *player, double ra)
{

	//double	nTan; 


	ray->ra = ra;
	ray->hit_dir = 0;
//	if (ra == 0.0 || fabs(PI - ra) < 0.0001)
//	{
//		printf("WEGETTHERE*****\n");
//		ray->rx = player->xpos;
//		ray->ry = player->ypos;
//		ray->xo = player->xpos;
//		ray->yo = player->ypos;
//	}
	//else
		calc_offset_right_left(ray, map, player, ra);
}

