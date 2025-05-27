#include <ctype.h>
#include <cub.h>
#include <string.h>

size_t	longest_row(t_list *lst)
{
	int	bigest_row_len;
	int	curr_row_len;

	bigest_row_len = 0;
	while (lst)
	{
		curr_row_len = ft_strlen(lst->content);
		if (curr_row_len > bigest_row_len)
			bigest_row_len = curr_row_len;
		lst = lst->next;
	}
	return (bigest_row_len);
}


static t_list *skip_to_map_lines(t_list *lst)
{
	while (lst && !is_map_line(lst->content))
		lst = lst->next;
	return lst;
}

static int **allocate_map_array(size_t rows, size_t cols)
{
	int **map;
	size_t i;

	map = malloc(sizeof(int *) * rows);
	if (!map)
		return NULL;
	i = 0;
	while (i < rows)
	{
		map[i] = malloc(sizeof(int) * cols);
		if (!map[i])
			return NULL;
		i++;
	}
	return map;
}

static char normalize_map_char(char c)
{
	if (c == '\0')
		return '1';
	if (c == ' ' )
		return '0';
	return c;
}

static void handle_player_char(char dir, size_t x, size_t y, t_parse *parse)
{
	parse->playerxpos = (x * TILE_SIZE) + (TILE_SIZE / 2);
	parse->playerypos = (y * TILE_SIZE) + (TILE_SIZE / 2);
	parse->p_first_xposm = x;
	parse->p_first_yposm = y;
	if (dir == 'N')
		parse->p_angle = tPI / 2;
	else if (dir == 'S')
		parse->p_angle = 3 * tPI / 2;
	else if (dir == 'E')
		parse->p_angle = 0;
	else if (dir == 'W')
		parse->p_angle = tPI;
}


static void process_map_line(char *line, int *row, size_t row_idx, size_t cols, t_parse *parse)
{
	size_t j;
	char c;
	size_t	line_len;

	j = 0;
	c = 'a';
	line_len = ft_strlen(line);
	//printf("line (addr: %p): \"%s\"\n", (void *)line, line);
//printf("strlen(line) = %zu, expected cols = %zu\n", ft_strlen(line), cols);
	//if (line == NULL)
		//return ;
	while (j < cols && j < line_len)
	{
		c = normalize_map_char(line[j]);
		if ((c == 'N' || c == 'S' || c == 'W' || c == 'E'))
		{
			handle_player_char(c, j, row_idx, parse);
			c = '0';
		}
		row[j] = c - '0';
		j++;
	}
}

//static void process_map_line(char *line, int *row, size_t row_idx, size_t cols, t_parse *parse)
//{
//	size_t j = 0;
//
//	while (j < cols)
//	{
//		if (line[j] == '\0')
//			line[j] = '1';
//		if (line[j] == ' ')
//			line[j] = '0';
//		if (line[j] == 'N' || line[j] == 'S' || line[j] == 'W' || line[j] == 'E')
//		{
//			parse->playerxpos = (j * TILE_SIZE) + (TILE_SIZE / 2);
//			parse->playerypos = (row_idx * TILE_SIZE) + (TILE_SIZE / 2);
//			//printf("Player found at map[%zu][%zu], setting position to %f, %f\n",
//				j, row_idx, parse->playerxpos, parse->playerypos);
//			line[j] = '0';
//		}
//		row[j] = line[j] - '0';
//		j++;
//	}
//}

int	**lst_to_int_map(t_list *lst, t_parse *parse)
{
	size_t	cols;
	size_t	rows;
	int	**map_tab_array;
	size_t	i;

	//(void)vars;
	lst = skip_to_map_lines(lst);
	rows = ft_lstsize(lst);
	cols = longest_row(lst);
	parse->m_w = cols;
	parse->m_h = rows;
	map_tab_array = allocate_map_array(rows, cols);
	if (!map_tab_array)
		return NULL;
	//needs exit

	i = 0;
	while (lst && is_map_line(lst->content))
	{
		process_map_line((char *)lst->content, map_tab_array[i], i, cols, parse);
		lst = lst->next;
		i++;
	}
	return map_tab_array;
}

