/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrellie <lgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:28:08 by lgrellie          #+#    #+#             */
/*   Updated: 2025/05/17 15:44:12 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_map_name(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 5)
		return (1);
	return (ft_strncmp(&str[len - 4], ".cub", 4));
}

int	main(int ac, char **av)
{
	int		fd;
	t_vars	vars;

	if (ac != 2 || check_map_name(av[1]))
	{
		printf("Syntax: ./cub3D [map_name].cub\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		perror("cub3D");
	if (parse_into_vars(fd, &vars))
		return (1);
	return (main_loop(vars));
}
