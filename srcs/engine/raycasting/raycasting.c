
#include <cub.h>


void	draw_rays(t_player player, t_map map, t_vars *vars)
{
	double	ra;
	t_ray	ray;
	int	nb_rays;

	nb_rays = 0;
	ra = player.angle - DR * 32;
	//ra = player.angle;
	//if (ra < 0)
	//	ra += 2 * PI;
	//if (ra > 2 * PI)
	//	ra -= 2 * PI;
//	while (nb_rays < 1)
	while (nb_rays < 64)
	{
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	//printf("THE value of ray.hitlen = %f\n", ray.hit_len);
		ray = casting(player, map, vars, ra);
		ra += DR;
		nb_rays++;
		draw_graphics(ray, nb_rays, vars);
	}
	
	//draw_graphics(ray, ra, vars);
	(void)ray;
	//draw() rays should be named raycasting()
		//and what's here should be a function named casting()
	// anyway inside raycsting()
		// there should be th loop to shoot multiple ray, and to in the same loop
		// have it draw garphics
	//do a function that now put pixel on tha screen for each rays
}


//void	draw_rays(t_player player, t_map map, t_vars *vars)
//{
//	//t_ray	ray;
//	int	r;
//	int	mx, my,  dof;
//	double	rx, ry, ra, xo, yo;
//	double	aTan; 
//	double	nTan; 
//
//	ra = player.angle;
//	r = 0;
//	while (r < 1)
//	{
//		dof = 0;
//		if (ra == 0.0 || fabs(PI - ra) < 0.0001)
//		{
//			printf("WEGETTHERE*****");
//			rx = player.xpos;
//			ry = player.ypos;
//			dof = 5;
//		}
//		else
//		{
//			aTan = -1 / tan(ra);
//			nTan = -tan(ra);
//			if (ra > PI)
//			{
//			printf("SUPP == \n");
////printf("player.ypos before: %d\n", (((int)player.ypos >> 7 )<< 7));
//				ry = (((int)player.ypos >> 7 )<< 7) - 0.0001;
//				rx = (player.ypos - ry) * aTan + player.xpos;
//				yo = -map.tilesize;
//				xo = -yo * aTan;
//			}
//			else if (ra < PI)
//			{
//			printf("INFF == \n");
//				ry = (((int)player.ypos >> 7)  << 7) + map.tilesize;
//				rx = (player.ypos - ry) * aTan + player.xpos;
//				yo = map.tilesize;
//				xo = -yo * aTan;
//			}
//			if (ra > PII && ra < PIII)
//			{
//			printf("LEFT== \n");
////printf("player.xpos before: %d\n", (((int)player.xpos >> 7 )<< 7));
//				rx = (((int)player.xpos >> 7 )<< 7) - 0.0001;
//				ry = (player.xpos - rx) * nTan + player.ypos;
//				xo = -map.tilesize;
//				yo = -xo * nTan;
//			}
//			else if (ra < PII || ra > PIII)
//			{
//			printf("RIGHT == \n");
//				rx = (((int)player.xpos >> 7)  << 7) + map.tilesize;
//				ry = (player.xpos - rx) * nTan + player.ypos;
//				xo = map.tilesize;
//				yo = -xo * nTan;
//			}
//		}
//		//printf("ry = %f\n", ry);
//		//printf("rx = %f\n", rx);
//		//printf("after OPP yo = %f\n", yo);
//		//printf("after OPP xo = %f\n", xo);
//		// TODO i think this is where we need to do a function
//		// params are :
//		// dof rx ry mx my xo yo
//		// so calculate_hit(rx, ry, xo, yo)
//		//	actually i need map too
//		//	maybe i need a struct to store ray x, y and offset x, y
//		//	or maybe some int array wher rx = r[0] and ry = r[1]
//			// insid is mx and my
//		// before that is 
//		// lookup(rx, ry, xo, yo);
//			// i guess the params are int *
//		while (dof < 5)
//		{
//			mx = (int)rx >> 7;
//			my = (int)ry >> 7;
//		//printf("my = %d\n", my);
//		//printf("mx = %d\n", mx);
//			if (my >= 0 && my < map.mapy && mx >= 0 && mx < map.mapx && map.grid[my][mx] == 1)
//				dof = 5;
//			else
//			{
//				rx += xo;
//				ry += yo;
//				dof++;
//			}
//		}
//		printf("rx = %f\nry = %f\n", rx, ry);
//		printf("aTan = %f\n", aTan);
//		line_drawing(vars, player.xpos, player.ypos, (int)rx, (int)ry);
//		r++;
//		
//	}
//	 
//}
