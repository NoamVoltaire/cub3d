#include <cub.h>

void	r_offset_calc_x(t_ray *ray, t_map map, t_player player)
{
	double	aTan; 
	double	dof;
	double	ra; 

	(void)dof;
	ra = player.angle;
	dof = 0;
	if (ra == 0.0 || fabs(PI - ra) < 0.0001)
	{
		printf("WEGETTHERE*****");
		ray->rx = player.xpos;
		ray->ry = player.ypos;
		dof = 5;
	}
	else
	{
		aTan = -1 / tan(ra);
		if (ra > PI)
		{
		printf("SUPP == \n");
			ray->ry = (((int)player.ypos >> 7 )<< 7) - 0.0001;
			ray->rx = (player.ypos - ray->ry) * aTan + player.xpos;
			ray->yo = -map.tilesize;
			ray->xo = -ray->yo * aTan;
		}
		else if (ra < PI)
		{
		printf("INFF == \n");
			ray->ry = (((int)player.ypos >> 7)  << 7) + map.tilesize;
			ray->rx = (player.ypos - ray->ry) * aTan + player.xpos;
			ray->yo = map.tilesize;
			ray->xo = -ray->yo * aTan;
		}
	}
}

void	r_offset_calc_y(t_ray *ray, t_map map, t_player player)
{

	//double	ray->rx, ray->ry, ra, ray->xo, ray->yo;
	double	dof;
	double	ra; 
	double	nTan; 

	(void)dof;

	ra = player.angle;
	dof = 0;
	if (ra == 0.0 || fabs(PI - ra) < 0.0001)
	{
		printf("WEGETTHERE*****");
		ray->rx = player.xpos;
		ray->ry = player.ypos;
		dof = 5;
	}
	else
	{
		nTan = -tan(ra);
		if (ra > PII && ra < PIII)
		{
		printf("LEFT== \n");
//printf("player.xpos before: %d\n", (((int)player.xpos >> 7 )<< 7));
			ray->rx = (((int)player.xpos >> 7 )<< 7) - 0.0001;
			ray->ry = (player.xpos - ray->rx) * nTan + player.ypos;
			ray->xo = -map.tilesize;
			ray->yo = -ray->xo * nTan;
		}
		else if (ra < PII || ra > PIII)
		{
		printf("RIGHT == \n");
			ray->rx = (((int)player.xpos >> 7)  << 7) + map.tilesize;
			ray->ry = (player.xpos - ray->rx) * nTan + player.ypos;
			ray->xo = map.tilesize;
			ray->yo = -ray->xo * nTan;
		}
	}
}

