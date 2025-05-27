/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrellie <lgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:15:50 by lgrellie          #+#    #+#             */
/*   Updated: 2025/05/19 14:26:55 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>
#include <stddef.h>
#include <stdio.h>

static t_list   *get_lines(int fd)
{
	char	*line;
	t_list	*new_line;
	t_list  *lines;
	int		ret;

	if (fd < 0)
		return (NULL);
	ret = next_gnl(&line, fd);
	lines = NULL;
	while (ret == 0)
	{
		new_line = ft_lstnew(line);
		if (new_line == NULL)
		{
			free(line);
			ft_lstclear(&lines, &free);
			return (NULL);
		}
		ft_lstadd_back(&lines, new_line);
		ret = next_gnl(&line, fd);
	}
	if (ret != 1)
		ft_lstclear(&lines, &free);
	return (lines);
}

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (!ft_strchr("01 NSEW", line[i]))
			return (false);
		++i;
	}
	if (i == 0)
		return (false);
	return (true);
}

int	check_input_syntax(t_list *input)
{
	t_list	*line;

	if (input == NULL)
		return (1);
	line = input;
	while (line != NULL)
	{
		if (is_map_line(line->content))
			printf("true\n");
		else
			printf("false\n");
		line = line->next;
	}
	return (0);
}




//size_t	longest_row(t_list *lst)
//{
//	int	bigest_row_len;
//	int	curr_row_len;
//
//	bigest_row_len = 0;
//	while (lst)
//	{
//		curr_row_len = ft_strlen(lst->content);
//		if (curr_row_len > bigest_row_len)
//			bigest_row_len = curr_row_len;
//		lst = lst->next;
//	}
//	return (bigest_row_len);
//}
//
//
//int **lst_to_int_map(t_list *lst, t_vars *vars, t_parse *parse)
//{
//	size_t cols;
//	size_t rows;
//	char	*line;
//	int	**map_tab_array;
//	int	i;
//	size_t	j;
//
//	(void)vars;
//	i = 0;
//	j = 0;
//	while (lst && !is_map_line(lst->content))
//		lst = lst->next;
//	rows = ft_lstsize(lst);
//	cols = longest_row(lst);
//	parse->m_w = cols;
//	parse->m_h = rows;
//	map_tab_array = malloc(sizeof(int *) * rows);
//	if (!map_tab_array)
//		return (NULL);
//	while (lst)
//	{
//		j = 0;
//		map_tab_array[i] = malloc(sizeof(int) * cols);
//		if (!map_tab_array[i])
//		return NULL;
//			line = (char *)lst->content;
//		while (j < cols)
//		{
//			if (line[j] == '\0')
//				line [j] = '1';
//			if (line[j] == 'N' || line[j] == 'S' || line[j] == 'W' || line[j] == 'E')
//			{
//				parse->playerxpos = (j * WIDTH / 32) + (WIDTH /32 /2);
//				parse->playerypos = (i * WIDTH / 32) + (WIDTH /32 /2);
//				//parse->playerxpos = (j * parse->m_w) + (parse->m_w / 2);
//				//parse->playerypos = (i * parse->m_w) + (parse->m_w / 2);
//				printf("Player found at map[%zu][%d], setting position to %f, %f\n",
//	j, i,
//	parse->playerxpos,
//	parse->playerypos);line[j] = '0';
//			}
//			else if (line[j] == ' ')
//				line[j] = '1';
//
//			map_tab_array[i][j] = line[j] - '0';
//
//			j++;
//		}
//		lst = lst->next; 
//		i++;
//		line = NULL;
//	}
//		
//
//	return  (map_tab_array);
//
//}
//
//
//
//
//
//
//
//int	check_args_before_map(t_list *lines)
//{
//	t_list *ptr;
//	int fd;
//	int i;
//
//	i = 0;
//	fd = 0;
//	ptr = lines;
//	while (ptr && i < 4)
//	{
//		char *line = ft_strdup((char *)ptr->content + 3);
//		//after "NO "
//		char *newline = strchr(line, '\n');
//		if (newline)
//			*newline = 0;
//		//delete "\n"
//		
//		//fd = open((char *)ptr->content + 3, O_RDONLY);
//		fd = open(line, O_RDONLY);
//		if (fd < 0)
//		{
//			printf("damn");
//			//printf("%s\n", (char *)ptr->content + 3);
//		}
//		else
//		{
//			printf("cool\n");
//			printf("%s\n", line);
//		}
//		ptr = ptr->next;
//		i++;
//		free (line);
//		line = NULL;
//	}
//	return (0);
//}
//void init_t_parse(t_list *lines, t_parse *parse)
//{
//	t_list *ptr;
//	char	*line;
//	char	*newline;
//	int	i;
//
//	ptr = lines;
//	i = 0;
//	while (ptr && i < 4)
//	{
//		//need to skip if space
//		line = ft_strdup((char *)ptr->content + 3);
//		//after "NO "
//		newline = strchr(line, '\n');
//		if (newline)
//			*newline = 0;
//		parse->t_paths[i] = line;
//		ptr = ptr->next;
//		i++;
//		
//	}
//}
//void	init_f_c_parse(t_list *lines, t_parse *parse)
//{
//	t_list *ptr;
//	char	*line;
//	//char	*newline;
//	int	i;
//	int	j;
//	int	is_f_flag;
//
//	i = 0;
//	j = 0;
//	is_f_flag = 1;
//	ptr = lines;
//	while (ptr && i < 7)
//	{
//		j = 0;
//		if (!strchr(ptr->content, 'F') )//&& !strchr(ptr->content, 'C'))
//		{
//			ptr = ptr->next;
//			i++;
//			continue;
//		}
//		line = ptr->content + 1;
//		printf("hahah %s\n", line);
//		while (j < 3)
//		{
//			if (is_f_flag)
//				parse->f_color_input[j] = ft_atoi(line);
//			else 
//				parse->c_color_input[j] = ft_atoi(line);
//			line = ft_strchr(line, ',') + 1;
//			j++;
//		}
//		is_f_flag = 0;
//		ptr = ptr->next;
//		i++;
//	}
//	//printf(" AYYYYY %d, %d, %d \n ", parse->f_color_input[0],parse->f_color_input[1], parse->f_color_input[2]);  
//
//}
int	parse_into_vars(int fd, t_vars *vars)
{
	t_list	*lines;
	t_parse	parse;//

	lines = get_lines(fd);
	if (close(fd) == -1)
	{
		perror("close");
		return (1);
	}
	//check_args_before_map(lines);//
	//(void)vars;
	//t_list *ptr = lines;
	//while (ptr)
	//{
	//	printf("%s", (char *)ptr->content);
	//	ptr = ptr->next;
	//}
	//ROUGH IDEA
	//init_t_parse(lines, &parse);
	//init_f_c_parse(lines, &parse);
	initialize_vars(lines, &parse);
	parse.tab = lst_to_int_map(lines, vars ,&parse);
	if (!flood_fill_map(&parse, parse.p_first_xposm,
			parse.p_first_yposm))
		printf("damn the room is not floodtight\n");
		
	vars->parse = parse;
	///
	////
	if (check_input_syntax(lines) == 1)
		return (1);
	return (0);
	//return (intialize_vars(lines, vars);
}
