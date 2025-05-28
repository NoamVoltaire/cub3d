/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:51:36 by noam              #+#    #+#             */
/*   Updated: 2025/04/22 16:09:51 by noam             ###   ########.fr       */
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
	if (keycode == XK_Right)
		vars->player.keybind.see_right = true;
	if (keycode == XK_Left)
		vars->player.keybind.see_left = true;
	if (keycode == 65307)
		quit_everything(vars);
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
	if (keycode == XK_Right)
		vars->player.keybind.see_right = false;
	if (keycode == XK_Left)
		vars->player.keybind.see_left = false;
	return (0);
}
