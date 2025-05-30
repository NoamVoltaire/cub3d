/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:37:18 by noam              #+#    #+#             */
/*   Updated: 2025/05/25 14:37:22 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_ray	casting(t_player *player, t_map *map, t_vars *vars, double ra)
{
	t_ray	rayv;
	t_ray	rayh;
	double	fisheye;

	r_offset_calc_x(&rayv, map, player, ra);
	r_offset_calc_y(&rayh, map, player, ra);
	rayv.hit_len = r_hit_wall(&rayv, map, vars);
	rayh.hit_len = r_hit_wall(&rayh, map, vars);
	fisheye = player->angle - ra;
	if (fisheye < 0)
		fisheye += 2 * PI;
	if (fisheye > 2 * PI)
		fisheye -= 2 * PI;
	rayh.hit_len *= cos(fisheye);
	rayv.hit_len *= cos(fisheye);
	if (rayv.hit_len < rayh.hit_len)
	{
		//line_drawing(vars, vars->player.xpos, vars->player.ypos, (int)rayv.rx, (int)rayv.ry);
		return (rayv);
	}
	else
	{
		//line_drawing(vars, vars->player.xpos, vars->player.ypos, (int)rayh.rx, (int)rayh.ry);
		return (rayh);
	}
}
