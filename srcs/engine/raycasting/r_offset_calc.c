#include <cub.h>

double safe_tan(double angle)
{
    double t = tan(angle);
    if (fabs(t - 1.0) < 1e-6)  // If tan(ra) is very close to 1
        return 1.0;
    if (fabs(t + 1.0) < 1e-6)  // If tan(ra) is very close to -1
        return -1.0;
    return t;
}

void	r_offset_calc_x(t_ray *ray, t_map map, t_player player, double ra)
{
	double	aTan; 
	double	dof;

	(void)dof;
	dof = 0;
	ray->hit_dir = 0;
	if (fabs(ra) < 0.0001 || fabs(PI - ra) < 0.0001)
	{
		////printf("WEGETTHERE*****\n");
		ray->rx = player.xpos;
		ray->ry = player.ypos;
		dof = 5;
	}
	else
	{
		//aTan = -1 / tan(ra);
		aTan = -1 / safe_tan(ra);
		//printf("aTan = %f\n", aTan);
		if (ra > PI)
		{
		//printf("SUPP == \n");
			ray->ry = (((int)player.ypos >> 7 )<< 7) - 0.0001;
			ray->rx = (player.ypos - ray->ry) * aTan + player.xpos;
			ray->yo = -map.tilesize;
			ray->xo = -ray->yo * aTan;
			ray->hit_dir = 0;
		}
		else if (ra < PI)
		{
		//printf("INFF == \n");
			ray->ry = (((int)player.ypos >> 7)  << 7) + map.tilesize;
			ray->rx = (player.ypos - ray->ry) * aTan + player.xpos;
			ray->yo = map.tilesize;
			ray->xo = -ray->yo * aTan;
			ray->hit_dir = 2;
		}
	}
}

void	r_offset_calc_y(t_ray *ray, t_map map, t_player player, double ra)
{

	double	dof;
	double	nTan; 

	(void)dof;

	dof = 0;
	ray->hit_dir = 0;
	if (ra == 0.0 || fabs(PI - ra) < 0.0001)
	{
		//printf("WEGETTHERE*****\n");
		ray->rx = player.xpos;
		ray->ry = player.ypos;
		dof = 5;
	}
	else
	{
		nTan = -tan(ra);
		//nTan = -safe_tan(ra);
		//printf("nTan = %f\n", nTan);
		if (ra > PII && ra < PIII)
		{
		//printf("LEFT== \n");
////printf("player.xpos before: %d\n", (((int)player.xpos >> 7 )<< 7));
			ray->rx = (((int)player.xpos >> 7 )<< 7) - 0.0001;
			ray->ry = (player.xpos - ray->rx) * nTan + player.ypos;
			ray->xo = -map.tilesize;
			ray->yo = -ray->xo * nTan;
			ray->hit_dir = 3;
		}
		else if (ra < PII || ra > PIII)
		{
		//printf("RIGHT == \n");
			ray->rx = (((int)player.xpos >> 7)  << 7) + map.tilesize;
			ray->ry = (player.xpos - ray->rx) * nTan + player.ypos;
			ray->xo = map.tilesize;
			ray->yo = -ray->xo * nTan;
			ray->hit_dir = 1;
		}
	}
}