//int **lst_to_int_map(t_list *lst, t_vars *vars, t_parse *parse)
//{
//
//	size_t cols;
//	size_t rows;
//	char	*line;
//	int	**map_tab_array;
//	int	i;
//	size_t	j;
//
//	(void)vars;
//	//		NEED FUNCTION FOR ALLOC
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
//			return NULL;
//		line = (char *)lst->content;
//		while (j < cols)
//		{
//			if (line[j] == '\0')
//				line [j] = '1';
//			//	NEED FUNCTION FOR SETTING PLAYER
//			if (line[j] == 'N' || line[j] == 'S' || line[j] == 'W' || line[j] == 'E')
//			{
//				parse->playerxpos = (j * TILE_SIZE) + (TILE_SIZE / 2);
//				parse->playerypos = (i * TILE_SIZE) + (TILE_SIZE / 2);
//				//parse->playerxpos = (j * parse->m_w) + (parse->m_w / 2);
//				//parse->playerypos = (i * parse->m_w) + (parse->m_w / 2);
//				printf("Player found at map[%zu][%d], setting position to %f, %f\n",
//	j, i,
//	parse->playerxpos,
//	parse->playerypos);line[j] = '0';
//			}
//			else if (line[j] == ' ')
//				line[j] = '1';
//			//	THIS IS A QUICKFIX BUT NEEDS FLOOD FILL BEFORE
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

int	check_args_before_map(t_list *lines)
{
	t_list *ptr;
	int fd;
	//int i;

	//i = 0;
	fd = 0;
	ptr = lines;
	while (ptr)
	{
		//if (ft_strchr((char*)ptr->content)
		char *line = ft_strdup((char *)ptr->content + 3);
		//after "NO "
		char *newline = strchr(line, '\n');
		if (newline)
			*newline = 0;
		//delete "\n"
		
		//fd = open((char *)ptr->content + 3, O_RDONLY);
		fd = open(line, O_RDONLY);
		if (fd < 0)
		{
			printf("damn BUT NEEDS EXIT");
			//printf("%s\n", (char *)ptr->content + 3);
		}
		else
		{
			printf("cool BUT NEEDS EXIT\n");
			printf("%s\n", line);
		}
		close(fd);
		ptr = ptr->next;
		//i++;
		free (line);
		line = NULL;
	}
	return (0);
}

static void	set_rgb_colors(char *line, int color_arr[4])
{
	char	**rgb_to_convert;
	int		count;
	int		j;
	int		is_in_range;

	//printf("line = = = %s\n", line);
	j = 0;
	rgb_to_convert = ft_split(line, ',');
	count = 0;
	is_in_range = 1;
	while (rgb_to_convert[count])
	{
		if (count <= 3 && !(ft_atoi(rgb_to_convert[count]) < 255
			&& ft_atoi(rgb_to_convert[count]) > 0))
			is_in_range = 0;
		count++;
	}
	   //for (j = 0; j < count; j++)
        //printf("Token %d: '%s'\n", j, rgb_to_convert[j]);
	//j = 0;
	if (count != 3 || is_in_range)
	{
		free_tab(rgb_to_convert);
		//return (0);
		printf("wrong nb of args%s\n", line);
		return ;
	}
	while (j < 3)
	{

		color_arr[j] = ft_atoi(rgb_to_convert[j]);
		j++;
		//color_arr[j] = ft_atoi(line);
		//line = ft_strchr(line, ',') + 1;
	}
	color_arr[3] = 1;
	free_tab(rgb_to_convert);

	//return (0);
	//needs returns


}

