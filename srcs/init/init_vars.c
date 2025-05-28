/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:04:16 by noam              #+#    #+#             */
/*   Updated: 2025/05/26 17:21:00 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <stdlib.h>

int	rgb_to_hex(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	init_vars(t_vars *vars)
{
	init_map(&vars->map, &vars->parse); //TEMPORARY
	//vars->map.grid = vars->parse.tab;
	//vars->map.mapx = vars->parse.m_w;
	//vars->map.mapy = vars->parse.m_h;
	//vars->map.tilesize = WIDTH / 16; 
	//vars->map.tilesize = TILE_SIZE; 
	init_player(&vars->player, &vars->parse);
	//vars->player.xpos = vars->parse.playerxpos;
	//vars->player.ypos = vars->parse.playerypos;
	//printf("Player position from vars:\n  x = %f\n  y = %f\n",
	//vars->parse.playerxpos,
	//vars->parse.playerypos);

	init_window(vars);
	//init_textures(vars, 0xCF60BF, 0x40303C);
	init_textures(vars, rgb_to_hex(vars->parse.f_color_input),
		rgb_to_hex(vars->parse.c_color_input));
}
/*
 *
in 0x000000
each 00 correspond to a letter R||G||B
as i understand it first '0' is R/16
and second '0' is R%16
BOTH digits are in HEX (0123456789ABCDEF)

R, G, B = [32,16,0] = 0x 20,10,00
R, G, B = [0,12,28] = 0x 00,0C,1C

*
*/

