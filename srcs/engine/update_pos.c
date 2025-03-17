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

void	update_pos(t_player *player)
{
	if (player->keybind.forwards)
	{
		player->xpos += player->xdelt / 2;
		player->ypos += player->ydelt / 2;
		// player->ypos -= 2;
	}
	if (player->keybind.backwards)
	{
	player->xpos -= player->xdelt / 2;
	player->ypos -= player->ydelt / 2;
	// player->ypos += 2;
	}
	if (player->keybind.left)
	{
		player->angle -= 0.1;
		if (player->angle < 0)
		player->angle += 2 * PI;
		player->xdelt = cos(player->angle) * 5;
		player->ydelt = sin(player->angle) * 5;
		// player->xpos -= 2;
	}
	if (player->keybind.right)
	{
		player->angle += 0.1;
		if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
		player->xdelt = cos(player->angle) * 5;
		player->ydelt = sin(player->angle) * 5;
		// player->xpos += 2;
	}
}
