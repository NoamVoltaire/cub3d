/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_states.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:51:36 by noam              #+#    #+#             */
/*   Updated: 2025/03/15 23:55:01 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	handle_key_press(int keycode, t_vars *vars)
{
	if (keycode == XK_w)
		vars->player.keybind.forwards = true;
	if (keycode == XK_s)
		vars->player.keybind.backwards = true;
	if (keycode == XK_a)
		vars->player.keybind.left = true;
	if (keycode == XK_d)
		vars->player.keybind.right = true;
	return (0);
}

int	handle_key_release(int keycode, t_vars *vars)
{
	if (keycode == XK_w)
		vars->player.keybind.forwards = false;
	if (keycode == XK_s)
		vars->player.keybind.backwards = false;
	if (keycode == XK_a)
		vars->player.keybind.left = false;
	if (keycode == XK_d)
		vars->player.keybind.right = false;
	return (0);
}
