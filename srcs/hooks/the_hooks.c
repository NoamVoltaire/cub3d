/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:10:22 by noam              #+#    #+#             */
/*   Updated: 2025/03/17 03:42:26 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	the_hooks(t_vars *vars)
{
	mlx_hook(vars->window, KeyPress, KeyPressMask, handle_key_press, vars);
	mlx_hook(vars->window, KeyRelease, KeyReleaseMask, handle_key_release, vars);
	// mlx_hook(vars->window, KeyRelease, KeyReleaseMask, handle_key_press, vars);
	// return;
}