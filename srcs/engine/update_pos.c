/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:06:53 by noam              #+#    #+#             */
/*   Updated: 2025/04/22 16:52:24 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	calc_offset(t_player *player, float *xo, float *yo)
{
	*xo = 0;
	*yo = 0;
	if (player->xdelt < 0)
		*xo = -20;
	else
		*xo = 20;
	if (player->ydelt < 0)
		*yo = -20;
	else
		*yo = 20;
}

static void	move_forward(t_player *player, t_map *map, float xo, float yo)
{
	int	mpx;
	int	mpy;
	int	pos_xo;
	int	pos_yo;

	mpx = player->xpos / map->tilesize;
	mpy = player->ypos / map->tilesize;
	pos_xo = (player->xpos + xo) / map->tilesize;
	pos_yo = (player->ypos + yo) / map->tilesize;
	if (map->grid[mpy][pos_xo] == 0)
		player->xpos += player->xdelt * player->delta_time * player->move_spd;
		//player->xpos += player->xdelt / 2;
	if (map->grid[pos_yo][mpx] == 0)
		player->ypos += player->ydelt * player->delta_time * player->move_spd;
		//player->ypos += player->ydelt / 2;
}

static void	move_backward(t_player *player, t_map *map, float xo, float yo)
{
	int	mpx;
	int	mpy;
	int	pos_xo;
	int	pos_yo;

	mpx = player->xpos / map->tilesize;
	mpy = player->ypos / map->tilesize;
	pos_xo = (player->xpos - xo) / map->tilesize;
	pos_yo = (player->ypos - yo) / map->tilesize;
	if (map->grid[mpy][pos_xo] == 0)
		player->xpos -= player->xdelt * player->delta_time * player->move_spd;
	//player->xpos -= player->xdelt / 4;
	if (map->grid[pos_yo][mpx] == 0)
		player->ypos -= player->ydelt * player->delta_time * player->move_spd;
	//player->ypos -= player->ydelt / 4;
}

void	get_delta_time(t_player *player)
{
	double current_time;

	current_time = get_time();
	player->delta_time = current_time - player->last_frame;
	player->last_frame = current_time;
}
void	update_pos(t_player *player, t_map *map)
{
	float	xo;
	float	yo;

	get_delta_time(player);
	//printf("delat = %f\n", player->delta_time);
	calc_offset(player, &xo, &yo);
	if (player->keybind.forwards)
		move_forward(player, map, xo, yo);
	if (player->keybind.backwards)
		move_backward(player, map, xo, yo);
	if(player->keybind.left)
		move_strafe_left(player, map);
	if(player->keybind.right)
		move_strafe_right(player, map);
	handle_rotation(player);
}


//void	update_pos(t_player *player, t_map *map)
//{
//	float	xo;
//	float	yo;
//	int	mpx;
//	int	mpy;
//	int	pos_xo;
//	//int	neg_xo;
//	int	pos_yo;
//	//int	neg_yo;
//
//	xo = 0;
//	yo = 0;
//	if (player->xdelt < 0)
//		xo = -20;
//	else
//		xo = 20;
//	if (player->ydelt < 0)
//		yo = -20;
//	else
//		yo = 20;
//	
//	mpx = player->xpos / map->tilesize;
//	mpy = player->ypos / map->tilesize;
//	pos_xo = (player->xpos + xo) / map->tilesize; 
//	pos_yo = (player->ypos + yo) / map->tilesize; 
//	//neg_xo = (player->xpos - xo) / 128; 
//	//neg_yo = (player->ypos - yo) / 128; 
//	
//
//	//printf("the pos_xo = %d\n", pos_xo);
//	//printf("the pos_yo = %d\n", pos_yo);
//	// printf("mpx = %d\n", mpx);
//	// printf("mpy = %d\n", mpy);
//
//	if (player->keybind.forwards)
//	{
//
//		if (map->grid[mpy][pos_xo] == 0)
//			player->xpos += player->xdelt / 2;
//		if (map->grid[pos_yo][mpx] == 0)
//			player->ypos += player->ydelt / 2;
//		// player->ypos -= 2;
//	}
//	if (player->keybind.backwards)
//	{
//	//	if (map->grid[pos_xo][mpy] == 0)
//	//		player->xpos -= player->xdelt / 4;
//	//	if (map->grid[mpx][neg_yo] == 0)
//	//	player->ypos -= player->ydelt / 4;
//	player->xpos -= player->xdelt / 4;
//	player->ypos -= player->ydelt / 4;
//	// player->ypos += 2;
//	}
//	if (player->keybind.left)
//	{
//		player->angle -= 0.04;
//		if (player->angle < 0)
//		player->angle += 2 * PI;
//		player->xdelt = cos(player->angle) * 5;
//		player->ydelt = sin(player->angle) * 5;
//		// player->xpos -= 2;
//	}
//	if (player->keybind.right)
//	{
//		player->angle += 0.04;
//		if (player->angle > 2 * PI)
//		player->angle -= 2 * PI;
//		player->xdelt = cos(player->angle) * 5;
//		player->ydelt = sin(player->angle) * 5;
//		// player->xpos += 2;
//	}
//}
