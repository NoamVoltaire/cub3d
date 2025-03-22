# include <cub.h>

int	r_hit_wall(t_ray *ray, t_map map, t_vars *vars)
{
	int	mx;
	int	my;
	int	dof;

	dof = 0;
	while (dof < 5)
	{
		mx = (int)ray->rx >> 7;
		my = (int)ray->ry >> 7;
	printf("my = %d\n", my);
	printf("mx = %d\n", mx);
		if (my >= 0 && my < map.mapy && mx >= 0 && mx < map.mapx && map.grid[my][mx] == 1)
			dof = 5;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			dof++;
		}
	}
	//printf("ray->rx = %f\nray->ry = %f\n", rx, ry);
	//printf("aTan = %f\n", aTan);
	//line_drawing(vars, vars->player.xpos, vars->player.ypos, (int)ray->rx, (int)ray->ry);
	//if (my >= 0 && my < map.mapy && mx >= 0 && mx < map.mapx && map.grid[my][mx] == 1)
		return (sqrt((ray->rx - vars->player.xpos) * (ray->rx - vars->player.xpos)
				+ (ray->ry - vars->player.ypos) *(ray->ry - vars->player.ypos)));
//	if (map.grid[my][mx] == 1)
//		return (dof);
//	else
//		return (0);
}
