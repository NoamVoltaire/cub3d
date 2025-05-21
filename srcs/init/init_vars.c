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
	init_textures(vars, 0x000000FF, 0x00FF0000);
}
