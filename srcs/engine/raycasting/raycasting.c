
#include <cub.h>


void	draw_rays(t_player *player, t_map *map, t_vars *vars)
{
	double	ra;
	t_ray	ray;
	int	nb_rays;

	nb_rays = 0;
	ra = player->angle -(DR / 2 * 64);
	while (nb_rays < 128)
	{
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	//printf("THE value of ray.hitlen = %f\n", ray.hit_len);
	ray = casting(player, map, vars, ra);
	ra += DR/2;
	nb_rays++;
	draw_graphics(&ray, nb_rays, vars);
	}
	
	//draw_graphics(ray, ra, vars);
	//(void)ray;
	//draw() rays should be named raycasting()
		//and what's here should be a function named casting()
	// anyway inside raycsting()
		// there should be th loop to shoot multiple ray, and to in the same loop
		// have it draw garphics
	//do a function that now put pixel on tha screen for each rays
}


