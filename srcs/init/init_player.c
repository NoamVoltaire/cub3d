/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:09:18 by noam              #+#    #+#             */
/*   Updated: 2025/03/16 00:10:53 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	set_keyb(t_keyb *keybind)
{
	keybind->forwards = false;
	keybind->backwards = false;
	keybind->left = false;
	keybind->right = false;
	keybind->see_left = false;
	keybind->see_right = false;
}

void	init_player(t_player *player, t_parse *parse)
{
	//player->xpos = WIDTH / 2;
	//player->ypos = HEIGHT / 2;
	player->xpos = parse->playerxpos;
	player->ypos = parse->playerypos;
	player->angle = parse->p_angle;
	player->xdelt = cos(player->angle) * 5;
	player->ydelt = sin(player->angle) * 5;
	player->move_spd = 15;
	player->rot_spd = 2.5;
	set_keyb(&player->keybind);
	player->last_frame = get_time();
}
