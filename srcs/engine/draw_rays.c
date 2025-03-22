
#include <cub.h>


//void	draw_rays(t_player player, t_map map, t_vars *vars)
//{
//	t_ray rayv;
//	t_ray rayh;
//	int	rayv_len;
//	int	rayh_len;
//
//	r_offset_calc(&rayv, vars->map, vars->player);
//	r_offset_calc(&rayh, vars->map, vars->player);
//	rayv_len = r_hit_wall(rayv, vars->map, vars);
//	rayh_len = r_hit_wall(rayh, vars->map, vars);
//}


void	draw_rays(t_player player, t_map map, t_vars *vars)
{
	//t_ray	ray;
	int	r;
	int	mx, my,  dof;
	double	rx, ry, ra, xo, yo;
	double	aTan; 
	double	nTan; 

	ra = player.angle;
	r = 0;
	while (r < 1)
	{
		dof = 0;
		if (ra == 0.0 || fabs(PI - ra) < 0.0001)
		{
			printf("WEGETTHERE*****");
			rx = player.xpos;
			ry = player.ypos;
			dof = 5;
		}
		else
		{
			aTan = -1 / tan(ra);
			nTan = -tan(ra);
			if (ra > PI)
			{
			printf("SUPP == \n");
//printf("player.ypos before: %d\n", (((int)player.ypos >> 7 )<< 7));
				ry = (((int)player.ypos >> 7 )<< 7) - 0.0001;
				rx = (player.ypos - ry) * aTan + player.xpos;
				yo = -map.tilesize;
				xo = -yo * aTan;
			}
			else if (ra < PI)
			{
			printf("INFF == \n");
				ry = (((int)player.ypos >> 7)  << 7) + map.tilesize;
				rx = (player.ypos - ry) * aTan + player.xpos;
				yo = map.tilesize;
				xo = -yo * aTan;
			}
			if (ra > PII && ra < PIII)
			{
			printf("LEFT== \n");
//printf("player.xpos before: %d\n", (((int)player.xpos >> 7 )<< 7));
				rx = (((int)player.xpos >> 7 )<< 7) - 0.0001;
				ry = (player.xpos - rx) * nTan + player.ypos;
				xo = -map.tilesize;
				yo = -xo * nTan;
			}
			else if (ra < PII || ra > PIII)
			{
			printf("RIGHT == \n");
				rx = (((int)player.xpos >> 7)  << 7) + map.tilesize;
				ry = (player.xpos - rx) * nTan + player.ypos;
				xo = map.tilesize;
				yo = -xo * nTan;
			}
		}
		//printf("ry = %f\n", ry);
		//printf("rx = %f\n", rx);
		//printf("after OPP yo = %f\n", yo);
		//printf("after OPP xo = %f\n", xo);
		// TODO i think this is where we need to do a function
		// params are :
		// dof rx ry mx my xo yo
		// so calculate_hit(rx, ry, xo, yo)
		//	actually i need map too
		//	maybe i need a struct to store ray x, y and offset x, y
		//	or maybe some int array wher rx = r[0] and ry = r[1]
			// insid is mx and my
		// before that is 
		// lookup(rx, ry, xo, yo);
			// i guess the params are int *
		while (dof < 5)
		{
			mx = (int)rx >> 7;
			my = (int)ry >> 7;
		//printf("my = %d\n", my);
		//printf("mx = %d\n", mx);
			if (my >= 0 && my < map.mapy && mx >= 0 && mx < map.mapx && map.grid[my][mx] == 1)
				dof = 5;
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		printf("rx = %f\nry = %f\n", rx, ry);
		printf("aTan = %f\n", aTan);
		line_drawing(vars, player.xpos, player.ypos, (int)rx, (int)ry);
		r++;
		
	}
	 
}
