/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:04:16 by noam              #+#    #+#             */
/*   Updated: 2025/04/21 17:12:51 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	init_vars(t_vars *vars)
{
	init_map(&vars->map); //TEMPORARY
	init_player(&vars->player);
	init_window(vars);
	init_textures(vars, 0xCF60BF, 0x40303C);
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

