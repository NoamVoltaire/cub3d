/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:10:22 by noam              #+#    #+#             */
/*   Updated: 2025/04/22 16:10:46 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->window);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit(0);
}

void	the_hooks(t_vars *vars)
{
	mlx_hook(vars->window, KeyPress, KeyPressMask, handle_key_press, vars);
	mlx_hook(vars->window, KeyRelease, KeyReleaseMask, handle_key_release, vars);
	mlx_hook(vars->window, 17, 0L, close_window, vars);//17 = fermeture de la fenetre
	// mlx_hook(vars->window, KeyRelease, KeyReleaseMask, handle_key_press, vars);
	// return;
}