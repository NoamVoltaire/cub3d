/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:41:40 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 10:41:43 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	handle_rotation(t_player *player)
{
	if (player->keybind.see_left)
	{
		player->angle -= player->rot_spd * player->delta_time;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
	if (player->keybind.see_right)
	{
		player->angle += player->rot_spd * player->delta_time;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
	}
	player->xdelt = cos(player->angle) * 5;
	player->ydelt = sin(player->angle) * 5;
}

void	move_strafe_left(t_player *player, t_map *map)
{
	float			str_x;
	float			str_y;
	t_moveprobe		probe;

	str_x = cos(player->angle - PI / 2) * 5;
	str_y = sin(player->angle - PI / 2) * 5;
	if (str_x > 0)
		probe.xo = 20;
	else
		probe.xo = -20;
	if (str_y > 0)
		probe.yo = 20;
	else
		probe.yo = -20;
	probe.mpx = player->xpos / map->tilesize;
	probe.mpy = player->ypos / map->tilesize;
	probe.pos_xo = (player->xpos + probe.xo) / map->tilesize;
	probe.pos_yo = (player->ypos + probe.yo) / map->tilesize;
	if (map->grid[probe.mpy][probe.pos_xo] == 0)
		player->xpos += str_x * player->move_spd * player->delta_time;
	if (map->grid[probe.pos_yo][probe.mpx] == 0)
		player->ypos += str_y * player->move_spd * player->delta_time;
}

void	move_strafe_right(t_player *player, t_map *map)
{
	float			str_x;
	float			str_y;
	t_moveprobe		probe;

	str_x = cos(player->angle + PI / 2) * 5;
	str_y = sin(player->angle + PI / 2) * 5;
	if (str_x > 0)
		probe.xo = 20;
	else
		probe.xo = -20;
	if (str_y > 0)
		probe.yo = 20;
	else
		probe.yo = -20;
	probe.mpx = player->xpos / map->tilesize;
	probe.mpy = player->ypos / map->tilesize;
	probe.pos_xo = (player->xpos + probe.xo) / map->tilesize;
	probe.pos_yo = (player->ypos + probe.yo) / map->tilesize;
	if (map->grid[probe.mpy][probe.pos_xo] == 0)
		player->xpos += str_x * player->move_spd * player->delta_time;
	if (map->grid[probe.pos_yo][probe.mpx] == 0)
		player->ypos += str_y * player->move_spd * player->delta_time;
}
