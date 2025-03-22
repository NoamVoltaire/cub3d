#include <cub.h>

t_ray	casting(t_player player, t_map map, t_vars *vars)
{
	t_ray	rayv;
	t_ray	rayh;

	r_offset_calc_x(&rayv, map, player);
	r_offset_calc_y(&rayh, map, player);
	rayv.hit_len = r_hit_wall(&rayv, map, vars);
	rayh.hit_len = r_hit_wall(&rayh, map, vars);
	printf("HITLEN H ====== %d\n", rayh.hit_len);
	printf("HITLEN V ====== %d\n", rayv.hit_len);
	if (rayv.hit_len < rayh.hit_len)
	{
		line_drawing(vars, vars->player.xpos, vars->player.ypos, (int)rayv.rx, (int)rayv.ry);
		return (rayv);
	}
	else
	{
		line_drawing(vars, vars->player.xpos, vars->player.ypos, (int)rayh.rx, (int)rayh.ry);
		return (rayh);
	}
}
