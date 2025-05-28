/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:13:33 by noam              #+#    #+#             */
/*   Updated: 2025/05/28 09:33:25 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static int	main_loop(t_vars *vars)
{
	//t_vars	vars;

	init_vars(vars);
	the_hooks(vars);
	
	//if (!vars.textures.t_addr)  // Exit function early to prevent crash
		 //printf("ITSNULLLLLLLLLL");
		// printf("vars.player.xpos = %f\n", vars.player.xpos);
	mlx_loop_hook(vars->mlx, every_frame, vars);
	mlx_loop(vars->mlx);
	return (0);
}

static int	check_map_name(char *str)
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
	ft_bzero(&vars, sizeof(t_vars));
	if (parse_into_vars(fd, &vars))
		return (1);
	return (main_loop(&vars));
}
