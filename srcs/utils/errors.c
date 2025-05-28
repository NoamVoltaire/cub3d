/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:54:12 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 10:54:14 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

char	*get_error_message(int err_code)
{
	if (err_code == ERR_TEXTURE_PATH)
		return (MSG_TEXTURE_PATH);
	if (err_code == ERR_COLOR_FORMAT)
		return (MSG_COLOR_FORMAT);
	if (err_code == ERR_COLOR_RANGE)
		return (MSG_COLOR_RANGE);
	if (err_code == ERR_FILE_OPEN)
		return (MSG_FILE_OPEN);
	if (err_code == ERR_MEMORY_ALLOC)
		return (MSG_MEMORY_ALLOC);
	if (err_code == ERR_MAP_FORMAT)
		return (MSG_MAP_FORMAT);
	if (err_code == ERR_MISSING_PLAYER)
		return (MSG_MISSING_PLAYER);
	if (err_code == ERR_MISSING_TEXTURE)
		return (MSG_MISSING_TEXTURE);
	return ("Unknown error.");
}

void	handle_parse_error(t_parse *parse, int err_code)
{
	char	*msg;

	msg = get_error_message(err_code);
	print_error_msg(msg);
	free_parse(parse);
	exit(EXIT_FAILURE);
}
