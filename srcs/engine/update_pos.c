/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 00:06:53 by noam              #+#    #+#             */
/*   Updated: 2025/03/16 00:07:30 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	update_pos(t_player *player, t_map map)
{
	float	xo;
	float	yo;
	int	mpx;
	int	mpy;
	int	pos_xo;
	//int	neg_xo;
	int	pos_yo;
	//int	neg_yo;

	xo = 0;
	yo = 0;
	if (player->xdelt < 0)
		xo = -20;
	else
		xo = 20;
	if (player->ydelt < 0)
		yo = -20;
	else
		yo = 20;
	
	mpx = player->xpos / 128;
	mpy = player->ypos / 128;
	pos_xo = (player->xpos + xo) / 128; 
	pos_yo = (player->ypos + yo) / 128; 
	//neg_xo = (player->xpos - xo) / 128; 
	//neg_yo = (player->ypos - yo) / 128; 
	

	//printf("the pos_xo = %d\n", pos_xo);
	//printf("the pos_yo = %d\n", pos_yo);

	if (player->keybind.forwards)
	{

		if (map.grid[mpy][pos_xo] == 0)
			player->xpos += player->xdelt / 2;
		if (map.grid[pos_yo][mpx] == 0)
		player->ypos += player->ydelt / 2;
		// player->ypos -= 2;
	}
	if (player->keybind.backwards)
	{
	//	if (map.grid[pos_xo][mpy] == 0)
	//		player->xpos -= player->xdelt / 4;
	//	if (map.grid[mpx][neg_yo] == 0)
	//	player->ypos -= player->ydelt / 4;
	player->xpos -= player->xdelt / 4;
	player->ypos -= player->ydelt / 4;
	// player->ypos += 2;
	}
	if (player->keybind.left)
	{
		player->angle -= 0.04;
		if (player->angle < 0)
		player->angle += 2 * PI;
		player->xdelt = cos(player->angle) * 5;
		player->ydelt = sin(player->angle) * 5;
		// player->xpos -= 2;
	}
	if (player->keybind.right)
	{
		player->angle += 0.04;
		if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
		player->xdelt = cos(player->angle) * 5;
		player->ydelt = sin(player->angle) * 5;
		// player->xpos += 2;
	}
}
