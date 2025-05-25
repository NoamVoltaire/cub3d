/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_hit_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:34:05 by noam              #+#    #+#             */
/*   Updated: 2025/05/25 14:34:07 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub.h>

float	r_hit_wall(t_ray *ray, t_map *map, t_vars *vars)
{
	int	mx;
	int	my;
	int	dof;

	dof = 0;
	mx = 0;
	my = 0;
	while (dof < 32)
	{
		mx = (int)ray->rx / map->tilesize;
		my = (int)ray->ry / map->tilesize;
	//printf("my = %d\n", my);
	//printf("mx = %d\n", mx);
	//printf("ray->xo = %f\n", ray->xo);
	//printf("ray->yo = %f\n", ray->yo);
	//printf("ray->rx = %f\n", ray->rx);
	//printf("ray->ry = %f\n", ray->ry);
		if (my >= 0 && my < map->mapy && mx >= 0 && mx < map->mapx && map->grid[my][mx] == 1)
			dof = 32;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			dof++;
		}
	}
	//printf("srt ====== %f\n", sqrt(((ray->rx - vars->player.xpos) * (ray->rx - vars->player.xpos)) + ((ray->ry - vars->player.ypos) *(ray->ry - vars->player.ypos))));
	//printf("aTan = %f\n", aTan);
	//line_drawing(vars, vars->player.xpos, vars->player.ypos, (int)ray->rx, (int)ray->ry);
	//if (my >= 0 && my < map->mapy && mx >= 0 && mx < map->mapx && map->grid[my][mx] == 1)
	//printf("VLAUE OF DX + %f\n", ray->rx - vars->player.xpos);
	//printf("VLAUE OF DY + %f\n", ray->ry - vars->player.ypos);
		return (sqrt(((ray->rx - vars->player.xpos) * (ray->rx - vars->player.xpos))
				+ ((ray->ry - vars->player.ypos) *(ray->ry - vars->player.ypos))));
//	if (map->grid[my][mx] == 1)
//		return (dof);
//	else
//		return (0);
}