int	line_into_color_textures(t_parse *parse, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
	{
					//printf ("GOOFY\n");
			//return (err_msg(data->mapinfo.path, ERR_FLOOR_CEILING, ERR));
			//printf("c_color_input[3] = %d, line[%d] = '%c'\n", parse->c_color_input[3], j, line[j]);

		if (parse->c_color_input[3] == 0 && line[j] == 'C')
		{
			set_rgb_colors(line + j + 1, parse->c_color_input);
			//parse->c_color_input = set_rgb_colors(line + j + 1, parse->c_color_input);
			if (parse->c_color_input[3] == 0)
			{
					printf ("not valid color\n");
			exit(1);
			}
				//return (err_msg(data->mapinfo.path, ERR_COLOR_CEILING, ERR));
		}
		else if (parse->f_color_input[3] == 0 && line[j] == 'F')
		{
					//printf ("AAAAAH\n");
			set_rgb_colors(line + j + 1, parse->f_color_input);
			//parse->f_color_input = set_rgb_colors(line + j + 1, parse->f_color_input);
			if (parse->f_color_input[3]== 0)
			{
					printf ("not valid color\n");
			exit(1);
			}
				//return (err_msg(data->mapinfo.path, ERR_COLOR_FLOOR, ERR));
		}
	}
	else
				printf ("error floor ceiling args\n");
		//return (err_msg(data->mapinfo.path, ERR_FLOOR_CEILING, ERR));
	return (0);
}


static char	*get_texture_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
				//printf ("uhhh %s\n", (path));
				//printf ("uhhh %s\n", (path));
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

int	line_into_texture_path(char *line, t_parse *parse, int j)
{
	if (!line[j + 2] && ft_isprint(line[j + 2]))
	return (1);
				//printf ("asdfasdfa %s\n", (line +j));
	if (line[j] == 'N' && line[j + 1] == 'O' && !(parse->t_paths[0]))
		parse->t_paths[0] = get_texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(parse->t_paths[1]))
		parse->t_paths[1] = get_texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(parse->t_paths[2]))
		parse->t_paths[2] = get_texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(parse->t_paths[3]))
		parse->t_paths[3] = get_texture_path(line, j + 2);
	else
		return (1);
	return (0);
}

//int	ignore_space_get_info(t_list *lst, t_parse *parse)
int	ignore_space_get_info(char *line, t_parse *parse)
{
	int	j;
	//char	*line;

	j = 0;
	//line = (char*)lst->content;
	while (line[j] == ' ' || line[j] == '\t' || line[j] == '\n')
		j++;
	if (ft_isprint(line[j]) && !ft_isdigit(line[j]))
	{
		if (line[j + 1] && (line[j] == 'C' || line[j] == 'F' ))
		{
			if (line_into_color_textures(parse, line, j))
			{
				//printf ("we didn't put an error for colors failing \n");
				ft_putstr_fd("we didn't put an error for colors failing \n", 2);
			}

		}
		else if (line[j + 1] && ft_isprint(line[j + 1]) && !ft_isdigit(line[j+1])) 
		{
			if (line_into_texture_path(line, parse, j))
			{
				ft_putstr_fd("we didn't put an error for colors failing \n", 2);
				printf ("we didn't put an error for texturepath failing \n");
				printf ("line is %s\n", (line +j));
			}
		}
	}
		
	return(0);

}

void	initialize_vars(t_list *lst, t_parse *parse)
{
	//parse->c_color_input[3] = 0;
	//parse->f_color_input[3] = 0;
	parse->t_paths[0] = NULL;
	parse->t_paths[1] = NULL;
	parse->t_paths[2] = NULL;
	parse->t_paths[3] = NULL;
	ft_memset(parse->c_color_input, 0, sizeof(parse->c_color_input));
	ft_memset(parse->f_color_input, 0, sizeof(parse->f_color_input));
	parse->c_color_input[3] = 0;
	parse->f_color_input[3] = 0;
	//
	while (lst && lst->content)
	{
		if (lst->content && !is_map_line(lst->content))
		{
			if (ignore_space_get_info(lst->content, parse))
				printf("error in line\n");
		}
		lst = lst->next;
	}

//	printf(" AYYYYY %d, %d, %d \n ", parse->f_color_input[0],parse->f_color_input[1], parse->f_color_input[2]);  
//	printf(" YAAAAAAAA %d, %d, %d \n ", parse->c_color_input[0],parse->c_color_input[1], parse->c_color_input[2]);  
		
}
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
//		if (!strchr(ptr->content, 'F') && !strchr(ptr->content, 'C'))
//		{
//			ptr = ptr->next;
//			i++;
//			continue;
//		}
//		line = ptr->content + 1;
//			//printf("hahah %s\n", line);
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
//	//printf(" YAAAAAAAA %d, %d, %d \n ", parse->c_color_input[0],parse->c_color_input[1], parse->c_color_input[2]);  
//
//}
